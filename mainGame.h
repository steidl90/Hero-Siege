#pragma once
#include"gameNode.h"
#include"camera.h"
#include"Cplayer.h"
#include"mapToolManager.h"
#include"Ctown.h"
#include"CsceneStart.h"
#include"CsceneSelect.h"
#include"CsceneTown.h"
#include"CsceneDungeon.h"
#include"CaStar.h"
#include"CplayerDate.h"
class mainGame : public gameNode
{
private:
	CaStar* m_astar;
	Cimage* m_image;
	CplayerDate* m_playerDate;
	bool isDebug;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};
