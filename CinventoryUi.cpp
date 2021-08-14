#include "framework.h"
#include "CinventoryUi.h"
#include "Cplayer.h"
CinventoryUi::CinventoryUi()
{
}

CinventoryUi::~CinventoryUi()
{
}

HRESULT CinventoryUi::init()
{
	// ��ü UI ��ǥ
	m_uiX = 200;
	m_uiY = 200;

	m_InventoryRect = RectMake(m_uiX, m_uiY, IMAGE->findImage("�κ��丮3")->getWidth(),
		IMAGE->findImage("�κ��丮3")->getHeight());

	// ���â ���� rect ���� ��ǥ
	m_EquipItemX = m_uiX + 60;
	m_EquipItemY = m_uiY + 70;

	// ������ rect
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			RECT temp;
			temp = RectMake(m_EquipItemX + j * 100, m_EquipItemY + i * 250, 70, 70);
			m_vEquipItemSubRect.push_back(temp);
		}
	}
	// ������ rect
	for (int i = 0; i < 3; i++)
	{
		RECT temp;
		temp = RectMake(m_EquipItemX + i * 100, m_EquipItemY + 110, 70, 107);
		m_vEquipItemMainRect.push_back(temp);
	}

	// ���� ����Ʈ ���� rect ���� ��ǥ
	m_itemListX = m_uiX + 410;
	m_itemListY = m_uiY + 25;

	for (int i = 0; i < 4; i++)
	{
		RECT temp;
		temp = RectMake(m_itemListX, m_itemListY + i * 88, 200, 80);
		m_vItemListRect.push_back(temp);
	}

	// 
	m_itemInfoX = m_uiX + 645;
	m_itemInfoY = m_uiY + 30;

	m_ItemInfoRect = RectMake(m_itemInfoX, m_itemInfoY, 180, 80);

	// ��� ��ư rect ���� ��ǥ
	m_functionButtonX = m_uiX + 430;
	m_functionButtonY = m_uiY + 390;

	m_equipButton = RectMake(m_functionButtonX - 5, m_functionButtonY + 10, 70, 20);
	m_abandonButton = RectMake(m_functionButtonX + 90, m_functionButtonY + 10, 70, 20);

	isKeyUp = false;
	isButtonClick = false;

	m_showIndex = 0;
	m_showEndIndex = 0;
	m_selectType = ITEMTYPE::ITEMTYPE_WEAPON;
	isSelectRender = false;
	m_clickCount = 0;
	m_SelectIndex = 0;

	for (int i = 0; i < 5; i++)
	{
		ZeroMemory(&m_equipItem[i], sizeof(m_equipItem));
	}
	return S_OK;
}

void CinventoryUi::release()
{
}

void CinventoryUi::update()
{
	this->selectItem();
	this->selectEquipItem();
	this->selectItemTypeMain();
	this->selectItemTypeSub();
	this->abandonItem();
	this->clickEquipButton();

	// ���� �߿� �ε��� ����� ������ ������ �� ������� �Ŀ� �ٷ� ���ֱ�
	this->setShowIndex();

	if (InputManager->isStayKeyDown(VK_LBUTTON)) isButtonClick = true;
	else
	{
		isButtonClick = false;
		isKeyUp = true;
	}
}

void CinventoryUi::render()
{
	IMAGE->findImage("�κ��丮3")->render(getMemDC(), m_uiX, m_uiY);
	
	for (auto iter = m_vItemListRect.begin(); iter != m_vItemListRect.end(); ++iter)
	{
		//Rectangle(getMemDC(), (*iter).left, (*iter).top, (*iter).right, (*iter).bottom);
	}
	for (auto iter = m_vEquipItemSubRect.begin(); iter != m_vEquipItemSubRect.end(); ++iter)
	{
		//Rectangle(getMemDC(), (*iter).left, (*iter).top, (*iter).right, (*iter).bottom);
	}
	for (auto iter = m_vEquipItemMainRect.begin(); iter != m_vEquipItemMainRect.end(); ++iter)
	{
		//Rectangle(getMemDC(), (*iter).left, (*iter).top, (*iter).right, (*iter).bottom);
	}
	//Rectangle(getMemDC(), m_ItemInfoRect.left, m_ItemInfoRect.top, m_ItemInfoRect.right, m_ItemInfoRect.bottom);

	SetTextColor(getMemDC(), RGB(255, 255, 255));
	//Rectangle(getMemDC(), m_equipButton.left, m_equipButton.top, m_equipButton.right, m_equipButton.bottom);
	TextOut(getMemDC(), m_equipButton.left, m_equipButton.top, TEXT("����"), lstrlen("����"));
	//Rectangle(getMemDC(), m_abandonButton.left, m_abandonButton.top, m_abandonButton.right, m_abandonButton.bottom);
	TextOut(getMemDC(), m_abandonButton.left, m_abandonButton.top, TEXT("������"), lstrlen("������"));
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	char strGold[100];
	wsprintf(strGold, "�����ݾ�: %dGold", m_player->getGold());
	TextOut(getMemDC(), m_equipButton.left, m_equipButton.top + 30, strGold, lstrlen(strGold));

	// ���õ� Ÿ�Ժ� ������ ���
	this->showListItemType();
	// ���� �׵θ�
	this->showEquipSelect();
	// ���ý� ��� �κ�
	if (isSelectRender)
	{
		IMAGE->findImage("�����׵θ�")->render(getMemDC(), m_selectRenderX, m_selectRenderY);
		this->showItemInfo();
	}
	// ���â ����
	// equipMain��Ʈ - 0,2: ���� / 1:����, equipSub��Ʈ - 0: �Ҵ�Ʈ, 3:�尩, 4:�Ź�
	//TODO::�Ҳ� - ��
	if (m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_WEAPON)->isEquip)
	{
		IMAGE->findImage(m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_WEAPON)->m_item->getBigImage())->frameRender(getMemDC(),
			m_vEquipItemMainRect[0].left - 10, m_vEquipItemMainRect[0].top + 10
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_WEAPON)->m_item->getFrame().x
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_WEAPON)->m_item->getFrame().y);
		IMAGE->findImage(m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_WEAPON)->m_item->getBigImage())->frameRender(getMemDC(),
			m_vEquipItemMainRect[2].left - 10, m_vEquipItemMainRect[2].top + 10
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_WEAPON)->m_item->getFrame().x
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_WEAPON)->m_item->getFrame().y);
	}
	if (m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_ARMOR)->isEquip)
	{
		IMAGE->findImage(m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_ARMOR)->m_item->getBigImage())->frameRender(getMemDC(),
			m_vEquipItemMainRect[1].left - 10, m_vEquipItemMainRect[1].top + 10
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_ARMOR)->m_item->getFrame().x
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_ARMOR)->m_item->getFrame().y);
	}
	if (m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_SHOES)->isEquip)
	{
		IMAGE->findImage(m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_SHOES)->m_item->getBigImage())->frameRender(getMemDC(),
			m_vEquipItemSubRect[4].left - 10, m_vEquipItemSubRect[4].top + 10
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_SHOES)->m_item->getFrame().x
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_SHOES)->m_item->getFrame().y);
	}
	if (m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_GLOVES)->isEquip)
	{
		IMAGE->findImage(m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_GLOVES)->m_item->getBigImage())->frameRender(getMemDC(),
			m_vEquipItemSubRect[3].left - 10, m_vEquipItemSubRect[3].top + 10
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_GLOVES)->m_item->getFrame().x
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_GLOVES)->m_item->getFrame().y);
	}
	if (m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_PENDANT)->isEquip)
	{
		IMAGE->findImage(m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_GLOVES)->m_item->getBigImage())->frameRender(getMemDC(),
			m_vEquipItemSubRect[0].left - 10, m_vEquipItemSubRect[0].top + 10
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_GLOVES)->m_item->getFrame().x
			, m_Inventory->getEquipItem(ITEMTYPE::ITEMTYPE_GLOVES)->m_item->getFrame().y);
	}
}

