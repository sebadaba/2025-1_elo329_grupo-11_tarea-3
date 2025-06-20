#include "topic.h"

Topic::Topic(QString topicName)
    :topicName(topicName)
    {}

void Topic::subscribe(Subscriber &sub){
    subscribers.append(sub);
}

void Topic::notify(QString message){
    for (Subscriber sub : subscribers){
        sub.update(message);
    }
}

bool Topic::hasThisName(QString name){
    return (this->topicName == name);
}
