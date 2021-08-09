#pragma once
#include"gameNode.h"
#include"Cinventory.h"

class CinventoryUi : public gameNode
{
private:
	Cinventory* m_myInventory;

private:

	// �⺻ UI �������
	RECT m_InventoryRc;
	int m_uiX;
	int m_uiY;
	int m_itemListX;
	int m_itemListY;
	int m_EquipItemX;
	int m_EquipItemY;
	int m_itemInfoX;
	int m_itemInfoY;
	int m_functionButtonX;
	int m_functionButtonY;

	vector<RECT> m_vInventoryItemList;
	vector<RECT> m_vInventoryEquipItemSub;
	vector<RECT> m_vInventoryEquipItemMain;
	RECT m_InventoryItemInfo;

	RECT m_exitButton;
	RECT m_equipButton;
	RECT m_unEquipButton;
	RECT m_abandonButton;

	Citem* m_equipWeapon;
	Citem* m_equipArmor;
	Citem* m_selectItem;

	// ��ư Ŭ���� stay�ٿ��� onceó�� ��������..
	bool isButtonClick;
	bool isOnceClick;

	// ��� ���� �������
	ITEMTYPE m_selectType;

	int m_showIndex;
	int m_showEndIndex;
	int m_selectRenderX;
	int m_selectRenderY;
	int m_equipRenderX;
	int m_equipRenderY;
	int m_clickCount;

	bool isSelectRender;
	bool isEquipRender;

	bool isEquipWeapon;
	bool isEquipArmor;

	int m_compareTime;

public:

	CinventoryUi();
	~CinventoryUi();

	HRESULT init();
	void release();
	void update();
	void render();

	// Ÿ���� ���������� ������ ����Ʈ�� showIndex ����
	void setShowIndex();

	// ������ ����Ʈ�� �ش�Ǵ� Ÿ���� ���� ����Ʈ ���
	void showListItemType();
	void showItemList(vector<Citem>* list);
	// ����Ʈ���� ���ý� ����
	void selectItem();
	void selectEquipItem();
	// ������ ������ ���� ��������� set
	void setEquipItem(int index);
	// ���â rect Ŭ���� ���� ������ Ÿ�� ����
	void selectItemType();

	// ������ �������ư
	void abandonItem();
	bool checkEquipItem();
};

