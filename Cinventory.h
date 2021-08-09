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
};

