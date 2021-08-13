#include "framework.h"
#include "Cplayer.h"

Cplayer::Cplayer() :isMoving(false), isIdle(false), isAttack(false), isLive(true), isRect(false)
{
}

Cplayer::~Cplayer()
{
}

HRESULT Cplayer::init()
{
	m_saveDate = 0;
	m_saveDate++;
	m_maxHp = 1000;
	m_maxMp = 500;
	m_maxExp = 100;
	setAtk(10),
	setDef(10);
	setHp(m_maxHp);
	setMp(m_maxMp);
	setCritical(5);
	setCriticalAtk(1.5);
	setSpeed(3.0f);
	setLv(1);
	setExp(0);
	setGold(1000);
	m_playerX = 50;
	m_playerY = WINSIZEY / 2 + 230;

	m_playerSkill = new CplayerSkill;
	m_playerSkill->init();

	m_time = 0;

	//DIRECTIONS
	direction = DIRECTIONS::DIRECTIONS_IDLE;
	beforeDirection = DIRECTIONS::DIRECTIONS_DOWN;

	//SKILL
	skillState = SKILL::SKILL_IDLE;

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

	//스킬
	ANIMATION->addDefAnimation("리치스킬애니", "리치스킬", 15, false, true);
	playerSkillLightning = IMAGE->findImage("라이트닝");

	ANIMATION->addDefAnimation("라이트닝애니", "라이트닝", 10, false, true);
	playerLightningAni = ANIMATION->findAnimation("라이트닝애니");

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
	playerMoveRc = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth(), playerMoveDown->getFrameHeight());

	return S_OK;
}

void Cplayer::release()
{
	SAFE_DELETE(m_playerSkill);
}

void Cplayer::update()
{
	//Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
	ANIMATION->resume("라이트닝애니");
	m_angle += 0.4;
	moveControl();
	playerMoveRc = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth() - 90, playerMoveDown->getFrameHeight() - 50);
	m_playerSkill->update("리치스킬애니");
}

void Cplayer::render()
{
	playerSkillControl();
	playerSkillRender();
	m_playerSkill->render();
	if (isAttack) isAttackRender();
	else playerStateRender();
}

