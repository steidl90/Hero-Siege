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

HRESULT Cenemy::init(POINT position, int HP)
{
    return S_OK;
}

void Cenemy::release()
{
	SAFE_DELETE(m_enemyAttack);
	SAFE_DELETE(m_player);
}

void Cenemy::update()
{
	m_enemyAttack->update();
	move();
	attack();
	m_walkRc = RectMakeCenter(m_x, m_y, m_walkImage->getFrameWidth(), m_walkImage->getFrameHeight());
	m_traceRc = RectMakeCenter(m_x, m_y, 500, 500);
}

void Cenemy::render()
{
	if (InputManager->isToggleKey(VK_TAB))
	{
		Rectangle(getMapDC(), m_traceRc.left, m_traceRc.top, m_traceRc.right, m_traceRc.bottom);
		Rectangle(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkRc.right, m_walkRc.bottom);
		Rectangle(getMapDC(), m_attackRc.left, m_attackRc.top, m_attackRc.right, m_attackRc.bottom);
		Rectangle(getMapDC(), m_dieRc.left, m_dieRc.top, m_dieRc.right, m_dieRc.bottom);
	}
	if (m_isWalking)m_walkImage->aniRender(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkAni);
	if (m_isAttack)m_attackImage->aniRender(getMapDC(), m_attackRc.left, m_attackRc.top, m_attackAni);
	if (m_isDie)m_dieImage->aniRender(getMapDC(), m_dieRc.left, m_dieRc.top, m_dieAni);
	m_enemyAttack->render();
}

void Cenemy::move()
{
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerMoveRC(), &m_traceRc))
	{
		if (m_player->getplayerMoveRC()->right >= m_traceRc.left && m_player->getplayerMoveRC()->right < m_walkRc.left)
		{
			if (m_player->getplayerMoveRC()->right < m_walkRc.left - m_distance) m_x--;
			m_state = STATE::LEFT;
		}
		if (m_player->getplayerMoveRC()->left <= m_traceRc.right && m_player->getplayerMoveRC()->left > m_walkRc.right)
		{
			if (m_player->getplayerMoveRC()->left > m_walkRc.right + m_distance) m_x++;
			m_state = STATE::RIGHT;
		}
		if (m_player->getplayerMoveRC()->bottom >= m_traceRc.top && m_player->getplayerMoveRC()->bottom < m_walkRc.top)
		{
			if (m_player->getplayerMoveRC()->bottom < m_walkRc.top - m_distance)m_y--;
			m_state = STATE::UP;
		}
		if (m_player->getplayerMoveRC()->top <= m_traceRc.bottom && m_player->getplayerMoveRC()->top > m_walkRc.bottom)
		{
			if (m_player->getplayerMoveRC()->top > m_walkRc.bottom + m_distance)m_y++;
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

void Cenemy::attack()
{
}

void Cenemy::die()
{
}

void Cenemy::animation()
{

}

//bool Cenemy::enemyCooltime()
//{
//	m_cooltimeCount++;
//
//	if (m_cooltimeCount % m_rndskillCount == 0)
//	{
//		m_rndskillCount = 100;
//		m_cooltimeCount = 0;
//		return true;
//	}
//	return false;
//}

bool Cenemy::enemyCooltime()
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