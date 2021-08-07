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
	
	m_image = new Cimage;
	m_image->init();

	/*m_player = new camel;
	m_player->init();*/

	player = new Cplayer;
	player->init();

	m_camera = new camera;
	m_camera->init();

	/*m_mapTool = new mapToolManager;
	m_mapTool->init();
	m_mapTool->setCameraMemory(m_camera);*/

	m_town = new CTown;
	m_town->init();
	m_town->setCameraMemory(m_camera);
	
	SCENE->addScene("����", m_town);
	SCENE->changeScene("����");
	
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	///* astar */ SAFE_DELETE(_aStar);
	//SAFE_DELETE(m_mapTool);
	SAFE_DELETE(m_image);
	SAFE_DELETE(m_player);
	SAFE_DELETE(m_camera);
	SAFE_DELETE(player);

	//SAFE_DELETE(m_town);
	SCENE->release();
}

void mainGame::update()
{
	gameNode::update();
	SCENE->update();
	//m_player->update();

	player->update();

	m_camera->setTargetPoint(PointMake(player->getplayerMoveRC()->left, player->getplayerMoveRC()->top));
	m_camera->update();
	///* astar */ _aStar->update();
	ANIMATION->update();

}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	/////////////////////////////////////////////////////////
	///* astar */ _aStar->render();

	// MapBuffer���� getMapDC�� �׷��� �� ��ü ũ���� �̹����� ����ִ�, MapBuffer�� render �Լ��� ����
	// ī�޶��� ���� x,y ��ǥ���� ���� ���� ���̸�ŭ ũ���� �̹����� �߶� (sour �μ��� �׷����)
	// �츮�� �� ȭ���� backBuffer�� getMemDC���ٰ� �׷��ش�

	this->getMapBuffer()->render(getMemDC(), 0, 0, m_camera->getCameraPoint().x, m_camera->getCameraPoint().y, m_camera->getCameraWidth(), m_camera->getCameraHeight());

	SCENE->render();

	//m_player->render();

	player->render();

	m_camera->render();
	TIME->render(getMemDC());

	char str[100];
	sprintf_s(str, "���콺 x : %d, ���콺 y: %d, ", m_ptMouse.x, m_ptMouse.y);
	SetTextColor(getMemDC(), RGB(255, 255, 0));
	TextOut(getMemDC(), WINSIZEX / 2 - 500, 70, str, lstrlen(str));


	/////////////////////////////////////////////////////////
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
