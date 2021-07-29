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
	

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}

void mainGame::update()
{
	gameNode::update();

	//정지수
}

void mainGame::render()
{
	//백버퍼 뿌리자.
	//HDC memDC = this->getBackBuffer()->getMemDC();
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============================================




	//백버퍼의 내용을 HDC그린다.(건드리지 말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
