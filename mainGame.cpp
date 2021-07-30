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

	///* astar */	_aStar = new CaStar;
	///* astar */ _aStar->init();
	
	m_player = new camel;
	m_player->init();

	m_camera = new camera;
	m_camera->init();

	m_mapTool = new mapToolManager;
	m_mapTool->init();

	m_mapTool->setCameraMemory(m_camera);

	SCENE->addScene("¸ÊÅø", m_mapTool);

	SCENE->changeScene("¸ÊÅø");

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	///* astar */ SAFE_DELETE(_aStar);
}

void mainGame::update()
{
	gameNode::update();
	SCENE->update();
	//ANIMATION->update();
	m_player->update();
	m_camera->setTargetPoint(PointMake(m_player->getPlayRc()->left, m_player->getPlayRc()->top));
	m_camera->update();
	///* astar */ _aStar->update();
	
}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	/////////////////////////////////////////////////////////
	///* astar */ _aStar->render();
	this->getMapBuffer()->render(getMemDC(), 0, 0, m_camera->getCameraPoint().x, m_camera->getCameraPoint().y, m_camera->getCameraWidth(), m_camera->getCameraHeight());

	SCENE->render();

	m_player->render();
	m_camera->render();
	TIME->render(getMemDC());

	char str[100];
	sprintf_s(str, "¸¶¿ì½º x : %d, ¸¶¿ì½º y: %d, ", m_ptMouse.x, m_ptMouse.y);
	SetTextColor(getMemDC(), RGB(255, 255, 0));
	TextOut(getMemDC(), WINSIZEX / 2 - 500, 70, str, lstrlen(str));


	/////////////////////////////////////////////////////////
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
