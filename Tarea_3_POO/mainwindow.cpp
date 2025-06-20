#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include "videopublisher.h"
#include "broker.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , broker(Broker())
    , videoPublisher(VideoPublisher("Ahmaru", broker, "twitch"))
{
    ui->setupUi(this);

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

void MainWindow::on_campoURL_returnPressed()
{
    videoPublisher.SetURL(ui->campoURL->text());
    ui->UrlBoton->setText(ui->campoURL->text());

    ui->campoURL->clear();
}

