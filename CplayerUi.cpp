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
//TODO::¹Ì´Ï¸Ê UI ¼³Á¤
void CplayerUi::render()
{
	IMAGE->findImage("SkillUi")->render(getMemDC(), 0, (WINSIZEY - 39) - IMAGE->findImage("SkillUi")->getHeight());
	IMAGE->findImage("StateUi")->render(getMemDC(), 0, 0);
	IMAGE->findImage("MiniMapUi")->render(getMemDC(), (WINSIZEX - 15) - IMAGE->findImage("MiniMapUi")->getWidth(), 0);

}
