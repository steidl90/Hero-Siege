#pragma once
#include"gameNode.h"
#include"camera.h"
#include"camel.h"
#include"mapToolManager.h"

///* astar */ #include "CaStar.h"

class mainGame : public gameNode
{
private:
	///* astar */ CaStar * _aStar;

	camel* m_player;
	camera* m_camera;

	mapToolManager* m_mapTool;

	bool isDebug;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};
