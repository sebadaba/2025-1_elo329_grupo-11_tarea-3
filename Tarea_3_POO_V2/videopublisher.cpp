#include "videopublisher.h"

VideoPublisher::VideoPublisher(QString name, Broker &broker, QString Topic_name)
    :Publisher(name, broker, Topic_name){



}

VideoPublisher::~VideoPublisher(){

}

void VideoPublisher::SetURL(QString url){this->URL = url;}
