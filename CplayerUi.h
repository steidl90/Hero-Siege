#pragma once
#include "gameNode.h"
class CplayerUi :public gameNode
{
private:
	RECT m_hudUi;

public:
	CplayerUi();
	~CplayerUi();

	HRESULT init();
	void release();
	void update();
	void render();
};

