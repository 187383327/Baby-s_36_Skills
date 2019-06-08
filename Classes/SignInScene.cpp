#include "SignInScene.h"

LabelTTF* SignInScene::label, * SignInScene::logLabel;
MenuItemLabel* SignInScene::connectItem;

QE_CreateSceneFromLayer_CPP(SignInScene);
	paths = { "fonts" };
	QE_SetResourcesSearchDir;

	createLabel("Log");
	label->setPosition(10, 100);
	logLabel = label;

	Connect::connect();
	initMenu();
	initEditBox();

	createLabel("Connect Status:");
	label->setPosition(340, 500);
	createLabel("");
	label->setPosition(530, 500);
	updateLabel();
	return true;
}

void SignInScene::createLabel(string show)
{
	label = LabelTTF::create(show, "Marker Felt.ttf", 24);
	label->setAnchorPoint(Vec2(0, 0));
	addChild(label, 1);
}

void SignInScene::updateLabel()
{
	if (Connect::isConnect) { label->setString("Successful"); }
	else { label->setString("Failed"); }
}

void SignInScene::initMenu()
{
	label = LabelTTF::create("sign in", "Marker Felt.ttf", 25);
	MenuItemLabel* inItem = MenuItemLabel::create(label, bind(&SignInScene::SignIn, this));
	inItem->setPosition(410, 270);

	label = LabelTTF::create("sign up", "Marker Felt.ttf", 25);
	MenuItemLabel* upItem = MenuItemLabel::create(label, bind(&SignInScene::SignUp, this));
	upItem->setPosition(510, 270);

	label = LabelTTF::create("Connect", "Marker Felt.ttf", 25);
	connectItem = MenuItemLabel::create(label, bind(&Connect::connect));
	connectItem->setPosition(480, 450);

	Menu* mn = Menu::create(inItem, upItem, connectItem, NULL);
	mn->setPosition(0, 0);
	addChild(mn);
}

void SignInScene::SignIn()
{
	//JValue& value = doc["type"];
	//value.SetInt(123);
	//value = doc["type"].GetInt();
	//if (value.IsInt())
	//{
	//	CCLOG("type is %d, doc[type] is %d", value.GetInt(), doc["type"].GetInt());
	//}


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