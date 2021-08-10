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
    SAFE_DELETE(m_playerUi);
    SAFE_DELETE(m_InventoryUI);
}

void CplayerManager::update()
{
    if (InputManager->isOnceKeyDown('I')) isInventoryOn = !isInventoryOn;

    m_player->update();

    if(isInventoryOn) m_InventoryUI->update();
}

void CplayerManager::render()
{
    m_player->render();
    m_playerUi->render();

    if(isInventoryOn) m_InventoryUI->render();
}
