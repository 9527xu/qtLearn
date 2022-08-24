#include "FrmTcpClient.h"
#include "head.h"

FrmTcpClient::FrmTcpClient(QWidget *parent)
	: QWidget(parent),ui_(new Ui::FrmTcpClientClass)
{
	ui_->setupUi(this);
	this->initForm();
	this->initConfig();
}

FrmTcpClient::~FrmTcpClient()
{
	delete ui_;

}

void FrmTcpClient::initForm()
{
	QFont font;
	font.setPixelSize(16);
	ui_->textEditMain->setFont(font);
	ui_->textEditMain->viewport()->installEventFilter(this);
	//收到连接信号
	connect(socket_, &QTcpSocket::connected, this, &FrmTcpClient::connected);
	//收到断开连接信号
	connect(socket_, &QTcpSocket::disconnected, this, &FrmTcpClient::disconnected);
	//收到消息信号
	connect(socket_, &QTcpSocket::readyRead, this, &FrmTcpClient::readData);
	//出现异常消息
#if QT_VERSION>=QT_VERSION_CHECK(6,0,0)
	connect(socket_,QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error),this, &FrmTcpClient::error);
#endif // QT_VERSION>=QT_VERSION_CHECK(6,0,0)

	connect(socket_, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error), this, &FrmTcpClient::error);

	//定时发送数据
	connect(timer_, &QTimer::timeout, this, &FrmTcpClient::on_send_clicked);
	//填充数据到下拉框
	ui_->comboBoxInterval->addItems(AppData::Intervals);//定时发送
	ui_->comboBoxData->addItems(AppData::Datas);//数据发送
	AppData::loadIP(ui_->comboBoxBindIP);
}
void FrmTcpClient::initConfig()
{
	ui_->checkBoxHexSend->setChecked(AppConfig::HexSendTcpClient);
	
	ui_->checkBoxHexReceive->setChecked(AppConfig::HexReceiveTcpClient);

	ui_->checkBoxAscii->setChecked(AppConfig::AsciiTcpClient);
	ui_->checkBoxAutoSend->setChecked(AppConfig::AutoSendTcpClient);

	ui_->checkBoxDebug->setChecked(AppConfig::DebugTcpClient);


	ui_->comboBoxInterval->setCurrentIndex(ui_->comboBoxInterval->findText(QString::number(AppConfig::IntervalTcpClient)));
	ui_->comboBoxBindIP->setCurrentIndex(ui_->comboBoxBindIP->findText(AppConfig::TcpBindIP));
	ui_->lineEditBindPort->setText(QString::number(AppConfig::TcpBindPort));
	ui_->lineEditServerIP->setText(AppConfig::TcpServerIP);
	ui_->lineEditServerPort->setText(QString::number(AppConfig::TcpServerPort));

	this->initTimer();
	
}
void FrmTcpClient::append(int type, const QString& data, bool clear)
{
	static int currentCount = 0;//静态变量全局唯一
	static int maxCount = 100;
	if (clear)
	{
		ui_->textEditMain->clear();
		currentCount = 0;
		return;
	}
	if (currentCount >= maxCount)
	{
		ui_->textEditMain->clear();
		currentCount = 0;
	}
	if (ui_->checkBoxShow->isChecked())
	{
		return;
	}
	//过滤回车换行符
	QString strData = data;
	strData = strData.replace("\r", "");
	strData = strData.replace("\n", "");
	//不同类型显示不同颜色
	QString strType;
	if (type == 0)
	{
		strType = "发送";
		ui_->textEditMain->setTextColor(QColor("#22A3A9"));
	}
	else if (type == 1)
	{
		strType = "接收";
		ui_->textEditMain->setTextColor(QColor("#753775"));
	}
	else
	{
		strType = "错误";
		ui_->textEditMain->setTextColor(QColor("#D64D54"));
	}
	strData = QString("时间[%1] %2:%3").arg(TIMEMS).arg(strType).arg(strData);
	ui_->textEditMain->append(strData);
	++currentCount;
}

