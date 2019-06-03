#pragma once

#include "QE.h"

class SignInScene : public Layer
	, public EditBoxDelegate
{
	QE_CreateSceneFromLayer_H(SignInScene);
private:
	//������״̬���
	LabelTTF* label;
	void createLabel(string show);
	void updateLabel();
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