﻿#pragma execution_character_set("utf-8")
#pragma once

#include "QE.h"

class Connect : public WebSocket::Delegate
{
	QE_SINGLETON_H(Connect);

public:
	
	static bool _isConnecting;
	static WebSocket* _ws;
	static string _addr, _nowEvent;

	static void connect(string nowEvent);
	static void createMsg();
	static void addMsg(JString key, JString value);
	static void sendMsg();


private:
	void initSocket();

	//委托协议方法
	virtual void onOpen(WebSocket* ws) override;
	virtual void onMessage(WebSocket* ws, const WebSocket::Data& data) override;
	virtual void onClose(WebSocket* ws) override;
	virtual void onError(WebSocket* ws, const WebSocket::ErrorCode& error) override;
};