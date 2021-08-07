#include "framework.h"
#include "CsceneTown.h"

CsceneTown::CsceneTown()
{
}

CsceneTown::~CsceneTown()
{
}

HRESULT CsceneTown::init()
{
	m_town = new Ctown;
	m_town->init();
	m_town->setCameraMemory(m_camera);

	return S_OK;
}

void CsceneTown::release()
{
	SAFE_DELETE(m_town);
}

void CsceneTown::update()
{
	m_town->update();
	//m_camera->setTargetPoint(PointMake(m_player->getplayerMoveRC()->left, m_player->getplayerMoveRC()->top));
}

void CsceneTown::render()
{
	m_town->render();
}
