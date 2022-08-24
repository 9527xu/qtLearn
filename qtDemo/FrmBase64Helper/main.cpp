#include "FrmBase64Helper.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FrmBase64Helper w;
    w.show();
    return a.exec();
}
