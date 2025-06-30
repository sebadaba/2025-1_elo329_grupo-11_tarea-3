#ifndef TOPIC_H
#define TOPIC_H
#include "subscriber.h"
#include <QVector>

class Topic
{
public:
    Topic(QString topicName);
    void subscribe(Subscriber *sub);
    void notify(QString message);
    bool hasThisName(QString name);

private:
    QString topicName;
    QVector<Subscriber*> subscribers;
};

#endif // TOPIC_H
