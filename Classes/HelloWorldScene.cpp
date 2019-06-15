﻿#pragma execution_character_set("utf-8")

#include "HelloWorldScene.h"

QE_CreateSceneFromLayer_CPP(HelloWorld);
	_listView = ListView::create();
	//testListView();
	testScrollView();
	return true;
}

void HelloWorld::testListView()
{
	_listView->setDirection(ScrollView::Direction::VERTICAL);
	_listView->setBounceEnabled(true);//回弹效果
	_listView->setBackGroundImage("green_edit.png");
	_listView->setBackGroundImageScale9Enabled(true);
	_listView->setContentSize(Size(240, 130));
	_listView->setPosition(Vec2(420, 160));
	addChild(_listView);
	for (int i = 0; i < 10; i++)
	{
		Layout* widget = Layout::create();;
		widget->setContentSize(Size(240, 50));
		auto* str = String::createWithFormat("TextArea Widget can line wrap %d", i + 1);
		Text* text = Text::create(str->getCString(), "Marker Felt.ttf", 13);
		text->setContentSize(Size(60, 10));
		text->setPosition(Vec2(20, 25));
		text->setAnchorPoint(Vec2(0, 0));
		widget->addChild(text);
		_listView->pushBackCustomItem(widget);
	}
}

void HelloWorld::setWidget(ListView* _listView, std::string str)
{
	_listView->removeAllChildren();
	std::string temp = "";
	int index = 0, max = str.length(), times=0;
	while (true)
	{
		temp = str.substr(0, max);
		CCLOG("temp=%s", temp.c_str());
		Layout* widget = Layout::create();
		widget->setContentSize(Size(240, 50));
		Text* text = Text::create(temp.c_str(), "Marker Felt.ttf", 13);
		text->setContentSize(Size(60, 10));
		text->setPosition(Vec2(20, 25));
		text->setAnchorPoint(Vec2(0, 0));
		widget->addChild(text);
		_listView->pushBackCustomItem(widget);
		if (times <= 10)
		{
			times++;
		}
		else
		{
			break;
		}
	}
}

void HelloWorld::testScrollView()
{
	Scale9Sprite* s = Scale9Sprite::create("green_edit.png");  //设置ScrollView背景，便于查看容器大小
	s->setContentSize(Size(400, 215));
	s->setPosition(Vec2(240, 160));
	addChild(s);
	ScrollView* _scrollView = ScrollView::create();
	_scrollView->setContentSize(Size(400, 215));//因为图片的高度为215
	_scrollView->setAnchorPoint(Vec2(0.5, 0.5));
	_scrollView->setPosition(Vec2(240, 160));
	_scrollView->setDirection(ScrollView::Direction::HORIZONTAL);
	_scrollView->setBounceEnabled(true);
	_scrollView->setInnerContainerSize(Size(135 * 9, 215));
	//因为图片的高度为215,135=图片的宽度120+缝隙15
	_scrollView->addEventListener(CC_CALLBACK_2(HelloWorld::scrollViewSdidScroll, this));
	addChild(_scrollView);
	for (int i = 0; i < 9; i++)
	{
		String* str = String::createWithFormat("LEVELSELECTION_%d.png", i + 1);
		Button* btn = Button::create(str->getCString(), str->getCString());
		btn->setScale9Enabled(true);
		btn->setContentSize(Size(120, 215));
		btn->setPosition(Vec2(135 * i + 70, 107.5));// 215/2=107.5，75=120/2+15，加70是为了让左右边界处都留有缝隙
		btn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::selectScene, this));
		btn->setTag(i + 1);
		_scrollView->addChild(btn);
	}
}
//scrollView滑动选项
void HelloWorld::scrollViewSdidScroll(Ref* sender, ScrollView::EventType type)
{
	switch (type)
	{
	case ScrollView::EventType::SCROLL_TO_TOP:
	{
		CCLOG("滑倒顶部了！");
		break;
	}
	case ScrollView::EventType::SCROLL_TO_BOTTOM:
	{
		CCLOG("滑倒底部了！");
		break;
	}
	case ScrollView::EventType::SCROLL_TO_LEFT:
	{
		CCLOG("滑倒左边了！");
		break;
	}
	case ScrollView::EventType::SCROLL_TO_RIGHT:
	{
		CCLOG("滑倒右边了！");
		break;
	}
	case ScrollView::EventType::SCROLLING:
	{
		CCLOG("正在滑动中！");
		break;
	}
	case ScrollView::EventType::BOUNCE_BOTTOM:
	{
		CCLOG("回弹到底部了！");
		break;
	}
	case ScrollView::EventType::BOUNCE_LEFT:
	{
		CCLOG("回弹到左边了！");
		break;
	}
	case ScrollView::EventType::BOUNCE_TOP:
	{
		CCLOG("回弹到顶部了！");
		break;
	}
	case ScrollView::EventType::BOUNCE_RIGHT:
	{
		CCLOG("回弹到右边了！");
		break;
	}
	}
}

void HelloWorld::selectScene(Ref* sender, Widget::TouchEventType type)
{
	auto btn = (Button*)sender;
	if (type == Widget::TouchEventType::ENDED)
	{
		CCLOG("您选择了第%d关！", btn->getTag());
	}
}