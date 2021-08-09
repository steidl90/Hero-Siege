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
	m_myInventory = new Cinventory();
	m_myInventory->init();

	// 전체 UI 좌표
	m_uiX = 200;
	m_uiY = 200;

	m_InventoryRc = RectMake(m_uiX, m_uiY, IMAGE->findImage("인벤토리3")->getWidth(),
		IMAGE->findImage("인벤토리3")->getHeight());

	// 장비창 내부 rect 기준 좌표
	m_EquipItemX = m_uiX + 60;
	m_EquipItemY = m_uiY + 70;

	// 서브템 rect
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			RECT temp;
			temp = RectMake(m_EquipItemX + j * 100, m_EquipItemY + i * 250, 70, 70);
			m_vInventoryEquipItemSub.push_back(temp);
		}
	}
	// 메인템 rect
	for (int i = 0; i < 3; i++)
	{
		RECT temp;
		temp = RectMake(m_EquipItemX + i * 100, m_EquipItemY + 110, 70, 107);
		m_vInventoryEquipItemMain.push_back(temp);
	}

	// 보유 리스트 내부 rect 기준 좌표
	m_itemListX = m_uiX + 410;
	m_itemListY = m_uiY + 25;

	for (int i = 0; i < 4; i++)
	{
		RECT temp;
		temp = RectMake(m_itemListX, m_itemListY + i * 88, 200, 80);
		m_vInventoryItemList.push_back(temp);
	}
	// 기능 버튼 rect 기준 좌표
	m_functionButtonX = m_uiX + 430;
	m_functionButtonY = m_uiY + 390;

	m_equipButton = RectMake(m_functionButtonX, m_functionButtonY, 70, 20);
	m_unEquipButton = RectMake(m_functionButtonX + 90, m_functionButtonY, 70, 20);
	m_abandonButton = RectMake(m_functionButtonX, m_functionButtonY + 24, 70, 20);
	m_exitButton = RectMake(m_functionButtonX + 90, m_functionButtonY + 24, 70, 20);

	isOnceClick = false;
	isButtonClick = false;

	m_showIndex = 0;
	m_selectType = ITEMTYPE::ITEMTYPE_ARMOR;
	isSelectRender = false;
	isEquipRender = false;
	m_clickCount = 0;
	return S_OK;
}

void CinventoryUi::release()
{
	SAFE_DELETE(m_myInventory);
}

void CinventoryUi::update()
{
	this->selectItem();
	this->selectEquipItem();
}

void CinventoryUi::render()
{
	IMAGE->findImage("인벤토리3")->render(getMemDC(), m_uiX, m_uiY);
	
	for (auto iter = m_vInventoryItemList.begin(); iter != m_vInventoryItemList.end(); ++iter)
	{
		//Rectangle(getMemDC(), (*iter).left, (*iter).top, (*iter).right, (*iter).bottom);
	}
	for (auto iter = m_vInventoryEquipItemSub.begin(); iter != m_vInventoryEquipItemSub.end(); ++iter)
	{
		Rectangle(getMemDC(), (*iter).left, (*iter).top, (*iter).right, (*iter).bottom);
	}
	for (auto iter = m_vInventoryEquipItemMain.begin(); iter != m_vInventoryEquipItemMain.end(); ++iter)
	{
		Rectangle(getMemDC(), (*iter).left, (*iter).top, (*iter).right, (*iter).bottom);
	}
	Rectangle(getMemDC(), m_equipButton.left, m_equipButton.top, m_equipButton.right, m_equipButton.bottom);
	Rectangle(getMemDC(), m_unEquipButton.left, m_unEquipButton.top, m_unEquipButton.right, m_unEquipButton.bottom);
	Rectangle(getMemDC(), m_abandonButton.left, m_abandonButton.top, m_abandonButton.right, m_abandonButton.bottom);
	Rectangle(getMemDC(), m_exitButton.left, m_exitButton.top, m_exitButton.right, m_exitButton.bottom);
	
	// 랜더 순서....
	this->selectItemType();

	if (isEquipRender)
		IMAGE->findImage("장착테두리")->render(getMemDC(), m_equipRenderX, m_equipRenderY);
	if(isSelectRender)
		IMAGE->findImage("선택테두리")->render(getMemDC(), m_selectRenderX, m_selectRenderY);
}

