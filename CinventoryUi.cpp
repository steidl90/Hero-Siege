#include"framework.h"
#include "CinventoryUi.h"

CinventoryUi::CinventoryUi()
{
}

CinventoryUi::~CinventoryUi()
{
}

HRESULT CinventoryUi::init()
{
	m_InventoryUi = IMAGE->addImage("인벤토리UI", "images/inventoryUI.bmp", 469, 473, true, RGB(255, 0, 255));
	
	m_uiX = 150;
	m_uiY = 150;
	m_InventoryRc = RectMake(m_uiX, m_uiY, m_InventoryUi->getWidth(), m_InventoryUi->getHeight());

	m_itemInfoX = m_uiX + 80;
	m_itemInfoY = m_uiY + 29;

	for (int i = 0; i < 4; i++)
	{
		RECT temp;
		temp = RectMake(m_itemInfoX, m_itemInfoY + i * 88, 140, 70);
		m_vInventoryItemInfo.push_back(temp);
	}

	m_functionButtonX = m_uiX + 40;
	m_functionButtonY = m_uiY + 390;

	m_EquipButton = RectMake(m_functionButtonX, m_functionButtonY, 70, 25);
	m_UnEquipButton = RectMake(m_functionButtonX + 90, m_functionButtonY, 70, 25);
	m_AbandonButton = RectMake(m_functionButtonX, m_functionButtonY + 40, 70, 25);
	m_ExitButton = RectMake(m_functionButtonX + 90, m_functionButtonY + 40, 70, 25);

	isInventoryOn = false;
	return S_OK;
}

void CinventoryUi::release()
{
}

void CinventoryUi::update()
{
	if (InputManager->isOnceKeyDown('I'))
	{
		isInventoryOn = !isInventoryOn;
	}
}

void CinventoryUi::render()
{
	if (isInventoryOn)
	{
		m_InventoryUi->render(getMemDC(), m_InventoryRc.left, m_InventoryRc.top);
		for (int i = 0; i < m_vInventoryItemInfo.size(); i++)
		{
		Rectangle(getMemDC(), m_vInventoryItemInfo[i].left, m_vInventoryItemInfo[i].top, m_vInventoryItemInfo[i].right, m_vInventoryItemInfo[i].bottom);
		}

		Rectangle(getMemDC(), m_EquipButton.left, m_EquipButton.top, m_EquipButton.right, m_EquipButton.bottom);
		Rectangle(getMemDC(), m_UnEquipButton.left, m_UnEquipButton.top, m_UnEquipButton.right, m_UnEquipButton.bottom);
		Rectangle(getMemDC(), m_AbandonButton.left, m_AbandonButton.top, m_AbandonButton.right, m_AbandonButton.bottom);
		Rectangle(getMemDC(), m_ExitButton.left, m_ExitButton.top, m_ExitButton.right, m_ExitButton.bottom);
	}
}
