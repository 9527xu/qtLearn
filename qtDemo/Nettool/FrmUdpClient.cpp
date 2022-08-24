#include "FrmUdpClient.h"
#include "quihelperdata.h"

FrmUdpClient::FrmUdpClient(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::FrmUdpClientClass())
{
	ui->setupUi(this);
	this->initForm();
	this->initConfig();
}

FrmUdpClient::~FrmUdpClient()
{
	delete ui;
}

void FrmUdpClient::slot_readData()
{
	QHostAddress host;
	quint16 port;
	QByteArray data;
	QString buffer;
	while (socket_->hasPendingDatagrams())
	{
		data.resize(socket_->pendingDatagramSize());
		socket_->readDatagram(data.data(), data.size(), &host, &port);
		if (AppConfig::HexReceiveUdpClient)
		{
			buffer = QUIHelperData::byteArrayToHexStr(data);

		}
		else if (AppConfig::AsciiUdpClient)
		{
			buffer = QUIHelperData::byteArrayToAsciiStr(data);
		}
		else
		{
			buffer = QString(data);
		}
		QString ip = host.toString();
		ip = ip.replace("::ffff:", "");
		if (ip.isEmpty())
		{
			append(2, "������ip��ַ");
			continue;
		}
		QString str = QString("[%1:%2] %3").arg(ip).arg(port).arg(buffer);
		append(1, str);

		//�Զ��ظ�����
		if (AppConfig::DebugUdpClient)
		{
			int count = AppData::Keys.count();
			for (int i = 0; i < count; ++i)
			{
				if (AppData::Keys[i] == buffer)
				{
					slot_sendData(ip,port,AppData::Values[i]);
					break;
				}
			}
		}
	}
}

bool FrmUdpClient::eventFilter(QObject* watched, QEvent* event)
{
	//˫�����
	if (watched == ui->textEditMain->viewport())
	{
		if (event->type() == QEvent::MouseButtonDblClick)
		{
			on_clear_clicked();
		}
	}
	return QWidget::eventFilter(watched, event);
}

void FrmUdpClient::initForm()
{
	QFont font;
	font.setPixelSize(16);
	ui->textEditMain->setFont(font);
	ui->textEditMain->viewport()->installEventFilter(this);
	//������Ϣ������ʱ
	connect(socket_, &QUdpSocket::readyRead, this, &FrmUdpClient::slot_readData);
#if (QT_VERSION>=QT_VERSION_CHECK(6,0,0))
	connect(socket_, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &FrmUdpClient::slot_error);
#else
	connect(socket_, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &FrmUdpClient::slot_error);
#endif // (QT_VERSION>=QT_VERSION_CHECK(6,0,0))
	//��ʱ��������Ϣ
	connect(timer_, &QTimer::timeout, this, &FrmUdpClient::on_send_clicked);
	//������ݵ�������
	ui->comboBoxInterval->addItems(AppData::Intervals);
	ui->comboBoxData->addItems(AppData::Datas);
	AppData::loadIP(ui->comboBoxBindIP);

}

void FrmUdpClient::initConfig()
{
	ui->checkBoxHexSend->setChecked(AppConfig::HexSendUdpClient);
	ui->checkBoxHexReceive->setChecked(AppConfig::HexReceiveUdpClient);
	ui->checkBoxAscii->setChecked(AppConfig::AsciiUdpClient);
	ui->checkBoxDebug->setChecked(AppConfig::DebugUdpClient);
	ui->checkBoxAutoSend->setChecked(AppConfig::AutoSendUdpClient);
	ui->comboBoxInterval->setCurrentIndex(ui->comboBoxInterval->findText(QString::number(AppConfig::IntervalUdpClient)));
	ui->comboBoxBindIP->setCurrentIndex(ui->comboBoxBindIP->findText(AppConfig::UdpBindIP));
	ui->lineEditBindPort->setText(QString::number(AppConfig::UdpBindPort));
	ui->lineEditServerIP->setText(AppConfig::UdpServerIP);
	ui->lineEditServerPort->setText(QString::number(AppConfig::UdpServerPort));
	this->initTimer();

}

