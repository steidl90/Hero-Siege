#include "framework.h"
#include "Cslime.h"

Cslime::Cslime()
{
}

Cslime::~Cslime()
{
}

<<<<<<< HEAD
HRESULT Cslime::init(POINT position, float HP, float damage, int exp,float trace)
{
	m_enemyAttack = new CenemyAttack;
	m_enemyAttack->init(5, 100, true, "½½¶óÀÓ°ø°ÝÇÏ");

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

	ANIMATION->addAnimation("½½¶óÀÓ¾Ö´Ï", "½½¶óÀÓ", 0, 5, 8, false, true);


	m_walkImage = IMAGE->findImage("½½¶óÀÓ");
	m_walkAni = ANIMATION->findAnimation("½½¶óÀÓ¾Ö´Ï");
	ANIMATION->start("½½¶óÀÓ¾Ö´Ï");
	return S_OK;
}

void Cslime::release()
{
	SAFE_DELETE(m_enemyAttack);
	SAFE_DELETE(m_player);
	SAFE_DELETE(m_hpBar);
}

void Cslime::update()
{
	m_hpBar->setGauge(m_hp, m_maxHp);
	m_hpBar->mapUpdate(m_x - 15, m_y - 25);
	m_enemyAttack->update();
	move();
	attack();
	if (m_walkImage != nullptr)
	{
		m_walkRc = RectMakeCenter(m_x, m_y, m_walkImage->getFrameWidth(), m_walkImage->getFrameHeight());
	}
	m_traceRc = RectMakeCenter(m_x, m_y, m_trace, m_trace);
}

void Cslime::render()
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
HRESULT Cslime::init(POINT position, int HP)
{
	return E_NOTIMPL;
>>>>>>> parent of 35abb8d (ëª¬ìŠ¤í„° ìµœì¢…)
}

void Cslime::attack()
{
}

void Cslime::die()
{
}

void Cslime::animation()
{
}