void Cplayer::moveControl()
{
	if (InputManager->isStayKeyDown(VK_RIGHT) && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
	{
		this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_RIGHT);
		if (InputManager->isStayKeyDown(VK_DOWN))
		{
			this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_DOWN);
		}
		if (InputManager->isStayKeyDown(VK_UP))
		{
			this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_UP);
		}
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_RIGHT;
	}
	else if (InputManager->isStayKeyDown(VK_LEFT) && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
	{
		this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_LEFT);
		if (InputManager->isStayKeyDown(VK_DOWN))
		{
			this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_DOWN);
		}
		if (InputManager->isStayKeyDown(VK_UP))
		{
			this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_UP);
		}
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_LEFT;
	}
	else if (InputManager->isStayKeyDown(VK_UP) && (InputManager->isStayKeyDown(VK_RIGHT) || InputManager->isStayKeyDown(VK_LEFT)))
	{
		this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_UP);
		if (InputManager->isStayKeyDown(VK_RIGHT))
		{
			this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_RIGHT);
		}
		if (InputManager->isStayKeyDown(VK_LEFT))
		{
			this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_LEFT);
		}
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_UP;
	}
	else if (InputManager->isStayKeyDown(VK_DOWN) && (InputManager->isStayKeyDown(VK_RIGHT) || InputManager->isStayKeyDown(VK_LEFT)))
	{
		this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_DOWN);
		if (InputManager->isStayKeyDown(VK_RIGHT))
		{
			this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_RIGHT);
		}
		if (InputManager->isStayKeyDown(VK_LEFT))
		{
			this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_LEFT);
		}
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_DOWN;
	}
	else if (InputManager->isStayKeyDown(VK_LEFT))
	{
		this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_LEFT);
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_LEFT;
	}
	else if (InputManager->isStayKeyDown(VK_RIGHT))
	{
		this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_RIGHT);
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_RIGHT;
	}
	else if (InputManager->isStayKeyDown(VK_UP))
	{
		this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_UP);
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_UP;
	}
	else if (InputManager->isStayKeyDown(VK_DOWN))
	{
		this->blockCheck(getSpeed(), &playerMoveRc, DIRECTIONS::DIRECTIONS_DOWN);
		isMoving = true;
		direction = DIRECTIONS::DIRECTIONS_DOWN;
	}
	else isMoving = false;

	if (InputManager->isStayKeyDown(VK_SPACE)) isAttack = true;
	else
	{
		isAttack = false;
		playerAttackRc = RectMake(-100, -100, 0, 0); //임시? 더 좋은 방법 있으면 바꿀 예정
	}

	if (InputManager->isOnceKeyDown('Q'))
	{
		isAttack = true;
		if (direction == DIRECTIONS::DIRECTIONS_LEFT)m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, PI, 7.0f, 700, "리치스킬", "리치스킬애니");
		else if (direction == DIRECTIONS::DIRECTIONS_RIGHT)m_playerSkill->skillInformation(m_playerX + 50, m_playerY + 33, PI2, 7.0f, 700, "리치스킬", "리치스킬애니");
		else if (direction == DIRECTIONS::DIRECTIONS_UP)m_playerSkill->skillInformation(m_playerX + 15, m_playerY - 20, PI * 0.5, 7.0f, 700, "리치스킬", "리치스킬애니");
		else if (direction == DIRECTIONS::DIRECTIONS_DOWN)m_playerSkill->skillInformation(m_playerX, m_playerY, PI * 1.5, 7.0f, 700, "리치스킬", "리치스킬애니");
	}
	else if (InputManager->isOnceKeyDown('W') && this->getLv() >= 3)
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
	else if (InputManager->isStayKeyDown('E') && this->getLv() >= 7 && m_count == 0)
	{
		m_count++;
		isAttack = true;
		m_time = TIME->getWorldTime();
		isRect = true;
		m_skillX = m_playerX;
		m_skillY = m_playerY;
		if (direction == DIRECTIONS::DIRECTIONS_LEFT) skillState = SKILL::SKILL_LEFT;
		else if (direction == DIRECTIONS::DIRECTIONS_RIGHT)  skillState = SKILL::SKILL_RIGHT;
		else if (direction == DIRECTIONS::DIRECTIONS_UP)  skillState = SKILL::SKILL_UP;
		else if (direction == DIRECTIONS::DIRECTIONS_DOWN) skillState = SKILL::SKILL_DOWN;
	}
	if (m_time + 2 < TIME->getWorldTime())
	{
		isRect = false;
		skillState = SKILL::SKILL_IDLE;
		m_count = 0;
	}

	if (InputManager->isStayKeyDown('Z')) // 디버깅
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

	//임시 레벨업
	if (getExp() >= 100)
	{
		setExp(0);
		setLv(getLv() + 1);
		setHp(m_maxHp);
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
			playerMoveLeft->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			playerMoveUp->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 15, playerMoveAni);
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			playerMoveRight->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			playerMoveDown->aniRender(getMapDC(), playerMoveRc.left - 45, playerMoveRc.top - 13, playerMoveAni);
			break;
		}
	}
	else
	{
		switch (direction)
		{
		case DIRECTIONS::DIRECTIONS_LEFT:
			playerLeft->aniRender(getMapDC(), playerMoveRc.left - 40, playerMoveRc.top - 3, playerIdleAni);
			if (isIdle == false)
			{
				playerIdleAni = ANIMATION->findAnimation("왼쪽");
				ANIMATION->start("왼쪽");
				isIdle = true;
			}
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			playerUp->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 4, playerIdleAni);
			if (!isIdle)
			{
				playerIdleAni = ANIMATION->findAnimation("위쪽");
				ANIMATION->start("위쪽");
				isIdle = true;
			}
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			playerRight->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 3, playerIdleAni);
			if (!isIdle)
			{
				playerIdleAni = ANIMATION->findAnimation("오른쪽");
				ANIMATION->start("오른쪽");
				isIdle = true;
			}
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			playerDown->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 3, playerIdleAni);
			if (!isIdle)
			{
				playerIdleAni = ANIMATION->findAnimation("아래쪽");
				ANIMATION->start("아래쪽");
				isIdle = true;
			}
			break;
		case DIRECTIONS::DIRECTIONS_IDLE:
			playerDown->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 3, playerIdleAni);
			if (!isIdle)
			{
				playerIdleAni = ANIMATION->findAnimation("아래쪽");
				ANIMATION->start("아래쪽");
				isIdle = true;
			}
			break;
		}
	}
}

