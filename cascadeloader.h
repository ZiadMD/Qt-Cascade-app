#ifndef CASCADELOADER_H
#define CASCADELOADER_H

#include <opencv2/objdetect.hpp>
#include <QDebug>
#include <string>

class CascadeLoader {
public:
    static cv::CascadeClassifier load(const std::string& path, const QString& name) {
        cv::CascadeClassifier cascade;
        if (!cascade.load(path)) {
            qWarning() << "Error loading" << name << "cascade!";
        }
        return cascade;
    }
};

#endif // CASCADELOADER_H
