#include "TcpClient.h"

TcpClient::TcpClient(QTcpSocket* socket, QObject *parent)
	: QObject(parent)
{
    this->socket_ = socket;
    ip_ = socket_->peerAddress().toString();
    port_ = socket_->peerPort();
    //����tcosocket�յ��Ͽ������ź�
    connect(socket_, &QTcpSocket::disconnected, this, &TcpClient::slot_disconnected);
    //�յ���������Ϣ
    connect(socket_, &QTcpSocket::readyRead, this, &TcpClient::slot_readData);
    //�յ������쳣�ź�
    // QAbstractSocket::SocketError>:����
    //������&QAbstractSocket::error)
    connect(socket_, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &TcpClient::slot_error);
}

TcpClient::~TcpClient()
{}

void TcpClient::sendData(const QString& data)
{
    QByteArray buffer;
    if (AppConfig::HexSendTcpServer)
    {
        buffer = QUIHelperData::hexStrToByteArray(data);
    }
    else if (AppConfig::AsciiTcpServer)
    {
        buffer = QUIHelperData::asciiStrToByteArray(data);
    }
    else
    {
        buffer = data.toUtf8();
    }
    socket_->write(buffer);
    emit signal_sendDate(ip_, port_, data);
}
void TcpClient::disconnectFromHost()
{
    socket_->disconnectFromHost();//���Թرյ�ǰsocket����������Ϣ���д�����������״̬ and emit disconnected
}
void TcpClient::abort()
{
    socket_->abort();
}
void TcpClient::slot_error()
{
    emit signal_error(ip_, port_, socket_->errorString());//���ʹ����źŵ�TcpServer
}
void TcpClient::slot_readData()
{
    QByteArray data = socket_->readAll();
    if (data.length() < 0)
    {
        return;
    }
    QString buf;
    if (AppConfig::HexReceiveTcpServer)
    {
        buf = QUIHelperData::byteArrayToHexStr(data);
    }
    else if (AppConfig::AsciiTcpServer)
    {
        buf = QUIHelperData::byteArrayToAsciiStr(data);
    }
    else
    {
        buf = QString(data);
    }
    emit signal_receiveData(ip_, port_, buf);//�����յ���Ϣ�źŽ���TcpServer����
    //�Զ��ظ�����
    if (AppConfig::DebugTcpServer)
    {
        int count = AppData::Keys.count();
        for (int i = 0; i < count; ++i)
        {
            if (AppData::Keys[i] == buf)
            {
                sendData(AppData::Values[i]);
                break;
            }
        }
    }
}
void TcpClient::slot_disconnected()
{
    emit signal_disconnected(ip_, port_);//���ͶϿ������źŵ�TcpServer
    socket_->deleteLater();//ɾ������
    this->deleteLater();//ɾ������
}
QString TcpClient::getIp() const
{
    return ip_;
}

int TcpClient::getPort() const
{
    return port_;
}

