#include"framework.h"
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

	m_equipButton = RectMake(m_functionButtonX, m_functionButtonY, 70, 20);
	m_unEquipButton = RectMake(m_functionButtonX + 90, m_functionButtonY, 70, 20);
	m_abandonButton = RectMake(m_functionButtonX, m_functionButtonY + 24, 70, 20);
	m_exitButton = RectMake(m_functionButtonX + 90, m_functionButtonY + 24, 70, 20);

	isKeyUp = false;
	isButtonClick = false;

	m_showIndex = 0;
	m_showEndIndex = 0;
	m_selectType = ITEMTYPE::ITEMTYPE_ARMOR;
	isSelectRender = false;
	m_clickCount = 0;

	isEquipWeapon = false;
	return S_OK;
}

void CinventoryUi::release()
{
}

void CinventoryUi::update()
{
	this->selectItem();
	this->selectEquipItem();
	this->selectItemType();
	this->abandonItem();
	// ��� set�� �����Ұ����� Ư�� Ÿ�ֿ̹� set�Ұ����� �ϴ� ���
	this->setShowIndex();

	if (InputManager->isStayKeyDown(VK_LBUTTON))
	{
		isButtonClick = true;
	}
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
	Rectangle(getMemDC(), m_ItemInfoRect.left, m_ItemInfoRect.top, m_ItemInfoRect.right, m_ItemInfoRect.bottom);

	Rectangle(getMemDC(), m_equipButton.left, m_equipButton.top, m_equipButton.right, m_equipButton.bottom);
	Rectangle(getMemDC(), m_unEquipButton.left, m_unEquipButton.top, m_unEquipButton.right, m_unEquipButton.bottom);
	Rectangle(getMemDC(), m_abandonButton.left, m_abandonButton.top, m_abandonButton.right, m_abandonButton.bottom);
	Rectangle(getMemDC(), m_exitButton.left, m_exitButton.top, m_exitButton.right, m_exitButton.bottom);
	
	// ���õ� Ÿ�Ժ� ������ ���
	this->showListItemType();
	// ���� �׵θ�
	this->showEquipSelect();
	if(isSelectRender)
		IMAGE->findImage("�����׵θ�")->render(getMemDC(), m_selectRenderX, m_selectRenderY);
	// ���â ����
	if (isEquipWeapon)
	{
		IMAGE->findImage((*m_equipWeapon).getBigImage())->frameRender(getMemDC(), m_vEquipItemMainRect[0].left - 10, m_vEquipItemMainRect[0].top + 10, (*m_equipWeapon).getFrame().x, (*m_equipWeapon).getFrame().y);
		IMAGE->findImage((*m_equipWeapon).getBigImage())->frameRender(getMemDC(), m_vEquipItemMainRect[2].left - 10, m_vEquipItemMainRect[2].top + 10, (*m_equipWeapon).getFrame().x, (*m_equipWeapon).getFrame().y);
	}
	if (isEquipArmor)
	{
		IMAGE->findImage((*m_equipArmor).getBigImage())->frameRender(getMemDC(), m_vEquipItemMainRect[1].left - 10, m_vEquipItemMainRect[1].top + 10 ,(*m_equipArmor).getFrame().x, (*m_equipArmor).getFrame().y);
	}
}

// ���� ����ó�� �ϼ� �ȵ�.. ��ũ�� ������ �������� ����ó�� �ʿ�
// ��ũ�� ����� ������, �κ��丮 ����Ʈ�� ������ 4�� �ε��� ����
void CinventoryUi::setShowIndex()
{
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		if (m_myInventory->getvWeaponList()->size() < 4)
			m_showEndIndex = m_myInventory->getvWeaponList()->size() + m_showIndex;
		else
			m_showEndIndex = m_showIndex + 4;
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		if (m_myInventory->getvArmorList()->size() < 4)
			m_showEndIndex = m_myInventory->getvArmorList()->size() + m_showIndex;
		else
			m_showEndIndex = m_showIndex + 4;
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
		showItemList(m_myInventory->getvWeaponList());
		
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		showItemList(m_myInventory->getvArmorList());
		break;
	default:
		break;
	}
}
// �ε��� �������� ���͸� �����Ͽ�
void CinventoryUi::showItemList(vector<Citem>* list)
{

	char str[100];
	// show �ε����� �⺻ 0~3������ �����ش�, ���� ��ũ�ѷ� 1~4 �̷������� �����ֱ�
	int	i = m_showIndex;
	int j = 0;
		for (auto iter = list->begin() + i; iter != list->end() && i < m_showEndIndex; ++iter, i++, j++)
		{
			IMAGE->findImage((*iter).getSmallImage())->frameRender(getMemDC()
				,m_vItemListRect[j].left, m_vItemListRect[j].top, (*iter).getFrame().x, (*iter).getFrame().y);

			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), m_vItemListRect[j].left + 80, m_vItemListRect[j].top + 10, (*iter).getName().c_str(), lstrlen((*iter).getName().c_str()));
			wsprintf(str, "�ʿ� ����: %d", (*iter).getLimitLevel());
			TextOut(getMemDC(), m_vItemListRect[j].left + 80, m_vItemListRect[j].top + 30, str, lstrlen(str));
			wsprintf(str, "���: %d", (*iter).getBuyPrice());
			TextOut(getMemDC(), m_vItemListRect[j].left + 80, m_vItemListRect[j].top + 50, str, lstrlen(str));
		}
}

