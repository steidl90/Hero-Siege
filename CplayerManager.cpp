#include "framework.h"
#include "CplayerManager.h"
#include "CenemyManager.h"
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

    m_InventoryUI->setPlayerMemory(m_player);
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
        this->showPlayerStat();
    }
}

void CplayerManager::showPlayerStat()
{
    vector<Citem*> equipSet;
    if(m_inventory->getEquipWeapon() != nullptr) equipSet.push_back(m_inventory->getEquipWeapon());
    if (m_inventory->getEquipArmor() != nullptr) equipSet.push_back(m_inventory->getEquipArmor());
    if (m_inventory->getEquipShoes() != nullptr) equipSet.push_back(m_inventory->getEquipShoes());
    if (m_inventory->getEquipGloves() != nullptr) equipSet.push_back(m_inventory->getEquipGloves());
    if (m_inventory->getEquipPendant() != nullptr) equipSet.push_back(m_inventory->getEquipPendant());
   
    int itemAtk = 0;
    int itemDef = 0;
    int itemHp = 0;
    int itemMp = 0;
    int itemCri = 0;
    float itemCriAtk = 0;
    float itemSpeed = 0;

    for (auto iter = equipSet.begin(); iter != equipSet.end(); ++iter)
    {
        itemAtk += (*iter)->getAtk();
        itemDef += (*iter)->getDef();
        itemHp += (*iter)->getHp();
        itemMp += (*iter)->getMp();
        itemCri += (*iter)->getCritical();
        itemCriAtk += (*iter)->getCriticalAtk();
        itemSpeed += (*iter)->getSpeed();
    }
    // 인벤토리창 옮길거면 좌표값도 UI것 해줘야한다, 현재는 임시

    TCHAR str[100];
    wsprintf(str, "Atk: %d + %d", m_player->getAtk() - itemAtk, itemAtk);
    TextOut(getMemDC(), WINSIZEX / 2 + 210, 330, str, lstrlen(str));
    wsprintf(str, "Def: %d + %d", m_player->getDef() - itemDef, itemDef);
    TextOut(getMemDC(), WINSIZEX / 2 + 210, 350, str, lstrlen(str));
    wsprintf(str, "Hp: %d + %d", m_player->getHp() - itemHp, itemHp);
    TextOut(getMemDC(), WINSIZEX / 2 + 210, 370, str, lstrlen(str));
    wsprintf(str, "Mp: %d + %d", m_player->getMp() - itemMp, itemMp);
    TextOut(getMemDC(), WINSIZEX / 2 + 210, 390, str, lstrlen(str)); 
    wsprintf(str, "Critical: %d + %d", m_player->getCritical() - itemCri, itemCri);
    TextOut(getMemDC(), WINSIZEX / 2 + 210, 410, str, lstrlen(str));
    sprintf(str, "CriAtk: %.1f + %.1f", m_player->getCriticalAtk() - itemCriAtk, itemCriAtk);
    TextOut(getMemDC(), WINSIZEX / 2 + 210, 430, str, lstrlen(str));
    sprintf(str, "Speed: %.1f + %.1f", m_player->getSpeed() - itemSpeed, itemSpeed);
    TextOut(getMemDC(), WINSIZEX / 2 + 210, 450, str, lstrlen(str));

}

void CplayerManager::itemStatSet()
{
 /*   vector<Citem*> equipSet;
    if (m_inventory->getEquipWeapon() != nullptr) equipSet.push_back(m_inventory->getEquipWeapon());
    if (m_inventory->getEquipArmor() != nullptr) equipSet.push_back(m_inventory->getEquipArmor());
    if (m_inventory->getEquipShoes() != nullptr) equipSet.push_back(m_inventory->getEquipShoes());
    if (m_inventory->getEquipGloves() != nullptr) equipSet.push_back(m_inventory->getEquipGloves());
    if (m_inventory->getEquipPendant() != nullptr) equipSet.push_back(m_inventory->getEquipPendant());

    int itemAtk = 0;
    int itemDef = 0;
    int itemHp = 0;
    int itemMp = 0;
    int itemCri = 0;
    int itemCriAtk = 0;
    int itemSpeed = 0;

    for (auto iter = equipSet.begin(); iter != equipSet.end(); ++iter)
    {
        itemAtk += (*iter)->getAtk();
        itemDef += (*iter)->getDef();
        itemHp += (*iter)->getHp();
        itemMp += (*iter)->getMp();
        itemCri += (*iter)->getCritical();
        itemCriAtk += (*iter)->getCriticalAtk();
        itemSpeed += (*iter)->getSpeed();
    }

    m_player->setAtk(m_player->getAtk() + itemAtk);
    m_player->setDef(m_player->getDef() + itemDef);
    m_player->setHp(m_player->getHp() + itemHp);
    m_player->setMp(m_player->getMp() + itemMp);
    m_player->setCritical(m_player->getCritical() + itemCri);
    m_player->setCriticalAtk(m_player->getCriticalAtk() + itemCriAtk);
    m_player->setSpeed(m_player->getSpeed() + itemSpeed);
*/

}

void CplayerManager::collisionEnemy()
{
    RECT temp;
    char atk[100];
    auto iter = m_enemy->getEnemy()->begin();
    int i = 0;

    for (iter; iter != m_enemy->getEnemy()->end(); ++iter, i++)
    {
        if (IntersectRect(&temp, m_player->getPlayerAttackRC(), &(*iter)->getRect()))
        {
            (*iter)->setHp((*iter)->getHp() - m_player->getAtk());
            wsprintf(atk, "%d", m_player->getAtk());
            TextOut(getMapDC(), (*iter)->getRect().left + ((*iter)->getRect().right - (*iter)->getRect().left) / 2, (*iter)->getRect().top, atk, lstrlen(atk));
            
            if ((*iter)->getHp() <= 0)
            {
                m_player->setExp(m_player->getExp() + (*iter)->getExp());
                m_enemy->removeMinion(i);
                break;
            }
        }
    }
}
