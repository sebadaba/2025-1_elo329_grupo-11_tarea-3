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
    , autito(GPSCarPublisher("Seba",broker,"ferrari"))
    , rutero(new GPSFollower("Sebagey","ferrari",nullptr))
    , reloj(new QTimer(this))
{
    ui->setupUi(this);
    ui->UrlBoton->setDisabled(true);
    connect(ui->actionVideo_Publisher, &QAction::triggered, this, &MainWindow::on_actionVideo_Publisher_triggered);
    connect(ui->actionVideo_Subscriber, &QAction::triggered, this, &MainWindow::on_actionVideo_Subscriber_triggered);

    connect(reloj, &QTimer::timeout, this , [=](){
        autito.pasarData();
    });
    reloj->start(1000);

    /*
    if(autito.getPosiciones().isEmpty()){
        reloj->stop();
        QMessageBox::warning(this,"ERROR","No se han cargado correctamente las posiciones.");
    }
    */
    if(!autito.existe()){
        reloj->stop();
        QMessageBox::warning(this,"ERROR","No se han cargado correctamente las posiciones.");
    }

    rutero->show();
    rutero->raise();
    rutero->activateWindow();

    connect(&autito,&GPSCarPublisher::endTime,this,[=](){
        reloj->stop();
        qDebug() << "Ruta finalizada.";
    });

}

MainWindow::~MainWindow()
{
    delete ui;
    delete reloj;
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

