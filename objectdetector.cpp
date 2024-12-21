#include "objectdetector.h"

void ObjectDetector::detect(cv::Mat& frame) {
    if (settings.detectFace) {
        performDetection(frame, faceCascade, cv::Scalar(255, 0, 0)); // Blue for faces
    }
    if (settings.detectEyes_R) {
        performDetection(frame, r_eyesCascade, cv::Scalar(0, 255, 0)); // Green for right eyes
    }
    if (settings.detectEyes_L) {
        performDetection(frame, l_eyesCascade, cv::Scalar(0, 0, 255)); // Red for left eyes
    }
    if (settings.detectEyes_RL) {
        performDetection(frame, rl_eyesCascade, cv::Scalar(255, 255, 0)); // Yellow for both eyes
    }
    if (settings.detectBody) {
        performDetection(frame, bodyCascade, cv::Scalar(0, 255, 255)); // Cyan for bodies
    }
}

void ObjectDetector::performDetection(cv::Mat &frame, cv::CascadeClassifier &cascade, const cv::Scalar &color)
{
    std::vector<cv::Rect> detections;
    cascade.detectMultiScale(frame, detections);
    Visualizer::drawRectangles(frame, detections, color);
}
