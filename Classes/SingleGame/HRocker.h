#ifndef __HROCKER_H__
#define __HROCKER_H__

#include "cocos2d.h"

using namespace cocos2d;

//���ڱ�ʶҡ����ҡ�˵ı���  
typedef enum{  //û�����õ�ʱ��Ĭ����ֵ��0��ʼ
	tag_rocker,
	tag_rockerBG,
}tagForHRocker;
//���ڱ�ʶҡ�˷���
typedef enum{  //û�����õ�ʱ��Ĭ����ֵ��0��ʼ
	rocker_stay,
	rocker_right,
	rocker_up,
	rocker_left,
	rocker_down,
}tagDirecton;
class HRocker :public CCLayer
{
public:
	HRocker(void);
	~HRocker(void);

	//����ҡ��(ҡ�˵Ĳ�����ͼƬ��Դ����ҡ�˱���ͼƬ��Դ������ʼ����)
	static HRocker* createHRocker(const char *rockerImageName, const char *rockerBGImageName, CCPoint position);
	//����ҡ��(��ʾҡ�ˡ�����ҡ�˴����¼�)
	void startRocker(bool _isStopOther);
	//ֹͣҡ��(����ҡ�ˣ�ȡ��ҡ�˵Ĵ�������)
	void stopRocker();
	//�жϿ��Ƹ˷��������жϾ����ϡ��¡������˶�
	int rocketDirection;
	//��ǰ�������߷���,�����жϾ���ĳ��򣬾��������һ��ǳ���
	bool rocketRun;
	void resumeState();
	CREATE_FUNC(HRocker);
private:
	//�Զ����ʼ������
	void rockerInit(const char* rockerImageName, const char* rockerBGImageName, CCPoint position);
	//�Ƿ�ɲ���ҡ��
	bool isCanMove;
	//��ȡ��ǰҡ�����û�������ĽǶ�
	float getRad(CCPoint pos1, CCPoint pos2);
	//ҡ�˱���������
	CCPoint rockerBGPosition;
	//ҡ�˱����İ뾶
	float rockerBGR;
	void update(float delta);//��ʱ�������һ��float���͵Ĳ���
	//�����¼�
	

	EventListenerTouchOneByOne * listener;


	CCSprite *rocker;
	CCSprite *rockerBG;

	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

};

#endif


