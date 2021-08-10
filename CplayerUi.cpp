#include "framework.h"
#include "CplayerUi.h"
#include "Cplayer.h"

CplayerUi::CplayerUi()
{
}

CplayerUi::~CplayerUi()
{
}

HRESULT CplayerUi::init()
{
	/*m_hpBar = new CprogressBar;
	m_hpBar->init("images/progressBarFront.bmp", "images/progressBarBack.bmp", 50, 100, 100, 10);
	m_hpBar->setGauge(m_player->getHp(), m_player->getMaxHp());*/

	return S_OK;
}

void CplayerUi::release()
{
	//SAFE_DELETE(m_hpBar);
}

void CplayerUi::update()
{
	/*m_hpBar->setX(49);
	m_hpBar->setY(23);

	m_hpBar->setGauge(m_player->getHp(), m_player->getMaxHp());
	m_hpBar->update();*/
}

void CplayerUi::render()
{
	//m_hpBar->render();
	IMAGE->findImage("SkillUi")->render(getMemDC(), 0, (WINSIZEY - 39) - IMAGE->findImage("SkillUi")->getHeight());
	IMAGE->findImage("StateUi")->render(getMemDC(), 0, 0);
	IMAGE->findImage("MiniMapUi")->render(getMemDC(), (WINSIZEX - 15) - IMAGE->findImage("MiniMapUi")->getWidth(), 0);
}
