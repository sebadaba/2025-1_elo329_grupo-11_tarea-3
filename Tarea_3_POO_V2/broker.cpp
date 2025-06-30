#include "broker.h"

Broker::Broker()
    :topics(new QVector<Topic*>)
{}

Broker::~Broker(){
    delete topics;
}

Topic * Broker::createTopic(QString topicName){
    Topic * topic = findTopic(topicName);
    if (topic != nullptr) return topic;
    topic = new Topic(topicName);
    topics->append(topic);
    return topic;
}

bool Broker::subscribe(Subscriber *sub){
    Topic * topic = findTopic(sub->getTopicName());
    if (topic == nullptr) return false; // no existe el topic y solo publishers crean topicos
    topic->subscribe(sub);
    return true;
}

Topic * Broker::findTopic(QString topicName){
    for (Topic * topic : *topics){
        if (topic->hasThisName(topicName)) return topic;
    }
    return nullptr;
}
