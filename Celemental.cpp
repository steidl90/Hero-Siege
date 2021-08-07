#include "framework.h"
#include "Celemental.h"

Celemental::Celemental()
{
}

Celemental::~Celemental()
{
}

HRESULT Celemental::init()
{
	a = TIME->getWorldTime();
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init();

	m_elementalImage = IMAGE->findImage("¿¤¸®¸àÅ»");
	ANIMATION->addAnimation("ElementalDown", "¿¤¸®¸àÅ»", 0, 3,8, false, true);
	ANIMATION->addAnimation("ElementalLeft", "¿¤¸®¸àÅ»", 4, 7, 8, false, true);
	ANIMATION->addAnimation("ElementalRight", "¿¤¸®¸àÅ»", 8, 11, 8, false, true);
	ANIMATION->addAnimation("ElementalUp", "¿¤¸®¸àÅ»", 12, 15, 8, false, true);

	m_elementalRc = RectMakeCenter(WINSIZEX/2, WINSIZEY/2, m_elementalImage->getFrameWidth(), m_elementalImage->getFrameHeight());
	m_elementalAnimation = ANIMATION->findAnimation("ElementalDown");

	m_x = WINSIZEX / 2;
	m_y = WINSIZEY / 2;
	m_speed = 2.0f;


	return S_OK;
}

void Celemental::release()
{
	SAFE_DELETE(m_enemyAttack);
}

void Celemental::update()
{


	//if (a + 1 < TIME->getWorldTime())
	//{
	//	m_enemyAttack->fire(m_elementalRc.left, m_elementalRc.bottom - (m_elementalRc.bottom - m_elementalRc.top) / 2,
	//		PI, 5.0f, "¿¤¸®¸àÅ»½ºÅ³1", "¿¤¸®¸àÅ»½ºÅ³¾Ö´Ï");
	//}

	m_elementalState = ELEMENTAL_STATE::ELEMENTAL_STATE_IDLE;
	m_enemyAttack->update("¿¤¸®¸àÅ»½ºÅ³¾Ö´Ï");

	if (InputManager->isStayKeyDown('W'))
	{
		m_y -= m_speed;
		m_elementalState = ELEMENTAL_STATE::ELEMENTAL_STATE_TOP;
	}
	if (InputManager->isStayKeyDown('S'))
	{
		m_y += m_speed;
		m_elementalState = ELEMENTAL_STATE::ELEMENTAL_STATE_BOTTOM;
	}
	if (InputManager->isStayKeyDown('A'))
	{
		m_x -= m_speed;
		m_elementalState = ELEMENTAL_STATE::ELEMENTAL_STATE_LEFT;
	}
	if (InputManager->isStayKeyDown('D'))
	{
			m_x += m_speed;
			m_elementalState = ELEMENTAL_STATE::ELEMENTAL_STATE_RIGHT;
	}
	if (InputManager->isOnceKeyDown('E'))
	{
	}
	if (InputManager->isOnceKeyDown(VK_LEFT))
	{
		a = TIME->getWorldTime();

		if (a + 1 < TIME->getWorldTime())
		{
			m_enemyAttack->fire(m_elementalRc.left, m_elementalRc.bottom - (m_elementalRc.bottom - m_elementalRc.top) / 2,
				PI, 5.0f, "¿¤¸®¸àÅ»½ºÅ³1", "¿¤¸®¸àÅ»½ºÅ³¾Ö´Ï");
		}
	}
	if (InputManager->isOnceKeyDown(VK_RIGHT))
	{
		m_enemyAttack->fire(m_elementalRc.right, m_elementalRc.bottom - (m_elementalRc.bottom - m_elementalRc.top) / 2,
			PI2, 5.0f, "¿¤¸®¸àÅ»½ºÅ³1", "¿¤¸®¸àÅ»½ºÅ³¾Ö´Ï");
	}
	if (InputManager->isOnceKeyDown(VK_UP))
	{
		m_enemyAttack->fire(m_elementalRc.right-(m_elementalRc.right-m_elementalRc.left)/2,m_elementalRc.top,
			PI*0.5, 5.0f, "¿¤¸®¸àÅ»½ºÅ³1", "¿¤¸®¸àÅ»½ºÅ³¾Ö´Ï");
	}
	if (InputManager->isOnceKeyDown(VK_DOWN))
	{
		m_enemyAttack->fire(m_elementalRc.right - (m_elementalRc.right - m_elementalRc.left) / 2, m_elementalRc.bottom,
			PI*1.5, 5.0f, "¿¤¸®¸àÅ»½ºÅ³1", "¿¤¸®¸àÅ»½ºÅ³¾Ö´Ï");
	}

	switch (m_elementalState)
	{
	case ELEMENTAL_STATE::ELEMENTAL_STATE_LEFT:
		m_elementalAnimation = ANIMATION->findAnimation("ElementalLeft");
		ANIMATION->resume("ElementalLeft");
		break;

	case ELEMENTAL_STATE::ELEMENTAL_STATE_RIGHT:

		m_elementalAnimation = ANIMATION->findAnimation("ElementalRight");
		ANIMATION->resume("ElementalRight");
		break;

	case ELEMENTAL_STATE::ELEMENTAL_STATE_TOP:

		m_elementalAnimation = ANIMATION->findAnimation("ElementalUp");
		ANIMATION->resume("ElementalUp");
		break;

	case ELEMENTAL_STATE::ELEMENTAL_STATE_BOTTOM:

		m_elementalAnimation = ANIMATION->findAnimation("ElementalDown");
		ANIMATION->resume("ElementalDown");
		break;
	}
	m_elementalRc = RectMakeCenter(m_x, m_y, m_elementalImage->getFrameWidth(), m_elementalImage->getFrameHeight());
}

void Celemental::render()
{
	m_elementalImage->aniRender(getMapDC(), m_elementalRc.left, m_elementalRc.top, m_elementalAnimation);
	//Rectangle(getMapDC(), m_elementalRc.left, m_elementalRc.top, m_elementalRc.right, m_elementalRc.bottom);
	m_enemyAttack->render();
}
