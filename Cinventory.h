#pragma once
#include"Citem.h"


class Cinventory
{
	vector<Citem> m_vWeaponList;
	vector<Citem> m_vArmorList;
	vector<Citem> m_vShoesList;
	vector<Citem> m_vGlovesList;
	vector<Citem> m_vPendantList;

	Citem* m_equipWeapon;
	Citem* m_equipArmor;
	Citem* m_equipShoes;
	Citem* m_equipGloves;
	Citem* m_equipPendant;

public:

	Cinventory();
	~Cinventory();

	HRESULT init();
	void release();
	void update();
	//void render();

	// 아이템 얻었을때
	void addItem(Citem* item);
	// 아이템 장착할때
	void EquipItem(Citem* item);
	// 아이템 장착 해제할때
	void UnEquipItem(Citem* item);
	// 아이템 버릴때
	void AbandonItem(Citem* item);

	vector<Citem>* getvWeaponList() { return &m_vWeaponList; }
	vector<Citem>* getvArmorList() { return &m_vArmorList; }
	vector<Citem>* getvShoesList() { return &m_vShoesList; }
	vector<Citem>* getvGlovesList() { return &m_vGlovesList; }
	vector<Citem>* getvPendantList() { return &m_vPendantList; }

	void setEquipWeapon(Citem* item) { m_equipWeapon = item; }
	void setEquipArmor(Citem* item) { m_equipArmor = item; }
	void setEquipShoes(Citem* item) { m_equipShoes = item; }
	void setEquipGloves(Citem* item) { m_equipGloves = item; }
	void setEquipPendant(Citem* item) { m_equipPendant = item; }

	Citem* getEquipWeapon() { return m_equipWeapon; }
	Citem* getEquipArmor() { return m_equipArmor; }
	Citem* getEquipShoes() { return m_equipShoes; }
	Citem* getEquipGloves() { return m_equipGloves; }
	Citem* getEquipPendant() { return m_equipPendant; }


	//void setItemId();
};

