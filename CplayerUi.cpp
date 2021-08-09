#include "framework.h"
#include "CplayerUi.h"

CplayerUi::CplayerUi()
{
}

CplayerUi::~CplayerUi()
{
}

HRESULT CplayerUi::init()
{
	return S_OK;
}

void CplayerUi::release()
{
}

void CplayerUi::update()
{
}

void CplayerUi::render()
{
	IMAGE->findImage("SkillUi")->render(getMemDC(), IMAGE->findImage("HUD")->getWidth(), WINSIZEY - IMAGE->findImage("HUD")->getHeight());
}