// ���� ����ó�� �ϼ� �ȵ�.. ��ũ�� ������ �������� ����ó�� �ʿ�
// ��ũ�� ����� ������, �κ��丮 ����Ʈ�� ������ 4�� �ε��� ����
// ��� Ÿ�Ժ� showIndex �ʿ��ҵ�?
void CinventoryUi::setShowIndex()
{
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		if (m_Inventory->getvWeaponList()->size() < 4)
		{
			m_showIndex = 0;
			m_showEndIndex = m_Inventory->getvWeaponList()->size();
		}
		else if(m_Inventory->getvWeaponList()->size() - 4 < m_showIndex)	// ������ ��ũ������ ��
		{
			m_showIndex = m_Inventory->getvWeaponList()->size() - 4;
			m_showEndIndex = m_showIndex + 4;
		}
		else m_showEndIndex = m_showIndex + 4;

		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		if (m_Inventory->getvArmorList()->size() < 5)
		{
			m_showIndex = 0;
			m_showEndIndex = m_Inventory->getvArmorList()->size();
		}
		else if (m_Inventory->getvArmorList()->size() - 4 < m_showIndex)	// ������ ��ũ������ �� ����ó��
		{
			m_showIndex = m_Inventory->getvArmorList()->size() - 4;
			m_showEndIndex = m_showIndex + 4;
		}
		else m_showEndIndex = m_showIndex + 4;

		break;
	case ITEMTYPE::ITEMTYPE_SHOES:
		if (m_Inventory->getvShoesList()->size() < 4)
		{
			m_showIndex = 0;
			m_showEndIndex = m_Inventory->getvShoesList()->size();
		}
		else if (m_Inventory->getvShoesList()->size() - 4 < m_showIndex)	// ������ ��ũ������ ��
		{
			m_showIndex = m_Inventory->getvShoesList()->size() - 4;
			m_showEndIndex = m_showIndex + 4;
		}
		else m_showEndIndex = m_showIndex + 4;

		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		if (m_Inventory->getvGlovesList()->size() < 4)
		{
			m_showIndex = 0;
			m_showEndIndex = m_Inventory->getvGlovesList()->size();
		}
		else if (m_Inventory->getvGlovesList()->size() - 4 < m_showIndex)	// ������ ��ũ������ ��
		{
			m_showIndex = m_Inventory->getvGlovesList()->size() - 4;
			m_showEndIndex = m_showIndex + 4;
		}
		else m_showEndIndex = m_showIndex + 4;
		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		if (m_Inventory->getvPendantList()->size() < 4)
		{
			m_showIndex = 0;
			m_showEndIndex = m_Inventory->getvPendantList()->size();
		}
		else if (m_Inventory->getvPendantList()->size() - 4 < m_showIndex)	// ������ ��ũ������ ��
		{
			m_showIndex = m_Inventory->getvPendantList()->size() - 4;
			m_showEndIndex = m_showIndex + 4;
		}
		else m_showEndIndex = m_showIndex + 4;
		
		break;
	default:
		break;
	}
}

// ������ Ÿ���� ������ Ÿ�Ը� �κ��丮 ����Ʈ�� ������
void CinventoryUi::showListItemType()
{
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		showItemList(m_Inventory->getvWeaponList());
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		showItemList(m_Inventory->getvArmorList());
		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		showItemList(m_Inventory->getvGlovesList());
		break;
	case ITEMTYPE::ITEMTYPE_SHOES:
		showItemList(m_Inventory->getvShoesList());
		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		showItemList(m_Inventory->getvPendantList());
		break;
	default:
		break;
	}
}
// �ε��� �������� ���͸� �����Ͽ�
void CinventoryUi::showItemList(vector<Citem*>* list)
{
	char str[100];
	// show �ε����� �����ε����� �����ϸ� �ű���� ������ ������ �����ִ� ���� (�ִ� 4��)
	// j �ε����� ��Ʈ 0~3���� �����ϱ� ���� �ε���
	// i �ε����� show�ε����� �븮 ����(showIndex���� ���ϸ� �ȵǴ�)
	int	i = m_showIndex;
	int j = 0;
	vector<Citem*>::iterator iter;
		for ( iter = list->begin() + i; i < m_showEndIndex; ++iter, i++, j++)
		{
			IMAGE->findImage((**iter).getSmallImage())->frameRender(getMemDC()
				,m_vItemListRect[j].left, m_vItemListRect[j].top, (**iter).getFrame().x, (**iter).getFrame().y);

			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), m_vItemListRect[j].left + 80, m_vItemListRect[j].top + 10, (**iter).getName().c_str(), lstrlen((**iter).getName().c_str()));
			wsprintf(str, "�ʿ� ����: %d", (**iter).getLimitLevel());
			TextOut(getMemDC(), m_vItemListRect[j].left + 80, m_vItemListRect[j].top + 30, str, lstrlen(str));
			wsprintf(str, "���: %d", (**iter).getBuyPrice());
			TextOut(getMemDC(), m_vItemListRect[j].left + 80, m_vItemListRect[j].top + 50, str, lstrlen(str));
		}
}

