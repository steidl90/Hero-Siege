#pragma once
#include "Cunit.h"
#include "Cplayer.h"
#include "CplayerAttack.h"
#include "CplayerSkill.h"
class CplayerManager :public Cunit
{
private:
	Cplayer* m_player;

public:
	CplayerManager();
	~CplayerManager();

	HRESULT init();
	void release();
	void update();
	void render();
};