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

	ANIMATION->addAnimation("ø§∏Æ∏‡≈ª«œ", "ø§∏Æ∏‡≈ª", 0, 3, 8, false, true);
	ANIMATION->addAnimation("ø§∏Æ∏‡≈ª¡¬", "ø§∏Æ∏‡≈ª", 4, 7, 8, false, true);
	ANIMATION->addAnimation("ø§∏Æ∏‡≈ªøÏ", "ø§∏Æ∏‡≈ª", 8, 11, 8, false, true);
	ANIMATION->addAnimation("ø§∏Æ∏‡≈ªªÛ", "ø§∏Æ∏‡≈ª", 12, 15, 8, false, true);
	
	m_walkImage = IMAGE->findImage("ø§∏Æ∏‡≈ª");
	m_walkAni = ANIMATION->findAnimation("ø§∏Æ∏‡≈ª«œ");
	ANIMATION->start("ø§∏Æ∏‡≈ª«œ");

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
		m_walkImage = IMAGE->findImage("ø§∏Æ∏‡≈ª");
		m_walkAni = ANIMATION->findAnimation("ø§∏Æ∏‡≈ª¡¬");
		ANIMATION->start("ø§∏Æ∏‡≈ª¡¬");
		break;
	case STATE::RIGHT:
		m_walkImage = IMAGE->findImage("ø§∏Æ∏‡≈ª");
		m_walkAni = ANIMATION->findAnimation("ø§∏Æ∏‡≈ªøÏ");
		ANIMATION->start("ø§∏Æ∏‡≈ªøÏ");
		break;
	case STATE::UP:
		m_walkImage = IMAGE->findImage("ø§∏Æ∏‡≈ª");
		m_walkAni = ANIMATION->findAnimation("ø§∏Æ∏‡≈ªªÛ");
		ANIMATION->start("ø§∏Æ∏‡≈ªªÛ");
		break;
	case STATE::DOWN:
		m_walkImage = IMAGE->findImage("ø§∏Æ∏‡≈ª");
		m_walkAni = ANIMATION->findAnimation("ø§∏Æ∏‡≈ª«œ");
		ANIMATION->start("ø§∏Æ∏‡≈ª«œ");
		break;
	}
}

bool Celemental::enemyCoolTime()
{
	return false;
}

