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

<<<<<<< HEAD
	m_time = 0;

	//DIRECTIONS
	direction = DIRECTIONS::DIRECTIONS_DOWN;
	beforeDirection = DIRECTIONS::DIRECTIONS_DOWN;

	//SKILL
	skillState = SKILL::SKILL_IDLE;

	//IMAGE
	playerDown = IMAGE->findImage("«√∑π¿ÃæÓæ∆∑°¬ ");
	playerAttackDown = IMAGE->findImage("«√∑π¿ÃæÓæ∆∑°¬ ∞¯∞›");
	playerMoveDown = IMAGE->findImage("«√∑π¿ÃæÓæ∆∑°¬ ∞»±‚");

	playerLeft = IMAGE->findImage("«√∑π¿ÃæÓøﬁ¬ ");
	playerMoveLeft = IMAGE->findImage("«√∑π¿ÃæÓøﬁ¬ ∞»±‚");
	playerAttackLeft = IMAGE->findImage("«√∑π¿ÃæÓøﬁ¬ ∞¯∞›");

	playerRight = IMAGE->findImage("«√∑π¿ÃæÓø¿∏•¬ ");
	playerMoveRight = IMAGE->findImage("«√∑π¿ÃæÓø¿∏•¬ ∞»±‚");
	playerAttackRight = IMAGE->findImage("«√∑π¿ÃæÓø¿∏•¬ ∞¯∞›");

	playerUp = IMAGE->findImage("«√∑π¿ÃæÓ¿ß¬ ");
	playerMoveUp = IMAGE->findImage("«√∑π¿ÃæÓ¿ß¬ ∞»±‚");
	playerAttackUp = IMAGE->findImage("«√∑π¿ÃæÓ¿ß¬ ∞¯∞›");

	//Ω∫≈≥
	ANIMATION->addDefAnimation("∏Æƒ°Ω∫≈≥æ÷¥œ", "∏Æƒ°Ω∫≈≥", 15, false, true);
	playerSkillLightning = IMAGE->findImage("∂Û¿Ã∆Æ¥◊");

	ANIMATION->addDefAnimation("∂Û¿Ã∆Æ¥◊æ÷¥œ", "∂Û¿Ã∆Æ¥◊", 10, false, true);
	playerLightningAni = ANIMATION->findAnimation("∂Û¿Ã∆Æ¥◊æ÷¥œ");

	//MOVE
	ANIMATION->addDefAnimation("¿ß¬ ∞»±‚", "«√∑π¿ÃæÓ¿ß¬ ∞»±‚", 10, false, true);
	ANIMATION->addDefAnimation("æ∆∑°¬ ∞»±‚", "«√∑π¿ÃæÓæ∆∑°¬ ∞»±‚", 10, false, true);
	ANIMATION->addDefAnimation("øﬁ¬ ∞»±‚", "«√∑π¿ÃæÓøﬁ¬ ∞»±‚", 10, false, true);
	ANIMATION->addDefAnimation("ø¿∏•¬ ∞»±‚", "«√∑π¿ÃæÓø¿∏•¬ ∞»±‚", 10, false, true);

	//IDLE
	ANIMATION->addDefAnimation("¿ß¬ ", "«√∑π¿ÃæÓ¿ß¬ ", 10, false, true);
	ANIMATION->addDefAnimation("æ∆∑°¬ ", "«√∑π¿ÃæÓæ∆∑°¬ ", 10, false, true);
	ANIMATION->addDefAnimation("øﬁ¬ ", "«√∑π¿ÃæÓøﬁ¬ ", 10, false, true);
	ANIMATION->addDefAnimation("ø¿∏•¬ ", "«√∑π¿ÃæÓø¿∏•¬ ", 10, false, true);

	//ATTACK
	ANIMATION->addDefAnimation("¿ß¬ ∞¯∞›", "«√∑π¿ÃæÓ¿ß¬ ∞¯∞›", 20, false, true);
	ANIMATION->addDefAnimation("æ∆∑°¬ ∞¯∞›", "«√∑π¿ÃæÓæ∆∑°¬ ∞¯∞›", 20, false, true);
	ANIMATION->addDefAnimation("øﬁ¬ ∞¯∞›", "«√∑π¿ÃæÓøﬁ¬ ∞¯∞›", 20, false, true);
	ANIMATION->addDefAnimation("ø¿∏•¬ ∞¯∞›", "«√∑π¿ÃæÓø¿∏•¬ ∞¯∞›", 20, false, true);

	//±‚∫ªªÛ≈¬
	playerIdleAni = ANIMATION->findAnimation("æ∆∑°¬ ");
	playerAttackAni = ANIMATION->findAnimation("æ∆∑°¬ ∞¯∞›");
	playerMoveAni = ANIMATION->findAnimation("æ∆∑°¬ ∞»±‚");

	//∑∫∆Æ
	m_playerX = WINSIZEX / 2;
	m_playerY = WINSIZEY / 2;
	playerMoveRc = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth(), playerMoveDown->getFrameHeight());

	return S_OK;
