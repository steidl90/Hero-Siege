#pragma once
#include "Cunit.h"
#include "Cplayer.h"
#include "CplayerAttack.h"
#include "CplayerSkill.h"
#include "camera.h"
#include "CplayerUi.h"
#include "CinventoryUi.h"

class CaStar;
class CenemyManager;
class CplayerManager :public Cunit
{
private:
	camera* m_camera;
	Cplayer* m_player;
	CplayerSkill* m_playerSkill;
	CplayerUi* m_playerUi;
	CinventoryUi* m_InventoryUI;
	Cinventory* m_inventory;
	CenemyManager* m_enemy;
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

	void itemStatSet();

	// Ãß°¡
	void setEnemyMemory(CenemyManager* enemy) { m_enemy = enemy; }

	void collisionEnemy();

	void setCheckTile(tagTile* tile) { m_player->setCheckTile(tile); }
	void setTileAttribute(ATTRIBUTE* att) { m_player->setAttribute(att); }
};