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


	ANIMATION->addAnimation("������Ʒ���", "������", 0, 7, 8, false, true);
	ANIMATION->addAnimation("���������", "������", 8, 15, 8, false, true);
	ANIMATION->addAnimation("�����������", "������", 16, 23, 8, false, true);
	ANIMATION->addAnimation("����������", "������", 24, 31, 8, false, true);

	ANIMATION->addAnimation("��������ݾƷ���", "����������", 0, 7, 8, false, false);
	ANIMATION->addAnimation("��������ݿ���", "����������", 8, 15, 8, false, false);
	ANIMATION->addAnimation("��������ݿ�����", "����������", 16, 23, 8, false, false);
	ANIMATION->addAnimation("�������������", "����������", 24, 31, 8, false, false);

	ANIMATION->addAnimation("���������Ʒ���", "���������", 0, 12, 8, false, true);
	ANIMATION->addAnimation("������������", "���������", 13, 25, 8, false, true);
	ANIMATION->addAnimation("��������������", "���������", 26, 38, 8, false, true);
	ANIMATION->addAnimation("������������", "���������", 39, 51, 8, false, true);



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

		m_prisonAttack = IMAGE->findImage("����������");
		m_prisonAttackAni = ANIMATION->findAnimation("�������������");
		m_prisonAttackAni->SetTriggerWhenClick(this, &Cprison::ReturnIdleAnimation);
		ANIMATION->start("�������������");
		m_prison = IMAGE->findImage("������");
		m_prisonAni = ANIMATION->findAnimation("����������");
		ANIMATION->resume("����������");
		break;
	case PRISON_STATE::PRISON_STATE_WALK_DOWN:
		m_prison = IMAGE->findImage("������");
		m_prisonAni = ANIMATION->findAnimation("������Ʒ���");
		ANIMATION->resume("������Ʒ���");
		m_prisonAttack = IMAGE->findImage("����������");
		m_prisonAttackAni = ANIMATION->findAnimation("��������ݾƷ���");
		m_prisonAttackAni->SetTriggerWhenClick(this, &Cprison::ReturnIdleAnimation);
		ANIMATION->start("��������ݾƷ���");
		break;
	case PRISON_STATE::PRISON_STATE_WALK_LEFT:
		m_prison = IMAGE->findImage("������");
		m_prisonAni = ANIMATION->findAnimation("���������");
		ANIMATION->resume("���������");
		m_prisonAttack = IMAGE->findImage("����������");
		m_prisonAttackAni = ANIMATION->findAnimation("��������ݿ���");
		m_prisonAttackAni->SetTriggerWhenClick(this, &Cprison::ReturnIdleAnimation);
		ANIMATION->start("��������ݿ���");
		break;
	case PRISON_STATE::PRISON_STATE_WALK_RIGHT:
		m_prison = IMAGE->findImage("������");
		m_prisonAni = ANIMATION->findAnimation("�����������");
		ANIMATION->resume("�����������");
		m_prisonAttack = IMAGE->findImage("����������");
		m_prisonAttackAni = ANIMATION->findAnimation("��������ݿ�����");
		m_prisonAttackAni->SetTriggerWhenClick(this, &Cprison::ReturnIdleAnimation);
		ANIMATION->start("��������ݿ�����");
		break;

	case PRISON_STATE::PRISON_STATE_DIE_UP:
		m_prison = IMAGE->findImage("���������");
		m_prisonAni = ANIMATION->findAnimation("������������");
		ANIMATION->resume("������������");
		break;
	case PRISON_STATE::PRISON_STATE_DIE_DOWN:
		m_prison = IMAGE->findImage("���������");
		m_prisonAni = ANIMATION->findAnimation("������������");
		ANIMATION->resume("������������");
		break;
	case PRISON_STATE::PRISON_STATE_DIE_LEFT:
		m_prison = IMAGE->findImage("���������");
		m_prisonAni = ANIMATION->findAnimation("������������");
		ANIMATION->resume("������������");
		break;
	case PRISON_STATE::PRISON_STATE_DIE_RIGHT:
		m_prison = IMAGE->findImage("���������");
		m_prisonAni = ANIMATION->findAnimation("������������");
		ANIMATION->resume("������������");
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
