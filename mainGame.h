#pragma once
#include"gameNode.h"
#include"camera.h"
#include"Cplayer.h"
#include"mapToolManager.h"
#include"Ctown.h"
#include"CsceneStart.h"
#include"CsceneSelect.h"
class mainGame : public gameNode
{
private:
	Cplayer* m_player;
	camera* m_camera;
	Cimage* m_image;
	mapToolManager* m_mapTool;
	Ctown* m_town;

	bool isDebug;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};
