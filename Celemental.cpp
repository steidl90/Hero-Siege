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
	m_enemyAttack->init(50,500,"������Ż��ų�ִ�");

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

	ANIMATION->addAnimation("������Ż��", "������Ż", 0, 3, 8, false, true);
	ANIMATION->addAnimation("������Ż��", "������Ż", 4, 7, 8, false, true);
	ANIMATION->addAnimation("������Ż��", "������Ż", 8, 11, 8, false, true);
	ANIMATION->addAnimation("������Ż��", "������Ż", 12, 15, 8, false, true);
	
	m_walkImage = IMAGE->findImage("������Ż");
	m_walkAni = ANIMATION->findAnimation("������Ż��");
	ANIMATION->start("������Ż��");
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
				5.0f, "������Ż��ų", "������Ż��ų�ִ�");
		}
	}
}

void Celemental::animation()
{
	switch (m_state)
	{
	case STATE::LEFT:
		m_walkImage = IMAGE->findImage("������Ż");
		m_walkAni = ANIMATION->findAnimation("������Ż��");
		ANIMATION->resume("������Ż��");
		break;
	case STATE::RIGHT:
		m_walkImage = IMAGE->findImage("������Ż");
		m_walkAni = ANIMATION->findAnimation("������Ż��");
		ANIMATION->resume("������Ż��");
		break;
	case STATE::UP:
		m_walkImage = IMAGE->findImage("������Ż");
		m_walkAni = ANIMATION->findAnimation("������Ż��");
		ANIMATION->resume("������Ż��");
		break;
	case STATE::DOWN:
		m_walkImage = IMAGE->findImage("������Ż");
		m_walkAni = ANIMATION->findAnimation("������Ż��");
		ANIMATION->resume("������Ż��");
		break;
	}
}





