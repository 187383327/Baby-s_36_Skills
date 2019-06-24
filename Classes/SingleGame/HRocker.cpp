#include "HRocker.h"
const double PI = 3.1415;
HRocker::HRocker(void)
{
	rocketRun = false;
}

HRocker::~HRocker(void)
{
}
//����ҡ��(ҡ�˵Ĳ�����ͼƬ��Դ����ҡ�˱���ͼƬ��Դ������ʼ����)
HRocker* HRocker::createHRocker(const char *rockerImageName, const char *rockerBGImageName, CCPoint position)
{
	HRocker *layer = HRocker::create();
	if (layer)
	{
		layer->rockerInit(rockerImageName, rockerBGImageName, position);
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return NULL;
}

//�Զ����ʼ������
void HRocker::rockerInit(const char* rockerImageName, const char* rockerBGImageName, CCPoint position)
{
	CCSprite *spRockerBG = CCSprite::create(rockerBGImageName);
	spRockerBG->setPosition(position);
	spRockerBG->setVisible(false);
	addChild(spRockerBG, 0, tag_rockerBG);//

	CCSprite *spRocker = CCSprite::create(rockerImageName);
	spRocker->setPosition(position);
	spRocker->setVisible(false);
	addChild(spRocker, 1, tag_rocker);

	rockerBGPosition = position;
	rockerBGR = spRockerBG->getContentSize().width*0.3;//  ҡ�˴�С
	rocketDirection = -1;//��ʾҡ�˷��򲻱�

	
}

//����ҡ��(��ʾҡ�ˡ�����ҡ�˴����¼�)
void HRocker::startRocker(bool _isStopOther)
{
	//��ʾҡ��
	rocker = (CCSprite*)this->getChildByTag(tag_rocker);
	rocker->setVisible(true);

	rockerBG = (CCSprite *)this->getChildByTag(tag_rockerBG);
	rockerBG->setVisible(true);


	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HRocker::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HRocker::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HRocker::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	
}

//ֹͣҡ��(����ҡ�ˣ�ȡ��ҡ�˵Ĵ�������)
void HRocker::stopRocker()
{
	
	
	Director::getInstance()->getEventDispatcher()->pauseEventListenersForTarget(this,false);
	Director::getInstance()->getEventDispatcher()-> removeEventListener(listener);
}


//��ȡ��ǰҡ�����û�������ĽǶ�
float HRocker::getRad(CCPoint pos1, CCPoint pos2)
{
	float px1 = pos1.x;
	float py1 = pos1.y;
	float px2 = pos2.x;
	float py2 = pos2.y;

	//�õ�����x�ľ���
	float x = px2 - px1;
	//�õ�����y�ľ���
	float y = py1 - py2;
	//���б�߳���
	float xie = sqrt(pow(x, 2) + pow(y, 2));
	//�õ�����Ƕȵ�����ֵ(ͨ�����Ǻ����еĵ���Ƕ�����ֵ=б��/б��)
	float cosAngle = x / xie;
	//ͨ�������Ҷ����ȡ���ڽǶȵĻ���
	float rad = acos(cosAngle);
	//ע�⣺��������λ��Y����<ҡ�˵�Y���꣬����Ҫȥ��ֵ-0~-180
	if (py2 < py1)
	{
		rad = -rad;
	}
	return rad;
}

CCPoint getAngelePosition(float r, float angle){
	return ccp(r*cos(angle), r*sin(angle));
}

//̧���¼�
bool HRocker::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint point = pTouch->getLocation(); //��ȡ������
	rocker = (CCSprite *)this->getChildByTag(tag_rocker);  //��ȡҡ��
	if (rocker->boundingBox().containsPoint(point))
	{
		isCanMove = true;
		
	}
	return true;
}
//�ƶ��¼�
void HRocker::onTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint point = pTouch->getLocation();//����ִ�����Ļ��λ��
	rocker = (CCSprite *)this->getChildByTag(tag_rocker);
	//�õ�ҡ���봥�������γɵĽǶ�
	float angle = getRad(rockerBGPosition, point);
	//�ж�����Բ��Բ�ľ��Ƿ����ҡ�˱����İ뾶
	if (sqrt(pow((rockerBGPosition.x - point.x), 2) + pow((rockerBGPosition.y - point.y), 2)) >= rockerBGR)
	{

		//��֤�ڲ�СԲ�˶��ĳ�������
		rocker->setPosition(ccpAdd(getAngelePosition(rockerBGR, angle), ccp(rockerBGPosition.x, rockerBGPosition.y)));
		//	CCLOG("touch");
	}
	else
	{
		//��û�г�������ҡ�˸����û��������ƶ�����
		rocker->setPosition(point);
		//CCLOG("touch");
	}

	//�жϷ���
	if (angle >= -PI / 4 && angle<PI / 4)
	{
		rocketDirection = rocker_right;
		rocketRun = false;
		//CCLOG("%d", rocketDirection);
	}
	else if (angle >= PI / 4 && angle<3 * PI / 4)
	{
		rocketDirection = rocker_up;
		//CCLOG("%d", rocketDirection);
	}
	else if ((angle >= 3 * PI / 4 && angle <= PI) || (angle >= -PI&&angle<-3 * PI / 4))
	{
		rocketDirection = rocker_left;
		rocketRun = true;
		//CCLOG("%d", rocketDirection);
	}
	else if (angle >= -3 * PI / 4 && angle<-PI / 4)
	{
		rocketDirection = rocker_down;
		/*CCLOG("%d", rocketDirection);*/
	}

	

}
//�뿪�¼�
void HRocker::onTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

	
	

	if (!isCanMove)
	{
		return;
	}
	rockerBG = (CCSprite*)this->getChildByTag(tag_rockerBG);
	rocker = (CCSprite*)this->getChildByTag(tag_rocker);
	rocker->stopAllActions();
	rocker->runAction(CCMoveTo::create(0.04f, rockerBG->getPosition()));
	isCanMove = false;
	rocketDirection = rocker_stay;
	
}

void HRocker::resumeState()
{

	rocker->stopAllActions();
	rocker->runAction(CCMoveTo::create(0.08f, rockerBG->getPosition()));
	isCanMove = false;
	rocketDirection = rocker_stay;
}

void HRocker::update(float dt)
{
	if (isCanMove)
	{

	}
}
