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

	// ��� ���� �������
	SelectItem m_selectItem;
	// ���� ����
	EquipItem m_equipItem[5];
	Citem m_tempItem[5];


public:

	Cinventory();
	~Cinventory();

	HRESULT init();
	void release();
	void update();
	//void render();

	// ������ �������
	void addItem(Citem* item);
	// ������ ����
	void equipItem();
	void setEquipRender(ITEMTYPE type, POINT renderPoint);
	// ������ ���� �����Ҷ�
	void UnEquipItem(Citem* item);
	// ������ ������
	//bool checkEquipItem(ITEMTYPE type);
	void AbandonItem();

	// ������ �����Ҷ�
	void setEquipWeapon(Citem* item) { m_equipWeapon = item; }
	void setEquipArmor(Citem* item) { m_equipArmor = item; }
	void setEquipShoes(Citem* item) { m_equipShoes = item; }
	void setEquipGloves(Citem* item) { m_equipGloves = item; }
	void setEquipPendant(Citem* item) { m_equipPendant = item; }

	// �������� ������ ����Ʈ 
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

