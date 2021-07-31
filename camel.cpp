#include "framework.h"
#include "camel.h"

camel::camel()
{
}

camel::~camel()
{
}

HRESULT camel::init()
{
	//_camel = IMAGE->addImage("camel", "images/camel.bmp", 300, 267, true, RGB(255, 0, 255));

	////처ㅏ음부터 끝까지
	//_ani1 = new animation;
	//_ani1->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	//_ani1->setDefPlayFrame(false, true);
	//_ani1->setFPS(1);

	////배열ㅇ에 담아서
	//int arrAni[] = { 0,1,2,3,4,5,6,7,8,9 };
	//_ani2 = new animation;
	//_ani2->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	//_ani2->setPlayFrame(arrAni, 10, true);
	//_ani2->setFPS(1);


	//_ani3 = new animation;
	//_ani3->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	//_ani3->setPlayFrame(1, 10, false, true);
	//_ani3->setFPS(1);




	//매니저로
	_camel = IMAGE->addFrameImage("camel", "images/camel.bmp", 300, 267, 4, 3, true, RGB(255, 0, 255));
	_red = IMAGE->addFrameImage("red", "images/레드.bmp", 256, 88, 8, 2, true, RGB(255, 0, 255));

	_redRc = RectMake(WINSIZEX / 2, WINSIZEY / 2, _red->getFrameWidth(), _red->getFrameHeight());
	_x = 100;
	_y = 100;
	_speed = 7;

	ANIMATION->addDefAnimation("ani1", "red", 10, true, false);


	int arrLen[] = { 0,1,2,3 };
	ANIMATION->addAnimation("ani2", "red", arrLen, 4, 5, true);

	ANIMATION->addAnimation("ani3", "red", 4, 7, 10, false, true);


	ANIMATION->addAnimation("redUp", "red", 4, 7, 10, false, true);
	ANIMATION->addAnimation("redDown", "red", 0, 3, 10, false, true);
	ANIMATION->addAnimation("redRight", "red", 8, 11, 10, false, true);
	ANIMATION->addAnimation("redLeft", "red", 12, 15, 10, false, true);

	//시작  애니메이션 설정
	_ani = ANIMATION->findAnimation("ani1");


	return S_OK;
}

void camel::release()
{
	//SAFE_DELETE(_ani1);
	//SAFE_DELETE(_ani2);
	//SAFE_DELETE(_ani3);
}

void camel::update()
{

	if (InputManager->isStayKeyDown(VK_UP) && _y > 0)
	{
		_y -= _speed;
		direct = DIRECTION::TOP;
	}
	if (InputManager->isStayKeyDown(VK_DOWN) && _y < MAPSIZE - IMAGE->findImage("red")->getFrameHeight())
	{
		_y += _speed;
		direct = DIRECTION::DOWN;
	}
	if (InputManager->isStayKeyDown(VK_RIGHT) && _x < MAPSIZE - IMAGE->findImage("red")->getFrameWidth())
	{
		_x += _speed;
		direct = DIRECTION::RIGHT;
	}
	if (InputManager->isStayKeyDown(VK_LEFT) && _x > 0)
	{
		if (_x > 0)
			_x -= _speed;
		direct = DIRECTION::LEFT;
	}

	switch (direct)
	{
	case DIRECTION::LEFT:
		_ani = ANIMATION->findAnimation("redLeft");
		ANIMATION->start("redLeft");
		break;
	case DIRECTION::RIGHT:
		_ani = ANIMATION->findAnimation("redRight");
		ANIMATION->start("redRight");
		break;
	case DIRECTION::TOP:
		_ani = ANIMATION->findAnimation("redUp");
		ANIMATION->start("redUp");
		break;
	case DIRECTION::DOWN:
		_ani = ANIMATION->findAnimation("redDown");
		ANIMATION->start("redDown");
		break;
	default:
		break;
	}

	/*_ani1->frameUpdate(0.4f);
	_ani2->frameUpdate(0.1f);
	_ani3->frameUpdate(1.0f);*/

	_redRc = RectMake(_x, _y, _red->getFrameWidth(), _red->getFrameHeight());

}

void camel::render()
{
	Rectangle(getMapDC(), _redRc.left, _redRc.top, _redRc.right, _redRc.bottom);
	_red->aniRender(getMapDC(), _redRc.left, _redRc.top, _ani);
}