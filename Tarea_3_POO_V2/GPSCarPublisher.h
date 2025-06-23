#ifndef GPSCARPUBLISHER_H
#define GPSCARPUBLISHER_H

#include "ObjectCarrier.h"
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

class GPSCarPublisher : public conveniente, public Publisher{
    Q_OBJECT
public:
    GPSCarPublisher(QString nombre,Broker &broker,QString topicName);
    ~GPSCarPublisher();
    QVector<posicion> getPosiciones() const;
    bool existe() const;
private slots:
    void pasarData();
signals:
    void endTime() override;
private:
    QVector<posicion> posiciones;
    int tiempoact;
    int iteradoract;
    QTimer* tempo;
};


#endif // GPSCARPUBLISHER_H
