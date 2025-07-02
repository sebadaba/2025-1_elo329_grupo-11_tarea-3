#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include "broker.h"
#include "videopublisher.h"
#include "GPSFollower.h"
#include "GPSCarPublisher.h"
#include "videofollower.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onVideoUrlChanged();
    void click_GPS();
    void on_actionVideo_Publisher_triggered();
    void on_actionVideo_Subscriber_triggered();
    void on_campoURL_returnPressed();
    void on_UrlBoton_clicked();

private:
    Ui::MainWindow *ui;
    Broker broker;
    VideoPublisher videoPublisher;
    GPSFollower *rutero;
    GPSCarPublisher *autito = nullptr;

};

#endif // MAINWINDOW_H
