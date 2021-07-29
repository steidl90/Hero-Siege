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

	//Á¤Áö¼ö
	//³Ü³Ü
	//±èÇåÈñ
}

void mainGame::render()
{
	//¹é¹öÆÛ »Ñ¸®ÀÚ.
	//HDC memDC = this->getBackBuffer()->getMemDC();
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============================================




	//¹é¹öÆÛÀÇ ³»¿ëÀ» HDC±×¸°´Ù.(°Çµå¸®Áö ¸»°Í.)
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
