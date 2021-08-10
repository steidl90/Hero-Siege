#include "framework.h"
#include "Cmonk.h"
#include "CenemyAttack.h"
#include "Cplayer.h"

Cmonk::Cmonk()
{
}

Cmonk::~Cmonk()
{
}

HRESULT Cmonk::init(POINT position, int HP)
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(50, 500, "������Ż��ų�ִ�");

	m_player = new Cplayer;
	m_player->init();

	m_isIdle = false;
	m_state = STATE::DOWN;

	m_x = m_returnX = position.x;
	m_y = m_returnY = position.y;

	m_distance = 10.0f;
	m_speed = 2.0f;
	m_hp = HP;

	m_cooltimeCount = 0;
	m_rndskillCount = 1;

	m_isWalking = true;
	m_isAttack = false;
	m_isDie = false;

	ANIMATION->addAnimation("��ũ��", "��ũ", 0, 5, 8, false, true);
	ANIMATION->addAnimation("��ũ��", "��ũ", 6, 11, 8, false, true);
	ANIMATION->addAnimation("��ũ��", "��ũ", 12, 17, 8, false, true);
	ANIMATION->addAnimation("��ũ��", "��ũ", 18, 23, 8, false, true);

	ANIMATION->addAnimation("��ũ������", "��ũ����", 0, 4, 8,	true, false);
	ANIMATION->addAnimation("��ũ������", "��ũ����", 5, 9, 8,	true, false);
	ANIMATION->addAnimation("��ũ���ݿ�", "��ũ����", 10, 14, 8,	true, false);
	ANIMATION->addAnimation("��ũ���ݻ�", "��ũ����", 15, 19, 8,	true, false);

	ANIMATION->addAnimation("��ũ�����", "��ũ���", 0, 11, 8, false,  false);
	ANIMATION->addAnimation("��ũ�����", "��ũ���", 12, 23, 8, false, false);
	ANIMATION->addAnimation("��ũ�����", "��ũ���", 24, 35, 8, false, false);
	ANIMATION->addAnimation("��ũ�����", "��ũ���", 36, 47, 8, false, false);

	m_walkImage = IMAGE->findImage("��ũ");
	m_walkAni = ANIMATION->findAnimation("��ũ��");
	ANIMATION->start("��ũ��");
	return S_OK;
}

void Cmonk::attack()
{

}

void Cmonk::die()
{
}

void Cmonk::animation()
{
	switch (m_state)
	{
	case STATE::LEFT:
		m_walkImage = IMAGE->findImage("��ũ");
		m_walkAni = ANIMATION->findAnimation("��ũ��");
		ANIMATION->resume("��ũ��");
		m_attackImage = IMAGE->findImage("��ũ����");
		m_attackAni = ANIMATION->findAnimation("��ũ������");
		ANIMATION->start("��ũ������");
		m_dieImage = IMAGE->findImage("��ũ���");
		m_dieAni = ANIMATION->findAnimation("��ũ�����");
		ANIMATION->resume("��ũ�����");
		break;
	case STATE::RIGHT:
		m_walkImage = IMAGE->findImage("��ũ");
		m_walkAni = ANIMATION->findAnimation("��ũ��");
		ANIMATION->resume("��ũ��");
		m_attackImage = IMAGE->findImage("��ũ���ݿ�");
		m_attackAni = ANIMATION->findAnimation("��ũ���ݿ�");
		ANIMATION->start("��ũ���ݿ�");
		m_dieImage = IMAGE->findImage("��ũ���");
		m_dieAni = ANIMATION->findAnimation("��ũ�����");
		ANIMATION->resume("��ũ�����");
		break;
	case STATE::UP:
		m_walkImage = IMAGE->findImage("��ũ");
		m_walkAni = ANIMATION->findAnimation("��ũ��");
		ANIMATION->resume("��ũ��");
		m_attackImage = IMAGE->findImage("��ũ����");
		m_attackAni = ANIMATION->findAnimation("��ũ���ݻ�");
		ANIMATION->start("��ũ���ݻ�");
		m_dieImage = IMAGE->findImage("��ũ���");
		m_dieAni = ANIMATION->findAnimation("��ũ�����");
		ANIMATION->resume("��ũ�����");
		break;
	case STATE::DOWN:
		m_walkImage = IMAGE->findImage("��ũ");
		m_walkAni = ANIMATION->findAnimation("��ũ��");
		ANIMATION->resume("��ũ��");
		m_attackImage = IMAGE->findImage("��ũ����");
		m_attackAni = ANIMATION->findAnimation("��ũ������");
		ANIMATION->start("��ũ������");
		m_dieImage = IMAGE->findImage("��ũ���");
		m_dieAni = ANIMATION->findAnimation("��ũ�����");
		ANIMATION->resume("��ũ�����");
		break;
	}
}


