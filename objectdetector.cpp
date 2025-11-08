#include "objectdetector.h"

void ObjectDetector::detect(cv::Mat& frame) {
    // Early exit if no detections are enabled
    if (!settings.detectFace && !settings.detectEyes_R && !settings.detectEyes_L && 
        !settings.detectEyes_RL && !settings.detectBody) {
        return;
    }
    
    // Convert to grayscale once for all detections (major performance improvement)
    cv::Mat grayFrame;
    cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
    
    if (settings.detectFace) {
        performDetection(frame, grayFrame, faceCascade, cv::Scalar(255, 0, 0)); // Blue for faces
    }
    if (settings.detectEyes_R) {
        performDetection(frame, grayFrame, r_eyesCascade, cv::Scalar(0, 255, 0)); // Green for right eyes
    }
    if (settings.detectEyes_L) {
        performDetection(frame, grayFrame, l_eyesCascade, cv::Scalar(0, 0, 255)); // Red for left eyes
    }
    if (settings.detectEyes_RL) {
        performDetection(frame, grayFrame, rl_eyesCascade, cv::Scalar(255, 255, 0)); // Yellow for both eyes
    }
    if (settings.detectBody) {
        performDetection(frame, grayFrame, bodyCascade, cv::Scalar(0, 255, 255)); // Cyan for bodies
    }
}

void ObjectDetector::performDetection(cv::Mat &frame, const cv::Mat &grayFrame, cv::CascadeClassifier &cascade, const cv::Scalar &color)
{
    std::vector<cv::Rect> detections;
    // Use optimized parameters for faster detection with reasonable accuracy
    // scaleFactor: 1.1 (smaller = more thorough but slower, 1.1 is good balance)
    // minNeighbors: 3 (higher = fewer false positives but may miss some objects)
    // flags: 0 (default)
    // minSize: cv::Size(30, 30) - ignore very small detections to improve speed
    cascade.detectMultiScale(grayFrame, detections, 1.1, 3, 0, cv::Size(30, 30));
    Visualizer::drawRectangles(frame, detections, color);
}
