#pragma once
#include"singleton.h"

class CplayerDate : public Singleton<CplayerDate>
{
private:
	int m_atk;
	int m_def;
	int m_hp;
	int m_mp;
	int m_critical;
	int m_lv;
	int m_exp;
	int m_gold;
	float m_criticalAtk;
	float m_speed;

public:
	CplayerDate();
	~CplayerDate();

	HRESULT init();
	void release();
	void update();
	void render();

	void setData(int atk, int def, int hp, int mp, int cri, int lv, int exp, int gold, float criatk, float speed);

	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
	int getHp() { return m_hp; }
	int getMp() { return m_mp; }
	int getCritical() { return m_critical; }
	int getLv() { return m_lv; }
	int getExp() { return m_exp; }
	int getGold() { return m_gold; }
	float getCriticalAtk() { return m_criticalAtk; }
	float getSpeed() { return m_speed; }

};

