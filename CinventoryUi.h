#pragma once
#include"gameNode.h"
#include"Cinventory.h"

class CinventoryUi : public gameNode
{
private:
	Cinventory* m_myInventory;

private:

	// 기본 UI 멤버변수
	RECT m_InventoryRc;
	int m_uiX;
	int m_uiY;
	int m_itemListX;
	int m_itemListY;
	int m_EquipItemX;
	int m_EquipItemY;
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

	Citem m_equipWeapon;
	Citem m_equipArmor;
	
	// 버튼 클릭시 stay다운을 once처럼 쓰기위해..
	bool isButtonClick;
	bool isOnceClick;

	// 기능 구현 멤버변수
	ITEMTYPE m_selectType;

	int m_showIndex;
	int m_selectRenderX;
	int m_selectRenderY;
	int m_equipRenderX;
	int m_equipRenderY;
	int m_clickCount;

	bool isSelectRender;
	bool isEquipRender;

	int m_compareTime;

public:

	CinventoryUi();
	~CinventoryUi();

	HRESULT init();
	void release();
	void update();
	void render();

	// 아이템 리스트에 해당되는 타입의 보유 리스트 출력
	void selectItemType();
	void showItemList(vector<Citem>* list);

	void selectItem();
	void selectEquipItem();

	void setEquipItem(int index);
};

