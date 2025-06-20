#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "videopublisher.h"
#include "broker.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionVideo_Publisher_triggered();
    void on_actionVideo_Subscriber_triggered();
    void on_campoURL_returnPressed();
    void on_UrlBoton_clicked();

private:
    Ui::MainWindow *ui;
    Broker broker;
    VideoPublisher videoPublisher;
};
#endif // MAINWINDOW_H
