#pragma once
#include"Citem.h"

struct EquipItem
{
	Citem* m_item;
	int m_itemIndex;
	POINT m_renderPoint;
	bool isEquip;
};

struct SelectItem
{
	Citem* m_item;
	int m_itemIndex;
	POINT m_renderPoint;
	bool isSelect;
};

class Cinventory
{
	vector<Citem> m_vWeaponList;
	vector<Citem> m_vArmorList;
	vector<Citem> m_vShoesList;
	vector<Citem> m_vGlovesList;
	vector<Citem> m_vPendantList;

	vector<Citem*> m_vEquipList;

	Citem* m_equipWeapon;
	Citem* m_equipArmor;
	Citem* m_equipShoes;
	Citem* m_equipGloves;
	Citem* m_equipPendant;

	// 기능 구현 멤버변수
	SelectItem m_selectItem;
	// 구조 수정
	EquipItem m_equipItem[5];
	Citem m_tempItem[5];


public:

	Cinventory();
	~Cinventory();

	HRESULT init();
	void release();
	void update();
	//void render();

	// 아이템 얻었을때
	void addItem(Citem* item);
	// 아이템 장착
	void equipItem();
	void setEquipRender(ITEMTYPE type, POINT renderPoint);
	// 아이템 장착 해제할때
	void UnEquipItem(Citem* item);
	// 아이템 버릴때
	//bool checkEquipItem(ITEMTYPE type);
	void AbandonItem();

	// 아이템 장착할때
	void setEquipWeapon(Citem* item) { m_equipWeapon = item; }
	void setEquipArmor(Citem* item) { m_equipArmor = item; }
	void setEquipShoes(Citem* item) { m_equipShoes = item; }
	void setEquipGloves(Citem* item) { m_equipGloves = item; }
	void setEquipPendant(Citem* item) { m_equipPendant = item; }

	// 장착중인 아이템 리스트 
	vector<Citem*>* getvEquipList() { return &m_vEquipList; }

	vector<Citem>* getvWeaponList() { return &m_vWeaponList; }
	vector<Citem>* getvArmorList() { return &m_vArmorList; }
	vector<Citem>* getvShoesList() { return &m_vShoesList; }
	vector<Citem>* getvGlovesList() { return &m_vGlovesList; }
	vector<Citem>* getvPendantList() { return &m_vPendantList; }

	Citem* getEquipWeapon() { return m_equipWeapon; }
	Citem* getEquipArmor() { return m_equipArmor; }
	Citem* getEquipShoes() { return m_equipShoes; }
	Citem* getEquipGloves() { return m_equipGloves; }
	Citem* getEquipPendant() { return m_equipPendant; }

	EquipItem* getEquipItem() { return m_equipItem; }
	EquipItem* getEquipItem(ITEMTYPE type);
	void setEquipItem(ITEMTYPE type, Citem* item, int index, POINT point, bool isEquip);

	SelectItem* getSelectItem() { return &m_selectItem; }
	void setSelectItem(Citem* item, int index, POINT point, bool isSelect);

	void clearSelectItem();
	void clearEquipItem(ITEMTYPE type);
	//void setItemId();
};

