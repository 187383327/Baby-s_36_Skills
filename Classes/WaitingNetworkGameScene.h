﻿#pragma execution_character_set("utf-8")
#pragma once

#include "QE.h"

class WaitingNetworkGameScene : public Layer, public EditBoxDelegate, public NetworkBaseScene
{
	QE_SINGLETON_H(WaitingNetworkGameScene);
	QE_CreateSceneFromLayer_H(WaitingNetworkGameScene);
	NW_BaseScene;
public:
	static void dealServerResponse(int statusCode);
private:
	//标签相关
	void initLabel();

	//富文本相关
	static RichText* _richText;
	static vector<RichText*> _texts;
	void initRichText();
	RichText* createRichText(int x, int y, string roleName, string fileName);
	void setTextsColor(int n);

	//菜单相关
	void initMenu();
	//菜单按钮回调函数相关
	void createRoom();
	void back();

	//选项
	static int _index;
	static RadioButtonGroup* _radioButtonGroup;
	void initRadioButton();
	void onChangedRadioButtonGroup(RadioButton* radioButton, int index, RadioButtonGroup::EventType type);
};