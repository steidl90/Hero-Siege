#include"framework.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);

	/* astar */	_aStar = new CaStar;
	/* astar */ _aStar->init();

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	/* astar */ SAFE_DELETE(_aStar);
}

void mainGame::update()
{
	gameNode::update();
	
	/* astar */ _aStar->update();
	
}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	/////////////////////////////////////////////////////////
	/* astar */ _aStar->render();




	/////////////////////////////////////////////////////////
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
