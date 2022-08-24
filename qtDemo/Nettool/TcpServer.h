#pragma once
#include"appconfig.h"
#include<QTcpServer>
#include<qlist.h>
#include"TcpClient.h"
class TcpServer  : public QTcpServer//������񣬴�TcpClient������Ϣ������FrmTcpServer��ʾ
{
	Q_OBJECT
private slots:
	void haveNewConnection();//���������Ӽ���
	void disconnected(const QString& ip, int port);//�Ͽ�ָ������
public slots:
	//�������񣬼���
	bool start();
	//ֹͣ���񣬹ر����пͻ���socket���͸����QTcpServer
	void stop();
	//ָ�����ӷ�������
	void writeData(const QString& ip, int port, const QString& data);
	//���������ӷ�������
	void writeData(const QString& data);
	//�Ͽ�ָ������
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
	QList<TcpClient*>clients_;//���������û�
};