// ���� �ε����� ����ؼ� ���� ������ �׵θ� ��ġ ����
// ������ Ÿ�� �߰� �ʿ�
void CinventoryUi::showEquipSelect()
{
	int renderIndex;
	bool isEquipSelectRender = true;
	renderIndex = m_equipItem[static_cast<int>(m_selectType)].m_itemIndex - m_showIndex;
	if (renderIndex < 0 || renderIndex > 3)
		isEquipSelectRender = false;
	for (int i = 0; i < 4; i++)
	{
		if (i == renderIndex)
		{
			m_equipItem[static_cast<int>(m_selectType)].m_renderPoint.x = m_vItemListRect[i].left - 5;
			m_equipItem[static_cast<int>(m_selectType)].m_renderPoint.y = m_vItemListRect[i].top - 3;
		}
	}
	//TODO::�Ҳ� - ��
	if (isEquipSelectRender)
	{
		switch (m_selectType)
		{
		case ITEMTYPE::ITEMTYPE_WEAPON:
			if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].isEquip)
				IMAGE->findImage("�����׵θ�")->render(getMemDC(), m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].m_renderPoint.x,
					m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].m_renderPoint.y);
			break;
		case ITEMTYPE::ITEMTYPE_ARMOR:
			if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].isEquip)
				IMAGE->findImage("�����׵θ�")->render(getMemDC(), m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].m_renderPoint.x,
					m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].m_renderPoint.y);
			break;
		case ITEMTYPE::ITEMTYPE_GLOVES:
			if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].isEquip)
				IMAGE->findImage("�����׵θ�")->render(getMemDC(), m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].m_renderPoint.x,
					m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].m_renderPoint.y);
			break;
		case ITEMTYPE::ITEMTYPE_SHOES:
			if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].isEquip)
				IMAGE->findImage("�����׵θ�")->render(getMemDC(), m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].m_renderPoint.x,
					m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].m_renderPoint.y);
			break;
		case ITEMTYPE::ITEMTYPE_PENDANT:
			if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].isEquip)
				IMAGE->findImage("�����׵θ�")->render(getMemDC(), m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].m_renderPoint.x,
					m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].m_renderPoint.y);
			break;
		}
	}

}

// ���콺 1Ŭ������ ������ ����ǥ��
void CinventoryUi::selectItem()
{
	int i = m_showIndex;
	vector<Citem*>::iterator itemIter;
	for (auto iter = m_vItemListRect.begin(); i < m_showEndIndex; ++iter, i++)
	{
		if (PtInRect(&(*iter), m_ptMouse))
		{
			if (InputManager->isOnceKeyDown(VK_LBUTTON))
			{
				/*isSelectRender = true;
				m_selectRenderX = (*iter).left - 5;
				m_selectRenderY = (*iter).top - 3;
				m_SelectIndex = i;*/
				// ������ ������ ���� inventory ���� �����ͼ� selectItem ������ ���
				switch (m_selectType)
				{
				case ITEMTYPE::ITEMTYPE_WEAPON:
					itemIter = m_Inventory->getvWeaponList()->begin() + i;
					break;
				case ITEMTYPE::ITEMTYPE_ARMOR:
					itemIter = m_Inventory->getvArmorList()->begin() + i;
					break;
				case ITEMTYPE::ITEMTYPE_GLOVES:
					itemIter = m_Inventory->getvGlovesList()->begin() + i;
					break;
				case ITEMTYPE::ITEMTYPE_SHOES:
					itemIter = m_Inventory->getvShoesList()->begin() + i;
					break;
				case ITEMTYPE::ITEMTYPE_PENDANT:
					itemIter = m_Inventory->getvPendantList()->begin() + i;
					break;
				}
				m_Inventory->setSelectItem((*itemIter), i
					, PointMake(m_selectRenderX, m_selectRenderY), true);
			}
		}
	}
}
// ���콺 2Ŭ������ ������ ����ǥ�� / ����
void CinventoryUi::selectEquipItem()
{
	int i = m_showIndex;
	vector<RECT>::iterator iter;
	for (iter = m_vItemListRect.begin(); i < m_showEndIndex; ++iter, i++)
	{
		if (PtInRect(&(*iter), m_ptMouse))
		{
			// ���� ��Ʈ Ŭ���ϰ��ִ��� üũ
			if (m_clickCheckRect.top != (*iter).top)
				m_clickCount = 0;
			m_clickCheckRect = (*iter);
			
			if (InputManager->isStayKeyDown(VK_LBUTTON))
			{
				isButtonClick = true;
				if (isButtonClick)
				{
					if (isKeyUp)
					{
						if (m_clickCount == 0)
							m_compareTime = TIME->getWorldTime();
						m_clickCount++;

						// ���콺 ����Ŭ�� �Ǵ� ����!
						// ������ ������ ���� ��� �� ����
						if (m_clickCount > 1)
						{
							m_equipItem[static_cast<int>(m_selectType)].m_itemIndex = i;
							this->setEquipItem(i, m_selectRenderX, m_selectRenderY);
						}
						isKeyUp = false;
					}
				}
			}
			else
			{
				isButtonClick = false;
				isKeyUp = true;
			}
		}
	}
	if (m_compareTime + 1 < TIME->getWorldTime())
		m_clickCount = 0;
}
// ������ ����!
// ������ ������ ����ü�迭 �� ������ ������ ���� �־��ֱ�
// ������ Ÿ�� �߰� �ʿ�
//TODO::�Ҳ� - ��
void CinventoryUi::setEquipItem(int index, int x, int y)
{
	Citem* itemTemp;
	
	this->setPlayerStat(index);

	// ���� �����ۺ����� ���
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		// ���ͷ����� �����ؼ� ���� ���Ҵ� �ش� ���� ������ ������ ���� ���־ �ٽ� ��ȯ����
		// ������ �𸣰����� ���� ���ͷ����Ͱ����� ������ ���߿� �κ��丮���� �ٸ��� �������� �������
		// �׷��� �ӽ� ������ �迭�� �����ؼ� �װ� ����ü �迭�� ����

		m_Inventory->setEquipWeapon(&(*(m_Inventory->getvWeaponList()->begin() + index)));
		itemTemp = m_Inventory->getEquipWeapon();
		m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)] = (*itemTemp);
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].m_equipItem = &m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)];
		// ���⼭ �ε����� �κ��丮���� �ش������ ����Ʈ���� ��ġ�� ��Ÿ����!
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].m_itemIndex = index;
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].m_renderPoint = PointMake(x, y);
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].isEquip = true;

		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		m_Inventory->setEquipArmor(&(*(m_Inventory->getvArmorList()->begin() + index)));
		itemTemp = m_Inventory->getEquipArmor();
		m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)] = (*itemTemp);
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].m_equipItem = &m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)];
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].m_itemIndex = index;
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].m_renderPoint = PointMake(x, y);
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].isEquip = true;
		break;
	case ITEMTYPE::ITEMTYPE_SHOES:
		m_Inventory->setEquipShoes(&(*(m_Inventory->getvShoesList()->begin() + index)));
		itemTemp = m_Inventory->getEquipShoes();
		m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)] = (*itemTemp);
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].m_equipItem = &m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)];
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].m_itemIndex = index;
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].m_renderPoint = PointMake(x, y);
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].isEquip = true;
		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		m_Inventory->setEquipGloves(&(*(m_Inventory->getvGlovesList()->begin() + index)));
		itemTemp = m_Inventory->getEquipGloves();
		m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)] = (*itemTemp);
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].m_equipItem = &m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)];
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].m_itemIndex = index;
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].m_renderPoint = PointMake(x, y);
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].isEquip = true;
		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		m_Inventory->setEquipPendant(&(*(m_Inventory->getvPendantList()->begin() + index)));
		itemTemp = m_Inventory->getEquipPendant();
		m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)] = (*itemTemp);
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].m_equipItem = &m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)];
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].m_itemIndex = index;
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].m_renderPoint = PointMake(x, y);
		m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].isEquip = true;
		break;
	default:
		break;
	}
}