=======
   //DIRECTIONS
   direction= DIRECTIONS::DIRECTIONS_DOWN;
   beforeDirection= DIRECTIONS::DIRECTIONS_DOWN;

   //IMAGE
   playerDown= IMAGE->findImage("«√∑π¿ÃæÓæ∆∑°¬ ");
   playerAttackDown= IMAGE->findImage("«√∑π¿ÃæÓæ∆∑°¬ ∞¯∞›");
   playerMoveDown = IMAGE->findImage("«√∑π¿ÃæÓæ∆∑°¬ ∞»±‚");

   playerLeft=IMAGE->findImage("«√∑π¿ÃæÓøﬁ¬ ");
   playerMoveLeft=IMAGE->findImage("«√∑π¿ÃæÓøﬁ¬ ∞»±‚");
   playerAttackLeft=IMAGE->findImage("«√∑π¿ÃæÓøﬁ¬ ∞¯∞›");

   playerRight=IMAGE->findImage("«√∑π¿ÃæÓø¿∏•¬ ");
   playerMoveRight=IMAGE->findImage("«√∑π¿ÃæÓø¿∏•¬ ∞»±‚");
   playerAttackRight=IMAGE->findImage("«√∑π¿ÃæÓø¿∏•¬ ∞¯∞›");

   playerUp=IMAGE->findImage("«√∑π¿ÃæÓ¿ß¬ ");
   playerMoveUp=IMAGE->findImage("«√∑π¿ÃæÓ¿ß¬ ∞»±‚");
   playerAttackUp=IMAGE->findImage("«√∑π¿ÃæÓ¿ß¬ ∞¯∞›");

   ANIMATION->addDefAnimation("∏Æƒ°Ω∫≈≥æ÷¥œ", "∏Æƒ°Ω∫≈≥", 15, false, true);



    //MOVE
   ANIMATION->addDefAnimation("¿ß¬ ∞»±‚", "«√∑π¿ÃæÓ¿ß¬ ∞»±‚",10, false, true);
   ANIMATION->addDefAnimation("æ∆∑°¬ ∞»±‚", "«√∑π¿ÃæÓæ∆∑°¬ ∞»±‚",10, false, true);
   ANIMATION->addDefAnimation("øﬁ¬ ∞»±‚", "«√∑π¿ÃæÓøﬁ¬ ∞»±‚",10, false, true);
   ANIMATION->addDefAnimation("ø¿∏•¬ ∞»±‚", "«√∑π¿ÃæÓø¿∏•¬ ∞»±‚", 10, false, true);

    //IDLE
   ANIMATION->addDefAnimation("¿ß¬ ", "«√∑π¿ÃæÓ¿ß¬ ", 10, false, true);
   ANIMATION->addDefAnimation("æ∆∑°¬ ", "«√∑π¿ÃæÓæ∆∑°¬ ", 10, false, true);
   ANIMATION->addDefAnimation("øﬁ¬ ", "«√∑π¿ÃæÓøﬁ¬ ", 10, false, true);
   ANIMATION->addDefAnimation("ø¿∏•¬ ", "«√∑π¿ÃæÓø¿∏•¬ ", 10, false, true);

    //ATTACK
   ANIMATION->addDefAnimation("¿ß¬ ∞¯∞›", "«√∑π¿ÃæÓ¿ß¬ ∞¯∞›", 20, false, true);
   ANIMATION->addDefAnimation("æ∆∑°¬ ∞¯∞›", "«√∑π¿ÃæÓæ∆∑°¬ ∞¯∞›", 20, false, true);
   ANIMATION->addDefAnimation("øﬁ¬ ∞¯∞›", "«√∑π¿ÃæÓøﬁ¬ ∞¯∞›", 20, false, true);
   ANIMATION->addDefAnimation("ø¿∏•¬ ∞¯∞›", "«√∑π¿ÃæÓø¿∏•¬ ∞¯∞›", 20, false, true);

   //±‚∫ªªÛ≈¬
   playerIdleAni = ANIMATION->findAnimation("æ∆∑°¬ ");
   playerAttackAni = ANIMATION->findAnimation("æ∆∑°¬ ∞¯∞›");
   playerMoveAni = ANIMATION->findAnimation("æ∆∑°¬ ∞»±‚");
   
   //∑∫∆Æ
   m_playerX = WINSIZEX / 2;
   m_playerY = WINSIZEY / 2;
   playerMoveRc = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth(), playerMoveDown->getFrameHeight());
   playerAttackRc = RectMake(m_playerX, m_playerY, 100, 100);
  
   return S_OK;
