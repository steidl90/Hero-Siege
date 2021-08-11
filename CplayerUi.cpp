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
	m_hpBar = new CprogressBar;
	m_hpBar->init("images/hp.bmp", "images/hp_back.bmp", 80, 20, 238, 10);
	m_hpBar->setGauge(m_player->getHp(), m_player->getMaxHp());

	m_mpBar = new CprogressBar;
	m_mpBar->init("images/mp.bmp", "images/hp_back.bmp", 80, 40, 196, 10);
	m_mpBar->setGauge(m_player->getMp(),m_player->getMaxMp());

	return S_OK;
}

void CplayerUi::release()
{
	SAFE_DELETE(m_hpBar);
	SAFE_DELETE(m_mpBar);
}

void CplayerUi::update()
{
	m_mpBar->update();
	m_mpBar->setGauge(m_player->getMp(), m_player->getMaxMp());

	m_hpBar->update();
	m_hpBar->setGauge(m_player->getHp(), m_player->getMaxHp());

}

void CplayerUi::render()
{
	m_hpBar->render();
	m_mpBar->render();
	IMAGE->findImage("SkillUi")->render(getMemDC(), 0, (WINSIZEY - 39) - IMAGE->findImage("SkillUi")->getHeight());
	IMAGE->findImage("StateUi")->render(getMemDC(), 0, 0);
	IMAGE->findImage("MiniMapUi")->render(getMemDC(), (WINSIZEX - 15) - IMAGE->findImage("MiniMapUi")->getWidth(), 0);
}
