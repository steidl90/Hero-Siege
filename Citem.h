#pragma once
#include"gameNode.h"

class Citem
{

private:
	string m_BigImage;
	string m_SmallImage;
	string m_Name;
	ITEMTYPE m_Type;
	int m_atk;
	int m_def;
	int m_hp;
	int m_mp;
	int m_critical;
	int m_criticalAtk;
	int m_speed;
	int m_limitLevel;
	int m_itemBuyPrice;
	// 아이템 등급 추가해야함
	POINT m_frame;

public:
	Citem();
	Citem(string bigImg, string smallImg, string name, ITEMTYPE type, int atk, int def, int hp, int mp,
		int cri, int criAtk, int speed, int level, int price, POINT frame);
	~Citem();

	string getBigImage()const { return m_BigImage; }
	string getSmallImage()const { return m_SmallImage; }
	string getName()const { return m_Name; }
	ITEMTYPE getType()const { return m_Type; }
	int getAtk()const { return m_atk; }
	int getDef()const { return m_def; }
	int getHp()const { return m_hp; }
	int getMp()const { return m_mp; }
	int getCritical()const { return m_critical; }
	int getCriticalAtk()const { return m_criticalAtk; }
	int getSpeed()const { return m_speed; }
	int getLimitLevel()const { return m_limitLevel; }
	int getBuyPrice()const { return m_itemBuyPrice; }
	POINT getFrame()const { return m_frame; }



};

