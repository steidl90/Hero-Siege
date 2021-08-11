#include "framework.h"
#include "Cplayer.h"

Cplayer::Cplayer() :isMoving(false), isIdle(false), isAttack(false), isLive(true)
{
}

Cplayer::~Cplayer()
{
}

HRESULT Cplayer::init()
{
	m_maxHp = 1000;
	m_maxMp = 500;
	m_maxExp = 100;
	setAtk(10);
	setDef(10);
	setHp(m_maxHp);
	setMp(m_maxMp);
	setCritical(5);
	setCriticalAtk(1.5);
	setSpeed(3.0f);
	setLv(1);
	setExp(0);

	m_playerSkill = new CplayerSkill;
	m_playerSkill->init();


	time = TIME->getWorldTime();

	//DIRECTIONS
	direction = DIRECTIONS::DIRECTIONS_DOWN;
	beforeDirection = DIRECTIONS::DIRECTIONS_DOWN;

	//IMAGE
	playerDown = IMAGE->findImage("�÷��̾�Ʒ���");
	playerAttackDown = IMAGE->findImage("�÷��̾�Ʒ��ʰ���");
	playerMoveDown = IMAGE->findImage("�÷��̾�Ʒ��ʰȱ�");

	playerLeft = IMAGE->findImage("�÷��̾����");
	playerMoveLeft = IMAGE->findImage("�÷��̾���ʰȱ�");
	playerAttackLeft = IMAGE->findImage("�÷��̾���ʰ���");

	playerRight = IMAGE->findImage("�÷��̾������");
	playerMoveRight = IMAGE->findImage("�÷��̾�����ʰȱ�");
	playerAttackRight = IMAGE->findImage("�÷��̾�����ʰ���");

	playerUp = IMAGE->findImage("�÷��̾�����");
	playerMoveUp = IMAGE->findImage("�÷��̾����ʰȱ�");
	playerAttackUp = IMAGE->findImage("�÷��̾����ʰ���");

	ANIMATION->addDefAnimation("��ġ��ų�ִ�", "��ġ��ų", 15, false, true);

	//MOVE
	ANIMATION->addDefAnimation("���ʰȱ�", "�÷��̾����ʰȱ�", 10, false, true);
	ANIMATION->addDefAnimation("�Ʒ��ʰȱ�", "�÷��̾�Ʒ��ʰȱ�", 10, false, true);
	ANIMATION->addDefAnimation("���ʰȱ�", "�÷��̾���ʰȱ�", 10, false, true);
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
	SAFE_DELETE(m_playerSkill);

}

void Cplayer::update()
{
	m_angle += 0.4;
	moveControl();
	playerMoveRc = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth() - 90, playerMoveDown->getFrameHeight() - 50);
	m_playerSkill->update("��ġ��ų�ִ�");
}

void Cplayer::render()
{
	playerStateRender();
	m_playerSkill->render();
}

