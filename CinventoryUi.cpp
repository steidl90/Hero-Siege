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

	// 
	m_itemInfoX = m_uiX + 645;
	m_itemInfoY = m_uiY + 30;

	m_InventoryItemInfo = RectMake(m_itemInfoX, m_itemInfoY, 180, 80);

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
	m_showEndIndex = 0;
	m_selectType = ITEMTYPE::ITEMTYPE_ARMOR;
	isSelectRender = false;
	isEquipRender = false;
	m_clickCount = 0;

	isEquipWeapon = false;
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
	this->selectItemType();
	this->abandonItem();
	// 상시 set을 적용할것인지 특정 타이밍에 set할것인지 일단 고민
	this->setShowIndex();
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
		//Rectangle(getMemDC(), (*iter).left, (*iter).top, (*iter).right, (*iter).bottom);
	}
	for (auto iter = m_vInventoryEquipItemMain.begin(); iter != m_vInventoryEquipItemMain.end(); ++iter)
	{
		//Rectangle(getMemDC(), (*iter).left, (*iter).top, (*iter).right, (*iter).bottom);
	}
	Rectangle(getMemDC(), m_InventoryItemInfo.left, m_InventoryItemInfo.top, m_InventoryItemInfo.right, m_InventoryItemInfo.bottom);

	Rectangle(getMemDC(), m_equipButton.left, m_equipButton.top, m_equipButton.right, m_equipButton.bottom);
	Rectangle(getMemDC(), m_unEquipButton.left, m_unEquipButton.top, m_unEquipButton.right, m_unEquipButton.bottom);
	Rectangle(getMemDC(), m_abandonButton.left, m_abandonButton.top, m_abandonButton.right, m_abandonButton.bottom);
	Rectangle(getMemDC(), m_exitButton.left, m_exitButton.top, m_exitButton.right, m_exitButton.bottom);
	
	// 랜더 순서....
	this->showListItemType();

	// 테두리 렌더
	if (isEquipRender)
	{
		IMAGE->findImage("장착테두리")->render(getMemDC(), m_equipRenderX, m_equipRenderY);
	}
	if(isSelectRender)
		IMAGE->findImage("선택테두리")->render(getMemDC(), m_selectRenderX, m_selectRenderY);
	// 장비창 렌더
	if (isEquipWeapon)
	{
		IMAGE->findImage((*m_equipWeapon).getBigImage())->frameRender(getMemDC(), m_vInventoryEquipItemMain[0].left - 10, m_vInventoryEquipItemMain[0].top + 10, (*m_equipWeapon).getFrame().x, (*m_equipWeapon).getFrame().y);
		IMAGE->findImage((*m_equipWeapon).getBigImage())->frameRender(getMemDC(), m_vInventoryEquipItemMain[2].left - 10, m_vInventoryEquipItemMain[2].top + 10, (*m_equipWeapon).getFrame().x, (*m_equipWeapon).getFrame().y);
	}
	if (isEquipArmor)
	{
		IMAGE->findImage((*m_equipArmor).getBigImage())->frameRender(getMemDC(), m_vInventoryEquipItemMain[1].left - 10, m_vInventoryEquipItemMain[1].top + 10 ,(*m_equipArmor).getFrame().x, (*m_equipArmor).getFrame().y);
	}
}

void CinventoryUi::setShowIndex()
{
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		m_showEndIndex = m_myInventory->getvWeaponList()->size() + m_showIndex;
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		m_showEndIndex = m_myInventory->getvArmorList()->size() + m_showIndex;
		break;
	default:
		break;
	}
}

// 선택한 타입의 아이템 타입만 인벤토리 리스트에 보여짐
void CinventoryUi::showListItemType()
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
	int i = m_showIndex;
	vector<Citem>::iterator weaponIter;
	vector<Citem>::iterator armorIter;

	for (auto iter = m_vInventoryItemList.begin(); iter != m_vInventoryItemList.end() && i < m_showEndIndex; ++iter, i++)
	{
		if (PtInRect(&(*iter), m_ptMouse))
		{
			if (InputManager->isOnceKeyDown(VK_LBUTTON))
			{
				isSelectRender = true;
				m_selectRenderX = (*iter).left - 5;
				m_selectRenderY = (*iter).top - 3;
				
				// 선택 아이템 변수에 담기
				switch (m_selectType)
				{
				case ITEMTYPE::ITEMTYPE_WEAPON:
					weaponIter = m_myInventory->getvWeaponList()->begin() + i;
					m_selectItem = &(*weaponIter);
					break;
				case ITEMTYPE::ITEMTYPE_ARMOR:
					armorIter = m_myInventory->getvArmorList()->begin() + i;
					m_selectItem = &(*armorIter);
					break;
				default:
					break;
				}
			}
		}
	}
}
// 마우스 2클릭으로 아이템 장착표시 / 장착
// 일단 같은렉트 클릭조건 예외처리는 안함 -> 추후에 추가필요
void CinventoryUi::selectEquipItem()
{
	int i = m_showIndex;
	for (auto iter = m_vInventoryItemList.begin(); iter != m_vInventoryItemList.end() && i<m_showEndIndex; ++iter, i++)
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
							this->setEquipItem(i);
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
	// 장착 아이템변수에 담기
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		weaponTemp = m_myInventory->getvWeaponList()->begin()+index;
		m_equipWeapon = &(*weaponTemp);
		isEquipWeapon = true;
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		armorTemp = m_myInventory->getvArmorList()->begin() + index;
		m_equipArmor = &(*armorTemp);
		isEquipArmor = true;
		break;
	default:
		break;
	}
}

// 장비창 아이템칸 클릭시 작동되는 것들
void CinventoryUi::selectItemType()
{
	for (auto iter = m_vInventoryEquipItemMain.begin(); iter != m_vInventoryEquipItemMain.end(); ++iter)
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

						// 야매로 비교.. 가운데 장비창인지 확인 else 는 양옆 장비창
						if ((*iter).left == m_vInventoryEquipItemMain[1].left)
						{
							m_selectType = ITEMTYPE::ITEMTYPE_ARMOR;
						}
						else
							m_selectType = ITEMTYPE::ITEMTYPE_WEAPON;

						// 마우스 더블클릭 되는 시점!
						// 장착 해제
						// 장착 해제시 장착 테두리도 타입별로 만들어 줘야함.. 일단 보류
						if (m_clickCount > 1)
						{
							if ((*iter).left == m_vInventoryEquipItemMain[1].left)
							{
								isEquipArmor = false;
								isEquipRender = false;
								m_equipArmor = nullptr;
							}
							else
							{
								isEquipWeapon = false;
								isEquipRender = false;
								m_equipWeapon = nullptr;
							}
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

void CinventoryUi::abandonItem()
{
	if (PtInRect(&m_abandonButton, m_ptMouse))
	{
		if (InputManager->isStayKeyDown(VK_LBUTTON))
		{
			isButtonClick = true;
				if (isButtonClick)
				{
					if (isOnceClick)
					{
						// 선택 아이템이 있을때만 실행
						// 장착중이지 않은 아이템만 실행
						if (m_selectItem != nullptr && this->checkEquipItem())
						{
							m_myInventory->AbandonItem(m_selectItem);
							m_selectItem = nullptr;
							isSelectRender = false;
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

bool CinventoryUi::checkEquipItem()
{
	if (m_equipWeapon == m_selectItem)
		return false;
	else if (m_equipArmor == m_selectItem)
		return false;

	return true;
}
