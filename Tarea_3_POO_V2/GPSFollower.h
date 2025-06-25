#ifndef GPSFOLLOWER_H
#define GPSFOLLOWER_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "subscriber.h"

QT_BEGIN_NAMESPACE
namespace Ui{
class Form;
}

struct posiciones{
    float X,Y;
    int tiempo;
};

QT_END_NAMESPACE

class GPSFollower : public QWidget, public Subscriber{
    Q_OBJECT
public:
    GPSFollower(QWidget* parent = nullptr);
    ~GPSFollower();
    void update(QString& mensaje);
    //bool existe() const;
protected:
    void paintEvent(QPaintEvent* event);
private:
    Ui::Form* ui;
    posiciones vctr;
};

#endif // GPSFOLLOWER_H
