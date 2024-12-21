#ifndef CV_01_H
#define CV_01_H

#include <QMainWindow>

#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QStyle>
#include <QDebug>
#include <QLabel>
#include <QMediaDevices>
// For Camera
#include <QCamera>

#include "objectdetector.h"
#include "frameconvertor.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CV_01;
}
QT_END_NAMESPACE

class CV_01 : public QMainWindow
{
    Q_OBJECT

public:
    CV_01(QWidget *parent = nullptr);
    ~CV_01();

private slots:
    void processFrame(); // New slot for processing frames

    void on_videoOpenButton_clicked();

    void on_videoPlayPause_clicked();

    void on_photoOpenButton_clicked();

    void on_photoRightSwitchButton_clicked();

    void on_photoLeftSwitchButton_clicked();

    void on_startCameraButton_clicked();

    void on_DetectEyesCheck_stateChanged(int arg1);

    void on_EyeRight_toggled(bool checked);

    void on_EyeLeft_toggled(bool checked);

    void on_EyeBoth_toggled(bool checked);

    void on_Detect_Face_stateChanged(int arg1);

    void on_Detect_Body_stateChanged(int arg1);

private:
    Ui::CV_01 *ui;
    ObjectDetector *Detector;
    QVector<QPixmap> images;
    QTimer *Timer;
    const int MMS_TIME = 40;
    VideoCapture FrameCapture;
    Mat Frame;
    QImage currentFrame;
    int currentImageIndex;
    bool isPaused = false;


    void displayImage();
    void getCameras();

    void disableVideoControls();
    void enableVideoControls();

    void disablePhotosControls();
    void enablePhotosControls();
};

#endif // CV_01_H
