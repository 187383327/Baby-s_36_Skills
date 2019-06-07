#include "SocketIOTest.h"
#include "SignInScene.h"

SIOClient* SocketIOTest::_sioClient;
bool SocketIOTest::isConnect = false;
string SocketIOTest::addr;

QE_SINGLETON_CPP(SocketIOTest);

void SocketIOTest::connect()
{
	if (!isConnect) { SocketIOTest::getInstance()->initSocket(); };
}

void SocketIOTest::initSocket()
{
	string ip = "10.6.32.1";
	//ip = "localhost";
	string port = "80";
	addr = "http://" + ip + ":" + port + "/";
	_sioClient = SocketIO::connect(addr, *this);
	//ע����������¼�
	_sioClient->on("callClientEvent", CC_CALLBACK_2(SocketIOTest::callClientEvent, this));
}

//ί��Э�鷽��
void SocketIOTest::onConnect(SIOClient* client)
{
	updateStatus(true);
	CCLOG("HelloWorld::onConnect called");
	String* s = String::createWithFormat("%s connected!", client->getTag());
	_sioClient->send("Hello, I am cocos2d-x, send()");
}

void SocketIOTest::onMessage(SIOClient* client, const std::string& data)
{
	updateStatus(true);
	CCLOG("HelloWorld::onMessage received: %s", data.c_str());
	String* s = String::createWithFormat("%s  received message.", client->getTag());
}

void SocketIOTest::onClose(SIOClient* client)
{
	updateStatus(false);
	CCLOG("HelloWorld::onClose called");
	if (client == _sioClient) {
		_sioClient = nullptr;
	}
}

void SocketIOTest::onError(SIOClient* client, const std::string& data)
{
	updateStatus(false);
	string error = data.c_str();
	SignInScene::logLabel->setString("onError:" + error + "||" + addr);
	//CCLOG("HelloWorld::onError received: %s", data.c_str());
	//String* s = String::createWithFormat("%s   received error .", client->getTag());
}

void SocketIOTest::callClientEvent(SIOClient* client, const std::string& data)
{
	updateStatus(true);
	CCLOG("HelloWorld::callClientEvent received: %s", data.c_str());
	String* s = String::createWithFormat("%s Server CallBack", client->getTag());
}

void SocketIOTest::updateStatus(bool status)
{
	isConnect = status;
	SignInScene::updateLabel();
}