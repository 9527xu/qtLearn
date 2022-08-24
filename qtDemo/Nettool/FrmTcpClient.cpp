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
	//�յ������ź�
	connect(socket_, &QTcpSocket::connected, this, &FrmTcpClient::connected);
	//�յ��Ͽ������ź�
	connect(socket_, &QTcpSocket::disconnected, this, &FrmTcpClient::disconnected);
	//�յ���Ϣ�ź�
	connect(socket_, &QTcpSocket::readyRead, this, &FrmTcpClient::readData);
	//�����쳣��Ϣ
#if QT_VERSION>=QT_VERSION_CHECK(6,0,0)
	connect(socket_,QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error),this, &FrmTcpClient::error);
#endif // QT_VERSION>=QT_VERSION_CHECK(6,0,0)

	connect(socket_, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error), this, &FrmTcpClient::error);

	//��ʱ��������
	connect(timer_, &QTimer::timeout, this, &FrmTcpClient::on_send_clicked);
	//������ݵ�������
	ui_->comboBoxInterval->addItems(AppData::Intervals);//��ʱ����
	ui_->comboBoxData->addItems(AppData::Datas);//���ݷ���
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
	static int currentCount = 0;//��̬����ȫ��Ψһ
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
	//���˻س����з�
	QString strData = data;
	strData = strData.replace("\r", "");
	strData = strData.replace("\n", "");
	//��ͬ������ʾ��ͬ��ɫ
	QString strType;
	if (type == 0)
	{
		strType = "����";
		ui_->textEditMain->setTextColor(QColor("#22A3A9"));
	}
	else if (type == 1)
	{
		strType = "����";
		ui_->textEditMain->setTextColor(QColor("#753775"));
	}
	else
	{
		strType = "����";
		ui_->textEditMain->setTextColor(QColor("#D64D54"));
	}
	strData = QString("ʱ��[%1] %2:%3").arg(TIMEMS).arg(strType).arg(strData);
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
	AppConfig::writeConfig();//����
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
	//˫�����
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
	ui_->pushButtonConnect->setText("�Ͽ�");
	this->append(0, "���ӳɹ�");

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

	//�Զ��ظ�����
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
	//��������Ϣ��ʾ������
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
	if (ui_->pushButtonConnect->text() == "����")
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
		append(2, "����з���������");
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
	ui_->pushButtonConnect->setText("����");
	append(1, "�Ͽ�������");
}


