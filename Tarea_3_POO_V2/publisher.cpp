#include "publisher.h"

Publisher::Publisher(QString name, Broker &broker, QString topicName)
    :Component(name, topicName),
    topic(broker.createTopic(topicName))
{}
