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

    m_inventory = new Cinventory;
    m_inventory->init();

    m_InventoryUI = new CinventoryUi;
    m_InventoryUI->init();
    m_InventoryUI->setInventoryMemory(m_inventory);

    isInventoryOn = false;
    return S_OK;
}

void CplayerManager::release()
{
    SAFE_DELETE(m_player);
    SAFE_DELETE(m_playerSkill);
    SAFE_DELETE(m_playerUi);
    SAFE_DELETE(m_inventory);
    SAFE_DELETE(m_InventoryUI);
}

void CplayerManager::update()
{
    if (InputManager->isOnceKeyDown('I')) isInventoryOn = !isInventoryOn;

    m_player->update();
    if(isInventoryOn) m_InventoryUI->update();
    m_playerSkill->update("리치스킬애니");

    m_player->setFastLoadLocation(m_fastLoadLocation);

}

void CplayerManager::render()
{
    m_player->render();
    m_playerUi->render();

    if(isInventoryOn) m_InventoryUI->render();
}
