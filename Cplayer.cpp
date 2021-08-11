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
	playerDown = IMAGE->findImage("플레이어아래쪽");
	playerAttackDown = IMAGE->findImage("플레이어아래쪽공격");
	playerMoveDown = IMAGE->findImage("플레이어아래쪽걷기");

	playerLeft = IMAGE->findImage("플레이어왼쪽");
	playerMoveLeft = IMAGE->findImage("플레이어왼쪽걷기");
	playerAttackLeft = IMAGE->findImage("플레이어왼쪽공격");

	playerRight = IMAGE->findImage("플레이어오른쪽");
	playerMoveRight = IMAGE->findImage("플레이어오른쪽걷기");
	playerAttackRight = IMAGE->findImage("플레이어오른쪽공격");

	playerUp = IMAGE->findImage("플레이어위쪽");
	playerMoveUp = IMAGE->findImage("플레이어위쪽걷기");
	playerAttackUp = IMAGE->findImage("플레이어위쪽공격");

	ANIMATION->addDefAnimation("리치스킬애니", "리치스킬", 15, false, true);

	//MOVE
	ANIMATION->addDefAnimation("위쪽걷기", "플레이어위쪽걷기", 10, false, true);
	ANIMATION->addDefAnimation("아래쪽걷기", "플레이어아래쪽걷기", 10, false, true);
	ANIMATION->addDefAnimation("왼쪽걷기", "플레이어왼쪽걷기", 10, false, true);
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
	SAFE_DELETE(m_playerSkill);

}

void Cplayer::update()
{
	m_angle += 0.4;
	moveControl();
	playerMoveRc = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth() - 90, playerMoveDown->getFrameHeight() - 50);
	m_playerSkill->update("리치스킬애니");
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
		if (direction == DIRECTIONS::DIRECTIONS_LEFT)m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, PI, 7.0f, 700, "리치스킬", "리치스킬애니");
		else if (direction == DIRECTIONS::DIRECTIONS_RIGHT)m_playerSkill->skillInformation(m_playerX + 50, m_playerY + 33, PI2, 7.0f, 700, "리치스킬", "리치스킬애니");
		else if (direction == DIRECTIONS::DIRECTIONS_UP)m_playerSkill->skillInformation(m_playerX + 15, m_playerY - 20, PI * 0.5, 7.0f, 700, "리치스킬", "리치스킬애니");//위??
		else if (direction == DIRECTIONS::DIRECTIONS_DOWN)m_playerSkill->skillInformation(m_playerX, m_playerY, PI * 1.5, 7.0f, 700, "리치스킬", "리치스킬애니");
	}
	else if (InputManager->isOnceKeyDown('W'))
	{
		isAttack = true;
		for (size_t i = 0; i < 30; i++)
		{
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.21, 5.0f, 150, "리치스킬", "리치스킬애니");
		}
	}
	else if (InputManager->isOnceKeyDown('E'))
	{
		isAttack = true;
		for (size_t i = 0; i < 30; i++)
		{
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.21, 7.0f, 350, "리치스킬", "리치스킬애니");
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.22, 6.0f, 300, "리치스킬", "리치스킬애니");
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.26, 5.0f, 250, "리치스킬", "리치스킬애니");
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.65, 4.3f, 200, "리치스킬", "리치스킬애니");
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
					playerIdleAni = ANIMATION->findAnimation("왼쪽");
					ANIMATION->start("왼쪽");
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
					playerIdleAni = ANIMATION->findAnimation("위쪽");
					ANIMATION->start("위쪽");
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
					playerIdleAni = ANIMATION->findAnimation("오른쪽");
					ANIMATION->start("오른쪽");
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
					playerIdleAni = ANIMATION->findAnimation("아래쪽");
					ANIMATION->start("아래쪽");
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