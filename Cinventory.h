#pragma once
#include"Citem.h"

class Cinventory
{
	vector<Citem> m_vWeaponList;
	vector<Citem> m_vArmorList;

public:

	Cinventory();
	~Cinventory();

	HRESULT init();
	void release();
	void update();
	//void render();

	void addItem(Citem* item);
	void EquipItem(Citem* item);
	void UnEquipItem(Citem* item);
	void AbandonItem(Citem* item);

	vector<Citem>* getvWeaponList() { return &m_vWeaponList; }
	vector<Citem>* getvArmorList() { return &m_vArmorList; }
};

