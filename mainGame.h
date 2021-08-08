#pragma once
#include "gameNode.h"
#include "camera.h"
#include "camel.h"
#include "mapToolManager.h"
#include "CTown.h"
#include "Cmevius.h"
#include "Celemental.h"
#include "Cpriest.h"
#include "Cmonk.h"
#include "Cprison.h"
#include "Cslime.h"

///* astar */ #include "CaStar.h"

class mainGame : public gameNode
{
private:
	///* astar */ CaStar * _aStar;

	camel* m_player;
	camera* m_camera;
	Cimage* m_image;
	mapToolManager* m_mapTool;
	CTown* m_town;
	Cmevius* m_mevius;
	Celemental* m_elemental;
	Cpriest* m_priest;
	Cmonk* m_monk;
	Cprison* m_prison;
	Cslime* m_slime;

	bool isDebug;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};