void CinventoryUi::showEquipSelect()
{
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		if (isEquipWeapon)
			IMAGE->findImage("�����׵θ�")->render(getMemDC(), m_equipRenderPoint[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].x,
				m_equipRenderPoint[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)].y);
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		if (isEquipArmor)
			IMAGE->findImage("�����׵θ�")->render(getMemDC(), m_equipRenderPoint[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].x,
				m_equipRenderPoint[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)].y);
		break;
	}

}

// ���콺 1Ŭ������ ������ ����ǥ��
void CinventoryUi::selectItem()
{
	vector<Citem>::iterator weaponIter;
	vector<Citem>::iterator armorIter;

	int i = m_showIndex;
	for (auto iter = m_vItemListRect.begin(); iter != m_vItemListRect.end() && i < m_showEndIndex; ++iter, i++)
	{
		if (PtInRect(&(*iter), m_ptMouse))
		{
			if (InputManager->isOnceKeyDown(VK_LBUTTON))
			{
				isSelectRender = true;
				m_selectRenderX = (*iter).left - 5;
				m_selectRenderY = (*iter).top - 3;
				
				// ������ ������ ���� inventory ���� �����ͼ� selectItem ������ ���
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
// ���콺 2Ŭ������ ������ ����ǥ�� / ����
// �ϴ� ������Ʈ Ŭ������ ����ó���� ���� -> ���Ŀ� �߰��ʿ�
void CinventoryUi::selectEquipItem()
{
	int i = m_showIndex;
	for (auto iter = m_vItemListRect.begin(); iter != m_vItemListRect.end() && i < m_showEndIndex; ++iter, i++)
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
							m_equipRenderX = (*iter).left - 5;
							m_equipRenderY = (*iter).top - 3;
							this->setEquipItem(i, m_equipRenderX, m_equipRenderY);
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
// ������ ������ �ʿ��� ������ ������ ������ ���� �־��ֱ�
void CinventoryUi::setEquipItem(int index, int x, int y)
{
	Citem* weaponTemp;
	Citem* armorTemp;
	
	this->setPlayerStat(index);

	// ���� �����ۺ����� ���
	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		// ���ͷ����� �����ؼ� ���� ���Ҵ� �ش� ���� ������ ������ ���� ���־ �ٽ� ��ȯ����
		m_myInventory->setEquipWeapon(&(*(m_myInventory->getvWeaponList()->begin() + index)));
		weaponTemp = m_myInventory->getEquipWeapon();
		// ������ �𸣰����� ���� �κ��丮 ����Ʈ ���� �����ϸ� ���߿� �κ��丮���� �ٸ��� �������� �������
		// �ӽ� ������ �迭�� �����ؼ� �װ� UI ���������� ����
		m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)] = (*weaponTemp);
		m_equipWeapon = &m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)];

		m_equipRenderPoint[static_cast<int>(ITEMTYPE::ITEMTYPE_WEAPON)] = PointMake(x, y);
		isEquipWeapon = true;
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		m_myInventory->setEquipArmor(&(*(m_myInventory->getvArmorList()->begin() + index)));
		armorTemp = m_myInventory->getEquipArmor();
		m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)] = (*armorTemp);
		m_equipArmor = &m_itemInit[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)];

		m_equipRenderPoint[static_cast<int>(ITEMTYPE::ITEMTYPE_ARMOR)] = PointMake(x, y);
		isEquipArmor = true;
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
		Temp = &(*(m_myInventory->getvWeaponList()->begin() + index));
		if (m_myInventory->getEquipWeapon() == nullptr)
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
			m_player->setAtk(m_player->getAtk() - m_myInventory->getEquipWeapon()->getAtk());
			m_player->setDef(m_player->getDef() - m_myInventory->getEquipWeapon()->getDef());
			m_player->setHp(m_player->getHp() - m_myInventory->getEquipWeapon()->getHp());
			m_player->setMp(m_player->getMp() - m_myInventory->getEquipWeapon()->getMp());
			m_player->setCritical(m_player->getCritical() - m_myInventory->getEquipWeapon()->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() - m_myInventory->getEquipWeapon()->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() - m_myInventory->getEquipWeapon()->getSpeed());

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
		Temp = &(*(m_myInventory->getvArmorList()->begin() + index));
		if (m_myInventory->getEquipArmor() == nullptr)
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
			m_player->setAtk(m_player->getAtk() - m_myInventory->getEquipArmor()->getAtk());
			m_player->setDef(m_player->getDef() - m_myInventory->getEquipArmor()->getDef());
			m_player->setHp(m_player->getHp() - m_myInventory->getEquipArmor()->getHp());
			m_player->setMp(m_player->getMp() - m_myInventory->getEquipArmor()->getMp());
			m_player->setCritical(m_player->getCritical() - m_myInventory->getEquipArmor()->getCritical());
			m_player->setCriticalAtk(m_player->getCriticalAtk() - m_myInventory->getEquipArmor()->getCriticalAtk());
			m_player->setSpeed(m_player->getSpeed() - m_myInventory->getEquipArmor()->getSpeed());

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
		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		break;
	default:
		break;
	}
}

