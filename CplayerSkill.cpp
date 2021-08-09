#include "framework.h"
#include "CplayerSkill.h"

CplayerSkill::CplayerSkill()
{
}

CplayerSkill::~CplayerSkill()
{
}

HRESULT CplayerSkill::init()
{
    skillDirection = SKILL::SKILL_DOWN;

    return S_OK;
}

void CplayerSkill::release()
{
}

void CplayerSkill::update()
{
}

void CplayerSkill::render()
{
}

void CplayerSkill::skillQ()
{
	skillBoxRc = RectMake();
    if (InputManager->isOnceKeyDown('Q'))
    {
		if (InputManager->isStayKeyDown(VK_RIGHT) && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
		{
			
			skillDirection = SKILL::SKILL_RIGHT;
		}
		else if (InputManager->isStayKeyDown(VK_LEFT) && (InputManager->isStayKeyDown(VK_UP) || InputManager->isStayKeyDown(VK_DOWN)))
		{
			
			skillDirection = SKILL::SKILL_LEFT;
		}
		else if (InputManager->isStayKeyDown(VK_UP) && (InputManager->isStayKeyDown(VK_RIGHT) || InputManager->isStayKeyDown(VK_LEFT)))
		{
			
			skillDirection = SKILL::SKILL_UP;
		}
		else if (InputManager->isStayKeyDown(VK_DOWN) && (InputManager->isStayKeyDown(VK_RIGHT) || InputManager->isStayKeyDown(VK_LEFT)))
		{
			skillDirection = SKILL::SKILL_DOWN;
		}
		else if (InputManager->isStayKeyDown(VK_LEFT))
		{
			skillDirection = SKILL::SKILL_LEFT;
		}
		else if (InputManager->isStayKeyDown(VK_RIGHT))
		{
			skillDirection = SKILL::SKILL_RIGHT;
		}
		else if (InputManager->isStayKeyDown(VK_UP))
		{
			skillDirection = SKILL::SKILL_UP;
		}
		else if (InputManager->isStayKeyDown(VK_DOWN))
		{
			skillDirection = SKILL::SKILL_DOWN;
		}
    }
    switch (skillDirection)
    {
    case SKILL::SKILL_LEFT:
        break;
    case SKILL::SKILL_UP:
        break;
    case SKILL::SKILL_RIGHT:
        break;
    case SKILL::SKILL_DOWN:
        break;

    }
}

void CplayerSkill::skillW()
{
}

void CplayerSkill::skillE()
{
}
