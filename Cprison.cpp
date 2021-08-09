#include "framework.h"
#include "Cprison.h"

Cprison::Cprison()
{
	m_prison = nullptr;
}

Cprison::~Cprison()
{
}

HRESULT Cprison::init()
{


	ANIMATION->addAnimation("프리즌아래쪽", "교도관", 0, 7, 8, false, true);
	ANIMATION->addAnimation("프리즌왼쪽", "교도관", 8, 15, 8, false, true);
	ANIMATION->addAnimation("프리즌오른쪽", "교도관", 16, 23, 8, false, true);
	ANIMATION->addAnimation("프리즌위쪽", "교도관", 24, 31, 8, false, true);

	ANIMATION->addAnimation("프리즌공격아래쪽", "교도관공격", 0, 7, 8, false, false);
	ANIMATION->addAnimation("프리즌공격왼쪽", "교도관공격", 8, 15, 8, false, false);
	ANIMATION->addAnimation("프리즌공격오른쪽", "교도관공격", 16, 23, 8, false, false);
	ANIMATION->addAnimation("프리즌공격위쪽", "교도관공격", 24, 31, 8, false, false);

	ANIMATION->addAnimation("프리즌사망아래쪽", "교도관사망", 0, 12, 8, false, true);
	ANIMATION->addAnimation("프리즌사망왼쪽", "교도관사망", 13, 25, 8, false, true);
	ANIMATION->addAnimation("프리즌사망오른쪽", "교도관사망", 26, 38, 8, false, true);
	ANIMATION->addAnimation("프리즌사망위쪽", "교도관사망", 39, 51, 8, false, true);



	m_x = WINSIZEX / 2;
	m_y = WINSIZEY / 2;
	m_speed = 2.0f;

	isWalking = true;
	isAttack = false;
	isDie = false;

	return S_OK;
}

void Cprison::release()
{
}

void Cprison::update()
{
	m_prisonState = PRISON_STATE::PRISON_STATE_IDLE;
	//if (InputManager->isOnceKeyDown('1'))
	//{
	//	isWalking = true;
	//	isDie = false;
	//}
	//if (InputManager->isOnceKeyDown('2'))
	//{
	//	isDie = true;
	//	isAttack = false;
	//	isWalking = false;
	//}
			move();

	if (m_prison != nullptr)
	{
		if (isWalking)
		{
			m_prisonRc = RectMakeCenter(m_x, m_y, m_prison->getFrameWidth(), m_prison->getFrameHeight());
		}
		if (isAttack)
		{
			m_prisonAttackRc = RectMakeCenter(m_x, m_y, m_prisonAttack->getFrameWidth(), m_prisonAttack->getFrameHeight());
		}
		if (isDie)
		{
			m_prisonDieRc = RectMakeCenter(m_x, m_y, m_prisonDie->getFrameWidth(), m_prisonDie->getFrameHeight());
		}
	}
}

void Cprison::render()
{
	if (m_prison != nullptr)
	{
		if (isWalking)
		{
			Rectangle(getMapDC(), m_prisonRc.left, m_prisonRc.top, m_prisonRc.right, m_prisonRc.bottom);
			m_prison->aniRender(getMapDC(), m_prisonRc.left, m_prisonRc.top, m_prisonAni);

		}
		if (isAttack)
		{
			Rectangle(getMapDC(), m_prisonAttackRc.left, m_prisonAttackRc.top, m_prisonAttackRc.right, m_prisonAttackRc.bottom);
			m_prisonAttack->aniRender(getMapDC(), m_prisonAttackRc.left, m_prisonAttackRc.top, m_prisonAttackAni);

		}
		if (isDie)
		{
			Rectangle(getMapDC(), m_prisonDieRc.left, m_prisonDieRc.top, m_prisonDieRc.right, m_prisonDieRc.bottom);
			m_prisonDie->aniRender(getMapDC(), m_prisonDieRc.left, m_prisonDieRc.top, m_prisonDieAni);

		}
	}
}

