#include "framework.h"
#include "Cpriest.h"
#include "CenemyAttack.h"

Cpriest::Cpriest()
{
}

Cpriest::~Cpriest()
{
}

<<<<<<< HEAD
HRESULT Cpriest::init(POINT position, float HP, float damage, int exp,float trace)
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(50, 500, false, "¸®Ä¡½ºÅ³¾Ö´Ï");

	m_player = new Cplayer;
	m_player->init();

	m_isIdle = false;
	m_state = STATE::DOWN;

	m_x = m_returnX = position.x;
	m_y = m_returnY = position.y;
	m_trace = trace;

	m_distance = 100.0f;
	m_speed = 2.0f;
	m_hp = m_maxHp = HP;
	m_damage = damage;
	m_exp = exp;

	m_hpBar = new CprogressBar;
	m_hpBar->init("images/hp.bmp", "images/hp_back.bmp", m_x, m_y, 50, 5);
	m_hpBar->setGauge(m_hp, m_maxHp);

	m_cooltimeCount = 260;
	m_rndskillCount = 259;

	m_isWalking = true;
	m_isDie = false;

	ANIMATION->addAnimation("¸®Ä¡ÇÏ", "¸®Ä¡", 0, 5, 8, false, true);
	ANIMATION->addAnimation("¸®Ä¡ÁÂ", "¸®Ä¡", 6, 11, 8, false, true);
	ANIMATION->addAnimation("¸®Ä¡¿ì", "¸®Ä¡", 12, 17, 8, false, true);
	ANIMATION->addAnimation("¸®Ä¡»ó", "¸®Ä¡", 18, 23, 8, false, true);

	ANIMATION->addAnimation("¸®Ä¡°ø°ÝÇÏ", "¸®Ä¡°ø°Ý", 0, 15, 8,	true, true);
	ANIMATION->addAnimation("¸®Ä¡°ø°ÝÁÂ", "¸®Ä¡°ø°Ý", 16, 31, 8,	true, true);
	ANIMATION->addAnimation("¸®Ä¡°ø°Ý¿ì", "¸®Ä¡°ø°Ý", 32, 47, 8,  true, true);
	ANIMATION->addAnimation("¸®Ä¡°ø°Ý»ó", "¸®Ä¡°ø°Ý", 48, 63, 8,  true, true);

	ANIMATION->addAnimation("¸®Ä¡»ç¸ÁÇÏ", "¸®Ä¡»ç¸Á", 0, 9, 8, false, false);
	ANIMATION->addAnimation("¸®Ä¡»ç¸ÁÁÂ", "¸®Ä¡»ç¸Á", 10, 19, 8, false, false);
	ANIMATION->addAnimation("¸®Ä¡»ç¸Á¿ì", "¸®Ä¡»ç¸Á", 20, 29, 8, false, false);
	ANIMATION->addAnimation("¸®Ä¡»ç¸Á»ó", "¸®Ä¡»ç¸Á", 30, 39, 8, false, false);

	m_walkImage = IMAGE->findImage("¸®Ä¡");
	m_walkAni = ANIMATION->findAnimation("¸®Ä¡ÇÏ");
	ANIMATION->start("¸®Ä¡ÇÏ");
	return S_OK;
}

void Cpriest::release()
{
	SAFE_DELETE(m_enemyAttack);
	SAFE_DELETE(m_player);
	SAFE_DELETE(m_hpBar);
}

void Cpriest::update()
{
	m_hpBar->setGauge(m_hp, m_maxHp);
	m_hpBar->mapUpdate(m_x - 18, m_y - 65);
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
	m_hpBar->mapRender();
	if (InputManager->isToggleKey(VK_TAB))
	{
		Rectangle(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkRc.right, m_walkRc.bottom);
		Rectangle(getMapDC(), m_traceRc.left, m_traceRc.top, m_traceRc.right, m_traceRc.bottom);
		Rectangle(getMapDC(), m_dieRc.left, m_dieRc.top, m_dieRc.right, m_dieRc.bottom);
	}
	if (m_isWalking)m_walkImage->aniRender(getMapDC(), m_walkRc.left, m_walkRc.top, m_walkAni);
	m_enemyAttack->render();
=======
HRESULT Cpriest::init(POINT position, int HP)
{
	return E_NOTIMPL;
>>>>>>> parent of 35abb8d (ëª¬ìŠ¤í„° ìµœì¢…)
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
