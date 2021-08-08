#pragma once
#include "gameNode.h"
#include "Ctown.h"
#include "CplayerManager.h"
#include "camera.h"
class CsceneTown : public gameNode
{
private:
	Ctown* m_town;
	camera* m_camera;
	CplayerManager* m_player;

public:
	CsceneTown();
	~CsceneTown();

	HRESULT init();
	void release();
	void update();
	void render();
};