#include "framework.h"
#include "Citem.h"
Citem::Citem()
{
}

Citem::Citem(string bigImg, string smallImg, string name, ITEMTYPE type, int atk, int def, int hp, int mp, int cri, int criAtk, int speed, int level, int price, POINT frame)
	: m_BigImage(bigImg), m_SmallImage(smallImg), m_Name(name), m_Type(type), m_atk(atk), m_def(def), m_hp(hp), m_mp(mp)
	,m_critical(cri), m_criticalAtk(criAtk), m_speed(speed), m_limitLevel(level), m_itemBuyPrice(price), m_frame(frame)
{
}

Citem::~Citem()
{
}
