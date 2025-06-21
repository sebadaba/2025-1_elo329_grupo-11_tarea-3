#include "GPSCarPublisher.h"
#include <QDebug>
#include <QTextStream>

GPSCarPublisher::GPSCarPublisher(QString nombre, Broker &broker, QString topicName) :
    Publisher(nombre,broker,topicName),
    tiempoact(0),
    iteradoract(0)
{
    QString archivoname = QFileDialog::getOpenFileName(nullptr,"Select route file","","Text Files (*.txt)");
    if(archivoname.isEmpty()){
        qDebug() << "Archivo no ha sido seleccionado.";
        return;
    }
    QFile file(archivoname);
    QTextStream in(&file);
    while(!in.atEnd()){
        int tiempo;
        float posx,posy;
        in >> tiempo >> posx >> posy;
        posiciones.append({tiempo,posx,posy});
    }
}

GPSCarPublisher::~GPSCarPublisher(){}

//funcion que interpola y usa publishNewEvent() para actualizar la ruta.
void GPSCarPublisher::pasarData(){

    posicion pos = Interpolacion();
    if(pos.time == -1){
        emit endTime();
        return;
    }

    QString mensaje = QString("%1 %2 %3").arg(pos.time).arg(pos.x).arg(pos.y);
    this->publishNewEvent(mensaje);
    tiempoact++;
}

posicion GPSCarPublisher::Interpolacion(){
    if(iteradoract >= posiciones.size()-1){
        posicion fin;
        fin.time = -1;
        fin.x = 0;
        fin.y = 0;
        return fin;
    }

    posicion p1 = posiciones[iteradoract];
    posicion p2 = posiciones[iteradoract + 1];

    int t1 = p1.time;
    int t2 = p2.time;

    if(tiempoact > t2){
        iteradoract++;
        return posicion{-1,0,0};
    }

    //interpolacion.
    float a = float(tiempoact - t1)/(t2-t1);
    float posx = (1-a) * p1.x + a * p2.x;
    float posy = (1-a) * p1.y + a * p2.y;

    return posicion{tiempoact,posx,posy};
}

QVector<posicion> GPSCarPublisher::getPosiciones() const{
    return posiciones;
}

bool GPSCarPublisher::existe() const{
    return !posiciones.isEmpty();
}

