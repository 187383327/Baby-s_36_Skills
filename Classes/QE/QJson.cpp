#include "QJson.h"

JDoc QJson::doc;

void QJson::initDocFromJsonFile(string fileName)
{
	//��ȡJson�ļ����ڵ�·��
	string  filefullPath = FileUtils::getInstance()->fullPathForFilename(fileName);
	//CCLOG("fullPath=%s", filefullPath.c_str());//����filefullPath��ȫ·������D:/projects/SnailGoHome/Resources/Data.json��
	Data data = FileUtils::getInstance()->getDataFromFile(filefullPath);
	//��Data����content
	string content = string((const char*)data.getBytes(), 0, data.getSize());

	//��content����document
	initDocWithString(content);
}

void QJson::initDocWithString(string content)
{
	doc.Parse<0>(content.c_str());
	//��������
	CCASSERT(!doc.HasParseError(), "Parsing to document failed.");
	//CCLOG("Parsed to document successfully !");
}

JValue& QJson::getArray(string key, JValue& value)
{
	//ȷ��ӵ����Ӧ��ֵ
	CC_ASSERT(value.HasMember(key.c_str()));

	//ȷ���������ֵ��Array���͵�
	CC_ASSERT(value[key.c_str()].IsArray());
	return value[key.c_str()];
}

int QJson::getInt(string key, JValue& value)
{
	//ȷ��ӵ����Ӧ��ֵ
	CC_ASSERT(value.HasMember(key.c_str()));
	//ȷ���������ֵ��Int���͵�
	CC_ASSERT(value[key.c_str()].IsInt());
	return value[key.c_str()].GetInt();
}

string QJson::getString(string key, JValue& value)
{
	//ȷ��ӵ����Ӧ��ֵ
	CC_ASSERT(value.HasMember(key.c_str()));
	//ȷ���������ֵ��String���͵�
	CC_ASSERT(value[key.c_str()].IsString());
	//����������Ҫ��ֵ
	return value[key.c_str()].GetString();
}

string QJson::getString()
{
	StringBuffer buffer;
	Writer<StringBuffer>writer(buffer);
	doc.Accept(writer);
	return buffer.GetString();
}