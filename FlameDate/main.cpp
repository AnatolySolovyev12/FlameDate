#include "FlameDate.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(1251);  // Установить UTF-8

    QApplication a(argc, argv);
    FlameDate w;

    return a.exec();
}
