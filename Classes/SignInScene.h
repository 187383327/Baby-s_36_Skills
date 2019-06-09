#pragma once

#include "QE.h"

class SignInScene : public Layer, public EditBoxDelegate
{
	QE_CreateSceneFromLayer_H(SignInScene);
public:
	//������״̬���
	static Label* _label, * _logLabel;
	static EditBox* _idBox, * _passwordBox;
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
	virtual void editBoxReturn(EditBox* editBox) {};
};