void CinventoryUi::setPlayerStat(int index)
{
	Citem* Temp;
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		Temp = (*(m_Inventory->getvWeaponList()->begin() + index));
		if (m_Inventory->getEquipWeapon() == nullptr)
		{
			m_player->setAtk(m_player->getAtk() + Temp->getAtk());
			m_player->setDef(m_player->getDef() + Temp->getDef());
			m_player->setHp(m_player->getHp() + Temp->getHp());
			m_player->setMp(m_player->getMp() + Temp->getMp());
			m_player->setCritical(m_player->getCritical() + Temp->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() + Temp->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() + Temp->getSpeed());
		}
		else
		{	// �̹� ������ ������ �ɷ�ġ ����
			m_player->setAtk(m_player->getAtk() - m_Inventory->getEquipWeapon()->getAtk());
			m_player->setDef(m_player->getDef() - m_Inventory->getEquipWeapon()->getDef());
			m_player->setHp(m_player->getHp() - m_Inventory->getEquipWeapon()->getHp());
			m_player->setMp(m_player->getMp() - m_Inventory->getEquipWeapon()->getMp());
			m_player->setCritical(m_player->getCritical() - m_Inventory->getEquipWeapon()->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() - m_Inventory->getEquipWeapon()->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() - m_Inventory->getEquipWeapon()->getSpeed());

			m_player->setAtk(m_player->getAtk() + Temp->getAtk());
			m_player->setDef(m_player->getDef() + Temp->getDef());
			m_player->setHp(m_player->getHp() + Temp->getHp());
			m_player->setMp(m_player->getMp() + Temp->getMp());
			m_player->setCritical(m_player->getCritical() + Temp->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() + Temp->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() + Temp->getSpeed());
		}
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		Temp = (*(m_Inventory->getvArmorList()->begin() + index));
		if (m_Inventory->getEquipArmor() == nullptr)
		{
			m_player->setAtk(m_player->getAtk() + Temp->getAtk());
			m_player->setDef(m_player->getDef() + Temp->getDef());
			m_player->setHp(m_player->getHp() + Temp->getHp());
			m_player->setMp(m_player->getMp() + Temp->getMp());
			m_player->setCritical(m_player->getCritical() + Temp->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() + Temp->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() + Temp->getSpeed());
		}
		else
		{	// �̹� ������ ������ �ɷ�ġ ����
			m_player->setAtk(m_player->getAtk() - m_Inventory->getEquipArmor()->getAtk());
			m_player->setDef(m_player->getDef() - m_Inventory->getEquipArmor()->getDef());
			m_player->setHp(m_player->getHp() - m_Inventory->getEquipArmor()->getHp());
			m_player->setMp(m_player->getMp() - m_Inventory->getEquipArmor()->getMp());
			m_player->setCritical(m_player->getCritical() - m_Inventory->getEquipArmor()->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() - m_Inventory->getEquipArmor()->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() - m_Inventory->getEquipArmor()->getSpeed());

			m_player->setAtk(m_player->getAtk() + Temp->getAtk());
			m_player->setDef(m_player->getDef() + Temp->getDef());
			m_player->setHp(m_player->getHp() + Temp->getHp());
			m_player->setMp(m_player->getMp() + Temp->getMp());
			m_player->setCritical(m_player->getCritical() + Temp->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() + Temp->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() + Temp->getSpeed());
		}
		break;
	case ITEMTYPE::ITEMTYPE_SHOES:
		Temp = (*(m_Inventory->getvShoesList()->begin() + index));
		if (m_Inventory->getEquipShoes() == nullptr)
		{
			m_player->setAtk(m_player->getAtk() + Temp->getAtk());
			m_player->setDef(m_player->getDef() + Temp->getDef());
			m_player->setHp(m_player->getHp() + Temp->getHp());
			m_player->setMp(m_player->getMp() + Temp->getMp());
			m_player->setCritical(m_player->getCritical() + Temp->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() + Temp->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() + Temp->getSpeed());
		}
		else
		{	// �̹� ������ ������ �ɷ�ġ ����
			m_player->setAtk(m_player->getAtk() - m_Inventory->getEquipShoes()->getAtk());
			m_player->setDef(m_player->getDef() - m_Inventory->getEquipShoes()->getDef());
			m_player->setHp(m_player->getHp() - m_Inventory->getEquipShoes()->getHp());
			m_player->setMp(m_player->getMp() - m_Inventory->getEquipShoes()->getMp());
			m_player->setCritical(m_player->getCritical() - m_Inventory->getEquipShoes()->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() - m_Inventory->getEquipShoes()->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() - m_Inventory->getEquipShoes()->getSpeed());

			m_player->setAtk(m_player->getAtk() + Temp->getAtk());
			m_player->setDef(m_player->getDef() + Temp->getDef());
			m_player->setHp(m_player->getHp() + Temp->getHp());
			m_player->setMp(m_player->getMp() + Temp->getMp());
			m_player->setCritical(m_player->getCritical() + Temp->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() + Temp->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() + Temp->getSpeed());
		}
		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		Temp = (*(m_Inventory->getvShoesList()->begin() + index));
		if (m_Inventory->getEquipShoes() == nullptr)
		{
			m_player->setAtk(m_player->getAtk() + Temp->getAtk());
			m_player->setDef(m_player->getDef() + Temp->getDef());
			m_player->setHp(m_player->getHp() + Temp->getHp());
			m_player->setMp(m_player->getMp() + Temp->getMp());
			m_player->setCritical(m_player->getCritical() + Temp->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() + Temp->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() + Temp->getSpeed());
		}
		else
		{	// �̹� ������ ������ �ɷ�ġ ����
			m_player->setAtk(m_player->getAtk() - m_Inventory->getEquipGloves()->getAtk());
			m_player->setDef(m_player->getDef() - m_Inventory->getEquipGloves()->getDef());
			m_player->setHp(m_player->getHp() - m_Inventory->getEquipGloves()->getHp());
			m_player->setMp(m_player->getMp() - m_Inventory->getEquipGloves()->getMp());
			m_player->setCritical(m_player->getCritical() - m_Inventory->getEquipGloves()->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() - m_Inventory->getEquipGloves()->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() - m_Inventory->getEquipGloves()->getSpeed());

			m_player->setAtk(m_player->getAtk() + Temp->getAtk());
			m_player->setDef(m_player->getDef() + Temp->getDef());
			m_player->setHp(m_player->getHp() + Temp->getHp());
			m_player->setMp(m_player->getMp() + Temp->getMp());
			m_player->setCritical(m_player->getCritical() + Temp->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() + Temp->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() + Temp->getSpeed());
		}
		break;

	case ITEMTYPE::ITEMTYPE_PENDANT:
		Temp = (*(m_Inventory->getvPendantList()->begin() + index));
		if (m_Inventory->getEquipPendant() == nullptr)
		{
			m_player->setAtk(m_player->getAtk() + Temp->getAtk());
			m_player->setDef(m_player->getDef() + Temp->getDef());
			m_player->setHp(m_player->getHp() + Temp->getHp());
			m_player->setMp(m_player->getMp() + Temp->getMp());
			m_player->setCritical(m_player->getCritical() + Temp->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() + Temp->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() + Temp->getSpeed());
		}
		else
		{	// �̹� ������ ������ �ɷ�ġ ����
			m_player->setAtk(m_player->getAtk() - m_Inventory->getEquipPendant()->getAtk());
			m_player->setDef(m_player->getDef() - m_Inventory->getEquipPendant()->getDef());
			m_player->setHp(m_player->getHp() - m_Inventory->getEquipPendant()->getHp());
			m_player->setMp(m_player->getMp() - m_Inventory->getEquipPendant()->getMp());
			m_player->setCritical(m_player->getCritical() - m_Inventory->getEquipPendant()->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() - m_Inventory->getEquipPendant()->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() - m_Inventory->getEquipPendant()->getSpeed());

			m_player->setAtk(m_player->getAtk() + Temp->getAtk());
			m_player->setDef(m_player->getDef() + Temp->getDef());
			m_player->setHp(m_player->getHp() + Temp->getHp());
			m_player->setMp(m_player->getMp() + Temp->getMp());
			m_player->setCritical(m_player->getCritical() + Temp->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() + Temp->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() + Temp->getSpeed());
		}
		break;
	default:
		break;
	}
}

