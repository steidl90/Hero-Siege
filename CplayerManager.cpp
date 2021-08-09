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

    m_playerUi = new CplayerUi;

    return S_OK;
}

void CplayerManager::release()
{
    SAFE_DELETE(m_player);
    SAFE_DELETE(m_playerUi);
}

void CplayerManager::update()
{
    m_player->update();
}

void CplayerManager::render()
{
    m_player->render();
    m_playerUi->render();
}
