#pragma once
#include"singleton.h"

class Citem;
class CplayerDate : public Singleton<CplayerDate>
{
private:
	int m_atk;
	int m_def;
	int m_hp;
	int m_maxHp;
	int m_mp;
	int m_maxMp;
	int m_critical;
	int m_lv;
	int m_exp;
	int m_gold;
	float m_criticalAtk;
	float m_speed;
	float m_x;
	float m_y;

	//���� ������
	vector<Citem*> m_vWeaponList;
	vector<Citem*> m_vArmorList;
	vector<Citem*> m_vShoesList;
	vector<Citem*> m_vGlovesList;
	vector<Citem*> m_vPendantList;
	
	//���� ������
	EquipItem m_equipItem[5];

public:
	CplayerDate();
	~CplayerDate();

	HRESULT init();
	void release();
	void update();
	void render();

	void setData(int atk, int def, int hp, int maxhp, int mp, int maxmp, int cri, int lv, int exp, int gold, float criatk, float speed, float x, float y);

	EquipItem* getEquipItem() { return m_equipItem; }
	void setEquipItem(EquipItem* equipItem);

	vector<Citem*>* getvWeaponList() { return &m_vWeaponList; }
	void setvWeaponList(vector<Citem*>* weaponList) { m_vWeaponList = *weaponList; }
	vector<Citem*>* getvArmorList() { return &m_vArmorList; }
	void setvArmorList(vector<Citem*>* armorList) { m_vArmorList = *armorList; }
	vector<Citem*>* getvShoesList() { return &m_vShoesList; }
	void setvShoesList(vector<Citem*>* shoesList) { m_vShoesList = *shoesList; }
	vector<Citem*>* getvGlovesList() { return &m_vGlovesList; }
	void setvGlovesList(vector<Citem*>* glovesList) { m_vGlovesList = *glovesList; }
	vector<Citem*>* getvPendantList() { return &m_vPendantList; }
	void setvPendantList(vector<Citem*>* pendantList) { m_vPendantList = *pendantList; }

	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
	int getHp() { return m_hp; }
	int getMaxHp() { return m_maxHp; }
	int getMp() { return m_mp; }
	int getMaxMp() { return m_maxMp; }
	int getCritical() { return m_critical; }
	int getLv() { return m_lv; }
	int getExp() { return m_exp; }
	int getGold() { return m_gold; }
	float getCriticalAtk() { return m_criticalAtk; }
	float getSpeed() { return m_speed; }
	float getX() { return m_x; }
	float getY() { return m_y; }
};

