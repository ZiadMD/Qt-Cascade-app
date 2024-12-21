#ifndef FRAMECONVERTOR_H
#define FRAMECONVERTOR_H

#include <QImage>
#include <opencv2/opencv.hpp>
#include <QDebug>

using namespace cv;

class FrameConvertor
{
public:
    static Mat QImageToCvMat(const QImage& image);
    static QImage CvMatToQImage(const Mat& mat);
};

#endif // FRAMECONVERTOR_H
