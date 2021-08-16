#include "framework.h"
#include "CplayerManager.h"
#include "CenemyManager.h"
#include "Cmevius.h"
CplayerManager::CplayerManager()
{
}

CplayerManager::~CplayerManager()
{
}


HRESULT CplayerManager::init()
{
    EFFECT->addEffect("히트1", "images/Hit.bmp", 414, 71, 69, 71, 1, 0.2f, 5);

    m_player = new Cplayer;
    m_player->init();

    m_playerUi = new CplayerUi;
    m_playerUi->setPlayerMemoryLink(m_player);
    m_playerUi->init();

    m_inventory = new Cinventory;
    m_inventory->init();

    m_InventoryUI = new CinventoryUi;
    m_InventoryUI->setInventoryMemory(m_inventory);

    m_InventoryUI->setPlayerMemory(m_player);
    m_InventoryUI->init();

    m_dropItem = new CdropItem;
    m_dropItem->init();

    isInventoryOn = false;
    return S_OK;
}

void CplayerManager::release()
{
    SAFE_DELETE(m_player);
    SAFE_DELETE(m_playerUi);
    SAFE_DELETE(m_inventory);
    SAFE_DELETE(m_InventoryUI);
    SAFE_DELETE(m_dropItem);
}

void CplayerManager::update()
{
    if (InputManager->isOnceKeyDown('I')) isInventoryOn = !isInventoryOn;
    EFFECT->update();
    m_playerUi->update();
    m_player->update();
    if(m_fastLoadLocation != nullptr)
        m_player->setAstarMove(m_fastLoadLocation);
    if(isInventoryOn) m_InventoryUI->update();

    getItem();
}

void CplayerManager::render()
{
    m_dropItem->render();
    m_player->render();
    m_playerUi->render();
    EFFECT->render();
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
            (*iter)->setHp((*iter)->getHp() - (m_player->getAtk() - (*iter)->getDef()));
            wsprintf(atk, "%d", (m_player->getAtk() - (*iter)->getDef()));
            TextOut(getMapDC(), (*iter)->getRect().left + ((*iter)->getRect().right - (*iter)->getRect().left) / 2, (*iter)->getRect().top, atk, lstrlen(atk));

            EFFECT->play("히트1", (*iter)->getRect().left + ((*iter)->getRect().right - (*iter)->getRect().left) / 2 + RND->getFromIntTo(0, 30),
                (*iter)->getRect().top + ((*iter)->getRect().bottom - (*iter)->getRect().top) / 2 + RND->getFromIntTo(0, 30));
        }

        for (int j = 0; j < m_player->getSkill()->getvSkill().size(); j++)
        {
            if (IntersectRect(&temp, &m_player->getSkill()->getvSkill()[j].m_skillRc, &(*iter)->getRect()))
            {
                (*iter)->setHp((*iter)->getHp() - (m_player->getAtk() - (*iter)->getDef()));
                //m_player->getSkill()->removeSkill(j);
                EFFECT->play("히트1", (*iter)->getRect().left + ((*iter)->getRect().right - (*iter)->getRect().left) / 2 + RND->getFromIntTo(0, 30),
                    (*iter)->getRect().top + ((*iter)->getRect().bottom - (*iter)->getRect().top) / 2 + RND->getFromIntTo(0, 30));
            }
        }

        if ((*iter)->getHp() <= 0)
        {
            m_player->setExp(m_player->getExp() + (*iter)->getExp());
            // 여기서 아이템 드랍
            m_dropItem->makeItem((*iter)->getX(), (*iter)->getY());
            m_enemy->removeMinion(i);
            break;
        }
    }

    RECT tempBoss;
    if (IntersectRect(&tempBoss, m_player->getPlayerAttackRC(), m_boss->getRect()))
    {
        m_boss->setHp(m_boss->getHp() - m_player->getAtk());
        
        EFFECT->play("히트1", m_boss->getRect()->left + (m_boss->getRect()->right - m_boss->getRect()->left) / 2 + RND->getFromIntTo(0, 30),
            m_boss->getRect()->top + (m_boss->getRect()->bottom - m_boss->getRect()->top) / 2 + RND->getFromIntTo(0, 30));
    }

    for (int j = 0; j < m_player->getSkill()->getvSkill().size(); j++)
    {
        if (IntersectRect(&tempBoss, &m_player->getSkill()->getvSkill()[j].m_skillRc, m_boss->getRect()))
        {
            m_boss->setHp(m_boss->getHp() - m_player->getAtk());
            //m_player->getSkill()->removeSkill(j);
            EFFECT->play("히트1", m_boss->getRect()->left + (m_boss->getRect()->right - m_boss->getRect()->left) / 2 + RND->getFromIntTo(0, 30),
                m_boss->getRect()->top + (m_boss->getRect()->bottom - m_boss->getRect()->top) / 2 + RND->getFromIntTo(0, 30));
        }
    }

    if (m_boss->getHp() <= 0)
    {
        PostQuitMessage(0);
    }
    
}

void CplayerManager::getItem()
{
    RECT temp;
    for (int i = 0; i < m_dropItem->getDropItemList().size(); i++)
    {
        if (IntersectRect(&temp, m_player->getplayerMoveRC(), &m_dropItem->getDropItemList()[i].itemRect))
        {
            if (InputManager->isOnceKeyDown('Z'))
            {
                m_inventory->addItem(m_dropItem->getDropItemList()[i].item);

                m_dropItem->removeItem(i);
            }
        }
    }
}
