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
   playerDown= IMAGE->findImage("�÷��̾�Ʒ���");
   playerAttackDown= IMAGE->findImage("�÷��̾�Ʒ��ʰ���");
   playerMoveDown = IMAGE->findImage("�÷��̾�Ʒ��ʰȱ�");

   playerLeft=IMAGE->findImage("�÷��̾����");
   playerMoveLeft=IMAGE->findImage("�÷��̾���ʰȱ�");
   playerAttackLeft=IMAGE->findImage("�÷��̾���ʰ���");

   playerRight=IMAGE->findImage("�÷��̾������");
   playerMoveRight=IMAGE->findImage("�÷��̾�����ʰȱ�");
   playerAttackRight=IMAGE->findImage("�÷��̾�����ʰ���");

   playerUp=IMAGE->findImage("�÷��̾�����");
   playerMoveUp=IMAGE->findImage("�÷��̾����ʰȱ�");
   playerAttackUp=IMAGE->findImage("�÷��̾����ʰ���");


    //MOVE
   ANIMATION->addDefAnimation("���ʰȱ�", "�÷��̾����ʰȱ�",10, false, true);
   ANIMATION->addDefAnimation("�Ʒ��ʰȱ�", "�÷��̾�Ʒ��ʰȱ�",10, false, true);
   ANIMATION->addDefAnimation("���ʰȱ�", "�÷��̾���ʰȱ�",10, false, true);
   ANIMATION->addDefAnimation("�����ʰȱ�", "�÷��̾�����ʰȱ�", 10, false, true);

    //IDLE
   ANIMATION->addDefAnimation("����", "�÷��̾�����", 10, false, true);
   ANIMATION->addDefAnimation("�Ʒ���", "�÷��̾�Ʒ���", 10, false, true);
   ANIMATION->addDefAnimation("����", "�÷��̾����", 10, false, true);
   ANIMATION->addDefAnimation("������", "�÷��̾������", 10, false, true);

    //ATTACK
   ANIMATION->addDefAnimation("���ʰ���", "�÷��̾����ʰ���", 20, false, true);
   ANIMATION->addDefAnimation("�Ʒ��ʰ���", "�÷��̾�Ʒ��ʰ���", 20, false, true);
   ANIMATION->addDefAnimation("���ʰ���", "�÷��̾���ʰ���", 20, false, true);
   ANIMATION->addDefAnimation("�����ʰ���", "�÷��̾�����ʰ���", 20, false, true);

   //�⺻����
   playerIdleAni = ANIMATION->findAnimation("�Ʒ���");
   playerAttackAni = ANIMATION->findAnimation("�Ʒ��ʰ���");
   playerMoveAni = ANIMATION->findAnimation("�Ʒ��ʰȱ�");
   
   //��Ʈ
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
					playerIdleAni = ANIMATION->findAnimation("����");
					ANIMATION->start("����");
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
					playerIdleAni = ANIMATION->findAnimation("����");
					ANIMATION->start("����");
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
					playerIdleAni = ANIMATION->findAnimation("������");
					ANIMATION->start("������");
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
					playerIdleAni = ANIMATION->findAnimation("�Ʒ���");
					ANIMATION->start("�Ʒ���");
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
			playerMoveAni = ANIMATION->findAnimation("���ʰȱ�");
			ANIMATION->start("���ʰȱ�");
			playerAttackAni = ANIMATION->findAnimation("���ʰ���");
			ANIMATION->start("���ʰ���");
			isIdle = false;
		}
		break;
	case DIRECTIONS::DIRECTIONS_UP:
		if (isMoving)
		{
			playerMoveAni = ANIMATION->findAnimation("���ʰȱ�");
			ANIMATION->start("���ʰȱ�");
			playerAttackAni = ANIMATION->findAnimation("���ʰ���");
			ANIMATION->start("���ʰ���");
			isIdle = false;
		}
		break;
	case DIRECTIONS::DIRECTIONS_RIGHT:
		if (isMoving)
		{
			playerMoveAni = ANIMATION->findAnimation("�����ʰȱ�");
			ANIMATION->start("�����ʰȱ�");
			playerAttackAni = ANIMATION->findAnimation("�����ʰ���");
			ANIMATION->start("�����ʰ���");
			isIdle = false;
		}
		break;
	case DIRECTIONS::DIRECTIONS_DOWN:
		if (isMoving)
		{
			playerMoveAni = ANIMATION->findAnimation("�Ʒ��ʰȱ�");
			ANIMATION->start("�Ʒ��ʰȱ�");
			playerAttackAni = ANIMATION->findAnimation("�Ʒ��ʰ���");
			ANIMATION->start("�Ʒ��ʰ���");
			isIdle = false;
		}
		break;
	}
}