#pragma once
#include "Cunit.h"
#include "Cplayer.h"
#include "CplayerAttack.h"
#include "CplayerSkill.h"
#include "camera.h"
#include "CplayerUi.h"
#include "CinventoryUi.h"

class CaStar;
class CplayerManager :public Cunit
{
private:
	camera* m_camera;
	Cplayer* m_player;
	CplayerSkill* m_playerSkill;
	CplayerUi* m_playerUi;
	CinventoryUi* m_InventoryUI;
	Cinventory* m_inventory;
private:

	vector<POINT>* m_fastLoadLocation;

	bool isInventoryOn;

public:
	CplayerManager();
	~CplayerManager();

	HRESULT init();
	void release();
	void update();
	void render();

	RECT* getplayerRect() { return m_player->getplayerMoveRC(); }

	void setFastLoadLocation(vector<POINT>* vp) { m_fastLoadLocation = vp; }
};