void Cplayer::moveControl()
{
	if (InputManager->isStayKeyDown(VK_RIGHT) && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
	{
		m_playerX += getSpeed();
		if (InputManager->isStayKeyDown(VK_DOWN))m_playerY += getSpeed();
		if (InputManager->isStayKeyDown(VK_UP))m_playerY -= getSpeed();
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_RIGHT;
	}
	else if (InputManager->isStayKeyDown(VK_LEFT) && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
	{
		m_playerX -= getSpeed();
		if (InputManager->isStayKeyDown(VK_DOWN))m_playerY += getSpeed();
		if (InputManager->isStayKeyDown(VK_UP))m_playerY -= getSpeed();
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_LEFT;
	}
	else if (InputManager->isStayKeyDown(VK_UP) && (InputManager->isStayKeyDown(VK_RIGHT) || InputManager->isStayKeyDown(VK_LEFT)))
	{
		m_playerY -= getSpeed();
		if (InputManager->isStayKeyDown(VK_RIGHT))m_playerX += getSpeed();
		if (InputManager->isStayKeyDown(VK_LEFT))m_playerX -= getSpeed();
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_UP;
	}
	else if (InputManager->isStayKeyDown(VK_DOWN) && (InputManager->isStayKeyDown(VK_RIGHT) || InputManager->isStayKeyDown(VK_LEFT)))
	{
		m_playerY += getSpeed();
		if (InputManager->isStayKeyDown(VK_RIGHT))m_playerX += getSpeed();
		if (InputManager->isStayKeyDown(VK_LEFT))m_playerX -= getSpeed();
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_DOWN;
	}
	else if (InputManager->isStayKeyDown(VK_LEFT))
	{
		m_playerX -= getSpeed();
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_LEFT;
	}
	else if (InputManager->isStayKeyDown(VK_RIGHT))
	{
		m_playerX += getSpeed();
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_RIGHT;
	}
	else if (InputManager->isStayKeyDown(VK_UP))
	{
		m_playerY -= getSpeed();
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_UP;
	}
	else if (InputManager->isStayKeyDown(VK_DOWN))
	{
		m_playerY += getSpeed();
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_DOWN;
	}
	else isMoving = false;

	if (InputManager->isStayKeyDown(VK_SPACE)) isAttack = true;
	else isAttack = false;

	if (InputManager->isOnceKeyDown('Q'))
	{
		isAttack = true;
		if (direction == DIRECTIONS::DIRECTIONS_LEFT)m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, PI, 7.0f, 700, "��ġ��ų", "��ġ��ų�ִ�");
		else if (direction == DIRECTIONS::DIRECTIONS_RIGHT)m_playerSkill->skillInformation(m_playerX + 50, m_playerY + 33, PI2, 7.0f, 700, "��ġ��ų", "��ġ��ų�ִ�");
		else if (direction == DIRECTIONS::DIRECTIONS_UP)m_playerSkill->skillInformation(m_playerX + 15, m_playerY - 20, PI * 0.5, 7.0f, 700, "��ġ��ų", "��ġ��ų�ִ�");//��??
		else if (direction == DIRECTIONS::DIRECTIONS_DOWN)m_playerSkill->skillInformation(m_playerX, m_playerY, PI * 1.5, 7.0f, 700, "��ġ��ų", "��ġ��ų�ִ�");
	}
	else if (InputManager->isOnceKeyDown('W'))
	{
		isAttack = true;
		for (size_t i = 0; i < 30; i++)
		{
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.21, 5.0f, 150, "��ġ��ų", "��ġ��ų�ִ�");
		}
	}
	else if (InputManager->isOnceKeyDown('E'))
	{
		isAttack = true;
		for (size_t i = 0; i < 30; i++)
		{
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.21, 7.0f, 350, "��ġ��ų", "��ġ��ų�ִ�");
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.22, 6.0f, 300, "��ġ��ų", "��ġ��ų�ִ�");
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.26, 5.0f, 250, "��ġ��ų", "��ġ��ų�ִ�");
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.65, 4.3f, 200, "��ġ��ų", "��ġ��ų�ִ�");
		}
	}

	if (InputManager->isStayKeyDown('Z'))
	{
		setHp(getHp() - 1);
		setMp(getMp() - 1);
		if (getExp() < 100)setExp(getExp() + 1);
		else
		{
			setExp(0);
			setLv(getLv() + 1);
		}
	}

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
	//Rectangle(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerMoveRc.right, playerMoveRc.bottom);
	if (isMoving)
	{
		switch (direction)
		{
		case DIRECTIONS::DIRECTIONS_LEFT:
			if (!isAttack) playerMoveLeft->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			else
			{
				playerAttackRc = RectMake(m_playerX - 99, m_playerY, 100, 40);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackLeft->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			if (!isAttack) playerMoveUp->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 15, playerMoveAni);
			else
			{
				playerAttackRc = RectMake(m_playerX + 10, m_playerY - 89, 40, 90);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackUp->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 76, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			if (!isAttack) playerMoveRight->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			else
			{
				playerAttackRc = RectMake(m_playerX + 35, m_playerY, 100, 40);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackRight->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			}
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			if (!isAttack) playerMoveDown->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			else
			{
				playerAttackRc = RectMake(m_playerX - 10, m_playerY + 67, 40, 90);
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
				playerAttackRc = RectMake(m_playerX - 99, m_playerY, 100, 40);
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
				playerAttackRc = RectMake(m_playerX + 10, m_playerY - 89, 40, 90);
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
				playerAttackRc = RectMake(m_playerX + 35, m_playerY, 100, 40);
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
				playerAttackRc = RectMake(m_playerX - 10, m_playerY + 67, 40, 90);
				Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
				playerAttackDown->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			}
			break;
		}
	}
}