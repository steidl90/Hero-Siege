#include "framework.h"
#include "camel.h"
#include"mapToolMain.h"
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
	_speed = 2;

	ANIMATION->addDefAnimation("ani1", "red", 10, true, false);


	int arrLen[] = { 0,1,2,3 };
	ANIMATION->addAnimation("ani2", "red", arrLen, 4, 5, true);

	ANIMATION->addAnimation("ani3", "red", 4, 7, 10, false, true);


	ANIMATION->addAnimation("redUp", "red", 4, 7, 5, false, true);
	ANIMATION->addAnimation("redDown", "red", 0, 3, 5, false, true);
	ANIMATION->addAnimation("redRight", "red", 8, 11, 5, false, true);
	ANIMATION->addAnimation("redLeft", "red", 12, 15, 5, false, true);

	//시작  애니메이션 설정
	_ani = ANIMATION->findAnimation("ani1");

	isKeyDown = false;

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
	//direct = DIRECTION::IDLE;
	
	this->playerMove();

	////마우스 왼쪽 버튼으로 화면 이동 기능 -> 현재 캐릭터의 x,y의 값을 변경하여 이동 하는 구조로 되어있음
	//if (!isKeyDown) //현재 마우스의 절대 좌표값 표현 용도
	//{
	//	m_currentX =  _x + m_ptMouse.x;
	//	m_currentY =  _x + m_ptMouse.y;
	//}
	//if (InputManager->isStayKeyDown(VK_RBUTTON))
	//{
	//	isKeyDown = true;

	//	m_nextX = _x + m_ptMouse.x;
	//	m_nextY = _x + m_ptMouse.y;
	//	if (m_nextX < m_currentX) //마우스를 왼쪽으로 이동시키면 화면이 오른쪽으로 이동한다
	//	{
	//		_x = _x + (m_currentX - m_nextX);
	//		if (_x > MAPSIZE)  _x = MAPSIZE - IMAGE->findImage("red")->getFrameWidth(); //좌표(캐릭터)가 화면 밖으로 이동 했을 때 예외처리
	//	}
	//	
	//	if (m_nextX > m_currentX) //마우스를 오른쪽으로 이동시키면 화면이 왼쪽으로 이동한다
	//	{
	//		_x = _x - (m_nextX - m_currentX);
	//		if (_x < 0) _x = 0; //좌표(캐릭터)가 화면 밖으로 이동 했을 때 예외처리
	//	}

	//	if (m_nextY < m_currentY) //마우스를 위쪽으로 이동시키면 화면이 아래쪽으로 이동한다
	//	{
	//		_y = _y + (m_currentY - m_nextY);
	//		if (_y > MAPSIZE) _y = MAPSIZE - IMAGE->findImage("red")->getFrameHeight() * 2; //좌표(캐릭터)가 화면 밖으로 이동 했을 때 예외처리
	//	}

	//	if (m_nextY > m_currentY) //마우스를 아래쪽으로 이동시키면 화면이 위쪽으로 이동한다
	//	{
	//		_y = _y - (m_nextY - m_currentY);
	//		if (_y < 0) _y = 0; //좌표(캐릭터)가 화면 밖으로 이동 했을 때 예외처리
	//	}
	//}
	//else isKeyDown = false;

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

	//char str[100];
	//sprintf_s(str, "current x : %d, current y : %d", m_currentX, m_currentY);
	//SetTextColor(getMemDC(), RGB(255, 255, 0));
	//TextOut(getMemDC(), WINSIZEX / 2 - 500, WINSIZEY - 200, str, lstrlen(str));
}

