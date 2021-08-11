#include "framework.h"
#include "Cmonk.h"
#include "CenemyAttack.h"
#include "Cplayer.h"

Cmonk::Cmonk()
{
	m_walkImage = nullptr;
}

Cmonk::~Cmonk()
{
}

HRESULT Cmonk::init(POINT position, float HP, float damage, float exp,float trace)
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(5, 100, true , "��ũ������");

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
	m_hpBar->init("images/hp.bmp", "images/hp_back.bmp", m_x, m_y, 33, 5);
	m_hpBar->setGauge(m_hp, m_maxHp);

	m_cooltimeCount = 200;
	m_rndskillCount = 1;

	m_isWalking = true;
	m_isDie = false;

	ANIMATION->addAnimation("��ũ��", "��ũ", 0, 5, 8, false, true);
	ANIMATION->addAnimation("��ũ��", "��ũ", 6, 11, 8, false, true);
	ANIMATION->addAnimation("��ũ��", "��ũ", 12, 17, 8, false, true);
	ANIMATION->addAnimation("��ũ��", "��ũ", 18, 23, 8, false, true);

	ANIMATION->addAnimation("��ũ�����", "��ũ���", 0, 11, 8, false, false);
	ANIMATION->addAnimation("��ũ�����", "��ũ���", 12, 23, 8, false, false);
	ANIMATION->addAnimation("��ũ�����", "��ũ���", 24, 35, 8, false, false);
	ANIMATION->addAnimation("��ũ�����", "��ũ���", 36, 47, 8, false, false);

	m_walkImage = IMAGE->findImage("��ũ");
	m_walkAni = ANIMATION->findAnimation("��ũ��");
	ANIMATION->start("��ũ��");
	return S_OK;
}

void Cmonk::release()
{
	SAFE_DELETE(m_enemyAttack);
	SAFE_DELETE(m_player);
	SAFE_DELETE(m_hpBar);
}

void Cmonk::update()
{
	m_hpBar->setGauge(m_hp, m_maxHp);
	m_hpBar->mapUpdate(m_x - 15, m_y - 45);
	m_enemyAttack->update();
	move();
	attack();
	
	if (m_walkImage != nullptr)
	{
		m_walkRc = RectMakeCenter(m_x, m_y, m_walkImage->getFrameWidth(), m_walkImage->getFrameHeight());
	}
	m_traceRc = RectMakeCenter(m_x, m_y, m_trace, m_trace);
}

void Cmonk::render()
{
	m_hpBar->mapRender();
	if (InputManager->isToggleKey(VK_TAB))
	{
		Rectangle(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkRc.right, m_walkRc.bottom);
		Rectangle(getMapDC(), m_traceRc.left, m_traceRc.top, m_traceRc.right, m_traceRc.bottom);
		Rectangle(getMapDC(), m_dieRc.left, m_dieRc.top, m_dieRc.right, m_dieRc.bottom);
	}
		if (m_isWalking)m_walkImage->aniRender(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkAni);
	m_enemyAttack->render();

}

void Cmonk::attack()
{
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerMoveRC(), &m_traceRc))
	{
		if (m_player->getplayerMoveRC()->right >= m_walkRc.left - m_distance && m_state == STATE::LEFT)
		{

			m_isWalking = false;
				m_enemyAttack->init2(1, 1, true, "��ũ������");
				m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
					m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top) / 2, 0, 1.0f, "��ũ����", "��ũ������");
		}

		else if (m_player->getplayerMoveRC()->left <= m_walkRc.right + m_distance && m_state == STATE::RIGHT)
		{
			m_isWalking = false;
				m_enemyAttack->init2(1, 1, true, "��ũ���ݿ�");
				m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
					m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top) / 2, 0, 1.0f, "��ũ����", "��ũ���ݿ�");
		}

		if (m_player->getplayerMoveRC()->bottom >= m_walkRc.top - m_distance && m_state == STATE::UP)
		{
			m_isWalking = false;
			m_enemyAttack->init2(1, 1, true, "��ũ���ݻ�");
			m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
				m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top) / 2, 0, 1.0f, "��ũ����", "��ũ���ݻ�");
		}

		if (m_player->getplayerMoveRC()->top <= m_walkRc.bottom + m_distance && m_state == STATE::DOWN)
		{
			m_isWalking = false;
			m_enemyAttack->init2(1, 1, true, "��ũ������");
			m_enemyAttack->fire(m_walkRc.right - (m_walkRc.right - m_walkRc.left) / 2,
				m_walkRc.bottom - (m_walkRc.bottom - m_walkRc.top) / 2+10, 0, 1.0f, "��ũ����", "��ũ������");
		}
	}
}

void Cmonk::die()
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

void Cmonk::animation()
{
	switch (m_state)
	{
	case STATE::LEFT:
		m_walkImage = IMAGE->findImage("��ũ");
		m_walkAni = ANIMATION->findAnimation("��ũ��");
		ANIMATION->resume("��ũ��");
		//m_attackImage = IMAGE->findImage("��ũ����");
		//m_attackAni = ANIMATION->findAnimation("��ũ������");
		//ANIMATION->start("��ũ������");
		//m_dieImage = IMAGE->findImage("��ũ���");
		//m_dieAni = ANIMATION->findAnimation("��ũ�����");
		//ANIMATION->resume("��ũ�����");
		break;
	case STATE::RIGHT:
		m_walkImage = IMAGE->findImage("��ũ");
		m_walkAni = ANIMATION->findAnimation("��ũ��");
		ANIMATION->resume("��ũ��");
		//m_attackImage = IMAGE->findImage("��ũ���ݿ�");
		//m_attackAni = ANIMATION->findAnimation("��ũ���ݿ�");
		//ANIMATION->start("��ũ���ݿ�");
		//m_dieImage = IMAGE->findImage("��ũ���");
		//m_dieAni = ANIMATION->findAnimation("��ũ�����");
		//ANIMATION->resume("��ũ�����");
		break;
	case STATE::UP:
		m_walkImage = IMAGE->findImage("��ũ");
		m_walkAni = ANIMATION->findAnimation("��ũ��");
		ANIMATION->resume("��ũ��");
		//m_attackImage = IMAGE->findImage("��ũ����");
		//m_attackAni = ANIMATION->findAnimation("��ũ���ݻ�");
		//ANIMATION->start("��ũ���ݻ�");
		//m_dieImage = IMAGE->findImage("��ũ���");
		//m_dieAni = ANIMATION->findAnimation("��ũ�����");
		//ANIMATION->resume("��ũ�����");
		break;
	case STATE::DOWN:
		m_walkImage = IMAGE->findImage("��ũ");
		m_walkAni = ANIMATION->findAnimation("��ũ��");
		ANIMATION->resume("��ũ��");
		//m_attackImage = IMAGE->findImage("��ũ����");
		//m_attackAni = ANIMATION->findAnimation("��ũ������");
		//ANIMATION->start("��ũ������");
		//m_dieImage = IMAGE->findImage("��ũ���");
		//m_dieAni = ANIMATION->findAnimation("��ũ�����");
		//ANIMATION->resume("��ũ�����");
		break;
	}
}

bool Cmonk::enemyCooltime()
{
	m_cooltimeCount++;

	if (m_cooltimeCount % m_rndskillCount == 0)
	{
		m_rndskillCount = 100;
		m_cooltimeCount = 0;
		return true;
	}
	return false;
}

void Cmonk::ReturnIdleAnimation()
{
	m_isAttack = false;
}


