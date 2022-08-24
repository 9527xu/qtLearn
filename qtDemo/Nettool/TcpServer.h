#pragma once
#include"appconfig.h"
#include<QTcpServer>
#include<qlist.h>
#include"TcpClient.h"
class TcpServer  : public QTcpServer//负责服务，从TcpClient接收消息，交由FrmTcpServer显示
{
	Q_OBJECT
private slots:
	void haveNewConnection();//当有新连接加入
	void disconnected(const QString& ip, int port);//断开指定连接
public slots:
	//启动服务，监听
	bool start();
	//停止服务，关闭所有客户端socket，和该类的QTcpServer
	void stop();
	//指定连接发送数据
	void writeData(const QString& ip, int port, const QString& data);
	//对所有连接发送数据
	void writeData(const QString& data);
	//断开指定连接
	void remove(const QString& ip, int port);
	void remove();
signals:
	void signal_error(const QString& ip, int port, const QString& erro);
	void signal_sendData(const QString& ip, int port, const QString& data);
	void signal_disconnected(const QString& ip, int port);
	void signal_connected(const QString& ip, int port);
	void signal_receiveData(const QString& ip, int port, const QString& data);
public:
	TcpServer(QObject *parent);
	~TcpServer();
private:
	QList<TcpClient*>clients_;//保存连接用户
};
