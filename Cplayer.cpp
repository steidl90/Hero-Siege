#include "framework.h"
#include "Cplayer.h"

Cplayer::Cplayer()
{
}

Cplayer::~Cplayer()
{
}

HRESULT Cplayer::init()
{
	isMoving = false;
	isIdle = false;
	isAttack = false;
	
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
   playerX = WINSIZEX / 2;
   playerY = WINSIZEY / 2;
   playerMoveRc = RectMake(playerX, playerY, playerMoveDown->getFrameWidth(), playerMoveDown->getFrameHeight());
   playerAttackRc = RectMakeCenter(300, 300, playerAttackDown->getFrameWidth(), playerAttackDown->getFrameHeight());
   return S_OK;
}

void Cplayer::release()
{
}

void Cplayer::update()
{
	move();
	playerMoveRc = RectMake(playerX, playerY, playerMoveDown->getFrameWidth() - 90, playerMoveDown->getFrameHeight() - 50);
}

void Cplayer::render()
{
	Rectangle(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerMoveRc.right, playerMoveRc.bottom);
	if (isMoving == true)
	{
		switch (direction)
		{
		case DIRECTIONS::DIRECTIONS_LEFT:
			if (!isAttack) playerMoveLeft->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			else
			{
				Rectangle(getMapDC(), playerMoveRc.left - 55, playerY + 10, playerMoveRc.left + 40, playerY - 40);
				playerAttackLeft->aniRender(getMapDC(), playerMoveRc.left - 100, playerMoveRc.top - 70, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			if (!isAttack) playerMoveUp->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			else
			{
				Rectangle(getMapDC(), playerMoveRc.left + 36, playerY - 135, playerMoveRc.left + 90, playerY - 55);
				playerAttackUp->aniRender(getMapDC(), playerMoveRc.left - 50, playerMoveRc.top - 60, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			if (!isAttack) playerMoveRight->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			else
			{
				Rectangle(getMapDC(), playerMoveRc.right - 40, playerY + 10, playerMoveRc.right + 55, playerY - 40);
				playerAttackRight->aniRender(getMapDC(), playerMoveRc.left - 50, playerMoveRc.top - 60, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			if (!isAttack) playerMoveDown->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			else
			{
				Rectangle(getMapDC(), playerMoveRc.left + 36, playerY + 25, playerMoveRc.left + 90, playerY + 115);
				playerAttackDown->aniRender(getMapDC(), playerMoveRc.left - 50, playerMoveRc.top - 60, playerAttackAni);
			}
			break;
		}
	}
	else if (isMoving == false)
	{
		switch (direction)
		{
		case DIRECTIONS::DIRECTIONS_LEFT:
			if (!isAttack)
			{
				playerLeft->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 4, playerIdleAni);
				if (isIdle == false)
				{
					playerIdleAni = ANIMATION->findAnimation("왼쪽");
					ANIMATION->start("왼쪽");
					isIdle = true;
				}
			}
			else
			{
				Rectangle(getMapDC(), playerMoveRc.left - 55, playerY + 10, playerMoveRc.left + 40, playerY - 40);
				playerAttackLeft->aniRender(getMapDC(), playerMoveRc.left - 50, playerMoveRc.top - 60, playerAttackAni);
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
				Rectangle(getMapDC(), playerMoveRc.left + 36, playerY - 135, playerMoveRc.left + 90, playerY - 55);
				playerAttackUp->aniRender(getMapDC(), playerMoveRc.left - 50, playerMoveRc.top - 60, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			if (!isAttack)
			{
				playerRight->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 4, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("오른쪽");
					ANIMATION->start("오른쪽");
					isIdle = true;
				}
			}
			else
			{
				Rectangle(getMapDC(), playerMoveRc.right - 40, playerY + 10, playerMoveRc.right + 55, playerY - 40);
				playerAttackRight->aniRender(getMapDC(), playerMoveRc.left - 50, playerMoveRc.top - 60, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			if (!isAttack)
			{
				playerDown->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 4, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("아래쪽");
					ANIMATION->start("아래쪽");
					isIdle = true;
				}

			}
			else
			{
				Rectangle(getMapDC(), playerMoveRc.left + 36, playerY + 25, playerMoveRc.left + 90, playerY + 115);
				playerAttackDown->aniRender(getMapDC(), playerMoveRc.left - 50, playerMoveRc.top - 60, playerAttackAni);
			}
			break;
		}
	}
}

void Cplayer::move()
{
	RECT rc;
	rc = playerMoveRc;
	float elpasedTime = TIME->getElapsedTime();
	float moveSpeed = elpasedTime * speed;
	
	if (InputManager->isStayKeyDown(VK_RIGHT) && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
	{
		playerX += moveSpeed * 1.2;
		if (InputManager->isStayKeyDown(VK_DOWN))playerY += moveSpeed * 1.2;
		if (InputManager->isStayKeyDown(VK_UP))playerY -= moveSpeed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_RIGHT;
	}
	else if (InputManager->isStayKeyDown(VK_LEFT) && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
	{
		playerX -= moveSpeed;
		if (InputManager->isStayKeyDown(VK_DOWN))playerY += moveSpeed*1.2;
		if (InputManager->isStayKeyDown(VK_UP))playerY -= moveSpeed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_LEFT;
	}
	else if (InputManager->isStayKeyDown(VK_UP)&&(InputManager->isStayKeyDown(VK_RIGHT)||InputManager->isStayKeyDown(VK_LEFT)))
	{
		playerY -= moveSpeed;
		if (InputManager->isStayKeyDown(VK_RIGHT))playerX += moveSpeed * 1.2;
		if (InputManager->isStayKeyDown(VK_LEFT))playerX -= moveSpeed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_UP;
	}
	else if (InputManager->isStayKeyDown(VK_DOWN) && (InputManager->isStayKeyDown(VK_RIGHT) || InputManager->isStayKeyDown(VK_LEFT)))
	{
		playerY += moveSpeed * 1.2;
		if (InputManager->isStayKeyDown(VK_RIGHT))playerX += moveSpeed * 1.2;
		if (InputManager->isStayKeyDown(VK_LEFT))playerX -= moveSpeed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_DOWN;
	}
	else if (InputManager->isStayKeyDown(VK_LEFT))
	{
		playerX -= moveSpeed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_LEFT;
	}
	else if (InputManager->isStayKeyDown(VK_RIGHT))
	{
		playerX += moveSpeed * 1.2;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_RIGHT;
	}
	else if (InputManager->isStayKeyDown(VK_UP))
	{
		playerY -= moveSpeed;
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_UP;
	}
	else if (InputManager->isStayKeyDown(VK_DOWN))
	{
		playerY += moveSpeed * 1.2;
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