>>>>>>> parent of 35abb8d (Î™¨Ïä§ÌÑ∞ ÏµúÏ¢Ö)
}

void Cplayer::release()
{
	SAFE_DELETE(m_playerSkill);
}

void Cplayer::update()
{
	//Rectangle(getMapDC(), playerAttackRc.left, playerAttackRc.top, playerAttackRc.right, playerAttackRc.bottom);
	ANIMATION->resume("∂Û¿Ã∆Æ¥◊æ÷¥œ");
	m_angle += 0.4;
	moveControl();
	playerMoveRc = RectMake(m_playerX, m_playerY, playerMoveDown->getFrameWidth() - 90, playerMoveDown->getFrameHeight() - 50);
	m_playerSkill->update("∏Æƒ°Ω∫≈≥æ÷¥œ");
}

void Cplayer::render()
{
	playerSkillControl();
	playerSkillRender();
	playerStateRender();
	m_playerSkill->render();
	if (isAttack) isAttackRender();
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
	else
	{
		isAttack = false;
		playerAttackRc = RectMake(-100, -100, 0, 0); //¿”Ω√? ¥ı ¡¡¿∫ πÊπ˝ ¿÷¿∏∏È πŸ≤‹ øπ¡§
	}

	if (InputManager->isOnceKeyDown('Q'))
	{
		isAttack = true;
		if (direction == DIRECTIONS::DIRECTIONS_LEFT)m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, PI, 7.0f, 700, "∏Æƒ°Ω∫≈≥", "∏Æƒ°Ω∫≈≥æ÷¥œ");
		else if (direction == DIRECTIONS::DIRECTIONS_RIGHT)m_playerSkill->skillInformation(m_playerX + 50, m_playerY + 33, PI2, 7.0f, 700, "∏Æƒ°Ω∫≈≥", "∏Æƒ°Ω∫≈≥æ÷¥œ");
		else if (direction == DIRECTIONS::DIRECTIONS_UP)m_playerSkill->skillInformation(m_playerX + 15, m_playerY - 20, PI * 0.5, 7.0f, 700, "∏Æƒ°Ω∫≈≥", "∏Æƒ°Ω∫≈≥æ÷¥œ");
		else if (direction == DIRECTIONS::DIRECTIONS_DOWN)m_playerSkill->skillInformation(m_playerX, m_playerY, PI * 1.5, 7.0f, 700, "∏Æƒ°Ω∫≈≥", "∏Æƒ°Ω∫≈≥æ÷¥œ");
	}
	else if (InputManager->isOnceKeyDown('W'))
	{
		isAttack = true;
		for (size_t i = 0; i < 30; i++)
		{
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.21, 7.0f, 350, "∏Æƒ°Ω∫≈≥", "∏Æƒ°Ω∫≈≥æ÷¥œ");
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.22, 6.0f, 300, "∏Æƒ°Ω∫≈≥", "∏Æƒ°Ω∫≈≥æ÷¥œ");
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.26, 5.0f, 250, "∏Æƒ°Ω∫≈≥", "∏Æƒ°Ω∫≈≥æ÷¥œ");
			m_playerSkill->skillInformation(m_playerX - 15, m_playerY + 33, (i + m_angle) * 0.65, 4.3f, 200, "∏Æƒ°Ω∫≈≥", "∏Æƒ°Ω∫≈≥æ÷¥œ");
		}
	}
	else if (InputManager->isStayKeyDown('E') && m_count == 0)
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

	//¿”Ω√ ∑π∫ßæ˜
	if (getExp() >= 100)
	{
		setExp(0);
		setLv(getLv() + 1);
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
			playerMoveAni = ANIMATION->findAnimation("øﬁ¬ ∞»±‚");
			ANIMATION->start("øﬁ¬ ∞»±‚");
			playerAttackAni = ANIMATION->findAnimation("øﬁ¬ ∞¯∞›");
			ANIMATION->start("øﬁ¬ ∞¯∞›");
			isIdle = false;
		}
		break;
	case DIRECTIONS::DIRECTIONS_UP:
		if (isMoving)
		{
			playerMoveAni = ANIMATION->findAnimation("¿ß¬ ∞»±‚");
			ANIMATION->start("¿ß¬ ∞»±‚");
			playerAttackAni = ANIMATION->findAnimation("¿ß¬ ∞¯∞›");
			ANIMATION->start("¿ß¬ ∞¯∞›");
			isIdle = false;
		}
		break;
	case DIRECTIONS::DIRECTIONS_RIGHT:
		if (isMoving)
		{
			playerMoveAni = ANIMATION->findAnimation("ø¿∏•¬ ∞»±‚");
			ANIMATION->start("ø¿∏•¬ ∞»±‚");
			playerAttackAni = ANIMATION->findAnimation("ø¿∏•¬ ∞¯∞›");
			ANIMATION->start("ø¿∏•¬ ∞¯∞›");
			isIdle = false;
		}
		break;
	case DIRECTIONS::DIRECTIONS_DOWN:
		if (isMoving)
		{
			playerMoveAni = ANIMATION->findAnimation("æ∆∑°¬ ∞»±‚");
			ANIMATION->start("æ∆∑°¬ ∞»±‚");
			playerAttackAni = ANIMATION->findAnimation("æ∆∑°¬ ∞¯∞›");
			ANIMATION->start("æ∆∑°¬ ∞¯∞›");
			isIdle = false;
		}
		break;
	}
}

