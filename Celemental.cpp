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

	ANIMATION->addAnimation("¿¤¸®¸àÅ»¾Æ·¡", "¿¤¸®¸àÅ»", 0, 3, 8, false, true);
	ANIMATION->addAnimation("¿¤¸®¸àÅ»¾Æ·¡", "¿¤¸®¸àÅ»", 4, 7, 8, false, true);
	ANIMATION->addAnimation("¿¤¸®¸àÅ»¾Æ·¡", "¿¤¸®¸àÅ»", 8, 11, 8, false, true);
	ANIMATION->addAnimation("¿¤¸®¸àÅ»¾Æ·¡", "¿¤¸®¸àÅ»", 12, 15, 8, false, true);
	
	m_x = WINSIZEX / 2;
	m_y = WINSIZEY / 2;
	m_speed = 2.0f;

	return S_OK;
}

void Celemental::release()
{
	SAFE_DELETE(m_image);
}

void Celemental::update()
{
	move();
	m_rc = RectMakeCenter(m_x, m_y,m_image->getFrameWidth(), m_image->getFrameHeight());
}

void Celemental::render()
{
	Rectangle(getMapDC(), m_x, m_y, m_image->getFrameWidth(), m_image->getFrameHeight());
	m_image->aniRender(getMapDC(), m_rc.left, m_rc.top, m_ani);
}

void Celemental::move()
{
}

void Celemental::moveAni()
{
}

void Celemental::attack()
{
}

void Celemental::Die()
{
}
