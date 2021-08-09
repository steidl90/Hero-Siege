#include "framework.h"
#include "Cmonk.h"

Cmonk::Cmonk()
{
	m_monk = nullptr;
}

Cmonk::~Cmonk(){}

HRESULT Cmonk::init()
{
	m_monk = IMAGE->findImage("根农");
	m_monkAttack = IMAGE->findImage("根农傍拜");
	m_monkDie = IMAGE->findImage("根农荤噶");

	m_direction = MONK_DIRECTION::MONK_DIRECTION_DOWN;
	m_beforeDirection = MONK_DIRECTION::MONK_DIRECTION_DOWN;

	ANIMATION->addAnimation("根农酒贰率", "根农", 0, 5, 8, false, true);
	ANIMATION->addAnimation("根农哭率", "根农", 6, 11, 8, false, true);
	ANIMATION->addAnimation("根农坷弗率", "根农", 12, 17, 8, false, true);
	ANIMATION->addAnimation("根农困率", "根农", 18, 23, 8, false, true);

	ANIMATION->addAnimation("根农傍拜酒贰率", "根农傍拜", 0, 4, false, true);
	ANIMATION->addAnimation("根农傍拜哭率", "根农傍拜", 5, 9, false, true);
	ANIMATION->addAnimation("根农傍拜坷弗率", "根农傍拜", 10, 14, false, true);
	ANIMATION->addAnimation("根农傍拜困率", "根农傍拜", 15, 19, false, true);

	ANIMATION->addAnimation("根农荤噶酒贰率", "根农荤噶", 0, 11, false, true);
	ANIMATION->addAnimation("根农荤噶哭率", "根农荤噶", 12, 23, false, true);
	ANIMATION->addAnimation("根农荤噶坷弗率", "根农荤噶", 24, 35, false, true);
	ANIMATION->addAnimation("根农荤噶困率", "根农荤噶", 36, 47, false, true);

	m_x = WINSIZEX / 2;
	m_y = WINSIZEY / 2;
	m_speed = 2.0f;

	isWalking = false;
	isAttack = false;
	isDie = false;

	m_monkAni = ANIMATION->findAnimation("根农酒贰率");
	m_monkAttackAni = ANIMATION->findAnimation("根农傍拜酒贰率");

	m_monkRc = RectMakeCenter(m_x, m_y, m_monk->getFrameWidth(), m_monk->getFrameHeight());
	m_monkAttackRc = RectMakeCenter(300, 300, m_monkAttack->getFrameWidth(), m_monkAttack->getFrameHeight());

	return S_OK;
}

void Cmonk::release()
{
}

void Cmonk::update()
{
	//if (m_monk != nullptr)
	//{
		move();
		m_monkRc = RectMakeCenter(m_x, m_y, m_monk->getFrameWidth(), m_monk->getFrameHeight());
	//}
}

void Cmonk::render()
{
	if (m_monk != nullptr)
	{
		//Rectangle(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkRc.right, m_monkRc.bottom);
		if (isWalking == true)
		{
			switch (m_direction)
			{
			case MONK_DIRECTION::MONK_DIRECTION_UP:
				if (!isAttack)m_monk->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				else
				{
					Rectangle(getMapDC(), m_monkRc.left, m_y, m_monkRc.left, m_y);
					m_monkAttack->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				}
				break;
			case MONK_DIRECTION::MONK_DIRECTION_DOWN:
				if (!isAttack)m_monk->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				else
				{
					Rectangle(getMapDC(), m_monkRc.left, m_y, m_monkRc.left, m_y);
					m_monkAttack->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				}
				break;
			case MONK_DIRECTION::MONK_DIRECTION_LEFT:
				if (!isAttack)m_monk->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				else
				{
					Rectangle(getMapDC(), m_monkRc.left, m_y, m_monkRc.left, m_y);
					m_monkAttack->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				}
				break;
			case MONK_DIRECTION::MONK_DIRECTION_RIGHT:
				if (!isAttack)m_monk->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				else
				{
					Rectangle(getMapDC(), m_monkRc.left, m_y, m_monkRc.left, m_y);
					m_monkAttack->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				}
				break;
			}
		}		//if isMoving
		else if (isWalking == false)
		{
			switch (m_direction)
			{
			case MONK_DIRECTION::MONK_DIRECTION_UP:
				if (isAttack == false) 
				{
					m_monk->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
					m_monkAni = ANIMATION->findAnimation("根农困率");
					ANIMATION->start("根农困率");
				}
				else
				{
					Rectangle(getMapDC(), m_monkRc.left, m_y, m_monkRc.left, m_y);
					m_monkAttack->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				}
				break;
			case MONK_DIRECTION::MONK_DIRECTION_DOWN:
				if (isAttack == false)
				{
					m_monk->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
					m_monkAni = ANIMATION->findAnimation("根农酒贰率");
					ANIMATION->start("根农酒贰率");
				}
				else
				{
					Rectangle(getMapDC(), m_monkRc.left, m_y, m_monkRc.left, m_y);
					m_monkAttack->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				}
				break;
			case MONK_DIRECTION::MONK_DIRECTION_LEFT:
				if (isAttack == false)
				{
					m_monk->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
					m_monkAni = ANIMATION->findAnimation("根农哭率");
					ANIMATION->start("根农哭率");
				}
				else
				{
					Rectangle(getMapDC(), m_monkRc.left, m_y, m_monkRc.left, m_y);
					m_monkAttack->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				}
				break;
			case MONK_DIRECTION::MONK_DIRECTION_RIGHT:
				if (isAttack == false)
				{
					m_monk->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
					m_monkAni = ANIMATION->findAnimation("根农坷弗率");
					ANIMATION->start("根农坷弗率");
				}
				else
				{
					Rectangle(getMapDC(), m_monkRc.left, m_y, m_monkRc.left, m_y);
					m_monkAttack->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAni);
				}
				break;
			}
		}
	}
}

