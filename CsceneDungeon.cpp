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

	//슬라임 설정 = 전역에 골고루
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Cslime* m_slime = new Cslime;
			m_slime->init(PointMake(RND->getFromIntTo(800, 1000) + i * RND->getFromIntTo(130, 180),
				RND->getFromIntTo(250, 350) + j * RND->getFromIntTo(100, 150)),
				900, 20, 200, 500);
			m_slime->setPlayer(m_player->getPlayer());
			m_enemyManager->registerEnemy(m_slime);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Cslime* m_slime2 = new Cslime;
			m_slime2->init(PointMake(RND->getFromIntTo(100, 150) + i * RND->getFromIntTo(100, 180),
				RND->getFromIntTo(600, 650) + j * RND->getFromIntTo(120, 150)),
				900, 20, 200, 500);
			m_slime2->setPlayer(m_player->getPlayer());
			m_enemyManager->registerEnemy(m_slime2);
		}
	}

	//엘리멘탈 설정 = 좌측 위, 중앙
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Celemental* m_elemental = new Celemental;
			m_elemental->init(PointMake(RND->getFromIntTo(100, 150) + i * RND->getFromIntTo(120, 150),
				240 + j * RND->getFromIntTo(50, 100)),
				500, 10, 200, 500);
			m_elemental->setPlayer(m_player->getPlayer());
			m_enemyManager->registerEnemy(m_elemental);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Celemental* m_elemental2 = new Celemental;
			m_elemental2->init(PointMake(RND->getFromIntTo(900, 1000) + i * RND->getFromIntTo(120, 150),
				RND->getFromIntTo(250, 350) + j * RND->getFromIntTo(100, 150)),
				500, 10, 200, 500);
			m_elemental2->setPlayer(m_player->getPlayer());
			m_enemyManager->registerEnemy(m_elemental2);
		}
	}
	//몽크 설정 = 좌측 중간
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Cmonk* m_monk = new Cmonk;
			m_monk->init(PointMake(RND->getFromIntTo(100, 150) + i * RND->getFromIntTo(100, 180),
				RND->getFromIntTo(600, 650) + j * RND->getFromIntTo(120, 150)),
				700, 20, 200, 350);
			m_monk->setPlayer(m_player->getPlayer());
			m_enemyManager->registerEnemy(m_monk);
		}
	}
	////프리스트 설정 = 중 상단, 좌 중단 1마리씩
	for (int i = 0; i < 2; i++)
	{
		Cpriest* m_priest = new Cpriest;
		m_priest->init(PointMake(900 + i * 650, 200 + i * 400),
			700, 20, 200, 500);
		m_priest->setPlayer(m_player->getPlayer());
		m_enemyManager->registerEnemy(m_priest);
	}

	//교도관 설정 = 중앙 하단
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Cprison* m_prison = new Cprison;
			m_prison->init(PointMake(950 + i * 100, 1050 + j * 100),
				700, 20, 200, 350);
			m_prison->setPlayer(m_player->getPlayer());
			m_enemyManager->registerEnemy(m_prison);
		}
	}

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
		SCENE->changeScene("마을");
	}
}
