#include "videofollower.h"
#include "ui_video.h"
#include <QDebug>
#include <QUrl>
#include <QCloseEvent>

VideoFollower::VideoFollower(QWidget *parent)
    : QDialog(parent), Subscriber("VideoFollower", "VideoTopic"), ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowTitle("Reproduccion de video");
    setModal(false);

    mediaPlayer = new QMediaPlayer(this);
    videoWindow = new QVideoWidget(this);
    
    mediaPlayer->setVideoOutput(videoWindow);


    ui->VideoLayout->addWidget(videoWindow); // Crea una ventana para el video

    videoWindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    mediaPlayer->setVolume(50);
    ui->SliderVolumen->setValue(50);


    
}

VideoFollower::~VideoFollower() // Destructor
{

    if (mediaPlayer) {
        mediaPlayer->stop();

    }
    
    if (videoWindow) {
        videoWindow->setParent(nullptr);
    }
    
    delete ui;
}

void VideoFollower::on_botonPlay_clicked() // Logica para el boton play
{

    if(mediaPlayer->state() == QMediaPlayer::PlayingState){
        ui->botonPlay->setText(">");
        mediaPlayer->pause();
        qDebug("pause video");
    }
    else{
        ui->botonPlay->setText("||");
        mediaPlayer->play();
        qDebug("video playing");
    }
}

void VideoFollower::on_BotonReInicio_clicked() // Logica para el boton reinicio
{
    mediaPlayer->setPosition(0);
    qDebug("restarting video");

}


void VideoFollower::on_SliderVolumen_valueChanged(int value) // Logica para el slider y el cambio de volumen
{
    mediaPlayer->setVolume(value);
}

void VideoFollower::PlayVideo(QString Url)
{
    videoUrl = Url;
    QUrl videoQUrl(Url);


    mediaPlayer->setMedia(videoQUrl);

    
    qDebug() << "Cargando video:" << Url;
}

void VideoFollower::update(QString message) // Logica de actualizacion de eventos
{
    qDebug() << "VideoFollower recibió actualización:" << message;
    if (!message.isEmpty()) {
        PlayVideo(message);
    }
}

void VideoFollower::closeEvent(QCloseEvent *event) // Metodo para para la reproduccion del video
{

    if (mediaPlayer) {
        mediaPlayer->stop();
    }
    
    qDebug("Cerrando VideoFollower");
    event->accept();
}

