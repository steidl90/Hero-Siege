#include "framework.h"
#include "Cpriest.h"

Cpriest::Cpriest()
{
	m_priestImage = nullptr;
}

Cpriest::~Cpriest()
{
}
//투사체로 만들어놓고 시간되면 블랙홀을 추가하기
HRESULT Cpriest::init()
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init();

	//m_priestImage = IMAGE->findImage("리치");

	ANIMATION->addAnimation("리치아래쪽", "리치", 0, 5, 8, false, true);
	ANIMATION->addAnimation("리치왼쪽", "리치", 6, 11, 8, false, true);
	ANIMATION->addAnimation("리치오른쪽", "리치", 12, 17, 8, false, true);
	ANIMATION->addAnimation("리치위쪽", "리치", 18, 23, 8, false, true);

	ANIMATION->addAnimation("리치공격아래쪽", "리치공격", 0, 15, 16, false, false);
	ANIMATION->addAnimation("리치공격왼쪽", "리치공격", 16, 31, 16, false, false);
	ANIMATION->addAnimation("리치공격오른쪽", "리치공격", 32, 47, 16, false, false);
	ANIMATION->addAnimation("리치공격위쪽", "리치공격", 48, 63, 16, false, false);

	ANIMATION->addAnimation("리치사망아래쪽", "리치사망", 0, 9, 8, false, false);
	ANIMATION->addAnimation("리치사망왼쪽", "리치사망", 10, 19, 8, false, false);
	ANIMATION->addAnimation("리치사망오른쪽", "리치사망", 20, 29, 8, false, false);
	ANIMATION->addAnimation("리치사망위쪽", "리치사망", 30, 39, 8, false, false);

	//m_priestRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, m_priestImage->getFrameWidth(), m_priestImage->getFrameHeight());
	//m_priestAnimation = ANIMATION->findAnimation("리치아래쪽");

	m_x = WINSIZEX / 2-200;
	m_y = WINSIZEY / 2-200;
	m_speed = 2.0f;
    return S_OK;
}

void Cpriest::release()
{
	SAFE_DELETE(m_enemyAttack);

}

