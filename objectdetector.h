#ifndef OBJECTDETECTOR_H
#define OBJECTDETECTOR_H

#include <string>
#include <opencv2/opencv.hpp> // Include OpenCV headers
#include "cascadeloader.h"
#include "detectionsettings.h"
#include "visualizer.h"

class ObjectDetector
{
public:
    ObjectDetector():
        faceCascade(CascadeLoader::load(faceDetectorPath, "face")),
        rl_eyesCascade(CascadeLoader::load(bothEyesDetectorPath, "both eyes")),
        l_eyesCascade(CascadeLoader::load(leftEyeDetectorPath, "left eye")),
        r_eyesCascade(CascadeLoader::load(rightEyeDetectorPath, "right eye")),
        bodyCascade(CascadeLoader::load(bodyDetectorPath, "body")) {}


    void detect(cv::Mat& frame); // Declaration of the detect function
    DetectionSettings settings;

private:


    std::string faceDetectorPath = "/home/ziadmoh/CPP_LIBS/opencv-4.10.0/data/lbpcascades/lbpcascade_frontalface_improved.xml";
    cv::CascadeClassifier faceCascade;

    std::string bothEyesDetectorPath = "/home/ziadmoh/CPP_LIBS/opencv-4.10.0/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
    cv::CascadeClassifier rl_eyesCascade;

    std::string leftEyeDetectorPath = "/home/ziadmoh/CPP_LIBS/opencv-4.10.0/data/haarcascades/haarcascade_lefteye_2splits.xml";
    cv::CascadeClassifier l_eyesCascade;

    std::string rightEyeDetectorPath = "/home/ziadmoh/CPP_LIBS/opencv-4.10.0/data/haarcascades/haarcascade_righteye_2splits.xml";
    cv::CascadeClassifier r_eyesCascade;

    std::string bodyDetectorPath = "/home/ziadmoh/CPP_LIBS/opencv-4.10.0/data/haarcascades/haarcascade_fullbody.xml";
    cv::CascadeClassifier bodyCascade;

    void performDetection(cv::Mat& frame, cv::CascadeClassifier& cascade, const cv::Scalar& color);

};

#endif // OBJECTDETECTOR_H
