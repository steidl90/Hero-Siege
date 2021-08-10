#include "framework.h"
#include "Cmonk.h"
#include "CenemyAttack.h"
#include "Cplayer.h"

Cmonk::Cmonk()
{
}

Cmonk::~Cmonk()
{
}

HRESULT Cmonk::init(POINT position, int HP)
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(50, 500, "郡府膏呕胶懦局聪");

	m_player = new Cplayer;
	m_player->init();

	m_isIdle = false;
	m_state = STATE::DOWN;

	m_x = m_returnX = position.x;
	m_y = m_returnY = position.y;

	m_distance = 10.0f;
	m_speed = 2.0f;
	m_hp = HP;

	m_cooltimeCount = 0;
	m_rndskillCount = 1;

	m_isWalking = true;
	m_isAttack = false;
	m_isDie = false;

	ANIMATION->addAnimation("根农窍", "根农", 0, 5, 8, false, true);
	ANIMATION->addAnimation("根农谅", "根农", 6, 11, 8, false, true);
	ANIMATION->addAnimation("根农快", "根农", 12, 17, 8, false, true);
	ANIMATION->addAnimation("根农惑", "根农", 18, 23, 8, false, true);

	ANIMATION->addAnimation("根农傍拜窍", "根农傍拜", 0, 4, 8,	true, false);
	ANIMATION->addAnimation("根农傍拜谅", "根农傍拜", 5, 9, 8,	true, false);
	ANIMATION->addAnimation("根农傍拜快", "根农傍拜", 10, 14, 8,	true, false);
	ANIMATION->addAnimation("根农傍拜惑", "根农傍拜", 15, 19, 8,	true, false);

	ANIMATION->addAnimation("根农荤噶窍", "根农荤噶", 0, 11, 8, false,  false);
	ANIMATION->addAnimation("根农荤噶谅", "根农荤噶", 12, 23, 8, false, false);
	ANIMATION->addAnimation("根农荤噶快", "根农荤噶", 24, 35, 8, false, false);
	ANIMATION->addAnimation("根农荤噶惑", "根农荤噶", 36, 47, 8, false, false);

	m_walkImage = IMAGE->findImage("根农");
	m_walkAni = ANIMATION->findAnimation("根农窍");
	ANIMATION->start("根农窍");
	return S_OK;
}

void Cmonk::attack()
{

}

void Cmonk::die()
{
}

void Cmonk::animation()
{
	switch (m_state)
	{
	case STATE::LEFT:
		m_walkImage = IMAGE->findImage("根农");
		m_walkAni = ANIMATION->findAnimation("根农谅");
		ANIMATION->resume("根农谅");
		m_attackImage = IMAGE->findImage("根农傍拜");
		m_attackAni = ANIMATION->findAnimation("根农傍拜谅");
		ANIMATION->start("根农傍拜谅");
		m_dieImage = IMAGE->findImage("根农荤噶");
		m_dieAni = ANIMATION->findAnimation("根农荤噶谅");
		ANIMATION->resume("根农荤噶谅");
		break;
	case STATE::RIGHT:
		m_walkImage = IMAGE->findImage("根农");
		m_walkAni = ANIMATION->findAnimation("根农快");
		ANIMATION->resume("根农快");
		m_attackImage = IMAGE->findImage("根农傍拜快");
		m_attackAni = ANIMATION->findAnimation("根农傍拜快");
		ANIMATION->start("根农傍拜快");
		m_dieImage = IMAGE->findImage("根农荤噶");
		m_dieAni = ANIMATION->findAnimation("根农荤噶快");
		ANIMATION->resume("根农荤噶快");
		break;
	case STATE::UP:
		m_walkImage = IMAGE->findImage("根农");
		m_walkAni = ANIMATION->findAnimation("根农惑");
		ANIMATION->resume("根农惑");
		m_attackImage = IMAGE->findImage("根农傍拜");
		m_attackAni = ANIMATION->findAnimation("根农傍拜惑");
		ANIMATION->start("根农傍拜惑");
		m_dieImage = IMAGE->findImage("根农荤噶");
		m_dieAni = ANIMATION->findAnimation("根农荤噶惑");
		ANIMATION->resume("根农荤噶惑");
		break;
	case STATE::DOWN:
		m_walkImage = IMAGE->findImage("根农");
		m_walkAni = ANIMATION->findAnimation("根农窍");
		ANIMATION->resume("根农窍");
		m_attackImage = IMAGE->findImage("根农傍拜");
		m_attackAni = ANIMATION->findAnimation("根农傍拜窍");
		ANIMATION->start("根农傍拜窍");
		m_dieImage = IMAGE->findImage("根农荤噶");
		m_dieAni = ANIMATION->findAnimation("根农荤噶窍");
		ANIMATION->resume("根农荤噶窍");
		break;
	}
}


