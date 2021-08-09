#include "framework.h"
#include "CplayerManager.h"

CplayerManager::CplayerManager()
{
}

CplayerManager::~CplayerManager()
{
}

HRESULT CplayerManager::init()
{
    m_player = new Cplayer;
    m_player->init();

    m_playerSkill = new CplayerSkill;
    m_playerUi = new CplayerUi;

    return S_OK;
}

void CplayerManager::release()
{
    SAFE_DELETE(m_player);
    SAFE_DELETE(m_playerSkill);
    SAFE_DELETE(m_playerUi);
}

void CplayerManager::update()
{
    m_player->update();
    m_playerSkill->update("리치스킬애니");
}

void CplayerManager::render()
{
    m_player->render();
    m_playerUi->render();
}