void Cplayer::playerStateRender()
{
	//Rectangle(getMapDC(), playerMoveRc.left, playerMoveRc.top, playerMoveRc.right, playerMoveRc.bottom);
	if (!isAttack)
	{
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
					playerIdleAni = ANIMATION->findAnimation("øﬁ¬ ");
					ANIMATION->start("øﬁ¬ ");
					isIdle = true;
				}
				break;
			case DIRECTIONS::DIRECTIONS_UP:
				playerUp->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 4, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("¿ß¬ ");
					ANIMATION->start("¿ß¬ ");
					isIdle = true;
				}
				break;
			case DIRECTIONS::DIRECTIONS_RIGHT:
				playerRight->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 3, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("ø¿∏•¬ ");
					ANIMATION->start("ø¿∏•¬ ");
					isIdle = true;
				}
				break;
			case DIRECTIONS::DIRECTIONS_DOWN:
				playerDown->aniRender(getMapDC(), playerMoveRc.left - 39, playerMoveRc.top - 3, playerIdleAni);
				if (!isIdle)
				{
					playerIdleAni = ANIMATION->findAnimation("æ∆∑°¬ ");
					ANIMATION->start("æ∆∑°¬ ");
					isIdle = true;
				}
				break;
			}
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

		//playerLightningAni = ANIMATION->findAnimation("∂Û¿Ã∆Æ¥◊æ÷¥œ");
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
		//¡ﬂæ”
		playerSkillLightning->aniRender(getMapDC(), lightningCenterRc.left + (lightningCenterRc.right - lightningCenterRc.left) / 2 - 36,
			lightningCenterRc.top + (lightningCenterRc.bottom - lightningCenterRc.top) / 2 - 402, playerLightningAni);
		//øﬁ¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningLeftRc.left + (lightningLeftRc.right - lightningLeftRc.left) / 2 - 36,
			lightningLeftRc.top + (lightningLeftRc.bottom - lightningLeftRc.top) / 2 - 402, playerLightningAni);
		//ø¿∏•¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningRightRc.left + (lightningRightRc.right - lightningRightRc.left) / 2 - 36,
			lightningRightRc.top + (lightningRightRc.bottom - lightningRightRc.top) / 2 - 402, playerLightningAni);
		//¿ß¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningUpRc.left + (lightningUpRc.right - lightningUpRc.left) / 2 - 36,
			lightningUpRc.top + (lightningUpRc.bottom - lightningUpRc.top) / 2 - 402, playerLightningAni);
		//æ∆∑°¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningDownRc.left + (lightningDownRc.right - lightningDownRc.left) / 2 - 36,
			lightningDownRc.top + (lightningDownRc.bottom - lightningDownRc.top) / 2 - 402, playerLightningAni);
		break;
	case SKILL::SKILL_UP:
		//¡ﬂæ”
		playerSkillLightning->aniRender(getMapDC(), lightningCenterRc.left + (lightningCenterRc.right - lightningCenterRc.left) / 2 - 36,
			lightningCenterRc.top + (lightningCenterRc.bottom - lightningCenterRc.top) / 2 - 402, playerLightningAni);
		//øﬁ¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningLeftRc.left + (lightningLeftRc.right - lightningLeftRc.left) / 2 - 36,
			lightningLeftRc.top + (lightningLeftRc.bottom - lightningLeftRc.top) / 2 - 402, playerLightningAni);
		//ø¿∏•¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningRightRc.left + (lightningRightRc.right - lightningRightRc.left) / 2 - 36,
			lightningRightRc.top + (lightningRightRc.bottom - lightningRightRc.top) / 2 - 402, playerLightningAni);
		//¿ß¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningUpRc.left + (lightningUpRc.right - lightningUpRc.left) / 2 - 36,
			lightningUpRc.top + (lightningUpRc.bottom - lightningUpRc.top) / 2 - 402, playerLightningAni);
		//æ∆∑°¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningDownRc.left + (lightningDownRc.right - lightningDownRc.left) / 2 - 36,
			lightningDownRc.top + (lightningDownRc.bottom - lightningDownRc.top) / 2 - 402, playerLightningAni);
		break;
	case SKILL::SKILL_RIGHT:
		//¡ﬂæ”
		playerSkillLightning->aniRender(getMapDC(), lightningCenterRc.left + (lightningCenterRc.right - lightningCenterRc.left) / 2 - 36,
			lightningCenterRc.top + (lightningCenterRc.bottom - lightningCenterRc.top) / 2 - 402, playerLightningAni);
		//øﬁ¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningLeftRc.left + (lightningLeftRc.right - lightningLeftRc.left) / 2 - 36,
			lightningLeftRc.top + (lightningLeftRc.bottom - lightningLeftRc.top) / 2 - 402, playerLightningAni);
		//ø¿∏•¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningRightRc.left + (lightningRightRc.right - lightningRightRc.left) / 2 - 36,
			lightningRightRc.top + (lightningRightRc.bottom - lightningRightRc.top) / 2 - 402, playerLightningAni);
		//¿ß¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningUpRc.left + (lightningUpRc.right - lightningUpRc.left) / 2 - 36,
			lightningUpRc.top + (lightningUpRc.bottom - lightningUpRc.top) / 2 - 402, playerLightningAni);
		//æ∆∑°¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningDownRc.left + (lightningDownRc.right - lightningDownRc.left) / 2 - 36,
			lightningDownRc.top + (lightningDownRc.bottom - lightningDownRc.top) / 2 - 402, playerLightningAni);
		break;
	case SKILL::SKILL_DOWN:
		//¡ﬂæ”
		playerSkillLightning->aniRender(getMapDC(), lightningCenterRc.left + (lightningCenterRc.right - lightningCenterRc.left) / 2 - 36,
			lightningCenterRc.top + (lightningCenterRc.bottom - lightningCenterRc.top) / 2 - 402, playerLightningAni);
		//øﬁ¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningLeftRc.left + (lightningLeftRc.right - lightningLeftRc.left) / 2 - 36,
			lightningLeftRc.top + (lightningLeftRc.bottom - lightningLeftRc.top) / 2 - 402, playerLightningAni);
		//ø¿∏•¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningRightRc.left + (lightningRightRc.right - lightningRightRc.left) / 2 - 36,
			lightningRightRc.top + (lightningRightRc.bottom - lightningRightRc.top) / 2 - 402, playerLightningAni);
		//¿ß¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningUpRc.left + (lightningUpRc.right - lightningUpRc.left) / 2 - 36,
			lightningUpRc.top + (lightningUpRc.bottom - lightningUpRc.top) / 2 - 402, playerLightningAni);
		//æ∆∑°¬ 
		playerSkillLightning->aniRender(getMapDC(), lightningDownRc.left + (lightningDownRc.right - lightningDownRc.left) / 2 - 36,
			lightningDownRc.top + (lightningDownRc.bottom - lightningDownRc.top) / 2 - 402, playerLightningAni);
		break;
	default:
		break;
	}
}


//void Cplayer::mouseMoveAstar()
//{
//	/*if (resetMove)
//	{
//		endCount = m_fastLoadLocation->size() - 1;
//		startCount = 0;
//	}
//	while (true)
//	{
//		
//		auto iter = m_fastLoadLocation->begin();
//
//		if (m_playerX > iter[startCount].x)
//			m_playerX += m_speed;
//		else if (m_playerX < iter[startCount].x)
//			m_playerX -= m_speed;
//
//		if (m_playerY > iter[startCount].y)
//			m_playerY -= m_speed;
//		else if (m_playerY < iter[startCount].y)
//			m_playerY += m_speed;
//
//	}*/
//
//	// ø°¿ÃΩ∫≈∏ ¿Ãµø -> ¿Ãµø«“ ≈∏¿œ¿ª ∏ÆΩ∫∆Æø° ¥„¿Ω..
//	// ∏ÆΩ∫∆Æ «œ≥™æø ¿Ãµø

