#include "framework.h"
#include "Cplayer.h"

Cplayer::Cplayer() :isMoving(false), isIdle(false), isAttack(false), isLive(true), m_speed(3.0f)
{
}

Cplayer::~Cplayer()
{
}

HRESULT Cplayer::init()
{
   //DIRECTIONS
   direction= DIRECTIONS::DIRECTIONS_DOWN;
   beforeDirection= DIRECTIONS::DIRECTIONS_DOWN;

   //IMAGE
   playerDown= IMAGE->findImage("플레이어아래쪽");
   playerAttackDown= IMAGE->findImage("플레이어아래쪽공격");
   playerMoveDown = IMAGE->findImage("플레이어아래쪽걷기");

   playerLeft=IMAGE->findImage("플레이어왼쪽");
   playerMoveLeft=IMAGE->findImage("플레이어왼쪽걷기");
   playerAttackLeft=IMAGE->findImage("플레이어왼쪽공격");

   playerRight=IMAGE->findImage("플레이어오른쪽");
   playerMoveRight=IMAGE->findImage("플레이어오른쪽걷기");
   playerAttackRight=IMAGE->findImage("플레이어오른쪽공격");

   playerUp=IMAGE->findImage("플레이어위쪽");
   playerMoveUp=IMAGE->findImage("플레이어위쪽걷기");
   playerAttackUp=IMAGE->findImage("플레이어위쪽공격");


    //MOVE
   ANIMATION->addDefAnimation("위쪽걷기", "플레이어위쪽걷기",10, false, true);
   ANIMATION->addDefAnimation("아래쪽걷기", "플레이어아래쪽걷기",10, false, true);
   ANIMATION->addDefAnimation("왼쪽걷기", "플레이어왼쪽걷기",10, false, true);
   ANIMATION->addDefAnimation("오른쪽걷기", "플레이어오른쪽걷기", 10, false, true);

    //IDLE
   ANIMATION->addDefAnimation("위쪽", "플레이어위쪽", 10, false, true);
   ANIMATION->addDefAnimation("아래쪽", "플레이어아래쪽", 10, false, true);
   ANIMATION->addDefAnimation("왼쪽", "플레이어왼쪽", 10, false, true);
   ANIMATION->addDefAnimation("오른쪽", "플레이어오른쪽", 10, false, true);

    //ATTACK
   ANIMATION->addDefAnimation("위쪽공격", "플레이어위쪽공격", 20, false, true);
   ANIMATION->addDefAnimation("아래쪽공격", "플레이어아래쪽공격", 20, false, true);
   ANIMATION->addDefAnimation("왼쪽공격", "플레이어왼쪽공격", 20, false, true);
   ANIMATION->addDefAnimation("오른쪽공격", "플레이어오른쪽공격", 20, false, true);

   //기본상태
   playerIdleAni = ANIMATION->findAnimation("아래쪽");
   playerAttackAni = ANIMATION->findAnimation("아래쪽공격");
   playerMoveAni = ANIMATION->findAnimation("아래쪽걷기");
   
   //렉트
   m_playerX = WINSIZEX / 2;
   m_playerY = WINSIZEY / 2;
   playerMoveRc = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth(), playerMoveDown->getFrameHeight());
   playerAttackRc = RectMake(m_playerX, m_playerY, 100, 100);
   return S_OK;
}

void Cplayer::release()
{
}



void Cplayer::update()
{
	moveControl();
	playerMoveRc = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth() - 90, playerMoveDown->getFrameHeight() - 50);
}

void Cplayer::render()
{
	playerStateRender();
}