void CinventoryUi::clickEquipButton()
{
	if (PtInRect(&m_equipButton, m_ptMouse))
	{
		if (isButtonClick)
		{
			if (isKeyUp)
			{
				this->setEquipItem(m_SelectIndex, m_selectRenderX, m_selectRenderY);
				isKeyUp = false;
			}
		}
	}
}

// ���â ������ĭ Ŭ���� �۵��Ǵ� �͵�
void CinventoryUi::selectItemTypeMain()
{
	vector<RECT>::iterator iter;
	for ( iter = m_vEquipItemMainRect.begin(); iter != m_vEquipItemMainRect.end(); ++iter)
	{
		if (PtInRect(&(*iter), m_ptMouse))
		{
			// ���� ��Ʈ Ŭ���ϰ��ִ��� üũ
			if (m_clickCheckRect.left != (*iter).left)
				m_clickCount = 0;
			m_clickCheckRect = (*iter);
			if (isButtonClick)
			{
				if (isKeyUp)
				{
					if (m_clickCount == 0)
						m_compareTime = TIME->getWorldTime();
					m_clickCount++;

					// Ŭ���� ���â rect�ε����� ���� Ÿ�Լ��� 1: ���� 0,2: ����
					if ((*iter).left == m_vEquipItemMainRect[1].left)
					{
						m_selectType = ITEMTYPE::ITEMTYPE_ARMOR;
					}
					else
						m_selectType = ITEMTYPE::ITEMTYPE_WEAPON;

					m_Inventory->clearSelectItem();
					isSelectRender = false;

					// ���콺 ����Ŭ�� �Ǵ� ����!
					// ���� ����
					if (m_clickCount > 1)
					{
						if ((*iter).left == m_vEquipItemMainRect[1].left)
						{
							if(m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].m_equipItem != nullptr)
								this->unEquipItem();
							m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].isEquip = false;
							m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].m_equipItem = nullptr;
						}
						else
						{
							if(m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].m_equipItem != nullptr)
								this->unEquipItem();
							m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].isEquip = false;
							m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].m_equipItem = nullptr;
						}
					}
					isKeyUp = false;
				}
			}
		}
	}

	if (m_compareTime + 1 < TIME->getWorldTime())
		m_clickCount = 0;
}

// �ֺ� ���� ���â ĭ Ŭ����
// ������ Ÿ�� �߰� �ʿ�!
//TODO::�Ҳ� - ��
void CinventoryUi::selectItemTypeSub()
{
	vector<RECT>::iterator iter;
	for (iter = m_vEquipItemSubRect.begin(); iter != m_vEquipItemSubRect.end(); ++iter)
	{
		if (PtInRect(&(*iter), m_ptMouse))
		{
			// ���� ��Ʈ Ŭ���ϰ��ִ��� üũ
			if (m_clickCheckRect.left != (*iter).left)
				m_clickCount = 0;
			m_clickCheckRect = (*iter);
			if (isButtonClick)
			{
				if (isKeyUp)
				{
					if (m_clickCount == 0)
						m_compareTime = TIME->getWorldTime();
					m_clickCount++;

					if ((*iter).left == m_vEquipItemSubRect[0].left) m_selectType = ITEMTYPE::ITEMTYPE_PENDANT;
					else if ((*iter).left == m_vEquipItemSubRect[3].left) m_selectType = ITEMTYPE::ITEMTYPE_GLOVES;
					else if ((*iter).left == m_vEquipItemSubRect[4].left) m_selectType = ITEMTYPE::ITEMTYPE_SHOES;

					m_Inventory->clearSelectItem();
					isSelectRender = false;

					// ���콺 ����Ŭ�� �Ǵ� ����!
					// ���� ����
					// 0: �Ҵ�Ʈ, 3: �尩, 4: �Ź�
					if (m_clickCount > 1)
					{
						if ((*iter).left == m_vEquipItemSubRect[0].left) // 0: �Ҵ�Ʈ
						{
							if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].m_equipItem != nullptr)
								this->unEquipItem();
							m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].isEquip = false;
							m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].m_equipItem = nullptr;
						}
						else if ((*iter).left == m_vEquipItemSubRect[3].left) // �尩
						{
							if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].m_equipItem != nullptr)
								this->unEquipItem();
							m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].isEquip = false;
							m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].m_equipItem = nullptr;
						}
						else if ((*iter).left == m_vEquipItemSubRect[4].left) // �Ź�
						{
							if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].m_equipItem != nullptr)
								this->unEquipItem();
							m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].isEquip = false;
							m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].m_equipItem = nullptr;
						}
					}
					isKeyUp = false;
				}
			}
		}
	}
	if (m_compareTime + 1 < TIME->getWorldTime())
		m_clickCount = 0;
}

