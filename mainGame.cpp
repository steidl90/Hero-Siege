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
	
	m_image = new Cimage;
	m_image->init();

	m_astar = new CaStar;
	m_astar->init();

	m_playerDate = new CplayerDate;
	
	SCENE->addScene("���̽�Ÿ", m_astar);
	SCENE->addScene("����ȭ��", new CsceneStart);
	SCENE->addScene("����ȭ��", new CsceneSelect);
	SCENE->addScene("����", new CsceneTown);
	SCENE->addScene("����", new CsceneDungeon);

	SCENE->changeScene("����ȭ��");

	
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(m_image);
	SAFE_DELETE(m_astar);
	SAFE_DELETE(m_playerDate);
	SCENE->release();
	EFFECT->release();
}

void mainGame::update()
{
	gameNode::update();
	EFFECT->update();
	SCENE->update();
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

	EFFECT->render();
	SCENE->render();
	TIME->render(getMemDC());

	/////////////////////////////////////////////////////////
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
