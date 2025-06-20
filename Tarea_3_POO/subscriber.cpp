#include "subscriber.h"

Subscriber::Subscriber(QString name, QString topicName)
    :Component(name, topicName)
    {}
void Subscriber::update(QString message){}
