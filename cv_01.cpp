#include "cv_01.h"
#include "ui_cv_01.h"

CV_01::CV_01(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CV_01)
    , Detector (new ObjectDetector())
    , isPaused(true)
{
    ui->setupUi(this);

    // Buttons Style
    ui->videoPlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->photoLeftSwitchButton->setIcon(style()->standardIcon(QStyle::SP_ArrowLeft));
    ui->photoRightSwitchButton->setIcon(style()->standardIcon(QStyle::SP_ArrowRight));

    ui->EyeRight->setEnabled(false);
    ui->EyeLeft->setEnabled(false);
    ui->EyeBoth->setEnabled(false);

    disablePhotosControls();
    disableVideoControls();

    Timer = new QTimer(this);
    connect(Timer, &QTimer::timeout, this, &CV_01::processFrame);
}

CV_01::~CV_01()
{
    delete ui;
}

void CV_01::processFrame()
{
    FrameCapture.read(Frame);
    if(Frame.empty()) return;

    Detector->detect(Frame);

    currentFrame = FrameConvertor::CvMatToQImage(Frame).scaled(ui->MediaBox->size());

    ui->MediaBox->setPixmap(QPixmap::fromImage(currentFrame));
}

/////////////////////////////////////////////////////////////  VIDEOS CONTROLS  ///////////////////////////////////////////////////////////////////

void CV_01::on_videoOpenButton_clicked()
{

    Timer->stop();
    if(!images.isEmpty()) images.clear();

    qDebug() <<"Getting Video File....";
    QString FileName = QFileDialog::getOpenFileName(this,tr("Select Video File"),"",tr("MP4 File (*.mp4)"));

    if (FileName.isEmpty()) {
        qDebug()<<"No file selected";

        return;
    }
    qDebug() <<"Video File Not Empty";

    FrameCapture.open(FileName.toStdString());

    qDebug() << (FrameCapture.isOpened() ? "Video file opened successfully!" : "Error: Unable to open video file!");

    enableVideoControls();
    disablePhotosControls();

    Timer->start(MMS_TIME);
}

void CV_01::on_videoPlayPause_clicked()
{
    if(isPaused){
        ui->videoPlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        Timer->stop();
    } else {
        ui->videoPlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        Timer->start(MMS_TIME);
    }
    isPaused = !isPaused;
}

void CV_01::getCameras()
{
    QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
    for (const QCameraDevice& camera : cameras) qDebug()<<camera.description();
}

void CV_01::disableVideoControls()
{


    ui->videoPlayPause->setVisible(false);
}

void CV_01::enableVideoControls()
{

    ui->videoPlayPause->setVisible(true);
}

////////////////////////////////////////////////////////////  PHOTOS CONTROLS  ///////////////////////////////////////////////////////////////////

void CV_01::on_photoOpenButton_clicked()
{
    Timer->stop();
    FrameCapture.release();

    qDebug() << "Getting Image File....";

    QStringList FileNames = QFileDialog::getOpenFileNames(this, tr("Select Image Files"), "", tr("Images (*.png *.jpg *.jpeg)"));
    if (FileNames.isEmpty()) {
        qDebug() << "No file selected.";
        return;
    }
    qDebug() << "Image File Not Empty";

    for (const QString &FileName : FileNames) {
        QPixmap pixmap(FileName);
        if (!pixmap.isNull()) {
            images.append(pixmap); // Add image to the vector
        } else {
            qDebug() << "Failed to load image:" << FileName;
        }
    }

    if (!images.isEmpty()) {
        currentImageIndex = 0; // Display the first image
        displayImage();
    }

    disableVideoControls();
    enablePhotosControls();
}

void CV_01::displayImage()
{

    QImage img = images[currentImageIndex].toImage();
    Frame = FrameConvertor::QImageToCvMat(img);
    Detector->detect(Frame);
    // Convert the processed cv::Mat back to QImage
    currentFrame = FrameConvertor::CvMatToQImage(Frame).scaled(ui->MediaBox->size());

    ui->MediaBox->setPixmap(QPixmap::fromImage(currentFrame));

    ui->currentFileNameLabel->setText(tr("Image %1 of %2").arg(currentImageIndex + 1).arg(images.size()));

}

