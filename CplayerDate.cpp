#include "framework.h"
#include "CplayerDate.h"

CplayerDate::CplayerDate() :m_hp(1000), m_mp(500), m_exp(0), m_atk(10), m_def(10), m_critical(5),m_criticalAtk(1.5),m_speed(3.0),m_lv(1)
{
}

CplayerDate::~CplayerDate()
{
}

HRESULT CplayerDate::init()
{
	return S_OK;
}

void CplayerDate::release()
{
}

void CplayerDate::update()
{
	/*setLv(m_player->getPlayer()->getLv());
	setExp(m_player->getPlayer()->getExp());
	setAtk(m_player->getPlayer()->getAtk());
	setDef(m_player->getPlayer()->getDef());
	setHp(m_player->getPlayer()->getHp());
	setMp(m_player->getPlayer()->getMp());
	setCritical(m_player->getPlayer()->getCritical());
	setCriticalAtk(m_player->getPlayer()->getCriticalAtk());
	setGold(m_player->getPlayer()->getGold());
	setSpeed(m_player->getPlayer()->getSpeed());*/
}

void CplayerDate::render()
{
}

void CplayerDate::setData(int atk, int def, int hp, int mp, int cri, int lv, int exp, int gold, float criatk, float speed)
{
	m_atk = atk;
	m_def = def;
	m_hp = hp;
	m_mp = mp;
	m_critical = cri;
	m_lv = lv;
	m_exp = exp;
	m_gold = gold;
	m_criticalAtk = criatk;
	m_speed = speed;
}
