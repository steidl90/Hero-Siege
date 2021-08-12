#include "framework.h"
#include "Cprison.h"

Cprison::Cprison()
{
}

Cprison::~Cprison()
{
}

<<<<<<< HEAD
HRESULT Cprison::init(POINT position, float HP, float damage, int exp, float trace)
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(5, 100, true, "±³µµ°ü°ø°ÝÇÏ");

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

	ANIMATION->addAnimation("±³µµ°üÇÏ", "±³µµ°ü", 0, 7, 8, false, true);
	ANIMATION->addAnimation("±³µµ°üÁÂ", "±³µµ°ü", 8, 15, 8, false, true);
	ANIMATION->addAnimation("±³µµ°ü¿ì", "±³µµ°ü", 16, 23, 8, false, true);
	ANIMATION->addAnimation("±³µµ°ü»ó", "±³µµ°ü", 24, 31, 8, false, true);

	ANIMATION->addAnimation("±³µµ°ü»ç¸ÁÇÏ", "±³µµ°ü»ç¸Á", 0, 12, 8, false, false);
	ANIMATION->addAnimation("±³µµ°ü»ç¸ÁÁÂ", "±³µµ°ü»ç¸Á", 13, 25, 8, false, false);
	ANIMATION->addAnimation("±³µµ°ü»ç¸Á¿ì", "±³µµ°ü»ç¸Á", 26, 38, 8, false, false);
	ANIMATION->addAnimation("±³µµ°ü»ç¸Á»ó", "±³µµ°ü»ç¸Á", 39, 51, 8, false, false);

	m_walkImage = IMAGE->findImage("±³µµ°ü");
	m_walkAni = ANIMATION->findAnimation("±³µµ°üÇÏ");
	ANIMATION->start("±³µµ°üÇÏ");
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
HRESULT Cprison::init(POINT position, int HP)
{
	return E_NOTIMPL;
>>>>>>> parent of 35abb8d (ëª¬ìŠ¤í„° ìµœì¢…)
}

void Cprison::attack()
{
}

void Cprison::die()
{
}

void Cprison::animation()
{
}
