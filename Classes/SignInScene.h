#pragma once

#include "QE.h"

class SignInScene : public Layer
	, public EditBoxDelegate
{
	QE_CreateSceneFromLayer_H(SignInScene);
public:
	//������״̬���
	static void updateLabel();
	static MenuItemLabel* connectItem;
	static LabelTTF* label, * logLabel;
private:
	void createLabel(string show);
	//�˵����
	void initMenu();
	//�˵���ť�ص��������
	void SignIn();
	void SignUp();

	//��������
	void initEditBox();
	EditBox* createEditBox(string normalPngFile);
	virtual void editBoxEditingDidBegin(EditBox* editBox);
	virtual void editBoxTextChanged(EditBox* editBox, const string& text);
	virtual void editBoxEditingDidEnd(EditBox* editBox);
	virtual void editBoxReturn(EditBox* editBox);
};