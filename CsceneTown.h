#pragma once
#include "gameNode.h"
class CsceneTown : public gameNode
{
private:
	RECT m_newStartRc;
	RECT m_loadRc;
	RECT m_exitRc;

	int m_startX, m_startY;
	int m_loadX, m_loadY;
	int m_exitX, m_exitY;

public:
	CsceneTown();
	~CsceneTown();

	HRESULT init();
	void release();
	void update();
	void render();
};