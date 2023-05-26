#include "pointui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PointUI w;
    w.show();
    return a.exec();
}
