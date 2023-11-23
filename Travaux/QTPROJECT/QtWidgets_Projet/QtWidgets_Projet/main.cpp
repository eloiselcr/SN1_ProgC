#include "QtWidgets_Projet.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgets_Projet w;
    w.show();
    return a.exec();
}
