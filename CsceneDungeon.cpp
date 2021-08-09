#include "framework.h"
#include "CsceneDungeon.h"

CsceneDungeon::CsceneDungeon()
{
}

CsceneDungeon::~CsceneDungeon()
{
}

HRESULT CsceneDungeon::init()
{
	m_camera = new camera;
	m_camera->init();

	m_dungeon = new Cdungeon;
	m_dungeon->init();
	m_dungeon->setCameraMemory(m_camera);

	m_player = new CplayerManager;
	m_player->init();

	return S_OK;
}

void CsceneDungeon::release()
{
	SAFE_DELETE(m_camera);
	SAFE_DELETE(m_dungeon);
	SAFE_DELETE(m_player);
}

void CsceneDungeon::update()
{
	m_camera->update();
	m_dungeon->update();
	m_player->update();
	m_camera->setTargetPoint(PointMake(m_player->getplayerRect()->left, m_player->getplayerRect()->top));
}

void CsceneDungeon::render()
{
	this->getMapBuffer()->render(getMemDC(), 0, 0, m_camera->getCameraPoint().x, m_camera->getCameraPoint().y, m_camera->getCameraWidth(), m_camera->getCameraHeight());

	m_camera->render();
	m_dungeon->render();
	m_player->render();
}
