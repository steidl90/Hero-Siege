#include "framework.h"
#include "Cenemy.h"
#include "Cplayer.h"
#include "CenemyAttack.h"
Cenemy::Cenemy()
{
}

Cenemy::~Cenemy()
{
}

HRESULT Cenemy::init(POINT position, float HP, float damage, float exp, float trace)
{

    return S_OK;
}

void Cenemy::release()
{

}

void Cenemy::update()
{

}

void Cenemy::render()
{

}

void Cenemy::move()
{
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerMoveRC(), &m_traceRc))
	{
		if (m_player->getplayerMoveRC()->right >= m_traceRc.left && m_player->getplayerMoveRC()->right < m_walkRc.left)
		{
			if (m_player->getplayerMoveRC()->right < m_walkRc.left - m_distance) m_x--;
			m_isWalking = true;
			m_state = STATE::LEFT;
		}
		if (m_player->getplayerMoveRC()->left <= m_traceRc.right && m_player->getplayerMoveRC()->left > m_walkRc.right)
		{
			if (m_player->getplayerMoveRC()->left > m_walkRc.right + m_distance) m_x++;
			m_isWalking = true;
			m_state = STATE::RIGHT;
		}
		if (m_player->getplayerMoveRC()->bottom >= m_traceRc.top && m_player->getplayerMoveRC()->bottom < m_walkRc.top)
		{
			if (m_player->getplayerMoveRC()->bottom < m_walkRc.top - m_distance)m_y--;
			m_isWalking = true;
			m_state = STATE::UP;
		}
		if (m_player->getplayerMoveRC()->top <= m_traceRc.bottom && m_player->getplayerMoveRC()->top > m_walkRc.bottom)
		{
			if (m_player->getplayerMoveRC()->top > m_walkRc.bottom + m_distance)m_y++;
			m_isWalking = true;
			m_state = STATE::DOWN;
		}
	}
	else
	{
		float distance = UTIL::getDistance(m_x, m_y, m_returnX, m_returnY);
		if (distance > 1)
		{
			m_x += (m_returnX - m_x) / distance * (m_speed * 0.8);
			m_y += (m_returnY - m_y) / distance * (m_speed * 0.8);
			if (m_x <= m_returnX && abs(m_x - m_returnX) > abs(m_y - m_returnY))
			{
				m_isWalking = true;
				m_state = STATE::RIGHT;
			}
			if (m_x >= m_returnX && abs(m_x - m_returnX) > abs(m_y - m_returnY))
			{
				m_isWalking = true;

				m_state = STATE::LEFT;
			}
			if (m_y <= m_returnY && abs(m_x - m_returnX) < abs(m_y - m_returnY))
			{
				m_isWalking = true;

				m_state = STATE::DOWN;
			}
			if (m_y >= m_returnY && abs(m_x - m_returnX) < abs(m_y - m_returnY))
			{
				m_isWalking = true;

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

void Cenemy::attack()
{
}

void Cenemy::die()
{
}

void Cenemy::animation()
{

}

bool Cenemy::enemyCooltime()
{
	return false;
}

void Cenemy::ReturnIdleAnimation()
{
}