void CinventoryUi::showItemInfo()
{
	char str[100];

	IMAGE->findImage(m_Inventory->getSelectItem()->m_item->getSmallImage())->frameRender(getMemDC(), m_ItemInfoRect.left + 11, m_ItemInfoRect.top
		, m_Inventory->getSelectItem()->m_item->getFrame().x
		,m_Inventory->getSelectItem()->m_item->getFrame().y);

	SetTextColor(getMemDC(), RGB(255, 255, 255));
	TextOut(getMemDC(), m_ItemInfoRect.left + 80, m_ItemInfoRect.top + 10
		,m_Inventory->getSelectItem()->m_item->getName().c_str()
		,lstrlen(m_Inventory->getSelectItem()->m_item->getName().c_str()));
	wsprintf(str, "�ʿ� ����: %d", m_Inventory->getSelectItem()->m_item->getLimitLevel());
	TextOut(getMemDC(), m_ItemInfoRect.left + 80, m_ItemInfoRect.top + 30, str, lstrlen(str));
	wsprintf(str, "���: %d", m_Inventory->getSelectItem()->m_item->getBuyPrice());
	TextOut(getMemDC(), m_ItemInfoRect.left + 80, m_ItemInfoRect.top + 50, str, lstrlen(str));

	this->showItemCompare();

}

