﻿#pragma execution_character_set("utf-8")
#pragma once

#include "QE.h"

class HelloWorld : public Layer
{
	QE_CreateSceneFromLayer_H(HelloWorld);
	Label* label;
	ListView* _listView;
private:
	void testListView();
	void setWidget(ListView* _listView, std::string str);
	void testScrollView();
	void scrollViewSdidScroll(Ref* sender, ScrollView::EventType type);
	void selectScene(Ref* sender, Widget::TouchEventType type);
};