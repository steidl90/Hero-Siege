#include "framework.h"
#include "Cmonk.h"

Cmonk::Cmonk()
{
	m_monk = nullptr;
}

Cmonk::~Cmonk(){}

HRESULT Cmonk::init()
{
	m_monk = IMAGE->findImage("��ũ");
	m_monkAttack = IMAGE->findImage("��ũ����");
	m_monkDie = IMAGE->findImage("��ũ���");

	m_direction = MONK_DIRECTION::MONK_DIRECTION_DOWN;
	m_beforeDirection = MONK_DIRECTION::MONK_DIRECTION_DOWN;

	ANIMATION->addAnimation("��ũ�Ʒ���", "��ũ", 0, 5, 8, false, true);
	ANIMATION->addAnimation("��ũ����", "��ũ", 6, 11, 8, false, true);
	ANIMATION->addAnimation("��ũ������", "��ũ", 12, 17, 8, false, true);
	ANIMATION->addAnimation("��ũ����", "��ũ", 18, 23, 8, false, true);

	ANIMATION->addAnimation("��ũ���ݾƷ���", "��ũ����", 0, 4, false, true);
	ANIMATION->addAnimation("��ũ���ݿ���", "��ũ����", 5, 9, false, true);
	ANIMATION->addAnimation("��ũ���ݿ�����", "��ũ����", 10, 14, false, true);
	ANIMATION->addAnimation("��ũ��������", "��ũ����", 15, 19, false, true);

	ANIMATION->addAnimation("��ũ����Ʒ���", "��ũ���", 0, 11, false, true);
	ANIMATION->addAnimation("��ũ�������", "��ũ���", 12, 23, false, true);
	ANIMATION->addAnimation("��ũ���������", "��ũ���", 24, 35, false, true);
	ANIMATION->addAnimation("��ũ�������", "��ũ���", 36, 47, false, true);

	m_x = WINSIZEX / 2;
	m_y = WINSIZEY / 2;
	m_speed = 2.0f;

	isWalking = false;
	isAttack = false;
	isDie = false;

	m_monkAni = ANIMATION->findAnimation("��ũ�Ʒ���");
	m_monkAttackAni = ANIMATION->findAnimation("��ũ���ݾƷ���");

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
					m_monkAni = ANIMATION->findAnimation("��ũ����");
					ANIMATION->start("��ũ����");
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
					m_monkAni = ANIMATION->findAnimation("��ũ�Ʒ���");
					ANIMATION->start("��ũ�Ʒ���");
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
					m_monkAni = ANIMATION->findAnimation("��ũ����");
					ANIMATION->start("��ũ����");
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
					m_monkAni = ANIMATION->findAnimation("��ũ������");
					ANIMATION->start("��ũ������");
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
			m_monkAni = ANIMATION->findAnimation("��ũ����");
			ANIMATION->start("��ũ����");
			m_monkAni = ANIMATION->findAnimation("��ũ��������");
			ANIMATION->start("��ũ��������");
		}
		break;
	case MONK_DIRECTION::MONK_DIRECTION_DOWN:
		if (isWalking)
		{
			m_monkAni = ANIMATION->findAnimation("��ũ�Ʒ���");
			ANIMATION->start("��ũ�Ʒ���");
			m_monkAni = ANIMATION->findAnimation("��ũ���ݾƷ���");
			ANIMATION->start("��ũ���ݾƷ���");
		}
		break;
	case MONK_DIRECTION::MONK_DIRECTION_LEFT:
		if (isWalking)
		{
			m_monkAni = ANIMATION->findAnimation("��ũ����");
			ANIMATION->start("��ũ����");
			m_monkAni = ANIMATION->findAnimation("��ũ���ݿ���");
			ANIMATION->start("��ũ���ݿ���");
		}
		break;
	case MONK_DIRECTION::MONK_DIRECTION_RIGHT:
		if (isWalking)
		{
			m_monkAni = ANIMATION->findAnimation("��ũ������");
			ANIMATION->start("��ũ������");
			m_monkAni = ANIMATION->findAnimation("��ũ���ݿ�����");
			ANIMATION->start("��ũ���ݿ�����");
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
			m_monkAttackAni = ANIMATION->findAnimation("��ũ��������");
			ANIMATION->start("��ũ��������");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_DOWN:
			m_monkAttackAni = ANIMATION->findAnimation("��ũ���ݾƷ���");
			ANIMATION->start("��ũ���ݾƷ���");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_LEFT:
			m_monkAttackAni = ANIMATION->findAnimation("��ũ���ݿ���");
			ANIMATION->start("��ũ���ݿ���");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_RIGHT:
			m_monkAttackAni = ANIMATION->findAnimation("��ũ���ݿ�����");
			ANIMATION->start("��ũ���ݿ�����");
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
			m_monkAttackAni = ANIMATION->findAnimation("��ũ�������");
			ANIMATION->start("��ũ�������");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_DOWN:
			m_monkAttackAni = ANIMATION->findAnimation("��ũ����Ʒ���");
			ANIMATION->start("��ũ����Ʒ���");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_LEFT:
			m_monkAttackAni = ANIMATION->findAnimation("��ũ�������");
			ANIMATION->start("��ũ�������");
			break;
		case MONK_DIRECTION::MONK_DIRECTION_RIGHT:
			m_monkAttackAni = ANIMATION->findAnimation("��ũ���������");
			ANIMATION->start("��ũ���������");
			break;

		}
	}
}
