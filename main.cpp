#include "cv_01.h"

#include <QApplication>

// #undef slots

// #include <torch/torch.h>

// #include <torch/script.h>

// #define slots Q_SLOTS

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CV_01 w;
    w.show();
    return a.exec();
}
