#pragma once
#include"gameNode.h"

/* astar */ #include "CaStar.h"

class mainGame : public gameNode
{
private:
	/* astar */ CaStar * _aStar;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};
