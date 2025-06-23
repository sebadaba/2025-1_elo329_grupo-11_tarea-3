#include "GPSFollower.h"
#include "ui_gpsfollower.h"
#include "subscriber.h"
#include <QTextStream>
#include <QPainter>

GPSFollower::GPSFollower(QString nombre, QString topicNamen,QWidget *parent) :
    QWidget(parent)
    , Subscriber(name,topicName)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowTitle("Seguimiento ruta Seba");
    setFixedSize(400,400);
}

GPSFollower::~GPSFollower(){
    delete ui;
}

void GPSFollower::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setBrush(Qt::red);
    painter.setRenderHint(QPainter::Antialiasing);
    //drawEllipse usa solo int.
    int transX = static_cast<int>(X);
    int transY = static_cast<int>(Y);
    painter.drawEllipse(transX*3,transY*3,15,15);
}

void GPSFollower::update(QString& msg){
    QString copy = msg;
    QTextStream stream(&copy);
    stream >> tiempo >> X >> Y ;

    //Escribe en el label.
    ui->labelcoordenadas->setText(QString("t: %1 , x: %2 , y: %3 ").arg(tiempo).arg(X).arg(Y));

    QWidget::update();
}
