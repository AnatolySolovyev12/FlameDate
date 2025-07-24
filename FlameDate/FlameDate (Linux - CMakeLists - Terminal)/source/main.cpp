#include "FlameDate.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    //SetConsoleOutputCP(1251);  // Установить UTF-8

    QCoreApplication a(argc, argv);
    FlameDate w;

    return a.exec();
}
