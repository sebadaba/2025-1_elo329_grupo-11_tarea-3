    #ifndef COMPONENT_H
#define COMPONENT_H
#include <QString>

class Component
{
public:
    Component(QString name, QString topicName);

    QString getName();
    QString getTopicName();

protected:
    QString name;
    QString topicName;
};

#endif // COMPONENT_H
