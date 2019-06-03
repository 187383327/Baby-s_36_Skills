#include "SignInScene.h"

QE_CreateSceneFromLayer_CPP(SignInScene);
	paths = { "fonts" };
	QE_SetResourcesSearchDir;

	Connect::connect();
	initMenu();
	initEditBox();

	//createLabel("����״̬��");
	
	createLabel(QCharsetConvert::GBKToUTF8("ʧ��"));
	createLabel(QE_GTU("ʧ��"));
	
	//createLabel("ʧ��");
	//label = Label::createWithTTF("1", "Marker Felt.ttf", 24);
	//label->setPosition(winSize / 3);
	//addChild(label, 1);
	return true;
}

void SignInScene::createLabel(string show)
{
	label = LabelTTF::create(show, "HannotateSC-W5.ttf", 24);
	label->setPosition(winSize / 3);
	addChild(label, 1);
}

void SignInScene::updateLabel()
{

}

void SignInScene::initMenu()
{
	label = LabelTTF::create("sign in", "Marker Felt.ttf", 25);
	MenuItemLabel* inItem = MenuItemLabel::create(label, CC_CALLBACK_0(SignInScene::SignIn, this));
	inItem->setPosition(410, 270);

	label = LabelTTF::create("sign up", "Marker Felt.ttf", 25);
	MenuItemLabel* upItem = MenuItemLabel::create(label, CC_CALLBACK_0(SignInScene::SignUp, this));
	upItem->setPosition(510, 270);

	Menu* mn = Menu::create(inItem, upItem, NULL);
	mn->setPosition(0, 0);
	addChild(mn);
}

void SignInScene::SignIn()
{

}
void SignInScene::SignUp()
{

}

void SignInScene::initEditBox()
{
	EditBox* box;
	//����ID�Ŀ�
	box = createEditBox("green_edit.png");
	box->setPosition(Vec2(480, 380));
	box->setPlaceHolder("ID or user name");	//���༭����û���κ��ַ����������ַ�ǰ������ʾ�ı�,��ռλ��
	//��������Ŀ�
	box = createEditBox("orange_edit.png");
	box->setPosition(Vec2(480, 330));
	box->setPlaceHolder("password");
	box->setInputFlag(EditBox::InputFlag::PASSWORD);////�����ı�����ʾ�ı�����ʽ������������
}

EditBox* SignInScene::createEditBox(string normalPngFile)
{
	EditBox* box = EditBox::create(Size(220, 38), Scale9Sprite::create(normalPngFile), Scale9Sprite::create("wite_edit.png"));
	box->setFontName("Marker Felt.ttf");
	box->setFontSize(25);
	box->setFontColor(Color3B(0, 0, 255));
	box->setPlaceholderFontName("Marker Felt.ttf");
	box->setPlaceholderFontSize(25);
	box->setPlaceholderFontColor(Color3B(255, 0, 0));
	box->setMaxLength(16);   //�����ı������ı�����󳤶�
	box->setInputMode(EditBox::InputMode::ANY);//�������ģʽ,�κη���
	box->setDelegate(this);//����ί�У��ı��������Ҫʵ��EditBoxDelegate�����еķ������Ϳ��Զ�EditBox���п���
	addChild(box);
	return box;
}

//�༭��ļ��̱༭�¼�
void SignInScene::editBoxEditingDidBegin(EditBox* editBox)
{
	CCLOG("editBoxEditingDidBegin");
	CCLOG("%d", editBox->getTag());
}

void SignInScene::editBoxTextChanged(EditBox* editBox, const std::string& text)
{
	CCLOG("editBoxTextChanged");
}

void SignInScene::editBoxEditingDidEnd(EditBox* editBox)
{
	CCLOG("editBoxEditingDidEnd");
}

void SignInScene::editBoxReturn(EditBox* editBox)
{
	CCLOG("editBoxReturn");
	std::string str = editBox->getText();
	CCLOG("%s", str.c_str());
	////�������������Ϣ
	//if (_sioClient != NULL) _sioClient->send(str);
}