void Cplayer::isAttackRender()
{
	if (isMoving)
	{
		switch (direction)
		{
		case DIRECTIONS::DIRECTIONS_LEFT:
			playerAttackRc = RectMake(m_playerX - 99, m_playerY, 100, 40);
			playerAttackLeft->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			playerAttackRc = RectMake(m_playerX + 10, m_playerY - 89, 40, 90);
			playerAttackUp->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 76, playerAttackAni);
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			playerAttackRc = RectMake(m_playerX + 35, m_playerY, 100, 40);
			playerAttackRight->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			playerAttackRc = RectMake(m_playerX - 10, m_playerY + 67, 40, 90);
			playerAttackDown->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			break;
		}
	}
	else if (!isMoving)
	{
		switch (direction)
		{
		case DIRECTIONS::DIRECTIONS_LEFT:
			playerAttackRc = RectMake(m_playerX - 99, m_playerY, 100, 40);
			playerAttackLeft->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			break;
		case DIRECTIONS::DIRECTIONS_UP:
			playerAttackRc = RectMake(m_playerX + 10, m_playerY - 89, 40, 90);
			playerAttackUp->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			break;
		case DIRECTIONS::DIRECTIONS_RIGHT:
			playerAttackRc = RectMake(m_playerX + 35, m_playerY, 100, 40);
			playerAttackRight->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			break;
		case DIRECTIONS::DIRECTIONS_DOWN:
			playerAttackRc = RectMake(m_playerX - 10, m_playerY + 67, 40, 90);
			playerAttackDown->aniRender(getMapDC(), playerMoveRc.left - 98, playerMoveRc.top - 75, playerAttackAni);
			break;
		}
	}
}

void Cplayer::playerSkillControl()
{
	if (isRect && skillState == SKILL::SKILL_LEFT)
	{
		lightningCenterRc = RectMake(m_skillX - 300, m_skillY, 36, 36);
		lightningLeftRc = RectMake(m_skillX - 336, m_skillY, 36, 36);
		lightningRightRc = RectMake(m_skillX - 264, m_skillY, 36, 36);
		lightningUpRc = RectMake(m_skillX - 300, m_skillY - 36, 36, 36);
		lightningDownRc = RectMake(m_skillX - 300, m_skillY + 36, 36, 36);
		/*Rectangle(getMapDC(), lightningCenterRc.left, lightningCenterRc.top, lightningCenterRc.right, lightningCenterRc.bottom);
		Rectangle(getMapDC(), lightningLeftRc.left, lightningLeftRc.top, lightningLeftRc.right, lightningLeftRc.bottom);
		Rectangle(getMapDC(), lightningRightRc.left, lightningRightRc.top, lightningRightRc.right, lightningRightRc.bottom);
		Rectangle(getMapDC(), lightningUpRc.left, lightningUpRc.top, lightningUpRc.right, lightningUpRc.bottom);
		Rectangle(getMapDC(), lightningDownRc.left, lightningDownRc.top, lightningDownRc.right, lightningDownRc.bottom);*/
	}

	else if (isRect && skillState == SKILL::SKILL_RIGHT)
	{
		lightningCenterRc = RectMake(m_skillX + 300, m_skillY, 36, 36);
		lightningLeftRc = RectMake(m_skillX + 264, m_skillY, 36, 36);
		lightningRightRc = RectMake(m_skillX + 336, m_skillY, 36, 36);
		lightningUpRc = RectMake(m_skillX + 300, m_skillY - 36, 36, 36);
		lightningDownRc = RectMake(m_skillX + 300, m_skillY + 36, 36, 36);
		/*Rectangle(getMapDC(), lightningCenterRc.left, lightningCenterRc.top, lightningCenterRc.right, lightningCenterRc.bottom);
		Rectangle(getMapDC(), lightningLeftRc.left, lightningLeftRc.top, lightningLeftRc.right, lightningLeftRc.bottom);
		Rectangle(getMapDC(), lightningRightRc.left, lightningRightRc.top, lightningRightRc.right, lightningRightRc.bottom);
		Rectangle(getMapDC(), lightningUpRc.left, lightningUpRc.top, lightningUpRc.right, lightningUpRc.bottom);
		Rectangle(getMapDC(), lightningDownRc.left, lightningDownRc.top, lightningDownRc.right, lightningDownRc.bottom);*/

		//playerLightningAni = ANIMATION->findAnimation("라이트닝애니");
	}
	else if (isRect && skillState == SKILL::SKILL_UP)
	{
		lightningCenterRc = RectMake(m_skillX, m_skillY - 300, 36, 36);
		lightningLeftRc = RectMake(m_skillX - 36, m_skillY - 300, 36, 36);
		lightningRightRc = RectMake(m_skillX + 36, m_skillY - 300, 36, 36);
		lightningUpRc = RectMake(m_skillX, m_skillY - 336, 36, 36);
		lightningDownRc = RectMake(m_skillX, m_skillY - 264, 36, 36);
		/*Rectangle(getMapDC(), lightningCenterRc.left, lightningCenterRc.top, lightningCenterRc.right, lightningCenterRc.bottom);
		Rectangle(getMapDC(), lightningLeftRc.left, lightningLeftRc.top, lightningLeftRc.right, lightningLeftRc.bottom);
		Rectangle(getMapDC(), lightningRightRc.left, lightningRightRc.top, lightningRightRc.right, lightningRightRc.bottom);
		Rectangle(getMapDC(), lightningUpRc.left, lightningUpRc.top, lightningUpRc.right, lightningUpRc.bottom);
		Rectangle(getMapDC(), lightningDownRc.left, lightningDownRc.top, lightningDownRc.right, lightningDownRc.bottom);*/
	}
	else if (isRect && skillState == SKILL::SKILL_DOWN)
	{
		lightningCenterRc = RectMake(m_skillX, m_skillY + 300, 36, 36);
		lightningLeftRc = RectMake(m_skillX - 36, m_skillY + 300, 36, 36);
		lightningRightRc = RectMake(m_skillX + 36, m_skillY + 300, 36, 36);
		lightningUpRc = RectMake(m_skillX, m_skillY + 264, 36, 36);
		lightningDownRc = RectMake(m_skillX, m_skillY + 336, 36, 36);
		/*Rectangle(getMapDC(), lightningCenterRc.left, lightningCenterRc.top, lightningCenterRc.right, lightningCenterRc.bottom);
		Rectangle(getMapDC(), lightningLeftRc.left, lightningLeftRc.top, lightningLeftRc.right, lightningLeftRc.bottom);
		Rectangle(getMapDC(), lightningRightRc.left, lightningRightRc.top, lightningRightRc.right, lightningRightRc.bottom);
		Rectangle(getMapDC(), lightningUpRc.left, lightningUpRc.top, lightningUpRc.right, lightningUpRc.bottom);
		Rectangle(getMapDC(), lightningDownRc.left, lightningDownRc.top, lightningDownRc.right, lightningDownRc.bottom);*/
	}
}

