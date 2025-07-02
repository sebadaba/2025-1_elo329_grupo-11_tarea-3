#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , broker(Broker())
    , videoPublisher(VideoPublisher("Ahmaru", broker, "twitch"))
    , rutero(new GPSFollower("AntonioOG","ferrari",nullptr))
{
    ui->setupUi(this);

    setWindowTitle("Simulador Publisher/Subscriber - Video y GPS");
    resize(500, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete autito;
    delete rutero;
}

void MainWindow::onVideoUrlChanged()
{
    if (!ui->campoURL->text().isEmpty()) {
        videoPublisher.SetURL(ui->campoURL->text());

        QString currentUrl = ui->campoURL->text();
        ui->UrlBoton->setText(currentUrl);
        ui->UrlBoton->setEnabled(true);
    }
}

void MainWindow::click_GPS(){
    bool okPublisherName;
    QString publisherName = QInputDialog::getText(this, tr("Crear Publicador GPS"),
                                                  tr("Nombre del Publicador:"), QLineEdit::Normal,
                                                  QString(), &okPublisherName);
    if (!okPublisherName || publisherName.isEmpty()) {
        QMessageBox::warning(this, "Creacion Cancelada", "Se requiere un nombre para el publicador.");
        return;
    }

    bool okTopicName;
    QString topicName = QInputDialog::getText(this, tr("Crear Publicador GPS"),
                                              tr("Nombre del Topico (GPS):"), QLineEdit::Normal,
                                              QString("GPS"), &okTopicName);
    if (!okTopicName || topicName.isEmpty()) {
        QMessageBox::warning(this, "Creacion Cancelada", "Se requiere un nombre para el topico.");
        return;
    }

    autito = new GPSCarPublisher("Seba",broker,"ferrari");
    if(!autito->existe()){
        QMessageBox::warning(this,"ERROR","No se cargaron correctamente las posiciones.");
        delete autito;
        autito = nullptr;
        return;
    }

    ui->gpsFileLabel->setText("Archivo cargado correctamente");

    qDebug("Se ha creado GPSPublisher bien");
    this->broker.subscribe(rutero);
    rutero->show();
    rutero->raise();
    rutero->activateWindow();

    connect(autito,&GPSCarPublisher::endTime,this,[=](){
        rutero->close();
        QMessageBox::information(this,"Ruta finalizada","Se ha terminado la simulacion de GPS");
    });

    rutero->update("0 0 0");
    ui->currentPositionLabel->setText("Posicion inicial cargada");
}

void MainWindow::on_actionVideo_Publisher_triggered()
{

}

void MainWindow::on_actionVideo_Subscriber_triggered()
{
}

void MainWindow::on_campoURL_returnPressed()
{
    onVideoUrlChanged();
}

void MainWindow::on_UrlBoton_clicked()
{
    VideoFollower *videoWindow = new VideoFollower();
    videoWindow->show();
    videoWindow->raise();
    videoWindow->activateWindow();

    QString currentUrl = ui->UrlBoton->text();
    videoWindow->PlayVideo(currentUrl);
}
