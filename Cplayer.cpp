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
   
   playerMoveRc = RectMakeCenter(WINSIZEX/2, WINSIZEY/2, playerMoveDown->getFrameWidth(), playerMoveDown->getFrameHeight());
   playerAttackRc = RectMakeCenter(300, 300, playerAttackDown->getFrameWidth(), playerAttackDown->getFrameHeight());
   playerX = 300;
   playerY = 300;
    return S_OK;
}

void Cplayer::release()
{
}

void Cplayer::update()
{
	move();
	playerMoveRc = RectMakeCenter(playerX, playerY, playerMoveDown->getFrameWidth()*1.5, playerMoveDown->getFrameWidth()*1.5);

}

void Cplayer::render()
{
	//Rectangle(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerMoveRc.right, playerMoveRc.bottom);
	if (isMoving == true)
	{
		switch (direction)
		{
		case DIRECTIONS::DIRECTIONS_LEFT:

			if(!isAttack) playerMoveLeft->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerMoveAni);
			else
			{
				playerAttackLeft->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			if (!isAttack) playerMoveUp->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerMoveAni);
			else
			{
				playerAttackUp->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			if (!isAttack) playerMoveRight->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerMoveAni);
			else
			{
				playerAttackRight->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			if (!isAttack) playerMoveDown->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerMoveAni);
			else
			{
				playerAttackDown->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);
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
				playerLeft->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerIdleAni);
				if (isIdle == false)
				{
					playerIdleAni = ANIMATION->findAnimation("����");
					ANIMATION->start("����");
					isIdle = true;
				}
			}
			else
			{
				playerAttackLeft->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			if (!isAttack)
			{
				playerUp->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("����");
					ANIMATION->start("����");
					isIdle = true;
				}
			}
			else
			{
				playerAttackUp->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			if (!isAttack)
			{
				playerRight->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("������");
					ANIMATION->start("������");
					isIdle = true;
				}
			}
			else
			{
				playerAttackRight->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			if (!isAttack)
			{
				playerDown->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("�Ʒ���");
					ANIMATION->start("�Ʒ���");
					isIdle = true;
				}
			}
			else
			{
				playerAttackDown->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);
			}
			break;
		}
	}

	/*switch (direction)
	{
	case DIRECTIONS::DIRECTIONS_LEFT:
		playerAttackLeft->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);

		break;
	case DIRECTIONS::DIRECTIONS_UP:
		playerAttackUp->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);

		break;
	case DIRECTIONS::DIRECTIONS_RIGHT:
		playerAttackRight->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);

		break;
	case DIRECTIONS::DIRECTIONS_DOWN:
		playerAttackDown->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);

		break;
	}*/

}

//void Cplayer::setPlayerPosition(RECT rc)
//{
//	rc = playerMoveRc;
//	playerX = playerMoveRc.left + (playerMoveRc.right - playerMoveRc.left) / 2;
//	playerY = playerMoveRc.top + (playerMoveRc.bottom - playerMoveRc.top) / 2;
//}

void Cplayer::move()
{
	RECT rc;
	rc = playerMoveRc;
	float elpasedTime = TIME->getElapsedTime();
	float moveSpeed = elpasedTime * speed;
	//setPlayerPosition(rc);
	
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
	//attack();

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

	/*if (isMoving == false)
	{
		playerMoveAni->stop();
	}*/
}

void Cplayer::attack()
{
	if (isAttack)
	{
		switch (direction)
		{
		case DIRECTIONS::DIRECTIONS_LEFT:
			playerAttackAni = ANIMATION->findAnimation("���ʰ���");
			ANIMATION->start("���ʰ���");
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			playerAttackAni = ANIMATION->findAnimation("���ʰ���");
			ANIMATION->start("���ʰ���");
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			playerAttackAni = ANIMATION->findAnimation("�����ʰ���");
			ANIMATION->start("�����ʰ���");
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			//playerAttackDown->aniRender(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerAttackAni);
			playerAttackAni = ANIMATION->findAnimation("�Ʒ��ʰ���");
			ANIMATION->start("�Ʒ��ʰ���");
			break;
		default:
			break;
		}
	}
	/*else if (isAttack = false)
	{
		playerAttackAni->stop();
	}*/
}
