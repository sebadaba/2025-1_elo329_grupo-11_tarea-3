#ifndef BROKER_H
#define BROKER_H
#include "topic.h"

class Broker
{
public:
    Broker();
    ~Broker();
    Topic * createTopic(QString topicName);
    bool subscribe(Subscriber &sub);

private:
    QVector<Topic*> * topics;
    Topic * findTopic(QString topicName);
};

#endif // BROKER_H
