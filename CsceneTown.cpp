#include "framework.h"
#include "CsceneTown.h"

CsceneTown::CsceneTown() :m_timerHp(NULL), m_timerMp(NULL)
{
}

CsceneTown::~CsceneTown()
{
}

HRESULT CsceneTown::init()
{
	m_wingImage = IMAGE->findImage("Ç³Â÷³¯°³");
	ANIMATION->addDefAnimation("Ç³Â÷", "Ç³Â÷³¯°³", 10, false, true);
	m_wingAni = ANIMATION->findAnimation("Ç³Â÷");
	ANIMATION->start("Ç³Â÷");

	m_wingX[0] = 575;
	m_wingY[0] = 200;

	m_camera = new camera;
	m_camera->init();

	m_town = new Ctown;
	m_town->setCameraMemory(m_camera);
	m_town->init();

	m_player = new CplayerManager;
	m_player->init();
	m_player->setCheckTile(m_town->getMap());
	m_player->setTileAttribute(m_town->getAttribute());

	m_player->getPlayer()->setAtk(DATA->getAtk());
	m_player->getPlayer()->setCritical(DATA->getCritical());
	m_player->getPlayer()->setCriticalAtk(DATA->getCriticalAtk());
	m_player->getPlayer()->setDef(DATA->getDef());
	m_player->getPlayer()->setExp(DATA->getExp());
	m_player->getPlayer()->setGold(DATA->getGold());
	m_player->getPlayer()->setHp(DATA->getHp());
	m_player->getPlayer()->setMaxHp(DATA->getMaxHp());
	m_player->getPlayer()->setMp(DATA->getMp());
	m_player->getPlayer()->setMaxMp(DATA->getMaxMp());
	m_player->getPlayer()->setLv(DATA->getLv());
	m_player->getPlayer()->setSpeed(DATA->getSpeed());
	m_player->getPlayer()->setPlayerX(DATA->getX());
	m_player->getPlayer()->setPlayerY(DATA->getY());

	m_player->getInventoryMemory()->setEquipItem(DATA->getEquipItem());
	m_player->getInventoryMemory()->setvWeaponList(DATA->getvWeaponList());
	m_player->getInventoryMemory()->setvArmorList(DATA->getvArmorList());
	m_player->getInventoryMemory()->setvShoesList(DATA->getvShoesList());
	m_player->getInventoryMemory()->setvGlovesList(DATA->getvGlovesList());
	m_player->getInventoryMemory()->setvPendantList(DATA->getvPendantList());

	m_aStar = new CaStar;
	m_aStar->setCameraMemory(m_camera);
	m_aStar->setPlayer(m_player->getPlayer());
	m_aStar->setAttribute(m_town->getAttribute());
	m_aStar->init();

	m_shop = new Cshop;
	m_shop->setInventoryMemory(m_player->getInventoryMemory());
	m_shop->setPlayerMemory(m_player->getPlayer());
	m_shop->init();
	

	m_shopUi = new CshopUi;
	//m_shopUi->setInventoryMemory(m_player->getInventoryMemory());
	//m_shopUi->setPlayerMemory(m_player->getPlayer());
	m_shopUi->setShopMemory(m_shop);
	m_shopUi->init();

	m_changeRect = RectMake(MAPSIZE - 10, MAPSIZE * 0.25 + 120, 100, 100);

	m_shopRect = RectMake(310, 230, IMAGE->findImage("NPC¿¡¸¯")->getFrameWidth() * 2, IMAGE->findImage("NPC¿¡¸¯")->getFrameHeight() * 2);
	m_npcRect = RectMake(WINSIZEX/2 , WINSIZEY/2, 100, 100);

	m_npc = new CNPC;
	m_npc->init();
	isShopOn = false;
	isNpcCollison = false;
	return S_OK;
}

void CsceneTown::release()
{
	SAFE_DELETE(m_camera);
	SAFE_DELETE(m_town);
	SAFE_DELETE(m_player);
	SAFE_DELETE(m_aStar);
	SAFE_DELETE(m_shop);
	SAFE_DELETE(m_shopUi);
	SAFE_DELETE(m_npc);
}

