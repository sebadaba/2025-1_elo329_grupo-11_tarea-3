#include "GPSFollower.h"
#include "ui_gpsfollower.h"
#include "subscriber.h"
#include <QTextStream>
#include <QPainter>
#include <QDebug>

GPSFollower::GPSFollower(QString nombre,QString topicName,QWidget *parent) :
    QWidget(parent)
    , Subscriber(nombre,topicName)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowTitle("Seguimiento ruta");
    setFixedSize(400,400);
}

GPSFollower::~GPSFollower(){
    delete ui;
}

void GPSFollower::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setBrush(Qt::red);
    painter.setRenderHint(QPainter::Antialiasing);
    if(vctr.tiempo >= 0){
        int transX = static_cast<int>(vctr.X);
        int transY = static_cast<int>(vctr.Y);
        painter.drawEllipse(transX*3,transY*3,15,15);
    }
}

void GPSFollower::update(QString message){
    qDebug()<<"Mensaje recibido"<<message;

    QString copy = message;
    QTextStream stream(&copy);
    stream >> vctr.tiempo >> vctr.X >> vctr.Y;

    qDebug()<< "Valores: "<<vctr.tiempo<<vctr.X<<vctr.Y;

    //Escribe en el label.
    ui->labelcoordenadas->setText(
        QString("t: %1 , x: %2 , y: %3")
            .arg(vctr.tiempo)
            .arg(vctr.X, 0, 'f', 2)
            .arg(vctr.Y, 0, 'f', 2)
        );
    QWidget::update();
}

