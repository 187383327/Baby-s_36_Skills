#pragma once

#include "QE.h"

class HttpTest : public cocos2d::Layer
{
	QE_CreateSceneFromLayer_H(HttpTest);
	static Label* label;
	// ���󷽷�
	void postHttpRequest();
	// ������ɵĻص�����
	void onHttpRequestCompleted(HttpClient* sender, HttpResponse* response);

};