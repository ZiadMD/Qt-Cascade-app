QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

CXXFLAGS += -Wno-unused-parameter -Wno-unused-variable

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    frameconvertor.cpp \
    main.cpp \
    cv_01.cpp \
    objectdetector.cpp

HEADERS += \
    cascadeloader.h \
    cv_01.h \
    detectionsettings.h \
    frameconvertor.h \
    objectdetector.h \
    visualizer.h

FORMS += \
    cv_01.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += /usr/include/opencv4

LIBS += -L/usr/lib/x86_64-linux-gnu/ \
        -lopencv_core \
        -lopencv_imgproc \
        -lopencv_highgui \
        -lopencv_videoio \
        -lopencv_objdetect

INCLUDEPATH += $$PWD/'../../CPP_LIBS/libtorch_cpu/include' \
               $$PWD/'../../CPP_LIBS/libtorch_cpu/include/torch/csrc/api/include'

# Library directories
LIBS += -L$$PWD/"../../CPP_LIBS/libtorch_cpu/lib" -ltorch -ltorch_cpu -lc10



