#include "GPSCarPublisher.h"
#include "GPSFollower.h"
#include <QDebug>
#include <QTextStream>

GPSCarPublisher::GPSCarPublisher(QString nombre, Broker &broker, QString topicName) :
    Publisher(nombre,broker,topicName),
    tiempoact(0),
    iteradoract(0)
{
    qDebug("OLA.....");
    QString archivoname = QFileDialog::getOpenFileName(nullptr,"Select route file","","Text Files (*.txt)");
    if(archivoname.isEmpty()){
        qDebug("Archivo no ha sido seleccionado.");
        return;
    }else{
        QFile file(archivoname);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << "No se pudo abrir el archivo." << file.errorString();
        }
        QTextStream in(&file);
        while(!in.atEnd()){
            int tiempo;
            float posx,posy;
            in >> tiempo >> posx >> posy;
            posiciones.append({tiempo,posx,posy});
            qDebug("Leyendo....");
        }
    }

    tempo = new QTimer(this);
    connect(tempo,&QTimer::timeout,this,&GPSCarPublisher::pasarData);
    tempo->start(1000);
    qDebug("Timer comenzado!!!!");
}

GPSCarPublisher::~GPSCarPublisher(){}

//funcion que interpola y usa publishNewEvent() para actualizar la ruta.
void GPSCarPublisher::pasarData(){
    if(iteradoract >= posiciones.size()-1){
        tempo->stop();
        emit endTime();
        return ;//"LOL";
    }

    posicion p1 = posiciones[iteradoract];
    posicion p2 = posiciones[iteradoract + 1];

    int t1 = p1.time;
    int t2 = p2.time;

    if(tiempoact > t2){
        iteradoract++;
        if (iteradoract >= posiciones.size() - 1) {
            tempo->stop();
            emit endTime();
            return;
        }
        pasarData();
        return;
    }

    //interpolacion.
    float a = (t2 - t1) != 0 ? float(tiempoact - t1) / (t2 - t1) : 0.0;
    float posx = (1-a) * p1.x + a * p2.x;
    float posy = (1-a) * p1.y + a * p2.y;

    QString mensaje = QString("%1 %2 %3").arg(tiempoact).arg(posx).arg(posy);
    this->publishNewEvent(mensaje);
    tiempoact++;
}

QVector<posicion> GPSCarPublisher::getPosiciones() const{
    return posiciones;
}

bool GPSCarPublisher::existe() const{
    return !posiciones.isEmpty();
}

