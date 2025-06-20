#include "GPSCarPublisher.h"


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
};

//funcion que interpola y usa publishNewEvent() para actualizar la ruta.
GPSCarPublisher::pasarData(){

}
