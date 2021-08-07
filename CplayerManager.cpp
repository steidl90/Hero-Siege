#include "framework.h"
#include "CplayerManager.h"

CplayerManager::CplayerManager()
{
}

CplayerManager::~CplayerManager()
{
}

HRESULT CplayerManager::init()
{
    m_player = new Cplayer;
    m_player->init();

    m_camera = new camera;
    m_camera->init();

  
    m_town = new CTown;
    m_town->init();
    m_town->setCameraMemory(m_camera);

    SCENE->addScene("¸ÊÅø", m_town);
    SCENE->changeScene("¸ÊÅø");
    return S_OK;
}

void CplayerManager::release()
{
    SAFE_DELETE(m_camera);
    SAFE_DELETE(m_player);
    SAFE_DELETE(m_town);


}

void CplayerManager::update()
{
    SCENE->update();
    m_player->update();
    m_camera->setTargetPoint(PointMake(m_player->getplayerMoveRC()->left, m_player->getplayerMoveRC()->top));
    m_camera->update();

}

void CplayerManager::render()
{

    SCENE->render();

    m_player->render();
    m_camera->render();
    this->getMapBuffer()->render(getMemDC(), 0, 0, m_camera->getCameraPoint().x, m_camera->getCameraPoint().y, m_camera->getCameraWidth(), m_camera->getCameraHeight());

}