void CV_01::disablePhotosControls()
{
    ui->photoLeftSwitchButton->setVisible(false);
    ui->photoRightSwitchButton->setVisible(false);
}

void CV_01::enablePhotosControls()
{
    ui->photoLeftSwitchButton->setVisible(true);
    ui->photoRightSwitchButton->setVisible(true);
}

void CV_01::on_photoRightSwitchButton_clicked()
{
    if (images.size() > 1) {
        currentImageIndex = (currentImageIndex + 1) % images.size(); // Go to the next image
        displayImage();
    }
}

void CV_01::on_photoLeftSwitchButton_clicked()
{
    if (images.size() > 1) {
        currentImageIndex = (currentImageIndex - 1 + images.size()) % images.size(); // Go to the previous image
        displayImage();
    }
}

//////////////////////////////////////////////////////////  CAMERA CONTROLS  ///////////////////////////////////////////////////////////////////

void CV_01::on_startCameraButton_clicked()
{
    Timer->stop();
    if(!images.isEmpty()) images.clear();

    ui->currentFileNameLabel->setText("Live Feed!");

    FrameCapture.open(0);

    qDebug() << (FrameCapture.isOpened() ? "Video file opened successfully!" : "Error: Unable to open video file!");

    enableVideoControls();
    disablePhotosControls();

    Timer->start(MMS_TIME);

    disablePhotosControls();
    enableVideoControls();
}

//////////////////////////////////////////////////////////////  DETECTIONS  ///////////////////////////////////////////////////////////////////

void CV_01::on_DetectEyesCheck_stateChanged(int arg1)
{
    if (arg1) {
        ui->EyeRight->setEnabled(true);
        ui->EyeLeft->setEnabled(true);
        ui->EyeBoth->setEnabled(true);

        ui->EyeBoth->setChecked(true);
    } else {
        ui->EyeBoth->setAutoExclusive(false);
        ui->EyeBoth->setChecked(false);
        ui->EyeBoth->setAutoExclusive(true);

        ui->EyeRight->setAutoExclusive(false);
        ui->EyeRight->setChecked(false);
        ui->EyeRight->setAutoExclusive(true);

        ui->EyeLeft->setAutoExclusive(false);
        ui->EyeLeft->setChecked(false);
        ui->EyeLeft->setAutoExclusive(true);


        ui->EyeRight->setEnabled(false);
        ui->EyeLeft->setEnabled(false);
        ui->EyeBoth->setEnabled(false);
    }
}

void CV_01::on_EyeRight_toggled(bool checked)
{
    Detector->settings.setDetectionType(DetectionType::EyesRight, checked);

    qDebug() << (checked ? "R Eye on" : "R Eye off");
    if(!images.empty()) displayImage();
}


void CV_01::on_EyeLeft_toggled(bool checked)
{
    Detector->settings.setDetectionType(DetectionType::EyesLeft, checked);
    qDebug() << (checked ? "L Eye on" : "L Eye off");
    if(!images.empty()) displayImage();
}


void CV_01::on_EyeBoth_toggled(bool checked)
{
    Detector->settings.setDetectionType(DetectionType::EyesBoth, checked);
    qDebug() << (checked ? "RL Eye on" : "RL Eye off");
    if(!images.empty()) displayImage();

}


void CV_01::on_Detect_Face_stateChanged(int arg1)
{
    if(arg1) {
        Detector->settings.setDetectionType(DetectionType::Face, true);
        qDebug() << "Face on";

    } else {
        Detector->settings.setDetectionType(DetectionType::Face, false);
        qDebug() << "Face off";
    }

    if(!images.empty()) displayImage();
}


void CV_01::on_Detect_Body_stateChanged(int arg1)
{
    if(arg1) {
        Detector->settings.setDetectionType(DetectionType::Body, true);
        qDebug() << "Body on";

    } else {
        Detector->settings.setDetectionType(DetectionType::Body, false);
        qDebug() << "Body off";
    }
    if(!images.empty()) displayImage();

}

