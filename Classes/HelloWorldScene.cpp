#include "HelloWorldScene.h"

QE_CreateSceneFromLayer_CPP(HelloWorld);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Send Message");
	auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(HelloWorld::menuSendMsgCallback, this));

	Menu* mn = Menu::create(pItmMenu1, NULL);
	mn->alignItemsVertically();
	addChild(mn);

	label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

	label->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label->getContentSize().height));

	addChild(label, 1);

	std::string ip = "10.6.32.1";
	//ip = "localhost";
	std::string port = "56";
	std::string addr = "http://" + ip + ":" + port + "/";
	_sioClient = SocketIO::connect(addr, *this);
	_sioClient->setTag("Cocos2d-x Client1");
	//ע����������¼�
	_sioClient->on("callClientEvent", CC_CALLBACK_2(HelloWorld::callClientEvent, this));

	testEditBox();
	_listView = ListView::create();

	testListView();

	return true;
}


void HelloWorld::menuSendMsgCallback(Ref* pSender)
{
	//�������������Ϣ
	if(_sioClient != NULL) _sioClient->send("Hello Socket.IO!��");
	//����������callServerEvent�¼�
	if(_sioClient != NULL) _sioClient->emit("callServerEvent","{\"message\":\"0Hello Server.��\"}");
}

//ί��Э�鷽��
void HelloWorld::onConnect(SIOClient* client)
{
	log("HelloWorld::onConnect called");
	String* s = String::createWithFormat("%s connected!",client->getTag());
	label->setString(s->getCString());
}

void HelloWorld::onMessage(SIOClient* client, const std::string& data)
{
	log("HelloWorld::onMessage received: %s", data.c_str());
	String* s = String::createWithFormat("%s  received message.",client->getTag());
	label->setString(s->getCString());
}

void HelloWorld::onClose(SIOClient* client)
{
	log("HelloWorld::onClose called");
	String* s = String::createWithFormat("%s closed!",client->getTag());
	label->setString(s->getCString());

	if(client == _sioClient) {	
		_sioClient = nullptr;
	}
}

void HelloWorld::onError(SIOClient* client, const std::string& data)
{
	log("HelloWorld::onError received: %s", data.c_str());
	String* s = String::createWithFormat("%s   received error .",client->getTag());
	label->setString(s->getCString());
}

void HelloWorld::callClientEvent(SIOClient *client, const std::string& data)
{
	CCLOG("HelloWorld::callClientEvent received: %s", data.c_str());
	String* s = String::createWithFormat("%s Server CallBack",client->getTag());
	label->setString(s->getCString());
}

void HelloWorld::testEditBox()
{
	auto userNameBox = EditBox::create(Size(200, 25), Scale9Sprite::create("green_edit.png"));
	userNameBox->setPosition(Vec2(240, 280));
	userNameBox->setFontName("fonts/arial.ttf");
	userNameBox->setFontSize(16);
	userNameBox->setFontColor(Color3B(0, 0, 255));
	userNameBox->setPlaceholderFontColor(Color3B(255, 0, 0));
	userNameBox->setPlaceHolder("Please Enter Name");////���༭����û���κ��ַ����������ַ�ǰ������ʾ�ı�,��ռλ��
	userNameBox->setPlaceholderFontName("fonts/arial.ttf");
	userNameBox->setPlaceholderFontSize(16);
	userNameBox->setMaxLength(20);   //�����ı������ı�����󳤶�
	userNameBox->setInputMode(EditBox::InputMode::ANY);//�������ģʽ,�κη���
	userNameBox->setReturnType(EditBox::KeyboardReturnType::DONE);//����������лس���ť������
	userNameBox->setDelegate(this);//����ί��
	userNameBox->setTag(0);
	addChild(userNameBox);

	auto userPasswordBox = EditBox::create(Size(200, 25), Scale9Sprite::create("orange_edit.png"));
	userPasswordBox->setPosition(Vec2(240, 220));
	userPasswordBox->setFontName("fonts/arial.ttf");
	userPasswordBox->setFontSize(16);
	userPasswordBox->setFontColor(Color3B(0, 0, 255));
	userPasswordBox->setPlaceHolder("Please Enter password");
	userPasswordBox->setPlaceholderFontName("fonts/arial.ttf");
	userPasswordBox->setPlaceholderFontSize(16);
	userPasswordBox->setPlaceholderFontColor(Color3B(255, 0, 0));
	userPasswordBox->setMaxLength(1);
	userPasswordBox->setInputMode(EditBox::InputMode::DECIMAL);//����ģʽ,ʮ��������
	userPasswordBox->setReturnType(EditBox::KeyboardReturnType::GO);//Ĭ��ʹ�ü���DONE��������
	userPasswordBox->setInputFlag(EditBox::InputFlag::PASSWORD);////�����ı�����ʾ�ı�����ʽ������������
	userPasswordBox->setDelegate(this);
	//�ı��������Ҫʵ��EditBoxDelegate�����еķ������Ϳ��Զ�EditBox���п���
	addChild(userPasswordBox);
}

//�༭��ļ��̱༭�¼�
void HelloWorld::editBoxEditingDidBegin(EditBox* editBox)
{
	CCLOG("editBoxEditingDidBegin");
	CCLOG("%d", editBox->getTag());
}

void HelloWorld::editBoxTextChanged(EditBox* editBox, const std::string& text)
{
	CCLOG("editBoxTextChanged");
}

void HelloWorld::editBoxEditingDidEnd(EditBox* editBox)
{
	CCLOG("editBoxEditingDidEnd");
}

void HelloWorld::editBoxReturn(EditBox* editBox)
{
	CCLOG("editBoxReturn");
	std::string str = editBox->getText();
	CCLOG("%s", str.c_str());
	//�������������Ϣ
	if (_sioClient != NULL) _sioClient->send(str);
	setWidget(_listView, str);
}

void HelloWorld::testListView()
{
	_listView->setDirection(ScrollView::Direction::VERTICAL);
	_listView->setBounceEnabled(true);//�ص�Ч��
	_listView->setBackGroundImage("green_edit.png");
	_listView->setBackGroundImageScale9Enabled(true);
	_listView->setContentSize(Size(240, 130));
	_listView->setPosition(Vec2(420, 160));
	addChild(_listView);
	for (int i = 0; i < 10; i++)
	{
		Layout* widget = Layout::create();;
		widget->setContentSize(Size(240, 50));
		auto* str = String::createWithFormat("TextArea Widget acn line wrap %d", i + 1);
		Text* text = Text::create(str->getCString(), "Marker Felt.ttf", 13);
		text->setContentSize(Size(60, 10));
		text->setPosition(Vec2(20, 25));
		text->setAnchorPoint(Vec2(0, 0));
		widget->addChild(text);
		_listView->pushBackCustomItem(widget);
	}
}

void HelloWorld::setWidget(ListView* _listView, std::string str)
{
	_listView->removeAllChildren();
	std::string temp = "";
	int index = 0, max = str.length(), times=0;
	while (true)
	{
		temp = str.substr(0, max);
		CCLOG("temp=%s", temp.c_str());
		Layout* widget = Layout::create();
		widget->setContentSize(Size(240, 50));
		Text* text = Text::create(temp.c_str(), "Marker Felt.ttf", 13);
		text->setContentSize(Size(60, 10));
		text->setPosition(Vec2(20, 25));
		text->setAnchorPoint(Vec2(0, 0));
		widget->addChild(text);
		_listView->pushBackCustomItem(widget);
		if (times <= 10)
		{
			times++;
		}
		else
		{
			break;
		}
	}
}