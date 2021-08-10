#include "framework.h"
#include "Cpriest.h"
#include "CenemyAttack.h"

Cpriest::Cpriest()
{
}

Cpriest::~Cpriest()
{
}

HRESULT Cpriest::init()
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(50, 500);

	m_isIdle = false;
	m_state = STATE::DOWN;

	ANIMATION->addAnimation("��ġ��", "��ġ", 0, 5, 8, false, true);
	ANIMATION->addAnimation("��ġ��", "��ġ", 6, 11, 8, false, true);
	ANIMATION->addAnimation("��ġ��", "��ġ", 12, 17, 8, false, true);
	ANIMATION->addAnimation("��ġ��", "��ġ", 18, 23, 8, false, true);

	ANIMATION->addAnimation("��ġ������", "��ġ����", 0, 15, 8, false, false);
	ANIMATION->addAnimation("��ġ������", "��ġ����", 16, 31, 8, false, false);
	ANIMATION->addAnimation("��ġ���ݿ�", "��ġ����", 32, 47, 8, false, false);
	ANIMATION->addAnimation("��ġ���ݻ�", "��ġ����", 48, 63, 8, false, false);

	ANIMATION->addAnimation("��ġ�����", "��ġ���", 0, 9, 8, false, false);
	ANIMATION->addAnimation("��ġ�����", "��ġ���", 10, 19, 8, false, false);
	ANIMATION->addAnimation("��ġ�����", "��ġ���", 20, 29, 8, false, false);
	ANIMATION->addAnimation("��ġ�����", "��ġ���", 30, 39, 8, false, false);

	m_walkImage = IMAGE->findImage("��ġ");
	m_walkAni = ANIMATION->findAnimation("��ġ��");
	ANIMATION->start("��ġ��");

	m_x = WINSIZEX / 2;
	m_y = WINSIZEY / 2;
	m_speed = 2.0f;
	m_hp = 100;
	m_damage = 10;
	return S_OK;
}

void Cpriest::release()
{
}

void Cpriest::update()
{
	m_state = STATE::IDLE;
	move();
}

void Cpriest::render()
{
	if (m_isWalking)
	{
		Rectangle(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkRc.right, m_walkRc.bottom);
		m_walkRc = RectMakeCenter(m_x, m_y, m_walkImage->getFrameWidth(), m_walkImage->getFrameHeight());
	}
	if(m_isAttack)
	{
		Rectangle(getMapDC(), m_attackRc.left, m_attackRc.top, m_attackRc.right, m_attackRc.bottom);
		m_attackRc = RectMakeCenter(m_x, m_y, m_attackImage->getFrameWidth(), m_attackImage->getFrameHeight());
	}
	if (m_isDie)
	{
		Rectangle(getMapDC(), m_dieRc.left, m_dieRc.top, m_dieRc.right, m_dieRc.bottom);
		m_dieRc = RectMakeCenter(m_x, m_y, m_dieImage->getFrameWidth(), m_dieImage->getFrameHeight());
	}
}

void Cpriest::move()
{ 
}

void Cpriest::attack()
{
}

void Cpriest::die()
{
}

void Cpriest::animation()
{
}

bool Cpriest::enemyCoolTime()
{
	return false;
}
