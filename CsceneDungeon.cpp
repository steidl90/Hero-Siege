#include "framework.h"
#include "CsceneDungeon.h"
#include "Celemental.h"
#include "Cmonk.h"
#include "Cpriest.h"
#include "Cprison.h"
#include "Cslime.h"
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

	m_enemyManager = new CenemyManager;
	m_enemyManager->init();
	m_enemyManager->setPlayer(m_player->getPlayer());

	m_changeRect = RectMake(170, MAPSIZE - 230, 100, 50);

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
	m_enemyManager->update();
	m_enemyManager->collision();
	m_camera->setTargetPoint(PointMake(m_player->getplayerRect()->left, m_player->getplayerRect()->top));

	sceneChange();
}

void CsceneDungeon::render()
{
	this->getMapBuffer()->render(getMemDC(), 0, 0, m_camera->getCameraPoint().x, m_camera->getCameraPoint().y, m_camera->getCameraWidth(), m_camera->getCameraHeight());
	this->getMapBuffer()->mapRender(getMemDC(), WINSIZEX - IMAGE->findImage("MiniMapUi")->getWidth(), 70);

	m_camera->render();
	m_dungeon->render();
	m_enemyManager->render();
	m_player->render();

	//Rectangle(getMapDC(), m_changeRect.left, m_changeRect.top, m_changeRect.right, m_changeRect.bottom);
}

void CsceneDungeon::sceneChange()
{
	RECT temp;

	if (IntersectRect(&temp, m_player->getplayerRect(), &m_changeRect))
	{
		SCENE->changeScene("¸¶À»");
	}
}
