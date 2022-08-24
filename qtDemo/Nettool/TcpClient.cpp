#include "TcpClient.h"

TcpClient::TcpClient(QTcpSocket* socket, QObject *parent)
	: QObject(parent)
{
    this->socket_ = socket;
    ip_ = socket_->peerAddress().toString();
    port_ = socket_->peerPort();
    //处理tcosocket收到断开连接信号
    connect(socket_, &QTcpSocket::disconnected, this, &TcpClient::slot_disconnected);
    //收到服务器信息
    connect(socket_, &QTcpSocket::readyRead, this, &TcpClient::slot_readData);
    //收到服务异常信号
    // QAbstractSocket::SocketError>:参数
    //函数名&QAbstractSocket::error)
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
    socket_->disconnectFromHost();//尝试关闭当前socket。当所有消息完成写入进入无连接状态 and emit disconnected
}
void TcpClient::abort()
{
    socket_->abort();
}
void TcpClient::slot_error()
{
    emit signal_error(ip_, port_, socket_->errorString());//发送错误信号到TcpServer
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
    emit signal_receiveData(ip_, port_, buf);//发送收到消息信号交给TcpServer处理
    //自动回复数据
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
    emit signal_disconnected(ip_, port_);//发送断开连接信号到TcpServer
    socket_->deleteLater();//删除对象
    this->deleteLater();//删除对象
}
QString TcpClient::getIp() const
{
    return ip_;
}

int TcpClient::getPort() const
{
    return port_;
}

