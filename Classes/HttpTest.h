#pragma once

#include "QE.h"

class HttpTest : public cocos2d::Layer
{
	QE_CreateSceneFromLayer_H(HttpTest);
	static LabelTTF* label;
	// ���󷽷�
	void postHttpRequest();
	// ������ɵĻص�����
	void onHttpRequestCompleted(HttpClient* sender, HttpResponse* response);

};