void Cplayer::playerSkillRender()
{
	switch (skillState)
	{
	case SKILL::SKILL_IDLE:
		break;
	case SKILL::SKILL_LEFT:
		//중앙
		playerSkillLightning->aniRender(getMapDC(), lightningCenterRc.left + (lightningCenterRc.right - lightningCenterRc.left) / 2 - 36,
			lightningCenterRc.top + (lightningCenterRc.bottom - lightningCenterRc.top) / 2 - 402, playerLightningAni);
		//왼쪽
		playerSkillLightning->aniRender(getMapDC(), lightningLeftRc.left + (lightningLeftRc.right - lightningLeftRc.left) / 2 - 36,
			lightningLeftRc.top + (lightningLeftRc.bottom - lightningLeftRc.top) / 2 - 402, playerLightningAni);
		//오른쪽
		playerSkillLightning->aniRender(getMapDC(), lightningRightRc.left + (lightningRightRc.right - lightningRightRc.left) / 2 - 36,
			lightningRightRc.top + (lightningRightRc.bottom - lightningRightRc.top) / 2 - 402, playerLightningAni);
		//위쪽
		playerSkillLightning->aniRender(getMapDC(), lightningUpRc.left + (lightningUpRc.right - lightningUpRc.left) / 2 - 36,
			lightningUpRc.top + (lightningUpRc.bottom - lightningUpRc.top) / 2 - 402, playerLightningAni);
		//아래쪽
		playerSkillLightning->aniRender(getMapDC(), lightningDownRc.left + (lightningDownRc.right - lightningDownRc.left) / 2 - 36,
			lightningDownRc.top + (lightningDownRc.bottom - lightningDownRc.top) / 2 - 402, playerLightningAni);
		break;
	case SKILL::SKILL_UP:
		//중앙
		playerSkillLightning->aniRender(getMapDC(), lightningCenterRc.left + (lightningCenterRc.right - lightningCenterRc.left) / 2 - 36,
			lightningCenterRc.top + (lightningCenterRc.bottom - lightningCenterRc.top) / 2 - 402, playerLightningAni);
		//왼쪽
		playerSkillLightning->aniRender(getMapDC(), lightningLeftRc.left + (lightningLeftRc.right - lightningLeftRc.left) / 2 - 36,
			lightningLeftRc.top + (lightningLeftRc.bottom - lightningLeftRc.top) / 2 - 402, playerLightningAni);
		//오른쪽
		playerSkillLightning->aniRender(getMapDC(), lightningRightRc.left + (lightningRightRc.right - lightningRightRc.left) / 2 - 36,
			lightningRightRc.top + (lightningRightRc.bottom - lightningRightRc.top) / 2 - 402, playerLightningAni);
		//위쪽
		playerSkillLightning->aniRender(getMapDC(), lightningUpRc.left + (lightningUpRc.right - lightningUpRc.left) / 2 - 36,
			lightningUpRc.top + (lightningUpRc.bottom - lightningUpRc.top) / 2 - 402, playerLightningAni);
		//아래쪽
		playerSkillLightning->aniRender(getMapDC(), lightningDownRc.left + (lightningDownRc.right - lightningDownRc.left) / 2 - 36,
			lightningDownRc.top + (lightningDownRc.bottom - lightningDownRc.top) / 2 - 402, playerLightningAni);
		break;
	case SKILL::SKILL_RIGHT:
		//중앙
		playerSkillLightning->aniRender(getMapDC(), lightningCenterRc.left + (lightningCenterRc.right - lightningCenterRc.left) / 2 - 36,
			lightningCenterRc.top + (lightningCenterRc.bottom - lightningCenterRc.top) / 2 - 402, playerLightningAni);
		//왼쪽
		playerSkillLightning->aniRender(getMapDC(), lightningLeftRc.left + (lightningLeftRc.right - lightningLeftRc.left) / 2 - 36,
			lightningLeftRc.top + (lightningLeftRc.bottom - lightningLeftRc.top) / 2 - 402, playerLightningAni);
		//오른쪽
		playerSkillLightning->aniRender(getMapDC(), lightningRightRc.left + (lightningRightRc.right - lightningRightRc.left) / 2 - 36,
			lightningRightRc.top + (lightningRightRc.bottom - lightningRightRc.top) / 2 - 402, playerLightningAni);
		//위쪽
		playerSkillLightning->aniRender(getMapDC(), lightningUpRc.left + (lightningUpRc.right - lightningUpRc.left) / 2 - 36,
			lightningUpRc.top + (lightningUpRc.bottom - lightningUpRc.top) / 2 - 402, playerLightningAni);
		//아래쪽
		playerSkillLightning->aniRender(getMapDC(), lightningDownRc.left + (lightningDownRc.right - lightningDownRc.left) / 2 - 36,
			lightningDownRc.top + (lightningDownRc.bottom - lightningDownRc.top) / 2 - 402, playerLightningAni);
		break;
	case SKILL::SKILL_DOWN:
		//중앙
		playerSkillLightning->aniRender(getMapDC(), lightningCenterRc.left + (lightningCenterRc.right - lightningCenterRc.left) / 2 - 36,
			lightningCenterRc.top + (lightningCenterRc.bottom - lightningCenterRc.top) / 2 - 402, playerLightningAni);
		//왼쪽
		playerSkillLightning->aniRender(getMapDC(), lightningLeftRc.left + (lightningLeftRc.right - lightningLeftRc.left) / 2 - 36,
			lightningLeftRc.top + (lightningLeftRc.bottom - lightningLeftRc.top) / 2 - 402, playerLightningAni);
		//오른쪽
		playerSkillLightning->aniRender(getMapDC(), lightningRightRc.left + (lightningRightRc.right - lightningRightRc.left) / 2 - 36,
			lightningRightRc.top + (lightningRightRc.bottom - lightningRightRc.top) / 2 - 402, playerLightningAni);
		//위쪽
		playerSkillLightning->aniRender(getMapDC(), lightningUpRc.left + (lightningUpRc.right - lightningUpRc.left) / 2 - 36,
			lightningUpRc.top + (lightningUpRc.bottom - lightningUpRc.top) / 2 - 402, playerLightningAni);
		//아래쪽
		playerSkillLightning->aniRender(getMapDC(), lightningDownRc.left + (lightningDownRc.right - lightningDownRc.left) / 2 - 36,
			lightningDownRc.top + (lightningDownRc.bottom - lightningDownRc.top) / 2 - 402, playerLightningAni);
		break;
	default:
		break;
	}
}

