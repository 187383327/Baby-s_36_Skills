#pragma once

/*
Quick Engine��������Json��дģ��
����
1.QJson��
��;�����ڿ��ٶ�дJson����
*/

#include "json/document.h"
#include "json/rapidjson.h"
#include "json/reader.h"
#include "json/writer.h"
#include  "json/stringbuffer.h"

using namespace rapidjson;
typedef rapidjson::Value JValue;
typedef Document JDoc;

#include "QE.h"

class QJson
{
public:
	static JDoc doc;

	static void initDocFromJsonFile(string fileName = "Data.json");
	static void initDocWithString(string content);

	//get the array of key from value
	static JValue& getArray(string key, JValue& value);
	static int getInt(string key, JValue& value);
	static string getString(string key, JValue& value);
	static string getString();
	template <typename T>
	static void addMember(string name, T value) { doc.AddMember(name, value, doc.GetAllocator()); }
	static void emptyDoc(){ doc.Parse<0>("{}"); }
};

/*
rapidjson::Value value��ֻ��һ�����壬��û�о������������ͣ������ȷvalue�����ͣ���ת����Ӧ�ĸ�ʽ

Value�����Ͱ�����int, double, string, bool, array, object, null

RapidJson�����ܹ���ȡ���޸����ݣ�������Ӻ�ɾ������
�������ʱ���Ȼ�ȡһ��������
rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();
���һ������
doc.AddMember("age", 15 , allocator);
���һ��null����
rapidjson::Value nullObject(rapidjson::kNullType);
doc.AddMember("null", nullObject, allocator);
���һ������
rapidjson::Value obj(rapidjson::kObjectType);
obj.AddMember("name", "xiaoli", allocator);
obj.AddMember("age", 20, allocator);
obj.AddMember("height", 180, allocator);
doc.AddMember("personInfo", obj, allocator);
���һ������
rapidjson::Value arr(rapidjson::kArrayType);
arr.PushBack(1, allocator);
arr.PushBack("string in array", allocator);
arr.PushBack(obj, allocator);
doc.AddMember("arr", arr, allocator);
*/