#ifndef GPSCARPUBLISHER_H
#define GPSCARPUBLISHER_H

#include <QVector>
#include <QFileDialog>
#include <QPair>
#include "publisher.h" //Clase base

//Estructura sacada de ChatGPT.
struct posicion{
    int time;
    float x;
    float y;
};

class GPSCarPublisher : public Publisher{
public:
    GPSCarPublisher(QString nombre,Broker &broker,QString topicName);
    ~GPSCarPublisher();
    void pasarData();
    posicion Interpolacion();

private:
    QVector<posicion> posiciones;
    int tiempoact;
    int iteradoract;

};


#endif // GPSCARPUBLISHER_H