// ���â ������ĭ Ŭ���� �۵��Ǵ� �͵�
void CinventoryUi::selectItemType()
{
	for (auto iter = m_vEquipItemMainRect.begin(); iter != m_vEquipItemMainRect.end(); ++iter)
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

					// �߸ŷ� ��.. ��� ���â���� Ȯ�� else �� �翷 ���â
					if ((*iter).left == m_vEquipItemMainRect[1].left)
					{
						m_selectType = ITEMTYPE::ITEMTYPE_ARMOR;
					}
					else
						m_selectType = ITEMTYPE::ITEMTYPE_WEAPON;

					// ���콺 ����Ŭ�� �Ǵ� ����!
					// ���� ����
					// ���� ������ ���� �׵θ��� Ÿ�Ժ��� ����� �����.. �ϴ� ����
					if (m_clickCount > 1)
					{
						if ((*iter).left == m_vEquipItemMainRect[1].left)
						{
							if(m_equipArmor != nullptr)
								this->unEquipItem();
							isEquipArmor = false;
							m_equipArmor = nullptr;
						}
						else
						{
							if(m_equipWeapon != nullptr)
								this->unEquipItem();
							isEquipWeapon = false;
							m_equipWeapon = nullptr;
						}
					}
				}
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

		if (isButtonClick)
		{
			if (isKeyUp)
			{
				// ���� �������� �������� ����
				// ���������� ���� �����۸� ����
				if (m_selectItem != nullptr && this->checkEquipItem())
				{
					m_myInventory->AbandonItem(m_selectItem);
					m_selectItem = nullptr;
					isSelectRender = false;
				}
				isKeyUp = false;
			}
		}
	}
}

// Id�� ���ϵ��� ����
bool CinventoryUi::checkEquipItem()
{
	if (m_equipWeapon != nullptr)
	{
		if (m_equipWeapon->getItemId() == m_selectItem->getItemId())
			return false;
	}
	if (m_equipArmor != nullptr)
	{
		if (m_equipArmor->getItemId() == m_selectItem->getItemId())
			return false;
	}
	return true;
}

void CinventoryUi::unEquipItem()
{

	switch (m_selectType)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		m_player->setAtk(m_player->getAtk() - m_myInventory->getEquipWeapon()->getAtk());
		m_player->setDef(m_player->getDef() - m_myInventory->getEquipWeapon()->getDef());
		m_player->setHp(m_player->getHp() - m_myInventory->getEquipWeapon()->getHp());
		m_player->setMp(m_player->getMp() - m_myInventory->getEquipWeapon()->getMp());
		m_player->setCritical(m_player->getCritical() - m_myInventory->getEquipWeapon()->getCritical());
		m_player->setCriticalAtk(m_player->getCriticalAtk() - m_myInventory->getEquipWeapon()->getCriticalAtk());
		m_player->setSpeed(m_player->getSpeed() - m_myInventory->getEquipWeapon()->getSpeed());

		m_myInventory->setEquipWeapon(nullptr);
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		m_player->setAtk(m_player->getAtk() - m_myInventory->getEquipArmor()->getAtk());
		m_player->setDef(m_player->getDef() - m_myInventory->getEquipArmor()->getDef());
		m_player->setHp(m_player->getHp() - m_myInventory->getEquipArmor()->getHp());
		m_player->setMp(m_player->getMp() - m_myInventory->getEquipArmor()->getMp());
		m_player->setCritical(m_player->getCritical() - m_myInventory->getEquipArmor()->getCritical());
		m_player->setCriticalAtk(m_player->getCriticalAtk() - m_myInventory->getEquipArmor()->getCriticalAtk());
		m_player->setSpeed(m_player->getSpeed() - m_myInventory->getEquipArmor()->getSpeed());

		m_myInventory->setEquipArmor(nullptr);
		break;
	case ITEMTYPE::ITEMTYPE_SHOES:
		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		break;
	default:
		break;
	}
}
