#ifndef GPSFOLLOWER_H
#define GPSFOLLOWER_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "subscriber.h"

class GPSFollower : public Subscriber{
public:
    GPSFollower();
    ~GPSFollower();
    void update(const QString& mensaje);

private:
    QWidget* ventana;
    QLabel* text;
    float X,Y;
    int tiempo;
};

#endif // GPSFOLLOWER_H
