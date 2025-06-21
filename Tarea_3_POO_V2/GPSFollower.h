#ifndef GPSFOLLOWER_H
#define GPSFOLLOWER_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "subscriber.h"

QT_BEGIN_NAMESPACE
namespace Ui{
class gpsfollower;
}
QT_END_NAMESPACE

class GPSFollower : public QWidget, public Subscriber{
    Q_OBJECT
public:
    GPSFollower(QString nombre,QString topicName, QWidget* parent = nullptr);
    ~GPSFollower();
    void update(const QString& mensaje);
protected:
    void paintEvent(QPaintEvent* event);
private:
    Ui::gpsfollower* ui;
    float X,Y;
    int tiempo;
};

#endif // GPSFOLLOWER_H