void Cplayer::moveControl()
{
	if (InputManager->isStayKeyDown(VK_RIGHT) && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
	{
		m_playerX += m_speed;
		if (InputManager->isStayKeyDown(VK_DOWN))m_playerY += m_speed;
		if (InputManager->isStayKeyDown(VK_UP))m_playerY -= m_speed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_RIGHT;
	}
	else if (InputManager->isStayKeyDown(VK_LEFT) && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
	{
		m_playerX -= m_speed;
		if (InputManager->isStayKeyDown(VK_DOWN))m_playerY += m_speed;
		if (InputManager->isStayKeyDown(VK_UP))m_playerY -= m_speed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_LEFT;
	}
	else if (InputManager->isStayKeyDown(VK_UP)&&(InputManager->isStayKeyDown(VK_RIGHT)||InputManager->isStayKeyDown(VK_LEFT)))
	{
		m_playerY -= m_speed;
		if (InputManager->isStayKeyDown(VK_RIGHT))m_playerX += m_speed;
		if (InputManager->isStayKeyDown(VK_LEFT))m_playerX -= m_speed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_UP;
	}
	else if (InputManager->isStayKeyDown(VK_DOWN) && (InputManager->isStayKeyDown(VK_RIGHT) || InputManager->isStayKeyDown(VK_LEFT)))
	{
		m_playerY += m_speed;
		if (InputManager->isStayKeyDown(VK_RIGHT))m_playerX += m_speed;
		if (InputManager->isStayKeyDown(VK_LEFT))m_playerX -= m_speed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_DOWN;
	}
	else if (InputManager->isStayKeyDown(VK_LEFT))
	{
		m_playerX -= m_speed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_LEFT;
	}
	else if (InputManager->isStayKeyDown(VK_RIGHT))
	{
		m_playerX += m_speed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_RIGHT;
	}
	else if (InputManager->isStayKeyDown(VK_UP))
	{
		m_playerY -= m_speed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_UP;
	}
	else if (InputManager->isStayKeyDown(VK_DOWN))
	{
		m_playerY += m_speed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_DOWN;
	}
	else isMoving = false;

	if (InputManager->isStayKeyDown(VK_SPACE)) isAttack = true;
	else isAttack = false;

	moveAnimation();
}

void Cplayer::moveAnimation()
{
	if (beforeDirection == direction) return;
	beforeDirection = direction;

	switch (direction)
	{
	case DIRECTIONS::DIRECTIONS_LEFT:
		if (isMoving)
		{
			playerMoveAni = ANIMATION->findAnimation("왼쪽걷기");
			ANIMATION->start("왼쪽걷기");
			playerAttackAni = ANIMATION->findAnimation("왼쪽공격");
			ANIMATION->start("왼쪽공격");
			isIdle = false;
		}
		break;
	case DIRECTIONS::DIRECTIONS_UP:
		if (isMoving)
		{
			playerMoveAni = ANIMATION->findAnimation("위쪽걷기");
			ANIMATION->start("위쪽걷기");
			playerAttackAni = ANIMATION->findAnimation("위쪽공격");
			ANIMATION->start("위쪽공격");
			isIdle = false;
		}
		break;
	case DIRECTIONS::DIRECTIONS_RIGHT:
		if (isMoving)
		{
			playerMoveAni = ANIMATION->findAnimation("오른쪽걷기");
			ANIMATION->start("오른쪽걷기");
			playerAttackAni = ANIMATION->findAnimation("오른쪽공격");
			ANIMATION->start("오른쪽공격");
			isIdle = false;
		}
		break;
	case DIRECTIONS::DIRECTIONS_DOWN:
		if (isMoving)
		{
			playerMoveAni = ANIMATION->findAnimation("아래쪽걷기");
			ANIMATION->start("아래쪽걷기");
			playerAttackAni = ANIMATION->findAnimation("아래쪽공격");
			ANIMATION->start("아래쪽공격");
			isIdle = false;
		}
		break;
	}
}

void Cplayer::playerStateRender()
{
	Rectangle(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerMoveRc.right, playerMoveRc.bottom);

	if (isMoving)
	{
		switch (direction)
		{
		case DIRECTIONS::DIRECTIONS_LEFT:
			if (!isAttack) playerMoveLeft->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			else
			{
				playerAttackRc = RectMake(m_playerX - 99, m_playerY, 100, 30);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
   				playerAttackLeft->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			if (!isAttack) playerMoveUp->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 15, playerMoveAni);
			else
			{
				playerAttackRc = RectMake(m_playerX + 10, m_playerY - 79, 25, 80);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackUp->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 76, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			if (!isAttack) playerMoveRight->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			else
			{
				playerAttackRc = RectMake(m_playerX + 35, m_playerY, 100, 30);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackRight->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			if (!isAttack) playerMoveDown->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			else
			{
				playerAttackRc = RectMake(m_playerX, m_playerY + 67, 25, 90);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackDown->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			}
			break;
		}
	}
	else if (!isMoving)
	{
		switch (direction)
		{
		case DIRECTIONS::DIRECTIONS_LEFT:
			if (!isAttack)
			{
				playerLeft->aniRender(getMapDC(), playerMoveRc.left - 40, playerMoveRc.top - 3, playerIdleAni);
				if (isIdle == false)
				{
					playerIdleAni = ANIMATION->findAnimation("왼쪽");
					ANIMATION->start("왼쪽");
					isIdle = true;
				}
			}
			else
			{
				playerAttackRc = RectMake(m_playerX - 99, m_playerY, 100, 30);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackLeft->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			if (!isAttack)
			{
				playerUp->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 4, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("위쪽");
					ANIMATION->start("위쪽");
					isIdle = true;
				}
			}
			else
			{
				playerAttackRc = RectMake(m_playerX + 10, m_playerY - 79, 25, 80);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackUp->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			if (!isAttack)
			{
				playerRight->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 3, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("오른쪽");
					ANIMATION->start("오른쪽");
					isIdle = true;
				}
			}
			else
			{
				playerAttackRc = RectMake(m_playerX + 35, m_playerY, 100, 30);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackRight->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			if (!isAttack)
			{
				playerDown->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 3, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("아래쪽");
					ANIMATION->start("아래쪽");
					isIdle = true;
				}
			}
			else
			{
				playerAttackRc = RectMake(m_playerX, m_playerY + 67, 25, 90);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackDown->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			}
			break;
		}
	}
}