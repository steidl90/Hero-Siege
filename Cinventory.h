#pragma once
#include"Citem.h"



class Cinventory
{
	vector<Citem*> m_vWeaponList;
	vector<Citem*> m_vArmorList;
	vector<Citem*> m_vShoesList;
	vector<Citem*> m_vGlovesList;
	vector<Citem*> m_vPendantList;


	Citem* m_equipWeapon;
	Citem* m_equipArmor;
	Citem* m_equipShoes;
	Citem* m_equipGloves;
	Citem* m_equipPendant;

	// ��� ���� �������
	// ���� ����
	SelectItem m_selectItem;
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
	void AbandonItem();


	// ������ �����Ҷ�
	void setEquipWeapon(Citem* item) { m_equipWeapon = item; }
	void setEquipArmor(Citem* item) { m_equipArmor = item; }
	void setEquipShoes(Citem* item) { m_equipShoes = item; }
	void setEquipGloves(Citem* item) { m_equipGloves = item; }
	void setEquipPendant(Citem* item) { m_equipPendant = item; }

	// �������� ������ ����Ʈ 

	vector<Citem*>* getvWeaponList() { return &m_vWeaponList; }
	vector<Citem*>* getvArmorList() { return &m_vArmorList; }
	vector<Citem*>* getvShoesList() { return &m_vShoesList; }
	vector<Citem*>* getvGlovesList() { return &m_vGlovesList; }
	vector<Citem*>* getvPendantList() { return &m_vPendantList; }

	Citem* getEquipWeapon() { return m_equipWeapon; }
	Citem* getEquipArmor() { return m_equipArmor; }
	Citem* getEquipShoes() { return m_equipShoes; }
	Citem* getEquipGloves() { return m_equipGloves; }
	Citem* getEquipPendant() { return m_equipPendant; }

	EquipItem* getEquipItem() { return m_equipItem; }
	EquipItem* getEquipItem(ITEMTYPE type);

	SelectItem* getSelectItem() { return &m_selectItem; }
	void setSelectItem(Citem* item, int index, POINT point, bool isSelect);

	void clearSelectItem();
	void clearEquipItem(ITEMTYPE type);
	//void setItemId();
};