void Cmonk::move()
{
	RECT rc;
	rc = m_monkRc;
	float elpasedTime = TIME->getElapsedTime();
	float moveSpeed = elpasedTime * m_speed;

	if (InputManager->isStayKeyDown('W'))
	{
		m_y -= moveSpeed;
		isWalking = true;
		m_direction = MONK_DIRECTION::MONK_DIRECTION_UP;
	}
	//else isWalking = false;
	if (InputManager->isStayKeyDown('S'))
	{
		m_y += moveSpeed;
		isWalking = true;
		m_direction = MONK_DIRECTION::MONK_DIRECTION_DOWN;
	}
	//else isWalking = false;
	if (InputManager->isStayKeyDown('A'))
	{
		m_x -= moveSpeed;
		isWalking = true;
		m_direction = MONK_DIRECTION::MONK_DIRECTION_LEFT;
	}
	//else isWalking = false;
	if (InputManager->isStayKeyDown('D'))
	{
		m_x += moveSpeed;
		isWalking = true;
		m_direction = MONK_DIRECTION::MONK_DIRECTION_RIGHT;
	}
	//else isWalking = false;

	if (InputManager->isStayKeyDown(VK_SPACE)) isAttack = true;
	else isAttack = false;

	if (InputManager->isOnceKeyDown('E')) isDie = true;
	if (InputManager->isOnceKeyDown('R')) isDie = false;

	moveAni();
	
}

void Cmonk::moveAni()
{
	if (m_beforeDirection == m_direction) return;
	m_beforeDirection = m_direction;

	switch (m_direction)
	{
	case MONK_DIRECTION::MONK_DIRECTION_UP:

		if (isWalking)
		{
			m_monkAni = ANIMATION->findAnimation("根农困率");
			ANIMATION->start("根农困率");
			m_monkAni = ANIMATION->findAnimation("根农傍拜困率");
			ANIMATION->start("根农傍拜困率");
		}
		break;
	case MONK_DIRECTION::MONK_DIRECTION_DOWN:
		if (isWalking)
		{
			m_monkAni = ANIMATION->findAnimation("根农酒贰率");
			ANIMATION->start("根农酒贰率");
			m_monkAni = ANIMATION->findAnimation("根农傍拜酒贰率");
			ANIMATION->start("根农傍拜酒贰率");
		}
		break;
	case MONK_DIRECTION::MONK_DIRECTION_LEFT:
		if (isWalking)
		{
			m_monkAni = ANIMATION->findAnimation("根农哭率");
			ANIMATION->start("根农哭率");
			m_monkAni = ANIMATION->findAnimation("根农傍拜哭率");
			ANIMATION->start("根农傍拜哭率");
		}
		break;
	case MONK_DIRECTION::MONK_DIRECTION_RIGHT:
		if (isWalking)
		{
			m_monkAni = ANIMATION->findAnimation("根农坷弗率");
			ANIMATION->start("根农坷弗率");
			m_monkAni = ANIMATION->findAnimation("根农傍拜坷弗率");
			ANIMATION->start("根农傍拜坷弗率");
		}
		break;
	}
}

void Cmonk::attack()
{
	if (isAttack)
	{
		switch (m_direction)
		{
		case MONK_DIRECTION::MONK_DIRECTION_UP:
			m_monkAttackAni = ANIMATION->findAnimation("根农傍拜困率");
			ANIMATION->start("根农傍拜困率");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_DOWN:
			m_monkAttackAni = ANIMATION->findAnimation("根农傍拜酒贰率");
			ANIMATION->start("根农傍拜酒贰率");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_LEFT:
			m_monkAttackAni = ANIMATION->findAnimation("根农傍拜哭率");
			ANIMATION->start("根农傍拜哭率");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_RIGHT:
			m_monkAttackAni = ANIMATION->findAnimation("根农傍拜坷弗率");
			ANIMATION->start("根农傍拜坷弗率");
			break;

		}
	}
}

void Cmonk::Die()
{
	if (isDie)
	{
		switch (m_direction)
		{
		case MONK_DIRECTION::MONK_DIRECTION_UP:
			m_monkAttackAni = ANIMATION->findAnimation("根农荤噶困率");
			ANIMATION->start("根农荤噶困率");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_DOWN:
			m_monkAttackAni = ANIMATION->findAnimation("根农荤噶酒贰率");
			ANIMATION->start("根农荤噶酒贰率");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_LEFT:
			m_monkAttackAni = ANIMATION->findAnimation("根农荤噶哭率");
			ANIMATION->start("根农荤噶哭率");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_RIGHT:
			m_monkAttackAni = ANIMATION->findAnimation("根农荤噶坷弗率");
			ANIMATION->start("根农荤噶坷弗率");
			break;

		}
	}
}
