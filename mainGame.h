#pragma once
#include"gameNode.h"
#include"camera.h"
#include"camel.h"
#include"mapToolManager.h"
#include"CTown.h"

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

	bool isDebug;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};
