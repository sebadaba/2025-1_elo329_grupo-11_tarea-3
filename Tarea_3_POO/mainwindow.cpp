#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
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
}

MainWindow::~MainWindow()
{

    delete ui;
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