// 선택한 타입의 아이템 타입
void CinventoryUi::selectItemType()
{
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		showItemList(m_myInventory->getvWeaponList());
		
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		showItemList(m_myInventory->getvArmorList());
		break;
	default:
		break;
	}
}
// 인덱스 기준으로 벡터를 참조하여
void CinventoryUi::showItemList(vector<Citem>* list)
{
	int i;
	char str[100];
	// show 인덱스는 기본 0~3까지만 보여준다, 이후 스크롤로 1~4 이런식으로 보여주기
	if (list->size() < m_showIndex + 5)
	{
		i = m_showIndex;
		for (auto iter = list->begin(); iter != list->end() && i < (m_showIndex + 4); ++iter, i++)
		{
			IMAGE->findImage((*iter).getSmallImage())->frameRender(getMemDC()
				,m_vInventoryItemList[i].left, m_vInventoryItemList[i].top, (*iter).getFrame().x, (*iter).getFrame().y);

			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), m_vInventoryItemList[i].left + 80, m_vInventoryItemList[i].top + 10, (*iter).getName().c_str(), lstrlen((*iter).getName().c_str()));
			wsprintf(str, "필요 레벨: %d", (*iter).getLimitLevel());
			TextOut(getMemDC(), m_vInventoryItemList[i].left + 80, m_vInventoryItemList[i].top + 30, str, lstrlen(str));
			wsprintf(str, "골드: %d", (*iter).getBuyPrice());
			TextOut(getMemDC(), m_vInventoryItemList[i].left + 80, m_vInventoryItemList[i].top + 50, str, lstrlen(str));
		}
	}
}

// 마우스 1클릭으로 아이템 선택표시
void CinventoryUi::selectItem()
{
	for (auto iter = m_vInventoryItemList.begin(); iter != m_vInventoryItemList.end(); ++iter)
	{
		if (PtInRect(&(*iter), m_ptMouse))
		{
			if (InputManager->isOnceKeyDown(VK_LBUTTON))
			{
				isSelectRender = true;
				m_selectRenderX = (*iter).left - 5;
				m_selectRenderY = (*iter).top - 3;
			}
		}
	}
}
// 마우스 2클릭으로 아이템 장착표시 / 장착
// 일단 같은렉트 클릭조건 예외처리는 안함 -> 추후에 추가필요
void CinventoryUi::selectEquipItem()
{
	int i = 0;
	for (auto iter = m_vInventoryItemList.begin(); iter != m_vInventoryItemList.end(); ++iter, i++)
	{
		if (PtInRect(&(*iter), m_ptMouse))
		{
			if (InputManager->isStayKeyDown(VK_LBUTTON))
			{
				isButtonClick = true;
				if (isButtonClick)
				{
					if (isOnceClick)
					{
						if (m_clickCount == 0)
							m_compareTime = TIME->getWorldTime();
						m_clickCount++;

						// 마우스 더블클릭 되는 시점!
						if (m_clickCount > 1)
						{
							m_equipRenderX = (*iter).left - 5;
							m_equipRenderY = (*iter).top - 3;
							isEquipRender = true;
						}
						isOnceClick = false;
					}
				}
				
			}
			else
			{
				isButtonClick = false;
				isOnceClick = true;
			}
		}
	}
	if (m_compareTime + 1 < TIME->getWorldTime())
		m_clickCount = 0;
}

void CinventoryUi::setEquipItem(int index)
{
	vector<Citem>::iterator weaponTemp;
	vector<Citem>::iterator armorTemp;
	index = index + m_showIndex;
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		weaponTemp = m_myInventory->getvWeaponList()->begin();

		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		break;
	default:
		break;
	}
}
