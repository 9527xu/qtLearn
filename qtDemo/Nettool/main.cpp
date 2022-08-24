#include "FrmTcpServer.h"
#include <QtWidgets/QApplication>
#include"TcpClient.h"
#include<iostream>
#include "FrmTcpClient.h"
#include "FrmUdpClient.h"
using namespace std;
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    FrmTcpClient w;
    FrmTcpServer h;
    FrmUdpClient r;
    w.show();
    h.show();
    r.show();
    return a.exec();
}
