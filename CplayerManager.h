#pragma once
#include "Cunit.h"
#include "Cplayer.h"
#include "CplayerAttack.h"
#include "camera.h"
#include "CplayerUi.h"
#include "CinventoryUi.h"
#include "CdropItem.h"

class CaStar;
class CenemyManager;
class Cmevius;
class CplayerManager :public Cunit
{
private:
	camera* m_camera;
	Cplayer* m_player;
	CplayerUi* m_playerUi;
	CinventoryUi* m_InventoryUI;
	Cinventory* m_inventory;
	CenemyManager* m_enemy;
	Cmevius* m_boss;
	CdropItem* m_dropItem;
	int m_deathCount;
private:
	
	vector<POINT>* m_fastLoadLocation;

	bool isInventoryOn;

	int m_timer;
public:
	CplayerManager();
	~CplayerManager();

	HRESULT init();
	void release();
	void update();
	void render();

	RECT* getplayerRect() { return m_player->getplayerMoveRC(); }

	Cplayer* getPlayer() { return m_player; }

	void setFastLoadLocation(vector<POINT>* vp) { m_fastLoadLocation = vp; }

	Cinventory* getInventoryMemory() { return m_inventory; }

	void showPlayerStat();

	// Ãß°¡
	void setEnemyMemory(CenemyManager* enemy) { m_enemy = enemy; }
	void setBossMemory(Cmevius* boss) { m_boss = boss; }

	void collisionEnemy();
	void getItem();

	void setCheckTile(tagTile* tile) { m_player->setCheckTile(tile); }
	void setTileAttribute(ATTRIBUTE* att) { m_player->setAttribute(att); }

	CdropItem* getDropItem() { return m_dropItem; }
};