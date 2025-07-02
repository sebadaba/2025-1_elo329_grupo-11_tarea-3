#ifndef VIDEOFOLLOWER_H
#define VIDEOFOLLOWER_H
#include <QDialog>
#include <QDebug>
#include <QCloseEvent>
#include "subscriber.h"
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui {
class Form;
}
QT_END_NAMESPACE

class VideoFollower : public QDialog, public Subscriber
{
    Q_OBJECT
public:
    VideoFollower(QWidget *parent = nullptr);
    ~VideoFollower();
    void PlayVideo(QString Url);
    void update(QString message) override;

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_botonPlay_clicked(); //Funcion para el boton play
    void on_botonPause_clicked(); //Funcion para el boton pause
    void on_BotonReInicio_clicked(); //Funcion para el boton reinicio
    void on_SliderVolumen_valueChanged(int value); // Funcion para cambiar el volumen

private:
    Ui::Form *ui; 
    QString videoUrl;
    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWindow;
};

#endif // VIDEOFOLLOWER_H