void CinventoryUi::showItemCompare()
{
	char atk[100];
	char def[100];
	char hp[100];
	char mp[100];
	char cri[100];
	char criAtk[100];
	char speed[100];

	int temp_atk, temp_def, temp_hp, temp_mp, temp_cri;
	float temp_criAtk, temp_speed;

	switch (m_Inventory->getSelectItem()->m_item->getType())
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		if (m_Inventory->getEquipWeapon() == nullptr)
		{
			temp_atk = temp_def = temp_hp = temp_mp = temp_cri = 0;
			temp_criAtk = temp_speed = 0;
		}
		else
		{
			temp_atk = m_Inventory->getEquipWeapon()->getAtk();
			temp_def = m_Inventory->getEquipWeapon()->getDef();
			temp_hp = m_Inventory->getEquipWeapon()->getHp();
			temp_mp = m_Inventory->getEquipWeapon()->getMp();
			temp_cri = m_Inventory->getEquipWeapon()->getCritical();
			temp_criAtk = m_Inventory->getEquipWeapon()->getCriticalAtk();
			temp_speed = m_Inventory->getEquipWeapon()->getSpeed();
		}

		if (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk > 0)
			wsprintf(atk, "+%d", (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk));
		else
			wsprintf(atk, "%d", (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk));
		if (m_Inventory->getSelectItem()->m_item->getDef() - temp_def > 0)
			wsprintf(def, "+%d", (m_Inventory->getSelectItem()->m_item->getDef() - temp_def));
		else
			wsprintf(def, "%d", (m_Inventory->getSelectItem()->m_item->getDef() - temp_def));
		if (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp > 0)
			wsprintf(hp, "+%d", (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp));
		else
			wsprintf(hp, "%d", (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp));
		if (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp > 0)
			wsprintf(mp, "+%d", (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp));
		else
			wsprintf(mp, "%d", (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp));
		if (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri > 0)
			wsprintf(cri, "+%d", (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri));
		else
			wsprintf(cri, "%d", (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri));
		if (m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk > 0)
			sprintf(criAtk, "+%.1f", m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk);
		else
			sprintf(criAtk, "%.1f", m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk);
		if (m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed > 0)
			sprintf(speed, "+%.1f", m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed);
		else
			sprintf(speed, "%.1f", m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed);

		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 100, atk, lstrlen(atk));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 120, def, lstrlen(def));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 140, hp, lstrlen(hp));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 160, mp, lstrlen(mp));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 180, cri, lstrlen(cri));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 200, criAtk, lstrlen(criAtk));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 220, speed, lstrlen(speed));

		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		if (m_Inventory->getEquipArmor() == nullptr)
		{
			temp_atk = temp_def = temp_hp = temp_mp = temp_cri = 0;
			temp_criAtk = temp_speed = 0;
		}
		else
		{
			temp_atk = m_Inventory->getEquipArmor()->getAtk();
			temp_def = m_Inventory->getEquipArmor()->getDef();
			temp_hp = m_Inventory->getEquipArmor()->getHp();
			temp_mp = m_Inventory->getEquipArmor()->getMp();
			temp_cri = m_Inventory->getEquipArmor()->getCritical();
			temp_criAtk = m_Inventory->getEquipArmor()->getCriticalAtk();
			temp_speed = m_Inventory->getEquipArmor()->getSpeed();
		}

		if (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk > 0)
			wsprintf(atk, "+%d", (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk));
		else
			wsprintf(atk, "%d", (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk));
		if (m_Inventory->getSelectItem()->m_item->getDef() - temp_def > 0)
			wsprintf(def, "+%d", (m_Inventory->getSelectItem()->m_item->getDef() - temp_def));
		else
			wsprintf(def, "%d", (m_Inventory->getSelectItem()->m_item->getDef() - temp_def));
		if (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp > 0)
			wsprintf(hp, "+%d", (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp));
		else
			wsprintf(hp, "%d", (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp));
		if (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp > 0)
			wsprintf(mp, "+%d", (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp));
		else
			wsprintf(mp, "%d", (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp));
		if (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri > 0)
			wsprintf(cri, "+%d", (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri));
		else
			wsprintf(cri, "%d", (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri));
		if (m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk > 0)
			sprintf(criAtk, "+%.1f", m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk);
		else
			sprintf(criAtk, "%.1f", m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk);
		if (m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed > 0)
			sprintf(speed, "+%.1f", m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed);
		else
			sprintf(speed, "%.1f", m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed);

		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 100, atk, lstrlen(atk));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 120, def, lstrlen(def));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 140, hp, lstrlen(hp));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 160, mp, lstrlen(mp));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 180, cri, lstrlen(cri));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 200, criAtk, lstrlen(criAtk));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 220, speed, lstrlen(speed));
		break;
	
	case ITEMTYPE::ITEMTYPE_SHOES:
		if (m_Inventory->getEquipShoes() == nullptr)
		{
			temp_atk = temp_def = temp_hp = temp_mp = temp_cri = 0;
			temp_criAtk = temp_speed = 0;
		}
		else
		{
			temp_atk = m_Inventory->getEquipShoes()->getAtk();
			temp_def = m_Inventory->getEquipShoes()->getDef();
			temp_hp = m_Inventory->getEquipShoes()->getHp();
			temp_mp = m_Inventory->getEquipShoes()->getMp();
			temp_cri = m_Inventory->getEquipShoes()->getCritical();
			temp_criAtk = m_Inventory->getEquipShoes()->getCriticalAtk();
			temp_speed = m_Inventory->getEquipShoes()->getSpeed();
		}

		if (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk > 0)
			wsprintf(atk, "+%d", (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk));
		else
			wsprintf(atk, "%d", (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk));
		if (m_Inventory->getSelectItem()->m_item->getDef() - temp_def > 0)
			wsprintf(def, "+%d", (m_Inventory->getSelectItem()->m_item->getDef() - temp_def));
		else
			wsprintf(def, "%d", (m_Inventory->getSelectItem()->m_item->getDef() - temp_def));
		if (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp > 0)
			wsprintf(hp, "+%d", (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp));
		else
			wsprintf(hp, "%d", (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp));
		if (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp > 0)
			wsprintf(mp, "+%d", (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp));
		else
			wsprintf(mp, "%d", (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp));
		if (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri > 0)
			wsprintf(cri, "+%d", (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri));
		else
			wsprintf(cri, "%d", (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri));
		if (m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk > 0)
			sprintf(criAtk, "+%.1f", m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk);
		else
			sprintf(criAtk, "%.1f", m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk);
		if (m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed > 0)
			sprintf(speed, "+%.1f", m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed);
		else
			sprintf(speed, "%.1f", m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed);

		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 100, atk, lstrlen(atk));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 120, def, lstrlen(def));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 140, hp, lstrlen(hp));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 160, mp, lstrlen(mp));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 180, cri, lstrlen(cri));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 200, criAtk, lstrlen(criAtk));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 220, speed, lstrlen(speed));
		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		if (m_Inventory->getEquipGloves() == nullptr)
		{
			temp_atk = temp_def = temp_hp = temp_mp = temp_cri = 0;
			temp_criAtk = temp_speed = 0;
		}
		else
		{
			temp_atk = m_Inventory->getEquipGloves()->getAtk();
			temp_def = m_Inventory->getEquipGloves()->getDef();
			temp_hp = m_Inventory->getEquipGloves()->getHp();
			temp_mp = m_Inventory->getEquipGloves()->getMp();
			temp_cri = m_Inventory->getEquipGloves()->getCritical();
			temp_criAtk = m_Inventory->getEquipGloves()->getCriticalAtk();
			temp_speed = m_Inventory->getEquipGloves()->getSpeed();
		}

		if (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk > 0)
			wsprintf(atk, "+%d", (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk));
		else
			wsprintf(atk, "%d", (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk));
		if (m_Inventory->getSelectItem()->m_item->getDef() - temp_def > 0)
			wsprintf(def, "+%d", (m_Inventory->getSelectItem()->m_item->getDef() - temp_def));
		else
			wsprintf(def, "%d", (m_Inventory->getSelectItem()->m_item->getDef() - temp_def));
		if (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp > 0)
			wsprintf(hp, "+%d", (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp));
		else
			wsprintf(hp, "%d", (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp));
		if (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp > 0)
			wsprintf(mp, "+%d", (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp));
		else
			wsprintf(mp, "%d", (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp));
		if (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri > 0)
			wsprintf(cri, "+%d", (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri));
		else
			wsprintf(cri, "%d", (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri));
		if (m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk > 0)
			sprintf(criAtk, "+%.1f", m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk);
		else
			sprintf(criAtk, "%.1f", m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk);
		if (m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed > 0)
			sprintf(speed, "+%.1f", m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed);
		else
			sprintf(speed, "%.1f", m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed);

		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 100, atk, lstrlen(atk));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 120, def, lstrlen(def));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 140, hp, lstrlen(hp));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 160, mp, lstrlen(mp));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 180, cri, lstrlen(cri));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 200, criAtk, lstrlen(criAtk));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 220, speed, lstrlen(speed));
		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		if (m_Inventory->getEquipPendant() == nullptr)
		{
			temp_atk = temp_def = temp_hp = temp_mp = temp_cri = 0;
			temp_criAtk = temp_speed = 0;
		}
		else
		{
			temp_atk = m_Inventory->getEquipPendant()->getAtk();
			temp_def = m_Inventory->getEquipPendant()->getDef();
			temp_hp = m_Inventory->getEquipPendant()->getHp();
			temp_mp = m_Inventory->getEquipPendant()->getMp();
			temp_cri = m_Inventory->getEquipPendant()->getCritical();
			temp_criAtk = m_Inventory->getEquipPendant()->getCriticalAtk();
			temp_speed = m_Inventory->getEquipPendant()->getSpeed();
		}

		if (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk > 0)
			wsprintf(atk, "+%d", (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk));
		else
			wsprintf(atk, "%d", (m_Inventory->getSelectItem()->m_item->getAtk() - temp_atk));
		if (m_Inventory->getSelectItem()->m_item->getDef() - temp_def > 0)
			wsprintf(def, "+%d", (m_Inventory->getSelectItem()->m_item->getDef() - temp_def));
		else
			wsprintf(def, "%d", (m_Inventory->getSelectItem()->m_item->getDef() - temp_def));
		if (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp > 0)
			wsprintf(hp, "+%d", (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp));
		else
			wsprintf(hp, "%d", (m_Inventory->getSelectItem()->m_item->getHp() - temp_hp));
		if (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp > 0)
			wsprintf(mp, "+%d", (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp));
		else
			wsprintf(mp, "%d", (m_Inventory->getSelectItem()->m_item->getMp() - temp_mp));
		if (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri > 0)
			wsprintf(cri, "+%d", (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri));
		else
			wsprintf(cri, "%d", (m_Inventory->getSelectItem()->m_item->getCritical() - temp_cri));
		if (m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk > 0)
			sprintf(criAtk, "+%.1f", m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk);
		else
			sprintf(criAtk, "%.1f", m_Inventory->getSelectItem()->m_item->getCriticalAtk() - temp_criAtk);
		if (m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed > 0)
			sprintf(speed, "+%.1f", m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed);
		else
			sprintf(speed, "%.1f", m_Inventory->getSelectItem()->m_item->getSpeed() - temp_speed);

		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 100, atk, lstrlen(atk));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 120, def, lstrlen(def));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 140, hp, lstrlen(hp));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 160, mp, lstrlen(mp));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 180, cri, lstrlen(cri));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 200, criAtk, lstrlen(criAtk));
		TextOut(getMemDC(), m_ItemInfoRect.left + 140, m_ItemInfoRect.top + 220, speed, lstrlen(speed));
		break;

	default:
		break;
	}
}

