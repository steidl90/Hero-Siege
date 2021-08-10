#include "framework.h"
#include "CenemyManager.h"

CenemyManager::CenemyManager()
{
}

CenemyManager::~CenemyManager()
{
}

HRESULT CenemyManager::init()
{
	return S_OK;
}

void CenemyManager::release()
{
	SAFE_DELETE(m_enemyAttack);
}

void CenemyManager::update()
{
}

void CenemyManager::render()
{
}

void CenemyManager::setElemental(int setenemy, int x, int y, int distanceX, int distanceY, int pattern)
{
}

void CenemyManager::setPriest(int setenemy, int x, int y, int distanceX, int distanceY, int pattern)
{
}

void CenemyManager::setMonk(int setenemy, int x, int y, int distanceX, int distanceY, int pattern)
{
}

void CenemyManager::setPrison(int setenemy, int x, int y, int distanceX, int distanceY, int pattern)
{
}

void CenemyManager::setSlime(int setenemy, int x, int y, int distanceX, int distanceY, int pattern)
{
}

void CenemyManager::elementalSkill()
{
	//for (m_viElemental = m_vElemental.begin(); m_viElemental != m_vElemental.end(); ++m_viElemental)
	//{
	//	if((_))
	//}
}

void CenemyManager::priestSkill()
{
}

void CenemyManager::monkAttack()
{
}

void CenemyManager::prisonAttack()
{
}

void CenemyManager::slimeAttack()
{
}

void CenemyManager::removeElemental(int arrNum)
{
}

void CenemyManager::removePriest(int arrNum)
{
}

void CenemyManager::removeMonk(int arrNum)
{
}

void CenemyManager::removePrison(int arrNum)
{
}

void CenemyManager::removeSlime(int arrNum)
{
}
