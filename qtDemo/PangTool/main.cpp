#include "PangTool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PangTool w;
    w.show();
    return a.exec();
}
