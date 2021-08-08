#pragma once
#include "Cunit.h"
#include "Cplayer.h"
#include "CplayerAttack.h"
#include "CplayerSkill.h"
#include "camera.h"
#include "CTown.h"
class CplayerManager :public Cunit
{
private:
	Cplayer* m_player;
	camera* m_camera;
	CTown* m_town;

public:
	CplayerManager();
	~CplayerManager();

	HRESULT init();
	void release();
	void update();
	void render();
};