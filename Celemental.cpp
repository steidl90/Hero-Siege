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
	m_enemyAttack->init(50,500);

	m_player = new Cplayer;
	m_player->init();

	m_isIdle = false;
	m_state = STATE::DOWN;

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

void Celemental::release()
{
	SAFE_DELETE(m_enemyAttack);
	SAFE_DELETE(m_player);
}

void Celemental::update()
{
	m_player->update();
	m_enemyAttack->update("������Ż��ų�ִ�");

	move();
	attack();
	m_walkRc = RectMakeCenter(m_x, m_y, m_walkImage->getFrameWidth(), m_walkImage->getFrameHeight());
	m_traceRc = RectMakeCenter(m_x, m_y, 500, 500);

}

void Celemental::render()
{
	Rectangle(getMapDC(), m_traceRc.left, m_traceRc.top, m_traceRc.right, m_traceRc.bottom);
	Rectangle(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkRc.right, m_walkRc.bottom);
	m_enemyAttack->render();
	m_walkImage->aniRender(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkAni);
}

void Celemental::move()
{
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerMoveRC(),&m_traceRc))
	{
			if (m_player->getplayerMoveRC()->right >= m_traceRc.left && m_player->getplayerMoveRC()->right < m_walkRc.left)
			{
				if (m_player->getplayerMoveRC()->right < m_walkRc.left - 100) m_x--;
				m_state = STATE::LEFT;
			}
			if (m_player->getplayerMoveRC()->left <= m_traceRc.right && m_player->getplayerMoveRC()->left > m_walkRc.right)
			{
				if(m_player->getplayerMoveRC()->left > m_walkRc.right+100) m_x++;
				m_state = STATE::RIGHT;
			}
			if (m_player->getplayerMoveRC()->bottom >= m_traceRc.top && m_player->getplayerMoveRC()->bottom < m_walkRc.top)
			{
				if(m_player->getplayerMoveRC()->bottom < m_walkRc.top-100)m_y--;
				m_state = STATE::UP;
			}
			if (m_player->getplayerMoveRC()->top <= m_traceRc.bottom && m_player->getplayerMoveRC()->top > m_walkRc.bottom)
			{
				if(m_player->getplayerMoveRC()->top > m_walkRc.bottom+100)m_y++;
				m_state = STATE::DOWN;
		}
	}
	else
	{
		float distance = UTIL::getDistance(m_x, m_y, m_returnX, m_returnY);
		if (distance>1)
		{
			m_x += (m_returnX - m_x) / distance * (m_speed * 0.8);
			m_y += (m_returnY - m_y) / distance * (m_speed * 0.8);
			if (m_x <= m_returnX && abs(m_x - m_returnX) > abs(m_y - m_returnY))
			{
				m_state = STATE::RIGHT;
			}
			if (m_x >= m_returnX && abs(m_x - m_returnX) > abs(m_y - m_returnY))
			{
				m_state = STATE::LEFT;
			}
			if (m_y <= m_returnY && abs(m_x - m_returnX) < abs(m_y - m_returnY))
			{
				m_state = STATE::DOWN;
			}
			if (m_y >= m_returnY && abs(m_x - m_returnX) < abs(m_y - m_returnY))
			{
				m_state = STATE::UP;
			}
		}
		else
		{
			m_x = m_returnX;
			m_y = m_returnY;
		}
	}
	animation();
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

bool Celemental::enemyCooltime()
{
	m_cooltimeCount++;

	if (m_cooltimeCount % m_rndskillCount == 0) 
	{
		m_rndskillCount = 100;
		m_cooltimeCount = 0;
	return true;
	}
	return false;
}

