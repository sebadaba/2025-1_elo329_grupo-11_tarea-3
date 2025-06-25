#include "GPSFollower.h"
#include "ui_gpsfollower.h"
#include "subscriber.h"
#include <QTextStream>
#include <QPainter>

GPSFollower::GPSFollower(QWidget *parent) :
    QWidget(parent)
    , Subscriber("AntonioOG","ferrari")
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
    int transX = static_cast<int>(vctr.X);
    int transY = static_cast<int>(vctr.Y);
    painter.drawEllipse(transX*3,transY*3,15,15);
}

void GPSFollower::update(QString& msg){
    QString copy = msg;
    QTextStream stream(&copy);
    stream >> vctr.tiempo >> vctr.X >> vctr.Y;

    //Escribe en el label.
    ui->labelcoordenadas->setText(QString("t: %1 , x: %2 , y: %3 ").arg(vctr.tiempo).arg(vctr.X).arg(vctr.Y));

    QWidget::update();
}

