#include"framework.h"
#include "mapToolManager.h"
#include"camera.h"

HRESULT mapToolManager::init()
{
	// 임시 추가 이미지, 나중에 한곳에서 몰아서 할수도
	IMAGE->addFrameImage("tilemap", "images/Tile2.bmp", 648, 504, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));

	m_mainMapTool = new mapToolMain;
	m_mainMapTool->init();

	m_subMapTool = new mapToolSub;
	m_subMapTool->init();

	m_subMapTool->setMapToolMainMemory(m_mainMapTool);

	m_mainMapTool->setCameraMemory(m_camera);

	
	return S_OK;
}

void mapToolManager::release()
{
}

void mapToolManager::update()
{

	m_subMapTool->update();

	// 공용값 적용시켜주기
	m_mainMapTool->setSubTile(m_subMapTool->getSubTile());
	m_mainMapTool->setMainMapCurrentTile(m_subMapTool->getCurrentTile());
	m_mainMapTool->setMainMapDragTile(m_subMapTool->getTagDragTile());
	m_mainMapTool->setMainMapSelect(m_subMapTool->getCtrlSelect());
	m_mainMapTool->setFrameKind(m_subMapTool->getFrameKind());

	m_mainMapTool->update();
}

void mapToolManager::render()
{
	m_mainMapTool->render();
	m_subMapTool->render();
	//m_mainMapTool->setSubTile(m_subMapTool->getSubTile());
}