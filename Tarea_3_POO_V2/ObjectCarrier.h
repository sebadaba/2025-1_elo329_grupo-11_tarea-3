#ifndef OBJECTCARRIER_H
#define OBJECTCARRIER_H
#include <QTimer>
#include <QPair>
#include <QObject>

class conveniente : public QObject{
    Q_OBJECT

public:
    conveniente(QObject* parent = nullptr) : QObject(parent){}

signals:
    void endTime();
};

#endif // OBJECTCARRIER_H
