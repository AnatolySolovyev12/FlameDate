#include "FlameDate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(1251);  // ���������� UTF-8

    QApplication a(argc, argv);
    FlameDate w;
    w.setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "\\icon.png"));
    w.setWindowTitle("FlameDate by Solovev");
    w.show();
    return a.exec();
}