void Cprison::animation()
{
	switch (m_prisonState)
	{
	case PRISON_STATE::PRISON_STATE_WALK_UP:

		m_prisonAttack = IMAGE->findImage("교도관공격");
		m_prisonAttackAni = ANIMATION->findAnimation("프리즌공격위쪽");
		m_prisonAttackAni->SetTriggerWhenClick(this, &Cprison::ReturnIdleAnimation);
		ANIMATION->start("프리즌공격위쪽");
		m_prison = IMAGE->findImage("교도관");
		m_prisonAni = ANIMATION->findAnimation("프리즌위쪽");
		ANIMATION->resume("프리즌위쪽");
		break;
	case PRISON_STATE::PRISON_STATE_WALK_DOWN:
		m_prison = IMAGE->findImage("교도관");
		m_prisonAni = ANIMATION->findAnimation("프리즌아래쪽");
		ANIMATION->resume("프리즌아래쪽");
		m_prisonAttack = IMAGE->findImage("교도관공격");
		m_prisonAttackAni = ANIMATION->findAnimation("프리즌공격아래쪽");
		m_prisonAttackAni->SetTriggerWhenClick(this, &Cprison::ReturnIdleAnimation);
		ANIMATION->start("프리즌공격아래쪽");
		break;
	case PRISON_STATE::PRISON_STATE_WALK_LEFT:
		m_prison = IMAGE->findImage("교도관");
		m_prisonAni = ANIMATION->findAnimation("프리즌왼쪽");
		ANIMATION->resume("프리즌왼쪽");
		m_prisonAttack = IMAGE->findImage("교도관공격");
		m_prisonAttackAni = ANIMATION->findAnimation("프리즌공격왼쪽");
		m_prisonAttackAni->SetTriggerWhenClick(this, &Cprison::ReturnIdleAnimation);
		ANIMATION->start("프리즌공격왼쪽");
		break;
	case PRISON_STATE::PRISON_STATE_WALK_RIGHT:
		m_prison = IMAGE->findImage("교도관");
		m_prisonAni = ANIMATION->findAnimation("프리즌오른쪽");
		ANIMATION->resume("프리즌오른쪽");
		m_prisonAttack = IMAGE->findImage("교도관공격");
		m_prisonAttackAni = ANIMATION->findAnimation("프리즌공격오른쪽");
		m_prisonAttackAni->SetTriggerWhenClick(this, &Cprison::ReturnIdleAnimation);
		ANIMATION->start("프리즌공격오른쪽");
		break;

	case PRISON_STATE::PRISON_STATE_DIE_UP:
		m_prison = IMAGE->findImage("교도관사망");
		m_prisonAni = ANIMATION->findAnimation("프리즌사망위쪽");
		ANIMATION->resume("프리즌사망위쪽");
		break;
	case PRISON_STATE::PRISON_STATE_DIE_DOWN:
		m_prison = IMAGE->findImage("교도관사망");
		m_prisonAni = ANIMATION->findAnimation("프리즌사망위쪽");
		ANIMATION->resume("프리즌사망위쪽");
		break;
	case PRISON_STATE::PRISON_STATE_DIE_LEFT:
		m_prison = IMAGE->findImage("교도관사망");
		m_prisonAni = ANIMATION->findAnimation("프리즌사망위쪽");
		ANIMATION->resume("프리즌사망위쪽");
		break;
	case PRISON_STATE::PRISON_STATE_DIE_RIGHT:
		m_prison = IMAGE->findImage("교도관사망");
		m_prisonAni = ANIMATION->findAnimation("프리즌사망위쪽");
		ANIMATION->resume("프리즌사망위쪽");
		break;
	}
}

void Cprison::move()
{
	if (!isAttack)
	{
		if (InputManager->isStayKeyDown('W'))
		{
			m_y -= m_speed;
			m_prisonState = PRISON_STATE::PRISON_STATE_WALK_UP;
		}
		if (InputManager->isStayKeyDown('S'))
		{
			m_y += m_speed;
			m_prisonState = PRISON_STATE::PRISON_STATE_WALK_DOWN;
		}
		if (InputManager->isStayKeyDown('A'))
		{
			m_x -= m_speed;
			m_prisonState = PRISON_STATE::PRISON_STATE_WALK_LEFT;
		}
		if (InputManager->isStayKeyDown('D'))
		{
			m_x += m_speed;
			m_prisonState = PRISON_STATE::PRISON_STATE_WALK_RIGHT;
		}
	}
	if (InputManager->isOnceKeyDown(VK_SPACE))
	{
		isAttack = true;

	}
	animation();
}

void Cprison::attack()
{

}

void Cprison::die()
{
}

void Cprison::ReturnIdleAnimation()
{
	isAttack = false;
}
