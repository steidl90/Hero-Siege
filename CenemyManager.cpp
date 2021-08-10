#include "framework.h"
#include "CenemyManager.h"
#include "Celemental.h"

CenemyManager::CenemyManager(){}
CenemyManager::~CenemyManager(){}

HRESULT CenemyManager::init()
{
	return S_OK;
}

void CenemyManager::release(){}

void CenemyManager::update()
{
	for (int i = 0; i < m_vEnemy.size(); i++)
	{
		m_vEnemy[i]->update();
	}
}

void CenemyManager::render()
{
	for (int i = 0; i < m_vEnemy.size(); i++)
	{
		m_vEnemy[i]->render();
	}
}

void CenemyManager::registerEnemy(Cenemy* enemy)
{
	m_vEnemy.push_back(enemy);
}

void CenemyManager::removeMinion(int arrNum)
{
	m_vEnemy.erase(m_vEnemy.begin() + arrNum);
}

void CenemyManager::collision()
{
	for (size_t i = 0; i < m_vEnemy.size(); i++)
	{
		if (m_vEnemy[i]->m_enemyAttack)
		{
			for (size_t j = 0; j < m_vEnemy[i]->m_enemyAttack->getVSkill().size(); j++)
			{
				RECT rc;
				if (IntersectRect(&rc, &m_vEnemy[i]->m_enemyAttack->getVSkill()[j].m_rc, m_player->getplayerMoveRC()))
				{
					m_vEnemy[i]->m_enemyAttack->removeSkill(j);
				}
			}
		}
		
	}
}