void camel::playerMove()
{

	//if (isUp && (InputManager->isStayKeyDown(VK_RIGHT) || InputManager->isStayKeyDown(VK_LEFT)))
	//{
	//	_y -= _speed;
	//	if (InputManager->isOnceKeyUp(VK_UP)) isUp = false;
	//	if (InputManager->isStayKeyDown(VK_RIGHT))_x += _speed;
	//	if (InputManager->isStayKeyDown(VK_LEFT))_x -= _speed;
	//	direct = DIRECTION::TOP;
	//}
	//else if (isRight && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
	//{
	//	_x += _speed;
	//	if (InputManager->isOnceKeyUp(VK_RIGHT)) isRight = false;
	//	if (InputManager->isStayKeyDown(VK_DOWN))_y += _speed;
	//	if (InputManager->isStayKeyDown(VK_UP))_y -= _speed;
	//	direct = DIRECTION::RIGHT;
	//}
	//else if (isDown && (InputManager->isStayKeyDown(VK_RIGHT) || InputManager->isStayKeyDown(VK_LEFT)))
	//{
	//	_y += _speed;
	//	if (InputManager->isOnceKeyUp(VK_DOWN)) isDown = false;
	//	if (InputManager->isStayKeyDown(VK_RIGHT))_x += _speed;
	//	if (InputManager->isStayKeyDown(VK_LEFT))_x -= _speed;
	//	direct = DIRECTION::DOWN;
	//}
	//else if (isLeft && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
	//{
	//	_x -= _speed;
	//	if (InputManager->isOnceKeyUp(VK_LEFT)) isLeft = false;
	//	if (InputManager->isStayKeyDown(VK_DOWN))_y += _speed;
	//	if (InputManager->isStayKeyDown(VK_UP))_y -= _speed;
	//	direct = DIRECTION::LEFT;
	//}
	//else if (InputManager->isStayKeyDown(VK_UP))
	//{
	//	_y -= _speed;
	//	isUp = true;
	//	isLeft = false;
	//	isRight = false;
	//	isDown = false;
	//	direct = DIRECTION::TOP;
	//}
	//else if (InputManager->isStayKeyDown(VK_RIGHT))
	//{
	//	_x += _speed;
	//	isRight = true;
	//	isLeft = false;
	//	isDown = false;
	//	isUp = false;
	//	direct = DIRECTION::RIGHT;
	//}
	//else if (InputManager->isStayKeyDown(VK_DOWN))
	//{
	//	_y += _speed;
	//	isDown = true;
	//	isLeft = false;
	//	isRight = false;
	//	isUp = false;
	//	direct = DIRECTION::DOWN;
	//}
	//else if (InputManager->isStayKeyDown(VK_LEFT))
	//{
	//	_x -= _speed;
	//	isLeft = true;
	//	isRight = false;
	//	isDown = false;
	//	isUp = false;
	//	direct = DIRECTION::LEFT;
	//}
	//else
	//{
	//	isLeft = false;
	//	isRight = false;
	//	isDown = false;
	//	isUp = false;
	//}

	RECT rcCollision;
	int tileIndex[2] = { 0, };//검사용 타일
	rcCollision = _redRc;

	if (InputManager->isStayKeyDown(VK_UP) && _y > 0)
	{
		_y -= _speed;
		direct = DIRECTION::TOP;
		rcCollision = RectMake(_x, _y, _red->getFrameWidth(), _red->getFrameHeight());
	}
	if (InputManager->isStayKeyDown(VK_DOWN) && _y < MAPSIZE - IMAGE->findImage("red")->getFrameHeight())
	{
		_y += _speed;
		direct = DIRECTION::DOWN;
		rcCollision = RectMake(_x, _y, _red->getFrameWidth(), _red->getFrameHeight());

	}
	if (InputManager->isStayKeyDown(VK_RIGHT) && _x < MAPSIZE - IMAGE->findImage("red")->getFrameWidth())
	{
		_x += _speed;
		direct = DIRECTION::RIGHT;
		rcCollision = RectMake(_x, _y, _red->getFrameWidth(), _red->getFrameHeight());

	}
	if (InputManager->isStayKeyDown(VK_LEFT) && _x > 0)
	{
		if (_x > 0)
			_x -= _speed;
		direct = DIRECTION::LEFT;
		rcCollision = RectMake(_x, _y, _red->getFrameWidth(), _red->getFrameHeight());

	}

	//// 지금 밟고  있는 타일 번호를 알아오자
	//tileX = rcCollision.left / TILESIZE;
	//tileY = rcCollision.top / TILESIZE;


	//switch (direct)
	//{
	//	// 타일 기준 검사 좌표가 레프트 탑이라서 반대쪽을 신경써주는 것
	//case DIRECTION::LEFT:
	//	tileIndex[0] = tileX + tileY * TILEX;
	//	tileIndex[1] = tileX + (tileY + 1) * TILEX;
	//	break;
	//case DIRECTION::RIGHT:
	//	tileIndex[0] = (tileX + tileY * TILEX) + 1;
	//	tileIndex[1] = (tileX + (tileY + 1) * TILEX) + 1;
	//	break;
	//case DIRECTION::TOP:
	//	tileIndex[0] = tileX + tileY * TILEX;
	//	tileIndex[1] = tileX + 1 + tileY * TILEX;
	//	break;
	//case DIRECTION::DOWN:
	//	tileIndex[0] = (tileX + tileY * TILEX) + TILEX;
	//	tileIndex[1] = (tileX + 1 + tileY * TILEX) + TILEX;
	//	break;
	//}

	//for (size_t i = 0; i < 2; i++)
	//{
	//	RECT rc;

	//	//해당 타일의 속성이 움직이지 못하는 곳이면
	//	if (((_map->getMainMapTile()[tileIndex[i]].collisionObj == COLLISIONOBJECT::COLLISIONOBJ) &&
	//		IntersectRect(&rc, &_map->getMainMapTile()[tileIndex[i]].rc, &rcCollision)))
	//	{
	//		switch (direct)

	//		{
	//		case DIRECTION::LEFT:

	//			_redRc.left = _map->getMainMapTile()[tileIndex[i]].rc.right;//왼쪽 타일의 라이트의 위치를 탱크의 레프트의 위치로 고정
	//			_redRc.right = _redRc.left + _red->getFrameWidth();			//탱크의 크기만큼
	//			_x = _redRc.left;				//탱크 X의 위치를 계산한 탱크 렉트의 위치값으로 설정(중앙으로)
	//			break;
	//		case DIRECTION::RIGHT:
	//			_redRc.right = _map->getMainMapTile()[tileIndex[i]].rc.left;
	//			_redRc.left = _redRc.right - _red->getFrameWidth();
	//			_x = _redRc.left;
	//			break;
	//		case DIRECTION::TOP:
	//			_redRc.top = _map->getMainMapTile()[tileIndex[i]].rc.bottom;
	//			_redRc.bottom = _redRc.top + _red->getFrameHeight();
	//			_y = _redRc.top;
	//			break;
	//		case DIRECTION::DOWN:
	//			_redRc.bottom = _map->getMainMapTile()[tileIndex[i]].rc.top;
	//			_redRc.top = _redRc.bottom - _red->getFrameHeight();
	//			_y = _redRc.top;
	//			break;
	//		}
	//		return;
	//	}

	//}//end of for

	rcCollision = RectMakeCenter(_x, _y, _red->getFrameWidth(), _red->getFrameHeight());
	_redRc = rcCollision;
}
