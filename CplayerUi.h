#pragma once
#include "gameNode.h"
#include "CprogressBar.h"

class Cplayer;
class CplayerUi :public gameNode
{
private:
	RECT m_hudUi;
	Cplayer* m_player;
	CprogressBar* m_hpBar;
	CprogressBar* m_mpBar;
	CprogressBar* m_expBar;
public:
	CplayerUi();
	~CplayerUi();

	HRESULT init();
	void release();
	void update();
	void render();

	void progressBarUpdate();
	void progressBarRender();

	void playerStateRender();

	void setPlayerMemoryLink(Cplayer* player) { m_player = player; }
};