void Cpriest::update()
{
	m_priestState = PRIEST_STATE::PRIEST_STATE_IDLE;
	m_enemyAttack->update("리치스킬애니");

	//================= Priest Walking motion =================
	if (InputManager->isStayKeyDown('W'))
	{
		m_y -= m_speed;
		m_priestState = PRIEST_STATE::PRIEST_STATE_WALK_UP;
	}

	if (InputManager->isStayKeyDown('S'))
	{
		m_y += m_speed;
		m_priestState = PRIEST_STATE::PRIEST_STATE_WALK_DOWN;
	}

	if (InputManager->isStayKeyDown('A'))
	{
		m_x-= m_speed;
		m_priestState = PRIEST_STATE::PRIEST_STATE_WALK_LEFT;
	}

	if (InputManager->isStayKeyDown('D'))
	{
		m_x += m_speed;
		m_priestState = PRIEST_STATE::PRIEST_STATE_WALK_RIGHT;
	}

	//================= Priest Dead motion =================

	if (InputManager->isOnceKeyDown(VK_UP))
	{
		m_y -= 20;
		m_priestState = PRIEST_STATE::PRIEST_STATE_DIE_UP;
	}
	if (InputManager->isOnceKeyDown(VK_DOWN))
	{
		m_y -= 20;
		m_priestState = PRIEST_STATE::PRIEST_STATE_DIE_DOWN;
	}
	if (InputManager->isOnceKeyDown(VK_LEFT))
	{
		m_y -= 20;
		m_priestState = PRIEST_STATE::PRIEST_STATE_DIE_LEFT;
	}
	if (InputManager->isOnceKeyDown(VK_RIGHT))
	{
		m_y -= 20;
		m_priestState = PRIEST_STATE::PRIEST_STATE_DIE_RIGHT;
	}

	//================= Priest Attacking motion =================

	if(InputManager->isOnceKeyDown(VK_NUMPAD8))
	{
		m_priestState = PRIEST_STATE::PRIEST_STATE_ATTACK_UP;
		m_enemyAttack->fire(m_priestRc.right - (m_priestRc.right - m_priestRc.left) / 2, m_priestRc.top,
			PI * 0.5, 5.0f, "리치스킬", "리치스킬애니");
	}
	if(InputManager->isOnceKeyDown(VK_NUMPAD2))
	{ 
		m_priestState = PRIEST_STATE::PRIEST_STATE_ATTACK_DOWN;
		m_enemyAttack->fire(m_priestRc.right - (m_priestRc.right - m_priestRc.left) / 2, m_priestRc.bottom,
			PI * 1.5, 5.0f, "리치스킬", "리치스킬애니");
	}
	if(InputManager->isOnceKeyDown(VK_NUMPAD4))
	{ 
		m_priestState = PRIEST_STATE::PRIEST_STATE_ATTACK_LEFT;
		m_enemyAttack->fire(m_priestRc.left, m_priestRc.bottom - (m_priestRc.bottom - m_priestRc.top) / 2,
			PI, 5.0f, "리치스킬", "리치스킬애니");
	}
	if(InputManager->isOnceKeyDown(VK_NUMPAD6))
	{ 
		m_priestState = PRIEST_STATE::PRIEST_STATE_ATTACK_RIGHT;
		m_enemyAttack->fire(m_priestRc.right, m_priestRc.bottom - (m_priestRc.bottom - m_priestRc.top) / 2,
			PI2, 5.0f, "리치스킬", "리치스킬애니");
	}




	switch (m_priestState)
	{
	case PRIEST_STATE::PRIEST_STATE_WALK_UP:
		m_priestImage = IMAGE->findImage("리치");
		m_priestAnimation = ANIMATION->findAnimation("리치위쪽");
		ANIMATION->resume("리치위쪽");
		break;
	case PRIEST_STATE::PRIEST_STATE_WALK_DOWN:
		m_priestImage = IMAGE->findImage("리치");
		m_priestAnimation = ANIMATION->findAnimation("리치아래쪽");
		ANIMATION->resume("리치아래쪽");
		break;
	case PRIEST_STATE::PRIEST_STATE_WALK_LEFT:
		m_priestImage = IMAGE->findImage("리치");
		m_priestAnimation = ANIMATION->findAnimation("리치왼쪽");
		ANIMATION->resume("리치왼쪽");
		break;
	case PRIEST_STATE::PRIEST_STATE_WALK_RIGHT:
		m_priestImage = IMAGE->findImage("리치");
		m_priestAnimation = ANIMATION->findAnimation("리치오른쪽");
		ANIMATION->resume("리치오른쪽");
		break;


	case PRIEST_STATE::PRIEST_STATE_ATTACK_UP:
		m_priestImage = IMAGE->findImage("리치공격");
		m_priestAnimation = ANIMATION->findAnimation("리치공격위쪽");
		ANIMATION->start("리치공격위쪽");
		break;
	case PRIEST_STATE::PRIEST_STATE_ATTACK_DOWN:
		m_priestImage = IMAGE->findImage("리치공격");
		m_priestAnimation = ANIMATION->findAnimation("리치공격아래쪽");
		ANIMATION->start("리치공격아래쪽");
		break;
	case PRIEST_STATE::PRIEST_STATE_ATTACK_LEFT:
		m_priestImage = IMAGE->findImage("리치공격");
		m_priestAnimation = ANIMATION->findAnimation("리치공격왼쪽");
		ANIMATION->start("리치공격왼쪽");
		break;
	case PRIEST_STATE::PRIEST_STATE_ATTACK_RIGHT:
		m_priestImage = IMAGE->findImage("리치공격");
		m_priestAnimation = ANIMATION->findAnimation("리치공격오른쪽");
		ANIMATION->start("리치공격오른쪽");
		break;

	case PRIEST_STATE::PRIEST_STATE_DIE_UP:
		m_priestImage = IMAGE->findImage("리치사망");
		m_priestAnimation = ANIMATION->findAnimation("리치사망위쪽");
		ANIMATION->start("리치사망위쪽");
		break;
	case PRIEST_STATE::PRIEST_STATE_DIE_DOWN:
		m_priestImage = IMAGE->findImage("리치사망");
		m_priestAnimation = ANIMATION->findAnimation("리치사망아래쪽");
		ANIMATION->start("리치사망아래쪽");
		break;
	case PRIEST_STATE::PRIEST_STATE_DIE_LEFT:
		m_priestImage = IMAGE->findImage("리치사망");
		m_priestAnimation = ANIMATION->findAnimation("리치사망왼쪽");
		ANIMATION->start("리치사망왼쪽");
		break;
	case PRIEST_STATE::PRIEST_STATE_DIE_RIGHT:
		m_priestImage = IMAGE->findImage("리치사망");
		m_priestAnimation = ANIMATION->findAnimation("리치사망오른쪽");
		ANIMATION->start("리치사망오른쪽");
		break;
	}
	if (m_priestImage != nullptr) {
		m_priestRc = RectMakeCenter(m_x, m_y, m_priestImage->getFrameWidth(), m_priestImage->getFrameHeight());
	}
}

void Cpriest::render()
{
	if (m_priestImage != nullptr) {
		Rectangle(getMapDC(), m_priestRc.left, m_priestRc.top, m_priestRc.right, m_priestRc.bottom);
		m_priestImage->aniRender(getMapDC(), m_priestRc.left, m_priestRc.top, m_priestAnimation);
		m_enemyAttack->render();
	}

}
