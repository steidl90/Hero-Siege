#include "framework.h"
#include "Cmonk.h"

Cmonk::Cmonk()
{
	m_monkImage = nullptr;
}

Cmonk::~Cmonk()
{
}

HRESULT Cmonk::init()
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init();

	ANIMATION->addAnimation("根农酒贰率", "根农", 0, 5, 8, false, true);
	ANIMATION->addAnimation("根农哭率", "根农", 6, 11, 8, false, true);
	ANIMATION->addAnimation("根农坷弗率", "根农", 12, 17, 8, false, true);
	ANIMATION->addAnimation("根农困率", "根农", 18, 23, 8, false, true);

	ANIMATION->addAnimation("根农傍拜酒贰率", "根农傍拜", 0, 4, 8, false, true);
	ANIMATION->addAnimation("根农傍拜哭率", "根农傍拜", 5, 9, 8, false, true);
	ANIMATION->addAnimation("根农傍拜坷弗率", "根农傍拜", 10, 14, 8, false, true);
	ANIMATION->addAnimation("根农傍拜困率", "根农傍拜", 15, 19, 8, false, true);

	ANIMATION->addAnimation("根农荤噶酒贰率", "根农荤噶", 0, 11, 8, false, false);
	ANIMATION->addAnimation("根农荤噶哭率", "根农荤噶", 12, 23, 8, false, false);
	ANIMATION->addAnimation("根农荤噶坷弗率", "根农荤噶", 24, 35, 8, false, false);
	ANIMATION->addAnimation("根农荤噶困率", "根农荤噶", 36, 47, 8, false, false);

	m_x = WINSIZEX / 2;
	m_y = WINSIZEY / 2;
	m_speed = 2.0f;

	return S_OK;
}

void Cmonk::release()
{
	SAFE_DELETE(m_enemyAttack);
}

void Cmonk::update()
{
	//================= Priest Walking motion =================
	if (InputManager->isStayKeyDown('W'))
	{
		m_y -= m_speed;
		m_monkState = MONK_STATE::MONK_STATE_WALK_UP;
	}
	if (InputManager->isStayKeyDown('S'))
	{
		m_y += m_speed;
		m_monkState = MONK_STATE::MONK_STATE_WALK_DOWN;
	}
	if (InputManager->isStayKeyDown('A'))
	{
		m_x -= m_speed;
		m_monkState = MONK_STATE::MONK_STATE_WALK_LEFT;
	}
	if (InputManager->isStayKeyDown('D'))
	{
		m_x += m_speed;
		m_monkState = MONK_STATE::MONK_STATE_WALK_RIGHT;
	}

	if (InputManager->isOnceKeyDown(VK_UP))
	{
		//m_y -= 20;
		m_monkState = MONK_STATE::MONK_STATE_DIE_UP;
	}
	if (InputManager->isOnceKeyDown(VK_DOWN))
	{
		//m_y -= 20;
		m_monkState = MONK_STATE::MONK_STATE_DIE_DOWN;
	}
	if (InputManager->isOnceKeyDown(VK_LEFT))
	{
		//m_y -= 20;
		m_monkState = MONK_STATE::MONK_STATE_DIE_LEFT;
	}
	if (InputManager->isOnceKeyDown(VK_RIGHT))
	{
		//m_y -= 20;
		m_monkState = MONK_STATE::MONK_STATE_DIE_RIGHT;
	}








	switch (m_monkState)
	{
	
	case MONK_STATE::MONK_STATE_WALK_UP:
		m_monkImage = IMAGE->findImage("根农");
		m_monkAnimation = ANIMATION->findAnimation("根农困率");
		ANIMATION->resume("根农困率");
		break;
	case MONK_STATE::MONK_STATE_WALK_DOWN:
		m_monkImage = IMAGE->findImage("根农");
		m_monkAnimation = ANIMATION->findAnimation("根农酒贰率");
		ANIMATION->resume("根农酒贰率");
		break;
	case MONK_STATE::MONK_STATE_WALK_LEFT:
		m_monkImage = IMAGE->findImage("根农");
		m_monkAnimation = ANIMATION->findAnimation("根农哭率");
		ANIMATION->resume("根农哭率");
		break;
	case MONK_STATE::MONK_STATE_WALK_RIGHT:
		m_monkImage = IMAGE->findImage("根农");
		m_monkAnimation = ANIMATION->findAnimation("根农坷弗率");
		ANIMATION->resume("根农坷弗率");
		break;
	
	case MONK_STATE::MONK_STATE_ATTACK_UP:
		m_monkImage = IMAGE->findImage("根农傍拜");
		m_monkAnimation = ANIMATION->findAnimation("根农傍拜困率");
		ANIMATION->resume("根农傍拜困率");
		break;
	case MONK_STATE::MONK_STATE_ATTACK_DOWN:
		m_monkImage = IMAGE->findImage("根农傍拜");
		m_monkAnimation = ANIMATION->findAnimation("根农傍拜酒贰率");
		ANIMATION->resume("根农傍拜");
		break;
	case MONK_STATE::MONK_STATE_ATTACK_LEFT:
		m_monkImage = IMAGE->findImage("根农傍拜");
		m_monkAnimation = ANIMATION->findAnimation("根农傍拜哭率");
		ANIMATION->resume("根农傍拜哭率");
		break;
	case MONK_STATE::MONK_STATE_ATTACK_RIGHT:
		m_monkImage = IMAGE->findImage("根农傍拜");
		m_monkAnimation = ANIMATION->findAnimation("根农傍拜坷弗率");
		ANIMATION->resume("根农傍拜坷弗率");
		break;
	
	
	
	case MONK_STATE::MONK_STATE_DIE_UP:
		m_monkImage = IMAGE->findImage("根农荤噶");
		m_monkAnimation = ANIMATION->findAnimation("根农荤噶困率");
		ANIMATION->resume("根农荤噶困率");
		break;
	case MONK_STATE::MONK_STATE_DIE_DOWN:
		m_monkImage = IMAGE->findImage("根农荤噶");
		m_monkAnimation = ANIMATION->findAnimation("根农荤噶酒贰率");
		ANIMATION->resume("根农荤噶酒贰率");
		break;
	case MONK_STATE::MONK_STATE_DIE_LEFT:
		m_monkImage = IMAGE->findImage("根农荤噶");
		m_monkAnimation = ANIMATION->findAnimation("根农荤噶哭率");
		ANIMATION->resume("根农荤噶哭率");
		break;
	case MONK_STATE::MONK_STATE_DIE_RIGHT:
		m_monkImage = IMAGE->findImage("根农荤噶");
		m_monkAnimation = ANIMATION->findAnimation("根农荤噶坷弗率");
		ANIMATION->resume("根农荤噶坷弗率");
		break;
	}
	if (m_monkImage != nullptr) 
	{
		m_monkRc = RectMakeCenter(m_x, m_y, m_monkImage->getFrameWidth(), m_monkImage->getFrameHeight());
	}
}

void Cmonk::render()
{
	if (m_monkImage != nullptr) {
		Rectangle(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkRc.right, m_monkRc.bottom);
		m_monkImage->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAnimation);
		m_enemyAttack->render();
	}
}
