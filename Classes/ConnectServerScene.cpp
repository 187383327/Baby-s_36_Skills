#include "ConnectServerScene.h"

EditBox* ConnectServerScene::_ip1Box, * ConnectServerScene::_port1Box, * ConnectServerScene::_ip2Box, * ConnectServerScene::_port2Box;
Label* ConnectServerScene::_logLabel;

QE_CreateSceneFromLayer_CPP(ConnectServerScene);
	paths = { "fonts" };
	QE_SetResourcesSearchDir;
	
	initLabel();
	initMenu();
	initEditBox();

	return true;
}

void ConnectServerScene::initLabel()
{
	createLabel("Server name")->setPosition(150, 450);
	createLabel("IP")->setPosition(320, 450);
	createLabel("Port")->setPosition(570, 450);
	createLabel("Act")->setPosition(680, 450);

	_logLabel = createLabel("");
	_logLabel->setPosition(100, 100);
}

Label* ConnectServerScene::createLabel(string text)
{
	Label* label = Label::create(text, QE_Font, 25);
	label->setAnchorPoint(Vec2(0, 0));
	addChild(label);
	return label;
}

void ConnectServerScene::initMenu()
{
	Menu* menu = QMenu::createMenuLabel("connect", bind(&ConnectServerScene::connect, this, 1));
	menu->setPosition(680, 390);
	addChild(menu);

	menu = QMenu::createMenuLabel("connect", bind(&ConnectServerScene::connect, this, 2));
	menu->setPosition(680, 340);
	addChild(menu);
}

void ConnectServerScene::connect(int n)
{
	if (Connect::_isConnecting)
	{
		_logLabel->setString("Connecting to " + Connect::_addr + "\nwait a moment , and try again later if necessary.");
		return;
	}
	Connect::_isConnecting = true;
	string ip, port;
	if (n == 1)
	{
		ip = _ip1Box->getText();
		port = _port1Box->getText();
	}
	else if (n == 2)
	{
		ip = _ip2Box->getText();
		port = _port2Box->getText();
	}
	Connect::_addr = String::createWithFormat("ws://%s:%s/", ip.c_str(), port.c_str())->getCString();
	_logLabel->setString("Connecting to " + Connect::_addr);
	Connect::connect();
}

void ConnectServerScene::initEditBox()
{
	EditBox* box;
	createLabel("Server 1")->setPosition(150, 390);
	//����IP�Ŀ�
	_ip1Box = box = createEditBox("green_edit.png", "10.6.32.1", 15);
	box->setPosition(Vec2(320, 380));
	//����˿ڵĿ�
	_port1Box = box = createEditBox("orange_edit.png", "56", 5);
	box->setSize(Size(80, 38));
	box->setPosition(Vec2(570, 380));

	createLabel("Server 2")->setPosition(150, 340);
	//����IP�Ŀ�
	_ip2Box = box = createEditBox("green_edit.png", "127.0.0.1", 15);
	box->setPosition(Vec2(320, 330));
	//����˿ڵĿ�
	_port2Box = box = createEditBox("orange_edit.png", "56", 5);
	box->setSize(Size(80, 38));
	box->setPosition(Vec2(570, 330));
}

EditBox* ConnectServerScene::createEditBox(string normalPngFile, string text, int maxLength)
{
	EditBox* box = EditBox::create(Size(210, 38), Scale9Sprite::create(normalPngFile), Scale9Sprite::create("wite_edit.png"));
	box->setFontName(QE_Font);
	box->setFontSize(25);
	box->setText(text.c_str());
	box->setFontColor(Color3B(0, 0, 255));
	box->setPlaceholderFontName(QE_Font);
	box->setPlaceholderFontSize(25);
	box->setPlaceHolder(text.c_str()); //���༭����û���κ��ַ����������ַ�ǰ������ʾ�ı�,��ռλ��
	box->setPlaceholderFontColor(Color3B(255, 0, 0));
	box->setMaxLength(maxLength);   //�����ı������ı�����󳤶�
	box->setInputMode(EditBox::InputMode::ANY);//�������ģʽ,�κη���
	box->setAnchorPoint(Vec2(0, 0));
	box->setDelegate(this);//����ί�У��ı��������Ҫʵ��EditBoxDelegate�����еķ������Ϳ��Զ�EditBox���п���
	addChild(box);
	return box;
}