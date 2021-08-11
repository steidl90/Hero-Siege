#include "framework.h"
#include "Cpriest.h"
#include "CenemyAttack.h"
#include "Cplayer.h"

Cpriest::Cpriest()
{
}

Cpriest::~Cpriest()
{
}

HRESULT Cpriest::init(POINT position, float HP, float damage, float exp,float trace)
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(50, 500, false, "��ġ��ų�ִ�");

	m_player = new Cplayer;
	m_player->init();

	m_isIdle = false;
	m_state = STATE::DOWN;

	m_x = m_returnX = position.x;
	m_y = m_returnY = position.y;
	m_trace = trace;

	m_distance = 100.0f;
	m_speed = 2.0f;
	m_hp = HP;
	m_damage = damage;
	m_exp = exp;

	m_cooltimeCount = 260;
	m_rndskillCount = 259;

	m_isWalking = true;
	m_isDie = false;

	ANIMATION->addAnimation("��ġ��", "��ġ", 0, 5, 8, false, true);
	ANIMATION->addAnimation("��ġ��", "��ġ", 6, 11, 8, false, true);
	ANIMATION->addAnimation("��ġ��", "��ġ", 12, 17, 8, false, true);
	ANIMATION->addAnimation("��ġ��", "��ġ", 18, 23, 8, false, true);

	ANIMATION->addAnimation("��ġ������", "��ġ����", 0, 15, 8,	true, true);
	ANIMATION->addAnimation("��ġ������", "��ġ����", 16, 31, 8,	true, true);
	ANIMATION->addAnimation("��ġ���ݿ�", "��ġ����", 32, 47, 8,  true, true);
	ANIMATION->addAnimation("��ġ���ݻ�", "��ġ����", 48, 63, 8,  true, true);

	ANIMATION->addAnimation("��ġ�����", "��ġ���", 0, 9, 8, false, false);
	ANIMATION->addAnimation("��ġ�����", "��ġ���", 10, 19, 8, false, false);
	ANIMATION->addAnimation("��ġ�����", "��ġ���", 20, 29, 8, false, false);
	ANIMATION->addAnimation("��ġ�����", "��ġ���", 30, 39, 8, false, false);

	m_walkImage = IMAGE->findImage("��ġ");
	m_walkAni = ANIMATION->findAnimation("��ġ��");
	ANIMATION->start("��ġ��");
	return S_OK;
}

void Cpriest::release()
{
	SAFE_DELETE(m_enemyAttack);
	SAFE_DELETE(m_player);
}

void Cpriest::update()
{
	m_enemyAttack->update();
	move();
	attack();
	die();
	if (m_walkImage != nullptr)
	{
		m_walkRc = RectMakeCenter(m_x, m_y, m_walkImage->getFrameWidth(), m_walkImage->getFrameHeight());
	}
	m_traceRc = RectMakeCenter(m_x, m_y, m_trace, m_trace);
}

void Cpriest::render()
{
	if (InputManager->isToggleKey(VK_TAB))
	{
		Rectangle(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkRc.right, m_walkRc.bottom);
		Rectangle(getMapDC(), m_traceRc.left, m_traceRc.top, m_traceRc.right, m_traceRc.bottom);
		Rectangle(getMapDC(), m_dieRc.left, m_dieRc.top, m_dieRc.right, m_dieRc.bottom);
	}
	if (m_isWalking)m_walkImage->aniRender(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkAni);
	m_enemyAttack->render();
}

void Cpriest::attack()
{
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerMoveRC(), &m_traceRc))
	{
		m_cooltimeCount++;

		if (m_state == STATE::LEFT)
		{
			m_walkImage = IMAGE->findImage("��ġ����");
			m_walkAni = ANIMATION->findAnimation("��ġ������");
			ANIMATION->fullstart("��ġ������");
			fire();

		}
		if (m_state == STATE::RIGHT)
		{
			m_walkImage = IMAGE->findImage("��ġ����");
			m_walkAni = ANIMATION->findAnimation("��ġ���ݿ�");
			ANIMATION->fullstart("��ġ���ݿ�");
			fire();

		}
		if (m_state == STATE::UP)
		{
			m_walkImage = IMAGE->findImage("��ġ����");
			m_walkAni = ANIMATION->findAnimation("��ġ���ݻ�");
			ANIMATION->fullstart("��ġ���ݻ�");
			fire();
		}
		if (m_state == STATE::DOWN)
		{
			m_walkImage = IMAGE->findImage("��ġ����");
			m_walkAni = ANIMATION->findAnimation("��ġ������");
			ANIMATION->fullstart("��ġ������");
			fire();

		}
	}
}

void Cpriest::die()
{
	if (m_hp <= 0)
	{
		if (m_state == STATE::LEFT)
		{

		}
		if (m_state == STATE::RIGHT)
		{

		}
		if (m_state == STATE::UP)
		{

		}
		if (m_state == STATE::DOWN)
		{

		}
	}
}

void Cpriest::animation()
{
	switch (m_state)
	{
	case STATE::LEFT:
		m_walkImage = IMAGE->findImage("��ġ");
		m_walkAni = ANIMATION->findAnimation("��ġ��");
		ANIMATION->resume("��ġ��");
		break;
	case STATE::RIGHT:
		m_walkImage = IMAGE->findImage("��ġ");
		m_walkAni = ANIMATION->findAnimation("��ġ��");
		ANIMATION->resume("��ġ��");
		break;
	case STATE::UP:
		m_walkImage = IMAGE->findImage("��ġ");
		m_walkAni = ANIMATION->findAnimation("��ġ��");
		ANIMATION->resume("��ġ��");
		break;
	case STATE::DOWN:
		m_walkImage = IMAGE->findImage("��ġ");
		m_walkAni = ANIMATION->findAnimation("��ġ��");
		ANIMATION->resume("��ġ��");
		break;
	}
}

bool Cpriest::enemyCooltime()
{

	if (m_cooltimeCount % m_rndskillCount == 0)
	{
		m_rndskillCount = 100;
		m_cooltimeCount = 0;
		return true;
	}
	return false;
}

void Cpriest::fire()
{
	if (enemyCooltime()) {
		m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
			m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top) / 2,
			UTIL::getAngle(m_walkRc.left + (m_walkRc.right - m_walkRc.left) / 2,
				m_walkRc.bottom + (m_walkRc.top - m_walkRc.bottom) / 2,
				m_player->getplayerMoveRC()->left + (m_player->getplayerMoveRC()->right - m_player->getplayerMoveRC()->left) / 2,
				m_player->getplayerMoveRC()->top + (m_player->getplayerMoveRC()->bottom - m_player->getplayerMoveRC()->top) / 2),
			5.0f, "��ġ��ų", "��ġ��ų�ִ�");
	}
}
