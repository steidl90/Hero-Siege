#pragma once
#include"gameNode.h"
#include"camera.h"
#include"mapToolManager.h"
#include"CTown.h"
#include"Cplayer.h"
#include"CplayerManager.h"
///* astar */ #include "CaStar.h"

class mainGame : public gameNode
{
private:
	///* astar */ CaStar * _aStar;

	camera* m_camera;
	Cimage* m_image;
	mapToolManager* m_mapTool;
	CTown* m_town;
	Cplayer* player;
	CplayerManager* m_playerManager;


	bool isDebug;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};
