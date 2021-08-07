#pragma once
#include"gameNode.h"
class CinventoryUi : public gameNode
{
	image* m_InventoryUi;

	RECT m_InventoryRc;
	int m_uiX;
	int m_uiY;
	int m_itemInfoX;
	int m_itemInfoY;
	int m_functionButtonX;
	int m_functionButtonY;

	RECT m_InventoryItem;
	vector<RECT> m_vInventoryItemInfo;

	RECT m_ExitButton;
	RECT m_EquipButton;
	RECT m_UnEquipButton;
	RECT m_AbandonButton;

	

	bool isInventoryOn;

public:

	CinventoryUi();
	~CinventoryUi();

	HRESULT init();
	void release();
	void update();
	void render();
};

