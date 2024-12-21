#ifndef DETECTIONSETTINGS_H
#define DETECTIONSETTINGS_H

enum class DetectionType {
    Face,
    EyesRight,
    EyesLeft,
    EyesBoth,
    Body
};


class DetectionSettings {
public:
    bool detectFace = false;
    bool detectEyes_R = false;
    bool detectEyes_L = false;
    bool detectEyes_RL = false;
    bool detectBody = false;

    void setDetectionType(DetectionType type, bool enable) {
        switch (type) {
        case DetectionType::Face: detectFace = enable; break;
        case DetectionType::EyesRight: detectEyes_R = enable; break;
        case DetectionType::EyesLeft: detectEyes_L = enable; break;
        case DetectionType::EyesBoth: detectEyes_RL = enable; break;
        case DetectionType::Body: detectBody = enable; break;
        }
    }
};

#endif // DETECTIONSETTINGS_H
