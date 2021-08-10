#pragma once
#include "Cunit.h"
#include "Cplayer.h"
#include "CplayerAttack.h"
#include "CplayerSkill.h"
#include "camera.h"
#include "CplayerUi.h"
#include "CinventoryUi.h"

class CplayerManager :public Cunit
{
private:
	camera* m_camera;
	Cplayer* m_player;
	CplayerUi* m_playerUi;
	CinventoryUi* m_InventoryUI;
	Cinventory* m_inventory;
private:


	bool isInventoryOn;

public:
	CplayerManager();
	~CplayerManager();

	HRESULT init();
	void release();
	void update();
	void render();

	RECT* getplayerRect() { return m_player->getplayerMoveRC(); }
};