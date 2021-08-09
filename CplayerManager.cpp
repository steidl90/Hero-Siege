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

    m_Inventory = new CinventoryUi;
    m_Inventory->init();

    isInventoryOn = false;
    return S_OK;
}

void CplayerManager::release()
{
    SAFE_DELETE(m_player);
    SAFE_DELETE(m_playerSkill);
    SAFE_DELETE(m_playerUi);
    SAFE_DELETE(m_Inventory);
}

void CplayerManager::update()
{
    if (InputManager->isOnceKeyDown('I')) isInventoryOn = !isInventoryOn;

    m_player->update();
    if(isInventoryOn) m_Inventory->update();
    m_playerSkill->update("리치스킬애니");
}

void CplayerManager::render()
{
    m_player->render();
    m_playerUi->render();

    if(isInventoryOn) m_Inventory->render();
}
