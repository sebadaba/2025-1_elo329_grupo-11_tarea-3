#ifndef PUBLISHER_H
#define PUBLISHER_H
#include "broker.h"

class Publisher : public Component
{
public:
    Publisher(QString name, Broker &broker, QString topicName);

protected:
    void publishNewEvent(QString message);

private:
    Topic * topic;
};

#endif // PUBLISHER_H
