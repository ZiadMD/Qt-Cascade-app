#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <opencv2/opencv.hpp>
#include <vector>

class Visualizer {
public:
    static void drawRectangles(cv::Mat& frame, const std::vector<cv::Rect>& detections, const cv::Scalar& color) {
        for (const auto& rect : detections) {
            cv::rectangle(frame, rect, color, 2);
        }
    }
};

#endif // VISUALIZER_H
