#pragma once
#include "Cunit.h"
#include "Cplayer.h"
#include "CplayerAttack.h"
#include "CplayerSkill.h"
#include "camera.h"
#include "CplayerUi.h"

class CplayerManager :public Cunit
{
private:
private:
	Cplayer* m_player;
	CplayerSkill* m_playerSkill;
	CplayerUi* m_playerUi;
	camera* m_camera;

public:
	CplayerManager();
	~CplayerManager();

	HRESULT init();
	void release();
	void update();
	void render();

	RECT* getplayerRect() { return m_player->getplayerMoveRC(); }
};