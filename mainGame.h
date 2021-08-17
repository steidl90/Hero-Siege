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
#include"CplayerData.h"
class mainGame : public gameNode
{
private:
	Cimage* m_image;
	CplayerData* m_playerData;
	bool isDebug;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};
