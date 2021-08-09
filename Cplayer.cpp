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
					playerIdleAni = ANIMATION->findAnimation("����");
					ANIMATION->start("����");
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
					playerIdleAni = ANIMATION->findAnimation("����");
					ANIMATION->start("����");
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
					playerIdleAni = ANIMATION->findAnimation("������");
					ANIMATION->start("������");
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
					playerIdleAni = ANIMATION->findAnimation("�Ʒ���");
					ANIMATION->start("�Ʒ���");
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