void CinventoryUi::abandonItem()
{
	if (PtInRect(&m_abandonButton, m_ptMouse))
	{

		if (isButtonClick)
		{
			if (isKeyUp)
			{
				// ���� �������� �������� ����
				// ���������� ���� �����۸� ����
				if (m_Inventory->getSelectItem()->m_item != nullptr && this->checkEquipItem())
				{
					if (m_equipItem[static_cast<int>(m_selectType)].m_itemIndex > m_SelectIndex)
						m_equipItem[static_cast<int>(m_selectType)].m_itemIndex--;

					m_Inventory->AbandonItem(m_selectItem);
					m_Inventory->clearSelectItem();
					isSelectRender = false;
				}
				isKeyUp = false;
			}
		}
	}
}

// Id�� ���ϵ��� ����
// ������ Ÿ�� �߰� �ʿ�
//TODO::�Ҳ� - ��
bool CinventoryUi::checkEquipItem()
{
	if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].m_equipItem != nullptr)
	{
		if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].m_equipItem->getItemId() == m_selectItem->getItemId())
			return false;
	}
	if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].m_equipItem != nullptr )
	{
		if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].m_equipItem->getItemId() == m_selectItem->getItemId())
			return false;
	}
	if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].m_equipItem != nullptr)
	{
		if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_GLOVES)].m_equipItem->getItemId() == m_selectItem->getItemId())
			return false;
	}
	if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].m_equipItem != nullptr)
	{
		if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_SHOES)].m_equipItem->getItemId() == m_selectItem->getItemId())
			return false;
	}
	if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].m_equipItem != nullptr)
	{
		if (m_equipItem[static_cast<int>(ITEMTYPE::ITEMTYPE_PENDANT)].m_equipItem->getItemId() == m_selectItem->getItemId())
			return false;
	}
	return true;
}

void CinventoryUi::unEquipItem()
{

	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		m_player->setAtk(m_player->getAtk() - m_Inventory->getEquipWeapon()->getAtk());
		m_player->setDef(m_player->getDef() - m_Inventory->getEquipWeapon()->getDef());
		m_player->setHp(m_player->getHp() - m_Inventory->getEquipWeapon()->getHp());
		m_player->setMp(m_player->getMp() - m_Inventory->getEquipWeapon()->getMp());
		m_player->setCritical(m_player->getCritical() - m_Inventory->getEquipWeapon()->getCritical());
		m_player->setCriticalAtk(m_player->getCriticalAtk() - m_Inventory->getEquipWeapon()->getCriticalAtk());
		m_player->setSpeed(m_player->getSpeed() - m_Inventory->getEquipWeapon()->getSpeed());

		m_Inventory->setEquipWeapon(nullptr);
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		m_player->setAtk(m_player->getAtk() - m_Inventory->getEquipArmor()->getAtk());
		m_player->setDef(m_player->getDef() - m_Inventory->getEquipArmor()->getDef());
		m_player->setHp(m_player->getHp() - m_Inventory->getEquipArmor()->getHp());
		m_player->setMp(m_player->getMp() - m_Inventory->getEquipArmor()->getMp());
		m_player->setCritical(m_player->getCritical() - m_Inventory->getEquipArmor()->getCritical());
		m_player->setCriticalAtk(m_player->getCriticalAtk() - m_Inventory->getEquipArmor()->getCriticalAtk());
		m_player->setSpeed(m_player->getSpeed() - m_Inventory->getEquipArmor()->getSpeed());

		m_Inventory->setEquipArmor(nullptr);
		break;
	case ITEMTYPE::ITEMTYPE_SHOES:
		m_player->setAtk(m_player->getAtk() - m_Inventory->getEquipShoes()->getAtk());
		m_player->setDef(m_player->getDef() - m_Inventory->getEquipShoes()->getDef());
		m_player->setHp(m_player->getHp() - m_Inventory->getEquipShoes()->getHp());
		m_player->setMp(m_player->getMp() - m_Inventory->getEquipShoes()->getMp());
		m_player->setCritical(m_player->getCritical() - m_Inventory->getEquipShoes()->getCritical());
		m_player->setCriticalAtk(m_player->getCriticalAtk() - m_Inventory->getEquipShoes()->getCriticalAtk());
		m_player->setSpeed(m_player->getSpeed() - m_Inventory->getEquipShoes()->getSpeed());

		m_Inventory->setEquipShoes(nullptr);

		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		m_player->setAtk(m_player->getAtk() - m_Inventory->getEquipGloves()->getAtk());
		m_player->setDef(m_player->getDef() - m_Inventory->getEquipGloves()->getDef());
		m_player->setHp(m_player->getHp() - m_Inventory->getEquipGloves()->getHp());
		m_player->setMp(m_player->getMp() - m_Inventory->getEquipGloves()->getMp());
		m_player->setCritical(m_player->getCritical() - m_Inventory->getEquipGloves()->getCritical());
		m_player->setCriticalAtk(m_player->getCriticalAtk() - m_Inventory->getEquipGloves()->getCriticalAtk());
		m_player->setSpeed(m_player->getSpeed() - m_Inventory->getEquipGloves()->getSpeed());

		m_Inventory->setEquipGloves(nullptr);

		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		m_player->setAtk(m_player->getAtk() - m_Inventory->getEquipPendant()->getAtk());
		m_player->setDef(m_player->getDef() - m_Inventory->getEquipPendant()->getDef());
		m_player->setHp(m_player->getHp() - m_Inventory->getEquipPendant()->getHp());
		m_player->setMp(m_player->getMp() - m_Inventory->getEquipPendant()->getMp());
		m_player->setCritical(m_player->getCritical() - m_Inventory->getEquipPendant()->getCritical());
		m_player->setCriticalAtk(m_player->getCriticalAtk() - m_Inventory->getEquipPendant()->getCriticalAtk());
		m_player->setSpeed(m_player->getSpeed() - m_Inventory->getEquipPendant()->getSpeed());

		m_Inventory->setEquipPendant(nullptr);

		break;
	default:
		break;
	}
}
