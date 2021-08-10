#include "framework.h"
#include "Celemental.h"
#include "CenemyAttack.h"

Celemental::Celemental()
{
}

Celemental::~Celemental()
{
}

HRESULT Celemental::init()
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init();

	isIdle = false;
	m_state = STATE::DOWN;

	ANIMATION->addAnimation("������Ż��", "������Ż", 0, 3, 8, false, true);
	ANIMATION->addAnimation("������Ż��", "������Ż", 4, 7, 8, false, true);
	ANIMATION->addAnimation("������Ż��", "������Ż", 8, 11, 8, false, true);
	ANIMATION->addAnimation("������Ż��", "������Ż", 12, 15, 8, false, true);
	
	m_walkImage = IMAGE->findImage("������Ż");
	m_walkAni = ANIMATION->findAnimation("������Ż��");
	ANIMATION->start("������Ż��");

	m_x = WINSIZEX / 2;
	m_y = WINSIZEY / 2;
	m_speed = 2.0f;

	return S_OK;
}

void Celemental::release()
{
	SAFE_DELETE(m_walkImage);
}

void Celemental::update()
{
	move();
	m_walkRc = RectMakeCenter(m_x, m_y, m_walkImage->getFrameWidth(), m_walkImage->getFrameHeight());
}

void Celemental::render()
{
	Rectangle(getMapDC(), m_x, m_y, m_walkImage->getFrameWidth(), m_walkImage->getFrameHeight());
	m_walkImage->aniRender(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkAni);
}

void Celemental::move()
{
	if (InputManager->isStayKeyDown('W'))
	{
		m_y -= m_speed;
		m_state = STATE::UP;
	}
	if (InputManager->isStayKeyDown('S'))
	{
		m_y += m_speed;
		m_state = STATE::DOWN;
	}
	if (InputManager->isStayKeyDown('A'))
	{
		m_x -= m_speed;
		m_state = STATE::LEFT;
	}
	if (InputManager->isStayKeyDown('D'))
	{
		m_x += m_speed;
		m_state = STATE::RIGHT;
	}
}

void Celemental::attack()
{
}

void Celemental::animation()
{
	switch (m_state)
	{
	case STATE::LEFT:
		m_walkImage = IMAGE->findImage("������Ż");
		m_walkAni = ANIMATION->findAnimation("������Ż��");
		ANIMATION->start("������Ż��");
		break;
	case STATE::RIGHT:
		m_walkImage = IMAGE->findImage("������Ż");
		m_walkAni = ANIMATION->findAnimation("������Ż��");
		ANIMATION->start("������Ż��");
		break;
	case STATE::UP:
		m_walkImage = IMAGE->findImage("������Ż");
		m_walkAni = ANIMATION->findAnimation("������Ż��");
		ANIMATION->start("������Ż��");
		break;
	case STATE::DOWN:
		m_walkImage = IMAGE->findImage("������Ż");
		m_walkAni = ANIMATION->findAnimation("������Ż��");
		ANIMATION->start("������Ż��");
		break;
	}
}

bool Celemental::enemyCoolTime()
{
	return false;
}