void CsceneTown::update()
{
	m_aStar->update();
	m_aStar->setPlayerIndex(PointMake(m_player->getplayerRect()->left / TILESIZE, m_player->getplayerRect()->top / TILESIZE));
	m_camera->update();
	m_camera->setTargetPoint(PointMake(m_player->getplayerRect()->left, m_player->getplayerRect()->top));
	m_town->update();
	m_town->setFastLoadIndex(m_aStar->getFastLoad());
	m_player->update();
	m_player->setFastLoadLocation(m_aStar->getFastLoadLocation());
	//NPC
	m_npc->update();

	if (isShopOn) m_shopUi->update();

	shopOn();

	npcCollison();

	//Ã¼·Â ¸®Á¨
	if (m_player->getPlayer()->getHp() < m_player->getPlayer()->getMaxHp())
	{
		if (m_timerHp + 3 < TIME->getWorldTime())
		{
			m_player->getPlayer()->setHp(m_player->getPlayer()->getHp() + 10);
			m_timerHp = TIME->getWorldTime();
		}
	}
	else if (m_player->getPlayer()->getHp() > m_player->getPlayer()->getMaxHp())
	{
		m_player->getPlayer()->setHp(m_player->getPlayer()->getMaxHp());
	}

	//¸¶³ª ¸®Á¨
	if (m_player->getPlayer()->getMp() < m_player->getPlayer()->getMaxMp())
	{
		if (m_timerMp + 3 < TIME->getWorldTime())
		{
			m_player->getPlayer()->setMp(m_player->getPlayer()->getMp() + 5);
			m_timerMp = TIME->getWorldTime();
		}
	}
	else if (m_player->getPlayer()->getMp() > m_player->getPlayer()->getMaxMp())
	{
		m_player->getPlayer()->setMp(m_player->getPlayer()->getMaxMp());
	}

	sceneChange();
	m_wingRect = RectMakeCenter(m_wingX[0], m_wingY[0], m_wingImage->getFrameWidth(), m_wingImage->getFrameHeight());
}

void CsceneTown::render()
{
	this->getMapBuffer()->render(getMemDC(), 0, 0, m_camera->getCameraPoint().x, m_camera->getCameraPoint().y, m_camera->getCameraWidth(), m_camera->getCameraHeight());
	this->getMapBuffer()->mapRender(getMemDC(), WINSIZEX - IMAGE->findImage("MiniMapUi")->getWidth(), 70);

	m_camera->render();
	m_town->render();
	//NPC
	m_npc->render();
	m_player->render();

	if (isShopOn) m_shopUi->render();


	if (isNpcCollison)
	{
		Rectangle(getMemDC(), m_npcRect.left, m_npcRect.top, m_npcRect.right, m_npcRect.bottom);
	}
	m_wingImage->aniRender(getMapDC(), m_wingX[0]-10, m_wingY[0]-10, m_wingAni);
	TCHAR str[256];
	sprintf_s(str, "ÀÌ³ë¾ß ¸¶À»");
	TextOut(getMemDC(), WINSIZEX - 165, 20, str, strlen(str));

}

void CsceneTown::sceneChange()
{
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerRect(), &m_changeRect))
	{
		DATA->setData(m_player->getPlayer()->getAtk(),
			m_player->getPlayer()->getDef(),
			m_player->getPlayer()->getHp(),
			m_player->getPlayer()->getMaxHp(),
			m_player->getPlayer()->getMp(),
			m_player->getPlayer()->getMaxMp(),
			m_player->getPlayer()->getCritical(),
			m_player->getPlayer()->getLv(),
			m_player->getPlayer()->getExp(),
			m_player->getPlayer()->getGold(),
			m_player->getPlayer()->getCriticalAtk(),
			m_player->getPlayer()->getSpeed(),
			m_player->getPlayer()->getPlayerX(),
			m_player->getPlayer()->getPlayerY());
		DATA->setEquipItem(m_player->getInventoryMemory()->getEquipItem());
		DATA->setvWeaponList(m_player->getInventoryMemory()->getvWeaponList());
		DATA->setvArmorList(m_player->getInventoryMemory()->getvArmorList());
		DATA->setvShoesList(m_player->getInventoryMemory()->getvShoesList());
		DATA->setvGlovesList(m_player->getInventoryMemory()->getvGlovesList());
		DATA->setvPendantList(m_player->getInventoryMemory()->getvPendantList());

		SCENE->changeScene("´øÀü");
	}
}

void CsceneTown::shopOn()
{
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerRect(), &m_shopRect))
	{
		if (InputManager->isOnceKeyDown('P'))
		{
			isShopOn = !isShopOn;
		}
	}
	else
	{
		isShopOn = false;
	}
	//isShopOn = true;
}

void CsceneTown::npcCollison()
{
	if (InputManager->isOnceKeyDown('B'))
	{
		RECT temp;
		if (IntersectRect(&temp, m_player->getplayerRect(), m_npc->getGaNorRect())||
		IntersectRect(&temp, m_player->getplayerRect(), m_npc->getShopKeeperRect())||
		IntersectRect(&temp, m_player->getplayerRect(), m_npc->getBlackMarketRect())||
		IntersectRect(&temp, m_player->getplayerRect(), m_npc->getEdwardRect())||
		IntersectRect(&temp, m_player->getplayerRect(), m_npc->getEricRect())||
		IntersectRect(&temp, m_player->getplayerRect(), m_npc->getHalsteinRect())||
		IntersectRect(&temp, m_player->getplayerRect(), m_npc->getKaylaRect())||
		IntersectRect(&temp, m_player->getplayerRect(), m_npc->getSarcasterRect())||
		IntersectRect(&temp, m_player->getplayerRect(), m_npc->getTorsteinRect())||
		IntersectRect(&temp, m_player->getplayerRect(), m_npc->getWitchRect()))
		{
			isNpcCollison = !isNpcCollison;
		}
	}
}


