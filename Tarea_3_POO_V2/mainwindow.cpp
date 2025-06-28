#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include "videopublisher.h"
#include "broker.h"
#include "videofollower.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , broker(Broker())
    , videoPublisher(VideoPublisher("Ahmaru", broker, "twitch"))
{
    ui->setupUi(this);
    ui->UrlBoton->setDisabled(true);
    connect(ui->actionVideo_Publisher, &QAction::triggered, this, &MainWindow::on_actionVideo_Publisher_triggered);
    connect(ui->actionVideo_Subscriber, &QAction::triggered, this, &MainWindow::on_actionVideo_Subscriber_triggered);
    connect(ui->actionGPS,&QAction::triggered, this, &MainWindow::click_GPS);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete autito;
    //delete rutero;
}

void MainWindow::click_GPS(){
    autito = new GPSCarPublisher("Seba",broker,"ferrari");

    if(!autito->existe()){
        QMessageBox::warning(this,"ERROR","No se cargaron correctamente las posiciones.");
        delete autito;
        autito = nullptr;
        return;
    }
    qDebug("Se ha creado GPSPublisher bien");

    GPSFollower* rutero = new GPSFollower(nullptr);

    rutero->show();
    rutero->raise();
    rutero->activateWindow();
    //qDebug("mostrando cosito");

    connect(autito,&GPSCarPublisher::endTime,this,[=](){
        rutero->close();
        QMessageBox::information(this,"Ruta finalizada","Se ha terminado la simulacion de GPS");
        //qDebug("Timer lindo terminado");
    });
    //rutero->update(autito->obtenerMSJ());
    //rutero->update();
}

void MainWindow::on_actionVideo_Publisher_triggered()
{

}

void MainWindow::on_actionVideo_Subscriber_triggered()
{
}

void MainWindow::on_campoURL_returnPressed() // Logica para el campo de texto URL
{
    videoPublisher.SetURL(ui->campoURL->text());
    ui->UrlBoton->setText(ui->campoURL->text());
    ui->UrlBoton->setDisabled(false);
    ui->campoURL->clear();
}

void MainWindow::on_UrlBoton_clicked()
{
    VideoFollower *videoWindow = new VideoFollower();
    videoWindow->show();
    videoWindow->raise();
    videoWindow->activateWindow();

    videoWindow->PlayVideo(ui->UrlBoton->text());
}