void FrmUdpClient::stateChange()
{
	AppConfig::HexSendUdpServer = ui->checkBoxHexSend->isChecked();
	AppConfig::HexReceiveUdpServer = ui->checkBoxHexReceive->isChecked();
	AppConfig::AsciiUdpServer = ui->checkBoxAscii->isChecked();
	AppConfig::DebugUdpServer = ui->checkBoxAscii->isChecked();
	AppConfig::AutoSendUdpServer = ui->checkBoxAutoSend->isChecked();
	AppConfig::IntervalUdpServer = ui->comboBoxInterval->currentText().toInt();
	AppConfig::UdpBindIP = ui->comboBoxBindIP->currentText();
	AppConfig::UdpBindPort = ui->lineEditBindPort->text().trimmed().toInt();
	AppConfig::UdpServerIP = ui->lineEditServerIP->text().trimmed();
	AppConfig::UdpServerPort = ui->lineEditServerPort->text().trimmed().toInt();
	AppConfig::writeConfig();
	this->initTimer();
}

void FrmUdpClient::initTimer()
{
	if (timer_->interval() != AppConfig::IntervalUdpClient)
	{
		timer_->setInterval(AppConfig::IntervalUdpClient);
	}
	if (AppConfig::AutoSendUdpClient)
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

void FrmUdpClient::append(int type, const QString& data, bool clear)
{
	static int currentCount = 0;
	static int maxCount = 100;
	if (clear)
	{
		ui->textEditMain->clear();
		currentCount = 0;
		return;
	}
	if (currentCount >= maxCount)
	{
		ui->textEditMain->clear();
		currentCount = 0;
	}
	if (ui->checkBoxShow->isChecked())
	{
		return;
	}
	//���˻س����з�
	QString strData = data;
	strData = strData.replace("\r", "");
	strData = strData.replace("\n", "");
	//��ͬ���Ͷ�Ӧ��ͬ��Ϣ
	QMap<int, QString> msgType = {
		{0,"����"},
		{1,"����"},
		{2,"����"}
	};
	//��ͬ��Ϣ��Ӧ��ͬ��ɫ
	QMap<QString, QColor>colorType = {
		{"����",QColor("#22A3A9")},
		{"����",QColor("#753775")},
		{"����",QColor("#D64D54")}
	};

	strData = QString("ʱ��[%1] %2:%3").arg(TIMEMS).arg(msgType[type]).arg(strData);
	ui->textEditMain->setTextColor(colorType[msgType[type]]);
	ui->textEditMain->append(strData);
	++currentCount;
}

void FrmUdpClient::slot_error()
{
	append(2, socket_->errorString());
}

void FrmUdpClient::slot_sendData(const QString& ip, int port, const QString& data)
{
	QByteArray buffer;
	if (AppConfig::HexSendUdpClient)
	{
		buffer = QUIHelperData::hexStrToByteArray(data);
	}
	else if (AppConfig::AsciiUdpClient)
	{
		buffer = QUIHelperData::asciiStrToByteArray(data);
	}
	else
	{
		buffer = data.toUtf8();
	}
	if (socket_->localPort() != AppConfig::UdpBindPort)
	{
		socket_->abort();
		socket_->bind(QHostAddress(AppConfig::UdpBindIP), AppConfig::UdpBindPort);
	}
	//ָ��
	socket_->writeDatagram(buffer, QHostAddress(ip), port);
	QString str = QString("[%1:%2] %3").arg(ip).arg(port).arg(data);
	append(0, str);
}

void FrmUdpClient::on_save_clicked()
{
	QString data = ui->textEditMain->toPlainText();
	AppData::saveData(data);
	on_clear_clicked();
}

void FrmUdpClient::on_clear_clicked()
{
	append(0, "", true);
}

void FrmUdpClient::on_send_clicked()
{
	QString data = ui->comboBoxData->currentText();
	if (data.length() <= 0)
	{
		return;
	}
	slot_sendData(AppConfig::UdpServerIP, AppConfig::UdpServerPort, data);
}
