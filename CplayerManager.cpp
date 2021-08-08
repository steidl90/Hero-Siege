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

    return S_OK;
}

void CplayerManager::release()
{
    SAFE_DELETE(m_player);
}

void CplayerManager::update()
{
    m_player->update();
}

void CplayerManager::render()
{
    m_player->render();
}
