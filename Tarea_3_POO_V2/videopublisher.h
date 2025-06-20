#ifndef VIDEOPUBLISHER_H
#define VIDEOPUBLISHER_H
#include "publisher.h"
#include <QHBoxLayout>


class VideoPublisher : public Publisher{

private:
    QString URL;
    QHBoxLayout layout;
public:
    VideoPublisher(QString name, Broker &broker, QString Topic_name);
    ~VideoPublisher();

    void SetURL(QString url);
};

#endif // VIDEOPUBLISHER_H
