#include "TcpServer.h"
#include<qlist.h>
void TcpServer::haveNewConnection()
{
	QTcpSocket* socket = this->nextPendingConnection();//返回请求连接的tcpsocket
	TcpClient* client = new TcpClient(socket, this);
	connect(client, &TcpClient::signal_disconnected, this, &TcpServer::disconnected);
	connect(client, &TcpClient::signal_error, this, &TcpServer::signal_error);
	connect(client, &TcpClient::signal_sendDate, this, &TcpServer::signal_sendData);
	connect(client, &TcpClient::signal_receiveData, this, &TcpServer::signal_receiveData);
	emit signal_connected(client->getIp(), client->getPort());//发送加入连接信号，让FrmTcpServer显示
	clients_.push_back(client);//加入链表
}

void TcpServer::disconnected(const QString& ip, int port)
{
	//sender():返回发出该信号的对象指针
	TcpClient* client = (TcpClient*)sender();
	emit signal_disconnected(ip, port);
	clients_.removeOne(client);
}

void TcpServer::stop()
{
	remove();//关闭所有客户端socket
	this->close();
}

void TcpServer::writeData(const QString& ip, int port, const QString& data)
{
	for (auto client : clients_)
	{
		if (client->getIp() == ip && client->getPort() == port)
		{
			client->sendData(data);
			break;
		}
	}
}

void TcpServer::writeData(const QString& data)
{
	for (const auto& client : clients_)
	{
		client->sendData(data);
	}
}

void TcpServer::remove(const QString& ip, int port)
{
	for (const auto& client : clients_)
	{
		if (client->getIp() == ip && client->getPort() == port)
		{
			client->abort();
			clients_.removeOne(client);
			break;
		}
	}
}

void TcpServer::remove()
{
	for (const auto& client : clients_)
	{
		client->abort();
	}
	clients_.clear();
}

bool TcpServer::start()
{
	
	return listen(QHostAddress(AppConfig::TcpListenIP), AppConfig::TcpListenPort);//开始监听
}

TcpServer::TcpServer(QObject *parent)
	: QTcpServer(parent)
{
	//处理新连接
	connect(this, &QTcpServer::newConnection, this, &TcpServer::haveNewConnection);
}

TcpServer::~TcpServer()
{}
