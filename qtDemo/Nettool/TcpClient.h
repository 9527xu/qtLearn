#pragma once
#include"quihelperdata.h"
#include"appconfig.h"
#include<qdebug.h>
#include <QObject>
#include<QtNetwork>
#include<qthread.h>
#include<qstring.h>
//为了方便并发和单独处理数据，所以单独写了个专门类处理
#if 1
//小数据量可以不用线程，手法数据本身默认异步的
class TcpClient  : public QObject//负责通信交流
#else
class TcpClient:public QThread
#endif
{
	Q_OBJECT

public:
	TcpClient(QTcpSocket *socket,QObject *parent=0);
	~TcpClient();
public slots:
	void sendData(const QString& data);
	void disconnectFromHost();
	void abort();
private slots:
	void slot_disconnected();
	void slot_error();
	void slot_readData();
signals:
	void signal_disconnected(const QString& ip, int port);
	void signal_error(const QString& ip, int port, const QString& erro);
	void signal_sendDate(const QString& ip, int port, const QString& data);
	void signal_receiveData(const QString& ip, int port, const QString& data);
private:
	QTcpSocket* socket_;
	QString ip_;
	int port_;

public:
    QString getIp() const;

    int getPort() const;


};
