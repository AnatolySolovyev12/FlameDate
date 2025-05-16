#include "FlameDate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlameDate w;
    w.show();
    return a.exec();
}