void FrmTcpClient::on_checkbox_stateChanged()
{
	
	AppConfig::HexSendTcpClient = ui_->checkBoxHexSend->isChecked();
	AppConfig::HexReceiveTcpClient = ui_->checkBoxHexReceive->isChecked();
	AppConfig::AsciiTcpClient = ui_->checkBoxAscii->isChecked();
	AppConfig::DebugTcpClient = ui_->checkBoxDebug->isChecked();
	AppConfig::AutoSendTcpClient = ui_->checkBoxAutoSend->isChecked();
	AppConfig::IntervalTcpClient = ui_->comboBoxInterval->currentText().toInt();
	AppConfig::TcpBindIP = ui_->comboBoxBindIP->currentText();
	AppConfig::TcpBindPort = ui_->lineEditBindPort->text().trimmed().toInt();
	AppConfig::TcpServerIP = ui_->lineEditServerIP->text().trimmed();
	AppConfig::TcpServerPort = ui_->lineEditServerPort->text().trimmed().toInt();
	AppConfig::writeConfig();//更新
	this->initTimer();

}

void FrmTcpClient::initTimer()
{
	if (timer_->interval() != AppConfig::IntervalTcpClient)
	{
		timer_->setInterval(AppConfig::IntervalTcpClient);
	}
	if (AppConfig::AutoSendTcpClient)
	{
		if (!timer_->isActive())
		{
			timer_->start();
		}
	}
	else
	{
		if (timer_->isActive())
		{
			timer_->stop();
		}
	}
}

void FrmTcpClient::sendData(const QString& data)
{
	QByteArray buffer;
	if (AppConfig::HexSendTcpClient)
	{
		buffer = QUIHelperData::hexStrToByteArray(data);
	}
	else if (AppConfig::AsciiTcpClient)
	{
		buffer = QUIHelperData::asciiStrToByteArray(data);
	}
	else
	{
		buffer = data.toUtf8();
	}
	socket_->write(buffer);
	append(0, data);
}

bool FrmTcpClient::eventFilter(QObject* watched, QEvent* event)
{
	//双击清空
	if (watched == ui_->textEditMain->viewport())
	{
		if (event->type() == QEvent::MouseButtonDblClick)
		{
			on_clear_clicked();
		}
	}
	return QWidget::eventFilter(watched,event);
}

void FrmTcpClient::connected()
{
	isOk_ = true;
	ui_->pushButtonConnect->setText("断开");
	this->append(0, "连接成功");

}

void FrmTcpClient::readData()
{
	QByteArray data = socket_->readAll();
	if (data.length() <= 0)
	{
		return;
	}
	QString buffer;
	if (AppConfig::HexReceiveTcpClient)
	{
		buffer = QUIHelperData::byteArrayToHexStr(data);

	}
	else if (AppConfig::AsciiTcpClient)
	{
		buffer = QUIHelperData::byteArrayToAsciiStr(data);
	}
	else
	{
		buffer = QString(data);
	}
	append(1, buffer);

	//自动回复数据
	if (AppConfig::DebugTcpClient)
	{
		int count = AppData::Keys.count();
		for (int i = 0; i < count; ++i)
		{
			if (AppData::Keys[i] == buffer)
			{
				sendData(AppData::Values[i]);
				break;
			}
		}
	}
}

void FrmTcpClient::error()
{
	//将错误消息显示到界面
	append(2, socket_->errorString());
}

void FrmTcpClient::on_save_clicked()
{
	QString data = ui_->textEditMain->toPlainText();
	AppData::saveData(data);
	on_clear_clicked();
}

void FrmTcpClient::on_connected_clicked()
{
	if (ui_->pushButtonConnect->text() == "连接")
	{
		socket_->connectToHost(AppConfig::TcpServerIP, AppConfig::TcpServerPort);
		
	}
	else
	{
		socket_->abort();
	}
	
}

void FrmTcpClient::on_clear_clicked()
{
	append(0, "", true);
}

void FrmTcpClient::on_send_clicked()
{
	if (!isOk_)
	{
		append(2, "请进行服务器连接");
		return;
	}
	QString data = ui_->comboBoxData->currentText();
	if (data.length() <= 0)
	{
		return;
	}
	sendData(data);
}

void FrmTcpClient::disconnected()
{
	isOk_ = false;
	ui_->pushButtonConnect->setText("连接");
	append(1, "断开服务器");
}


