#pragma once

/*
Quick Engineģ��

QE V2.0 for Baby's_36_Skills

QE��Quick Engine���������棩��飺
����Cocos2d-x 3.17.1��C++ 17���������������ܶ����������ĸ����ԡ�
QE�������Ϊ���Ż�Ĭ�ϵĲ���ֵ�������б�ʹԭ����Ҫ���д��������ɵĹ��ܣ�����ֻ��Ҫһ�д��������ɡ�

���磺
1.�������ɱ������顢����ê���λ�þ�Ϊ��0, 0��������ӵ���ǰ�ڵ㣬ֻ��Ҫ����һ��������ˡ�
	�ǵð���Դ�ĳ�bg.png��
	���á�QE_addBgSpriteToThis������꼴�ɣ�������ڴ��룬Ҳ����Ҫ�����κβ���

2.�������ɲ˵���������ͼƬ�����Լ�һ���ɵ��ö��󼴿ɡ�

3.����ͷ�ļ�ֻ��Ҫ���������һ�£�Ȼ������Ӧ��ͷ�ļ����ٰ���һ�´�ͷ�ļ��Ϳ����ˡ�
�����������ң�������������Ч�����Դ����ٰ�����ͷ�ļ�������
*/

//��
//CB = callback
#define QE_CB0(Type, Fun, ...) std::bind(&Type::Fun,this, ##__VA_ARGS__)
//CBWT = callback with target
#define QE_CBWT0(Type, Fun, targert, ...) std::bind(&Type::Fun,targert, ##__VA_ARGS__)
//#define CC_CALLBACK_0(__selector__,__target__, ...) std::bind(&__selector__,__target__, ##__VA_ARGS__)
#define QE_CALLBACK_1(Type,Fun) CC_CALLBACK_1(Type::Fun, this)

//C++
using namespace std;

//Cocos2d-x
#include "cocos2d.h"
USING_NS_CC;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
#include "network/SocketIO.h"
using namespace cocos2d::network;

//���ģʽ
#include "QE/QDesignMode.h"

//QE
#include "QE/QType.h"
#include "QE/QScene.h"
#include "QE/QLayer.h"
#include "QE/QMenu.h"
#include "QE/QSprite.h"
#include "QE/QFileUtils.h"
#include "QE/QAnimate.h"
#include "QE/QObject.h"
#include "QE/QJson.h"
#include "QE/QTMX.h"

//User
#include "AppDelegate.h"
#include "HelloWorldScene.h"
