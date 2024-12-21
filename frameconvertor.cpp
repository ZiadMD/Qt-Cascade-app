#include "frameconvertor.h"


Mat FrameConvertor::QImageToCvMat(const QImage &image)
{
    // Convert QImage to cv::Mat
    Mat mat;
    switch (image.format()) {
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = Mat(image.height(), image.width(), CV_8UC4, (void*)image.bits(), image.bytesPerLine());
        cvtColor(mat, mat, cv::COLOR_BGRA2BGR);
        break;
    case QImage::Format_RGB888:
        mat = Mat(image.height(), image.width(), CV_8UC3, (void*)image.bits(), image.bytesPerLine());
        cvtColor(mat, mat, cv::COLOR_RGB2BGR);
        break;
    default:
        qWarning() << "QImage "<< image.format() << "format not supported!";
        break;
    }
    return mat;
}

QImage FrameConvertor::CvMatToQImage(const Mat &mat)
{

    // Convert cv::Mat to QImage
    switch (mat.type()) {
    case CV_8UC4:
        return QImage(mat.data, mat.cols, mat.rows, mat.step[0], QImage::Format_ARGB32).copy(); // Return a copy to avoid dangling pointer
    case CV_8UC3:
        return QImage(mat.data, mat.cols, mat.rows, mat.step[0], QImage::Format_RGB888).rgbSwapped(); // Convert BGR to RGB
    case CV_8U:
        return QImage(mat.data, mat.cols, mat.rows, mat.step[0], QImage::Format_Grayscale8).copy(); // Return a copy to avoid dangling pointer
    default:
        qWarning() << "cv::Mat type not supported!";
        return QImage();
    }
}
