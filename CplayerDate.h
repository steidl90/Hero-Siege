#pragma once
#include"singleton.h"

class Citem;
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
	float m_x;
	float m_y;

	//보유 아이템
	vector<Citem*> m_vWeaponList;
	vector<Citem*> m_vArmorList;
	vector<Citem*> m_vShoesList;
	vector<Citem*> m_vGlovesList;
	vector<Citem*> m_vPendantList;

	//장착 아이템
	Citem* m_equipWeapon;
	Citem* m_equipArmor;
	Citem* m_equipShoes;
	Citem* m_equipGloves;
	Citem* m_equipPendant;

public:
	CplayerDate();
	~CplayerDate();

	HRESULT init();
	void release();
	void update();
	void render();

	void setData(int atk, int def, int hp, int mp, int cri, int lv, int exp, int gold, float criatk, float speed, float x, float y);
	
	Citem* getWeaponEquip() { return m_equipWeapon; }
	void setWeaponEquip(Citem* Weapon) { m_equipWeapon = Weapon; }
	Citem* getArmorEquip() { return m_equipArmor; }
	void setArmorEquip(Citem* Armor) { m_equipArmor = Armor; }
	Citem* getShoesEquip() { return m_equipShoes; }
	void setShoesEquip(Citem* Shoes) { m_equipShoes = Shoes; }
	Citem* getGlovesEquip() { return m_equipGloves; }
	void setGlovesEquip(Citem* Gloves) { m_equipGloves = Gloves; }
	Citem* getPendantEquip() { return m_equipPendant; }
	void setPendantEquip(Citem* Pendant) { m_equipPendant = Pendant; }


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
	float getX() { return m_x; }
	float getY() { return m_y; }
};

