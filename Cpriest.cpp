#include "framework.h"
#include "Cpriest.h"
#include "CenemyAttack.h"
#include "Cplayer.h"

Cpriest::Cpriest()
{
}

Cpriest::~Cpriest()
{
}

HRESULT Cpriest::init(POINT position, float HP, float damage, float exp,float trace)
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(50, 500, false, "리치스킬애니");

	m_player = new Cplayer;
	m_player->init();

	m_isIdle = false;
	m_state = STATE::DOWN;

	m_x = m_returnX = position.x;
	m_y = m_returnY = position.y;
	m_trace = trace;

	m_distance = 100.0f;
	m_speed = 2.0f;
	m_hp = HP;
	m_damage = damage;
	m_exp = exp;

	m_cooltimeCount = 260;
	m_rndskillCount = 259;

	m_isWalking = true;
	m_isDie = false;

	ANIMATION->addAnimation("리치하", "리치", 0, 5, 8, false, true);
	ANIMATION->addAnimation("리치좌", "리치", 6, 11, 8, false, true);
	ANIMATION->addAnimation("리치우", "리치", 12, 17, 8, false, true);
	ANIMATION->addAnimation("리치상", "리치", 18, 23, 8, false, true);

	ANIMATION->addAnimation("리치공격하", "리치공격", 0, 15, 8,	true, true);
	ANIMATION->addAnimation("리치공격좌", "리치공격", 16, 31, 8,	true, true);
	ANIMATION->addAnimation("리치공격우", "리치공격", 32, 47, 8,  true, true);
	ANIMATION->addAnimation("리치공격상", "리치공격", 48, 63, 8,  true, true);

	ANIMATION->addAnimation("리치사망하", "리치사망", 0, 9, 8, false, false);
	ANIMATION->addAnimation("리치사망좌", "리치사망", 10, 19, 8, false, false);
	ANIMATION->addAnimation("리치사망우", "리치사망", 20, 29, 8, false, false);
	ANIMATION->addAnimation("리치사망상", "리치사망", 30, 39, 8, false, false);

	m_walkImage = IMAGE->findImage("리치");
	m_walkAni = ANIMATION->findAnimation("리치하");
	ANIMATION->start("리치하");
	return S_OK;
}

void Cpriest::release()
{
	SAFE_DELETE(m_enemyAttack);
	SAFE_DELETE(m_player);
}

void Cpriest::update()
{
	m_enemyAttack->update();
	move();
	attack();
	die();
	if (m_walkImage != nullptr)
	{
		m_walkRc = RectMakeCenter(m_x, m_y, m_walkImage->getFrameWidth(), m_walkImage->getFrameHeight());
	}
	m_traceRc = RectMakeCenter(m_x, m_y, m_trace, m_trace);
}

void Cpriest::render()
{
	if (InputManager->isToggleKey(VK_TAB))
	{
		Rectangle(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkRc.right, m_walkRc.bottom);
		Rectangle(getMapDC(), m_traceRc.left, m_traceRc.top, m_traceRc.right, m_traceRc.bottom);
		Rectangle(getMapDC(), m_dieRc.left, m_dieRc.top, m_dieRc.right, m_dieRc.bottom);
	}
	if (m_isWalking)m_walkImage->aniRender(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkAni);
	m_enemyAttack->render();
}

void Cpriest::attack()
{
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerMoveRC(), &m_traceRc))
	{
		m_cooltimeCount++;

		if (m_state == STATE::LEFT)
		{
			m_walkImage = IMAGE->findImage("리치공격");
			m_walkAni = ANIMATION->findAnimation("리치공격좌");
			ANIMATION->fullstart("리치공격좌");
			fire();

		}
		if (m_state == STATE::RIGHT)
		{
			m_walkImage = IMAGE->findImage("리치공격");
			m_walkAni = ANIMATION->findAnimation("리치공격우");
			ANIMATION->fullstart("리치공격우");
			fire();

		}
		if (m_state == STATE::UP)
		{
			m_walkImage = IMAGE->findImage("리치공격");
			m_walkAni = ANIMATION->findAnimation("리치공격상");
			ANIMATION->fullstart("리치공격상");
			fire();
		}
		if (m_state == STATE::DOWN)
		{
			m_walkImage = IMAGE->findImage("리치공격");
			m_walkAni = ANIMATION->findAnimation("리치공격하");
			ANIMATION->fullstart("리치공격하");
			fire();

		}
	}
}

void Cpriest::die()
{
	if (m_hp <= 0)
	{
		if (m_state == STATE::LEFT)
		{

		}
		if (m_state == STATE::RIGHT)
		{

		}
		if (m_state == STATE::UP)
		{

		}
		if (m_state == STATE::DOWN)
		{

		}
	}
}

void Cpriest::animation()
{
	switch (m_state)
	{
	case STATE::LEFT:
		m_walkImage = IMAGE->findImage("리치");
		m_walkAni = ANIMATION->findAnimation("리치좌");
		ANIMATION->resume("리치좌");
		break;
	case STATE::RIGHT:
		m_walkImage = IMAGE->findImage("리치");
		m_walkAni = ANIMATION->findAnimation("리치우");
		ANIMATION->resume("리치우");
		break;
	case STATE::UP:
		m_walkImage = IMAGE->findImage("리치");
		m_walkAni = ANIMATION->findAnimation("리치상");
		ANIMATION->resume("리치상");
		break;
	case STATE::DOWN:
		m_walkImage = IMAGE->findImage("리치");
		m_walkAni = ANIMATION->findAnimation("리치하");
		ANIMATION->resume("리치하");
		break;
	}
}

bool Cpriest::enemyCooltime()
{

	if (m_cooltimeCount % m_rndskillCount == 0)
	{
		m_rndskillCount = 100;
		m_cooltimeCount = 0;
		return true;
	}
	return false;
}

void Cpriest::fire()
{
	if (enemyCooltime()) {
		m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
			m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top) / 2,
			UTIL::getAngle(m_walkRc.left + (m_walkRc.right - m_walkRc.left) / 2,
				m_walkRc.bottom + (m_walkRc.top - m_walkRc.bottom) / 2,
				m_player->getplayerMoveRC()->left + (m_player->getplayerMoveRC()->right - m_player->getplayerMoveRC()->left) / 2,
				m_player->getplayerMoveRC()->top + (m_player->getplayerMoveRC()->bottom - m_player->getplayerMoveRC()->top) / 2),
			5.0f, "리치스킬", "리치스킬애니");
	}
}
