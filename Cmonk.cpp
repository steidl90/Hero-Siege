#include "framework.h"
#include "Cmonk.h"

Cmonk::Cmonk()
{
	m_monkImage = nullptr;
}

Cmonk::~Cmonk()
{
}

HRESULT Cmonk::init()
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init();

	ANIMATION->addAnimation("��ũ�Ʒ���", "��ũ", 0, 5, 8, false, true);
	ANIMATION->addAnimation("��ũ����", "��ũ", 6, 11, 8, false, true);
	ANIMATION->addAnimation("��ũ������", "��ũ", 12, 17, 8, false, true);
	ANIMATION->addAnimation("��ũ����", "��ũ", 18, 23, 8, false, true);

	ANIMATION->addAnimation("��ũ���ݾƷ���", "��ũ����", 0, 4, 8, false, true);
	ANIMATION->addAnimation("��ũ���ݿ���", "��ũ����", 5, 9, 8, false, true);
	ANIMATION->addAnimation("��ũ���ݿ�����", "��ũ����", 10, 14, 8, false, true);
	ANIMATION->addAnimation("��ũ��������", "��ũ����", 15, 19, 8, false, true);

	ANIMATION->addAnimation("��ũ����Ʒ���", "��ũ���", 0, 11, 8, false, false);
	ANIMATION->addAnimation("��ũ�������", "��ũ���", 12, 23, 8, false, false);
	ANIMATION->addAnimation("��ũ���������", "��ũ���", 24, 35, 8, false, false);
	ANIMATION->addAnimation("��ũ�������", "��ũ���", 36, 47, 8, false, false);

	m_x = WINSIZEX / 2;
	m_y = WINSIZEY / 2;
	m_speed = 2.0f;

	return S_OK;
}

void Cmonk::release()
{
	SAFE_DELETE(m_enemyAttack);
}

void Cmonk::update()
{
	//================= Priest Walking motion =================
	if (InputManager->isStayKeyDown('W'))
	{
		m_y -= m_speed;
		m_monkState = MONK_STATE::MONK_STATE_WALK_UP;
	}
	if (InputManager->isStayKeyDown('S'))
	{
		m_y += m_speed;
		m_monkState = MONK_STATE::MONK_STATE_WALK_DOWN;
	}
	if (InputManager->isStayKeyDown('A'))
	{
		m_x -= m_speed;
		m_monkState = MONK_STATE::MONK_STATE_WALK_LEFT;
	}
	if (InputManager->isStayKeyDown('D'))
	{
		m_x += m_speed;
		m_monkState = MONK_STATE::MONK_STATE_WALK_RIGHT;
	}

	if (InputManager->isOnceKeyDown(VK_UP))
	{
		//m_y -= 20;
		m_monkState = MONK_STATE::MONK_STATE_DIE_UP;
	}
	if (InputManager->isOnceKeyDown(VK_DOWN))
	{
		//m_y -= 20;
		m_monkState = MONK_STATE::MONK_STATE_DIE_DOWN;
	}
	if (InputManager->isOnceKeyDown(VK_LEFT))
	{
		//m_y -= 20;
		m_monkState = MONK_STATE::MONK_STATE_DIE_LEFT;
	}
	if (InputManager->isOnceKeyDown(VK_RIGHT))
	{
		//m_y -= 20;
		m_monkState = MONK_STATE::MONK_STATE_DIE_RIGHT;
	}








	switch (m_monkState)
	{
	
	case MONK_STATE::MONK_STATE_WALK_UP:
		m_monkImage = IMAGE->findImage("��ũ");
		m_monkAnimation = ANIMATION->findAnimation("��ũ����");
		ANIMATION->resume("��ũ����");
		break;
	case MONK_STATE::MONK_STATE_WALK_DOWN:
		m_monkImage = IMAGE->findImage("��ũ");
		m_monkAnimation = ANIMATION->findAnimation("��ũ�Ʒ���");
		ANIMATION->resume("��ũ�Ʒ���");
		break;
	case MONK_STATE::MONK_STATE_WALK_LEFT:
		m_monkImage = IMAGE->findImage("��ũ");
		m_monkAnimation = ANIMATION->findAnimation("��ũ����");
		ANIMATION->resume("��ũ����");
		break;
	case MONK_STATE::MONK_STATE_WALK_RIGHT:
		m_monkImage = IMAGE->findImage("��ũ");
		m_monkAnimation = ANIMATION->findAnimation("��ũ������");
		ANIMATION->resume("��ũ������");
		break;
	
	case MONK_STATE::MONK_STATE_ATTACK_UP:
		m_monkImage = IMAGE->findImage("��ũ����");
		m_monkAnimation = ANIMATION->findAnimation("��ũ��������");
		ANIMATION->resume("��ũ��������");
		break;
	case MONK_STATE::MONK_STATE_ATTACK_DOWN:
		m_monkImage = IMAGE->findImage("��ũ����");
		m_monkAnimation = ANIMATION->findAnimation("��ũ���ݾƷ���");
		ANIMATION->resume("��ũ����");
		break;
	case MONK_STATE::MONK_STATE_ATTACK_LEFT:
		m_monkImage = IMAGE->findImage("��ũ����");
		m_monkAnimation = ANIMATION->findAnimation("��ũ���ݿ���");
		ANIMATION->resume("��ũ���ݿ���");
		break;
	case MONK_STATE::MONK_STATE_ATTACK_RIGHT:
		m_monkImage = IMAGE->findImage("��ũ����");
		m_monkAnimation = ANIMATION->findAnimation("��ũ���ݿ�����");
		ANIMATION->resume("��ũ���ݿ�����");
		break;
	
	
	
	case MONK_STATE::MONK_STATE_DIE_UP:
		m_monkImage = IMAGE->findImage("��ũ���");
		m_monkAnimation = ANIMATION->findAnimation("��ũ�������");
		ANIMATION->resume("��ũ�������");
		break;
	case MONK_STATE::MONK_STATE_DIE_DOWN:
		m_monkImage = IMAGE->findImage("��ũ���");
		m_monkAnimation = ANIMATION->findAnimation("��ũ����Ʒ���");
		ANIMATION->resume("��ũ����Ʒ���");
		break;
	case MONK_STATE::MONK_STATE_DIE_LEFT:
		m_monkImage = IMAGE->findImage("��ũ���");
		m_monkAnimation = ANIMATION->findAnimation("��ũ�������");
		ANIMATION->resume("��ũ�������");
		break;
	case MONK_STATE::MONK_STATE_DIE_RIGHT:
		m_monkImage = IMAGE->findImage("��ũ���");
		m_monkAnimation = ANIMATION->findAnimation("��ũ���������");
		ANIMATION->resume("��ũ���������");
		break;
	}
	if (m_monkImage != nullptr) 
	{
		m_monkRc = RectMakeCenter(m_x, m_y, m_monkImage->getFrameWidth(), m_monkImage->getFrameHeight());
	}
}

void Cmonk::render()
{
	if (m_monkImage != nullptr) {
		Rectangle(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkRc.right, m_monkRc.bottom);
		m_monkImage->aniRender(getMapDC(), m_monkRc.left, m_monkRc.top, m_monkAnimation);
		m_enemyAttack->render();
	}
}
