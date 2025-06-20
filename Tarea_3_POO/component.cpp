#include "component.h"


Component::Component(QString name, QString topicName)
    :name(name),
    topicName(topicName)
    {}

QString Component::getName() {return name;}
QString Component::getTopicName() {return topicName;}
