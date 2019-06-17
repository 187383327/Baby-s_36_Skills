﻿#pragma execution_character_set("utf-8")
#pragma once

#include "QuickEngine.h"

/*
Quick Engine所属快速精灵模块
含：
1.QSprite类
用途：用于快速管理精灵
*/

class QSprite
{
public:
	static Sprite* createBg();
	static Sprite* createBg(const std::string& filename);
	static Sprite* create(string fileName, int x, int y);
};

#define QE_addBgSpriteToThis addChild(QSprite::createBg());
#define QE_CreateSprite(fileName, x, y) addChild(QSprite::create(fileName, x, y));