#include "framework.h"
#include "Celemental.h"
#include "CenemyAttack.h"
#include "Cplayer.h"

Celemental::Celemental()
{
}

Celemental::~Celemental()
{
}

HRESULT Celemental::init(POINT position, int HP)
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(50,500,"ø§∏Æ∏‡≈ªΩ∫≈≥æ÷¥œ");

	m_player = new Cplayer;
	m_player->init();

	m_isWalking = true;
	m_state = STATE::DOWN;
	m_distance = 100;
	m_x = m_returnX = position.x;
	m_y = m_returnY = position.y;

	m_speed = 2.0f;
	m_hp = HP;

	m_cooltimeCount = 0;
	m_rndskillCount = 1;

	ANIMATION->addAnimation("ø§∏Æ∏‡≈ª«œ", "ø§∏Æ∏‡≈ª", 0, 3, 8, false, true);
	ANIMATION->addAnimation("ø§∏Æ∏‡≈ª¡¬", "ø§∏Æ∏‡≈ª", 4, 7, 8, false, true);
	ANIMATION->addAnimation("ø§∏Æ∏‡≈ªøÏ", "ø§∏Æ∏‡≈ª", 8, 11, 8, false, true);
	ANIMATION->addAnimation("ø§∏Æ∏‡≈ªªÛ", "ø§∏Æ∏‡≈ª", 12, 15, 8, false, true);
	
	m_walkImage = IMAGE->findImage("ø§∏Æ∏‡≈ª");
	m_walkAni = ANIMATION->findAnimation("ø§∏Æ∏‡≈ª«œ");
	ANIMATION->start("ø§∏Æ∏‡≈ª«œ");
	return S_OK;
}


void Celemental::attack()
{
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerMoveRC(), &m_traceRc))
	{
		if (enemyCooltime()) 
		{
				m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
				m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top)/2,
				UTIL::getAngle(m_walkRc.left + (m_walkRc.right - m_walkRc.left) / 2,
				m_walkRc.bottom + (m_walkRc.top - m_walkRc.bottom) / 2,
				m_player->getplayerMoveRC()->left + (m_player->getplayerMoveRC()->right - m_player->getplayerMoveRC()->left) / 2,
				m_player->getplayerMoveRC()->top+(m_player->getplayerMoveRC()->bottom - m_player->getplayerMoveRC()->top) / 2),
				5.0f, "ø§∏Æ∏‡≈ªΩ∫≈≥", "ø§∏Æ∏‡≈ªΩ∫≈≥æ÷¥œ");
		}
	}
}

void Celemental::animation()
{
	switch (m_state)
	{
	case STATE::LEFT:
		m_walkImage = IMAGE->findImage("ø§∏Æ∏‡≈ª");
		m_walkAni = ANIMATION->findAnimation("ø§∏Æ∏‡≈ª¡¬");
		ANIMATION->resume("ø§∏Æ∏‡≈ª¡¬");
		break;
	case STATE::RIGHT:
		m_walkImage = IMAGE->findImage("ø§∏Æ∏‡≈ª");
		m_walkAni = ANIMATION->findAnimation("ø§∏Æ∏‡≈ªøÏ");
		ANIMATION->resume("ø§∏Æ∏‡≈ªøÏ");
		break;
	case STATE::UP:
		m_walkImage = IMAGE->findImage("ø§∏Æ∏‡≈ª");
		m_walkAni = ANIMATION->findAnimation("ø§∏Æ∏‡≈ªªÛ");
		ANIMATION->resume("ø§∏Æ∏‡≈ªªÛ");
		break;
	case STATE::DOWN:
		m_walkImage = IMAGE->findImage("ø§∏Æ∏‡≈ª");
		m_walkAni = ANIMATION->findAnimation("ø§∏Æ∏‡≈ª«œ");
		ANIMATION->resume("ø§∏Æ∏‡≈ª«œ");
		break;
	}
}