void Cplayer::blockCheck(float speed, RECT* playerRC, DIRECTIONS direct)
{
	RECT rcCollision;
	int tileIndex[2];
	rcCollision = playerMoveRc;

	int tileX;
	int tileY;

	switch (direct)
	{
	case DIRECTIONS::DIRECTIONS_LEFT:
		m_playerX -= this->getSpeed();
		rcCollision = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth()/4, playerMoveDown->getFrameHeight()/2);
		break;
	case DIRECTIONS::DIRECTIONS_UP:
		m_playerY -= this->getSpeed();
		rcCollision = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth() / 4, playerMoveDown->getFrameHeight() / 2);
		break;
	case DIRECTIONS::DIRECTIONS_RIGHT:
		m_playerX += this->getSpeed();
		rcCollision = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth() / 4, playerMoveDown->getFrameHeight() / 2);
		break;
	case DIRECTIONS::DIRECTIONS_DOWN:
		m_playerY += this->getSpeed();
		rcCollision = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth() / 4, playerMoveDown->getFrameHeight() / 2);
		break;
	}

	tileX = rcCollision.left / TILESIZE;
	tileY = (rcCollision.top + TILESIZE) / TILESIZE;

	switch (direct)
	{
	case DIRECTIONS::DIRECTIONS_LEFT:
		tileIndex[0] = tileX + tileY * TILEX;
		tileIndex[1] = tileX + (tileY+1) * TILEX;
		break;
	case DIRECTIONS::DIRECTIONS_UP:
		tileIndex[0] = tileX + tileY * TILEX;
		tileIndex[1] = tileX + 1 + tileY * TILEX;
		break;
	case DIRECTIONS::DIRECTIONS_RIGHT:
		tileIndex[0] = (tileX + tileY * TILEX) + 1;
		tileIndex[1] = (tileX + (tileY + 1) * TILEX) + 1;
		break;
	case DIRECTIONS::DIRECTIONS_DOWN:
		tileIndex[0] = (tileX + tileY * TILEX) + TILEX;
		tileIndex[1] = (tileX + 1 + tileY * TILEX) + TILEX;
		break;
	}

	for (int i = 0; i < 2; i++)
	{
		RECT temp;
		if((m_attribute[tileIndex[i]] == ATTRIBUTE::COLLISION_ON) &&
			IntersectRect(&temp, &m_CheckTile[tileIndex[i]].rc, &rcCollision))
		{
			switch (direct)
			{
			case DIRECTIONS::DIRECTIONS_LEFT:
				playerMoveRc.left = m_CheckTile[tileIndex[i]].rc.right;
				m_playerX = playerMoveRc.left;
				break;
			case DIRECTIONS::DIRECTIONS_UP:
				playerMoveRc.top = m_CheckTile[tileIndex[i]].rc.bottom - (playerMoveRc.bottom - playerMoveRc.top)/2;
				m_playerY = playerMoveRc.top;
				break;
			case DIRECTIONS::DIRECTIONS_RIGHT:
				playerMoveRc.right = m_CheckTile[tileIndex[i]].rc.left;
				m_playerX = playerMoveRc.left;
				break;
			case DIRECTIONS::DIRECTIONS_DOWN:
				playerMoveRc.bottom = m_CheckTile[tileIndex[i]].rc.top;
				m_playerY = playerMoveRc.top;
				break;
			}
			return;
		}
	}
	//Rectangle(getMapDC(), rcCollision.left, rcCollision.top, rcCollision.right, rcCollision.bottom);
	rcCollision = RectMake(m_playerX, m_playerY, TILESIZE, TILESIZE * 2);
	playerMoveRc = rcCollision;
}


void Cplayer::mouseMoveAstar()
{
	///*if (resetMove)
	//{
	//	endCount = m_fastLoadLocation->size() - 1;
	//	startCount = 0;
	//}
	/*while (true)
	{
		auto iter = m_fastLoadLocation->begin();

		if (m_playerX > iter[startCount].x)
			m_playerX += getSpeed();
		else if (m_playerX < iter[startCount].x)
			m_playerX -= getSpeed();

		if (m_playerY > iter[startCount].y)
			m_playerY -= getSpeed();
		else if (m_playerY < iter[startCount].y)
			m_playerY += getSpeed();
	}*/

	// 에이스타 이동 -> 이동할 타일을 리스트에 담음..
	// 리스트 하나씩 이동
}

