#pragma once
#include "gameNode.h"
#include "Ctown.h"
#include "CplayerManager.h"
#include "camera.h"
#include "CaStar.h"
#include "CshopUi.h"
#include "CplayerDate.h"

#include "CNPC.h"
class CsceneTown : public gameNode
{
private:
	Ctown* m_town;
	camera* m_camera;
	CplayerManager* m_player;
	CaStar* m_aStar;
	Cshop* m_shop;
	CshopUi* m_shopUi;
	CplayerDate* m_playerDate;

	CNPC* m_npc;
private:
	RECT m_changeRect;
	RECT m_shopRect;
	RECT m_garNorRect;

	bool isShopOn;

	bool isGarNorCollison;

	float m_timerHp;
	float m_timerMp;

public:
	CsceneTown();
	~CsceneTown();

	HRESULT init();
	void release();
	void update();
	void render();

	void sceneChange();
	void shopOn();
	void garNORCollison();
	void setPlayerMemory(CplayerDate* playerdate){ m_playerDate = playerdate;}
};