#include "framework.h"
#include "Cprison.h"
#include "CenemyAttack.h"
#include "Cplayer.h"

Cprison::Cprison()
{
}

Cprison::~Cprison()
{
}

HRESULT Cprison::init(POINT position, float HP, float damage, int exp, float trace)
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(5, 100, true, "������������");

	m_player = new Cplayer;
	m_player->init();

	m_isIdle = false;
	m_state = STATE::DOWN;

	m_x = m_returnX = position.x;
	m_y = m_returnY = position.y;
	m_trace = trace;

	m_distance = 10.0f;
	m_speed = 2.0f;
	m_hp = m_maxHp = HP;
	m_damage = damage;
	m_exp = exp;

	m_hpBar = new CprogressBar;
	m_hpBar->init("images/hp.bmp", "images/hp_back.bmp", m_x, m_y, 33, 4);
	m_hpBar->setGauge(m_hp, m_maxHp);

	m_cooltimeCount = 200;
	m_rndskillCount = 1;

	m_isWalking = true;
	m_isDie = false;

	ANIMATION->addAnimation("��������", "������", 0, 7, 8, false, true);
	ANIMATION->addAnimation("��������", "������", 8, 15, 8, false, true);
	ANIMATION->addAnimation("��������", "������", 16, 23, 8, false, true);
	ANIMATION->addAnimation("��������", "������", 24, 31, 8, false, true);

	ANIMATION->addAnimation("�����������", "���������", 0, 12, 8, false, false);
	ANIMATION->addAnimation("�����������", "���������", 13, 25, 8, false, false);
	ANIMATION->addAnimation("�����������", "���������", 26, 38, 8, false, false);
	ANIMATION->addAnimation("�����������", "���������", 39, 51, 8, false, false);

	m_walkImage = IMAGE->findImage("������");
	m_walkAni = ANIMATION->findAnimation("��������");
	ANIMATION->start("��������");
	return S_OK;
}

void Cprison::release()
{
	SAFE_DELETE(m_enemyAttack);
	SAFE_DELETE(m_player);
	SAFE_DELETE(m_hpBar);
}

void Cprison::update()
{
	m_hpBar->setGauge(m_hp, m_maxHp);
	m_hpBar->mapUpdate(m_x - 15, m_y - 45);
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

void Cprison::render()
{
	if (InputManager->isToggleKey(VK_TAB))
	{
		Rectangle(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkRc.right, m_walkRc.bottom);
		Rectangle(getMapDC(), m_traceRc.left, m_traceRc.top, m_traceRc.right, m_traceRc.bottom);
		Rectangle(getMapDC(), m_dieRc.left, m_dieRc.top, m_dieRc.right, m_dieRc.bottom);
	}
	m_hpBar->mapRender();
	IMAGE->findImage("�Ϲݸ���ü�¹�")->render(getMapDC(), m_x -21, m_y - 48);
	if (m_isWalking)m_walkImage->aniRender(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkAni);
	m_enemyAttack->render();
}

void Cprison::attack()
{
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerMoveRC(), &m_traceRc))
	{
		if (m_player->getplayerMoveRC()->right >= m_walkRc.left - m_distance && m_state == STATE::LEFT)
		{

			m_isWalking = false;
			m_enemyAttack->init2(1, 1, true, "������������");
			m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
				m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top) / 2, 0, 1.0f, "����������", "������������");
		}

		else if (m_player->getplayerMoveRC()->left <= m_walkRc.right + m_distance && m_state == STATE::RIGHT)
		{
			m_isWalking = false;
			m_enemyAttack->init2(1, 1, true, "���������ݿ�");
			m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
				m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top) / 2, 0, 1.0f, "����������", "���������ݿ�");
		}

		if (m_player->getplayerMoveRC()->bottom >= m_walkRc.top - m_distance && m_state == STATE::UP)
		{
			m_isWalking = false;
			m_enemyAttack->init2(1, 1, true, "���������ݻ�");
			m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
				m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top) / 2, 0, 1.0f, "����������", "���������ݻ�");
		}

		if (m_player->getplayerMoveRC()->top <= m_walkRc.bottom + m_distance && m_state == STATE::DOWN)
		{
			m_isWalking = false;
			m_enemyAttack->init2(1, 1, true, "������������");
			m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
				m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top) / 2 + 10, 0, 1.0f, "����������", "������������");
		}
	}
}

void Cprison::die()
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

void Cprison::animation()
{
	switch (m_state)
	{
	case STATE::LEFT:
		m_walkImage = IMAGE->findImage("������");
		m_walkAni = ANIMATION->findAnimation("��������");
		ANIMATION->resume("��������");
		break;
	case STATE::RIGHT:
		m_walkImage = IMAGE->findImage("������");
		m_walkAni = ANIMATION->findAnimation("��������");
		ANIMATION->resume("��������");
		break;
	case STATE::UP:
		m_walkImage = IMAGE->findImage("������");
		m_walkAni = ANIMATION->findAnimation("��������");
		ANIMATION->resume("��������");
		break;
	case STATE::DOWN:
		m_walkImage = IMAGE->findImage("������");
		m_walkAni = ANIMATION->findAnimation("��������");
		ANIMATION->resume("��������");
		break;
	}
}

bool Cprison::enemyCooltime()
{
	return false;
}
