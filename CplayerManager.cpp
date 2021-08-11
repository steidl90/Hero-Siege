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
    m_playerUi->setPlayerMemoryLink(m_player);
    m_playerUi->init();

    m_inventory = new Cinventory;
    m_inventory->init();

    m_InventoryUI = new CinventoryUi;
    m_InventoryUI->setInventoryMemory(m_inventory);
    m_InventoryUI->init();

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
    m_playerUi->update();
    m_playerSkill->update("리치스킬애니");
}

void CplayerManager::render()
{
    m_player->render();
    m_playerUi->render();

    if (isInventoryOn)
    {
        m_InventoryUI->render();
        TCHAR str[100];
        wsprintf(str, "Atk : %d", m_player->getAtk());
        TextOut(getMemDC(), WINSIZEX / 2 + 210, WINSIZEY / 2 - 80, str, lstrlen(str));
        wsprintf(str, "Def : %d", m_player->getDef());
        TextOut(getMemDC(), WINSIZEX / 2 + 210, WINSIZEY / 2 - 60, str, lstrlen(str));
        wsprintf(str, "Hp : %d", m_player->getHp());
        TextOut(getMemDC(), WINSIZEX / 2 + 210, WINSIZEY / 2 - 40, str, lstrlen(str));
        wsprintf(str, "Mp : %d", m_player->getMp());
        TextOut(getMemDC(), WINSIZEX / 2 + 210, WINSIZEY / 2 - 20, str, lstrlen(str));
    }
}
