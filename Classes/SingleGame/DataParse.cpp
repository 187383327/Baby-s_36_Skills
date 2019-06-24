#include "DataParse.h"
#include"json\document.h"
#include"json/writer.h"
#include"json/stringbuffer.h"
#include"json/rapidjson.h"


void DataParse::CopyFile()
{
	std::string writeablePath = FileUtils::getInstance()->getWritablePath();
	writeablePath = writeablePath + "Data.json";
	
	std::string filePath = FileUtils::getInstance()->fullPathForFilename("Data.json");
	if (!FileUtils::getInstance()->isFileExist(writeablePath))
	{
		std::string data = FileUtils::getInstance()->getStringFromFile(filePath);
		FILE* file = fopen(writeablePath.c_str(), "w");
		if (file)
		{
			fputs(data.c_str(), file);
			fclose(file);
		}
	}
	
}

int  DataParse::getclok(int levelIndex)
{
	std::string writeablePath = FileUtils::getInstance()->getWritablePath();
	//��ȡ����·��
	writeablePath = writeablePath + "Data.json";
	//��һ���ļ����ݶ�ȡΪ�ַ���
	std::string data = FileUtils::getInstance()->getStringFromFile(writeablePath);
	//�������� 
	rapidjson::Document doc;
	//��ʼ����
	doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());
	//�жϽ����Ƿ��������
	if (doc.HasParseError())
	{
		return 0;
	}

	char levelName[20];
	sprintf(levelName, "level_%d_1", levelIndex);
	int num = doc[levelName]["lock"].GetInt();
	return num;
}

__Dictionary* DataParse::getChapter(int chapterIndex)
{
	CopyFile();
	//��ȡ�ɶ�д·��
	std::string writeablePath = FileUtils::getInstance()->getWritablePath();
	//��ȡ����·��
	writeablePath = writeablePath + "Data.json";
	
	
	//��ȡ��Դ
	std::string data = FileUtils::getInstance()->getStringFromFile(writeablePath);
	//����
	rapidjson::Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());
	
	if (doc.HasParseError())
	{
		
		return 0;
	}
	//�����ֵ�
	
	__Dictionary* dic = __Dictionary::create();
	
	//��ʼ��
	
	
	
	for (int i = 1; i <= 6; i++)
	{
		//�����
		char word[20];
		sprintf(word, "level_%d%d_word", chapterIndex,i);
		char prue[20];
		sprintf(prue, "level_%d%d_true",chapterIndex,i);
		//��doc�л�ȡֵ
		
		char level[20];
		sprintf(level, "level_%d%d", chapterIndex,i);
		//��Ϊֵ��int�͵���Ҫת��Ϊ����
		String* lockValue = String::create(doc[level]["word"].GetString());
		Integer * starValue = Integer::create(doc[level]["prue"].GetInt());
		
		dic->setObject(lockValue, word);
		dic->setObject(starValue, prue);
	}
	return dic;   
}

int DataParse::getNum( int levelIndex)
{
	//recouse
	std::string writeablePath = FileUtils::getInstance()->getWritablePath();
	writeablePath = writeablePath + "Data.json";
	std::string data = FileUtils::getInstance()->getStringFromFile(writeablePath);
	rapidjson::Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());
	if (doc.HasParseError())
	{
		return 0;
	}
	char levelName[20];
	sprintf(levelName, "level_%d", levelIndex);
	int num = doc[levelName]["prue"].GetInt();
	return num;
}

int DataParse::getStar( int levelIndex)
{
	std::string writeablePath = FileUtils::getInstance()->getWritablePath();
	writeablePath = writeablePath + "Data.json";
	std::string data = FileUtils::getInstance()->getStringFromFile(writeablePath);
	rapidjson::Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());
	if (doc.HasParseError())
	{
		return 0;
	}
	char levelName[20];
	sprintf(levelName, "level_%d", levelIndex);
	int num = doc[levelName]["star"].GetInt();
	return num;
}

void DataParse::setStar( int levelIndex, int starNum)
{
	std::string writeablePath = FileUtils::getInstance()->getWritablePath();
	writeablePath = writeablePath + "Data.json";
	std::string data = FileUtils::getInstance()->getStringFromFile(writeablePath);
	rapidjson::Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());
	if (doc.HasParseError())
	{
		return;
	}
	char levelName[20];
	sprintf(levelName, "level_%d", levelIndex);
	int starNum_Data = doc[levelName]["star"].GetInt();
	if (starNum_Data<=starNum)
	{
		doc[levelName]["star"].SetInt(starNum);
		if (starNum == 3 && levelIndex != 7)
		{
			char nextLevelName[20];
			sprintf(nextLevelName, "level_%d", levelIndex + 1);
			doc[nextLevelName]["lock"].SetInt(0);
		}
		writefile(doc, writeablePath);
	}
}

void DataParse::writefile(rapidjson::Document& document, std::string path)
{
	rapidjson::StringBuffer buffer;//��ʼ������
	//��ʼ��д����
	rapidjson::Writer<rapidjson::StringBuffer>writer(buffer);
	document.Accept(writer);//json д��buffer
	//��ԭ�����ļ����ݸ��ǵ�
	FILE *file = fopen(path.c_str(), "w");
	if (file)
	{
		fputs(buffer.GetString(), file);//����
		fclose(file);
	}
}