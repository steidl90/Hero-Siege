#include "framework.h"
#include "Cpriest.h"

Cpriest::Cpriest()
{
	m_priestImage = nullptr;
}

Cpriest::~Cpriest()
{
}
//����ü�� �������� �ð��Ǹ� ��Ȧ�� �߰��ϱ�
HRESULT Cpriest::init()
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init();

	//m_priestImage = IMAGE->findImage("��ġ");

	ANIMATION->addAnimation("��ġ�Ʒ���", "��ġ", 0, 5, 8, false, true);
	ANIMATION->addAnimation("��ġ����", "��ġ", 6, 11, 8, false, true);
	ANIMATION->addAnimation("��ġ������", "��ġ", 12, 17, 8, false, true);
	ANIMATION->addAnimation("��ġ����", "��ġ", 18, 23, 8, false, true);

	ANIMATION->addAnimation("��ġ���ݾƷ���", "��ġ����", 0, 15, 16, false, false);
	ANIMATION->addAnimation("��ġ���ݿ���", "��ġ����", 16, 31, 16, false, false);
	ANIMATION->addAnimation("��ġ���ݿ�����", "��ġ����", 32, 47, 16, false, false);
	ANIMATION->addAnimation("��ġ��������", "��ġ����", 48, 63, 16, false, false);

	ANIMATION->addAnimation("��ġ����Ʒ���", "��ġ���", 0, 9, 8, false, false);
	ANIMATION->addAnimation("��ġ�������", "��ġ���", 10, 19, 8, false, false);
	ANIMATION->addAnimation("��ġ���������", "��ġ���", 20, 29, 8, false, false);
	ANIMATION->addAnimation("��ġ�������", "��ġ���", 30, 39, 8, false, false);

	//m_priestRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, m_priestImage->getFrameWidth(), m_priestImage->getFrameHeight());
	//m_priestAnimation = ANIMATION->findAnimation("��ġ�Ʒ���");

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
	m_enemyAttack->update("��ġ��ų�ִ�");

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
			PI * 0.5, 5.0f, "��ġ��ų", "��ġ��ų�ִ�");
	}
	if(InputManager->isOnceKeyDown(VK_NUMPAD2))
	{ 
		m_priestState = PRIEST_STATE::PRIEST_STATE_ATTACK_DOWN;
		m_enemyAttack->fire(m_priestRc.right - (m_priestRc.right - m_priestRc.left) / 2, m_priestRc.bottom,
			PI * 1.5, 5.0f, "��ġ��ų", "��ġ��ų�ִ�");
	}
	if(InputManager->isOnceKeyDown(VK_NUMPAD4))
	{ 
		m_priestState = PRIEST_STATE::PRIEST_STATE_ATTACK_LEFT;
		m_enemyAttack->fire(m_priestRc.left, m_priestRc.bottom - (m_priestRc.bottom - m_priestRc.top) / 2,
			PI, 5.0f, "��ġ��ų", "��ġ��ų�ִ�");
	}
	if(InputManager->isOnceKeyDown(VK_NUMPAD6))
	{ 
		m_priestState = PRIEST_STATE::PRIEST_STATE_ATTACK_RIGHT;
		m_enemyAttack->fire(m_priestRc.right, m_priestRc.bottom - (m_priestRc.bottom - m_priestRc.top) / 2,
			PI2, 5.0f, "��ġ��ų", "��ġ��ų�ִ�");
	}




	switch (m_priestState)
	{
	case PRIEST_STATE::PRIEST_STATE_WALK_UP:
		m_priestImage = IMAGE->findImage("��ġ");
		m_priestAnimation = ANIMATION->findAnimation("��ġ����");
		ANIMATION->resume("��ġ����");
		break;
	case PRIEST_STATE::PRIEST_STATE_WALK_DOWN:
		m_priestImage = IMAGE->findImage("��ġ");
		m_priestAnimation = ANIMATION->findAnimation("��ġ�Ʒ���");
		ANIMATION->resume("��ġ�Ʒ���");
		break;
	case PRIEST_STATE::PRIEST_STATE_WALK_LEFT:
		m_priestImage = IMAGE->findImage("��ġ");
		m_priestAnimation = ANIMATION->findAnimation("��ġ����");
		ANIMATION->resume("��ġ����");
		break;
	case PRIEST_STATE::PRIEST_STATE_WALK_RIGHT:
		m_priestImage = IMAGE->findImage("��ġ");
		m_priestAnimation = ANIMATION->findAnimation("��ġ������");
		ANIMATION->resume("��ġ������");
		break;


	case PRIEST_STATE::PRIEST_STATE_ATTACK_UP:
		m_priestImage = IMAGE->findImage("��ġ����");
		m_priestAnimation = ANIMATION->findAnimation("��ġ��������");
		ANIMATION->start("��ġ��������");
		break;
	case PRIEST_STATE::PRIEST_STATE_ATTACK_DOWN:
		m_priestImage = IMAGE->findImage("��ġ����");
		m_priestAnimation = ANIMATION->findAnimation("��ġ���ݾƷ���");
		ANIMATION->start("��ġ���ݾƷ���");
		break;
	case PRIEST_STATE::PRIEST_STATE_ATTACK_LEFT:
		m_priestImage = IMAGE->findImage("��ġ����");
		m_priestAnimation = ANIMATION->findAnimation("��ġ���ݿ���");
		ANIMATION->start("��ġ���ݿ���");
		break;
	case PRIEST_STATE::PRIEST_STATE_ATTACK_RIGHT:
		m_priestImage = IMAGE->findImage("��ġ����");
		m_priestAnimation = ANIMATION->findAnimation("��ġ���ݿ�����");
		ANIMATION->start("��ġ���ݿ�����");
		break;

	case PRIEST_STATE::PRIEST_STATE_DIE_UP:
		m_priestImage = IMAGE->findImage("��ġ���");
		m_priestAnimation = ANIMATION->findAnimation("��ġ�������");
		ANIMATION->start("��ġ�������");
		break;
	case PRIEST_STATE::PRIEST_STATE_DIE_DOWN:
		m_priestImage = IMAGE->findImage("��ġ���");
		m_priestAnimation = ANIMATION->findAnimation("��ġ����Ʒ���");
		ANIMATION->start("��ġ����Ʒ���");
		break;
	case PRIEST_STATE::PRIEST_STATE_DIE_LEFT:
		m_priestImage = IMAGE->findImage("��ġ���");
		m_priestAnimation = ANIMATION->findAnimation("��ġ�������");
		ANIMATION->start("��ġ�������");
		break;
	case PRIEST_STATE::PRIEST_STATE_DIE_RIGHT:
		m_priestImage = IMAGE->findImage("��ġ���");
		m_priestAnimation = ANIMATION->findAnimation("��ġ���������");
		ANIMATION->start("��ġ���������");
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
