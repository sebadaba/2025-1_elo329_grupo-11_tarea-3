#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include "component.h"

class Subscriber : public Component
{
public:
    Subscriber(QString name, QString topicName);
    virtual void update(QString message);
};

#endif // SUBSCRIBER_H
