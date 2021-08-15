#include "framework.h"
#include "Cinventory.h"

Cinventory::Cinventory()
{
}

Cinventory::~Cinventory()
{
}

HRESULT Cinventory::init()
{
	// 일단 push할때 타입 예외처리 안함.. 그냥 실험용

	Citem tempWeapon1 = *(ITEM->getItem(0));
	Citem tempWeapon2 = *(ITEM->getItem(1));
	Citem tempWeapon3 = *(ITEM->getItem(2));
	Citem tempWeapon4 = *(ITEM->getItem(3));
	Citem tempWeapon5 = *(ITEM->getItem(4));
	m_vWeaponList.push_back(tempWeapon1);
	m_vWeaponList.push_back(tempWeapon2);
	m_vWeaponList.push_back(tempWeapon3);
	m_vWeaponList.push_back(tempWeapon4);
	m_vWeaponList.push_back(tempWeapon5);

	Citem tempArmor1 = *(ITEM->getItem(7));
	Citem tempArmor2= *(ITEM->getItem(8));
	Citem tempArmor3= *(ITEM->getItem(9));
	Citem tempArmor4= *(ITEM->getItem(10));
	Citem tempArmor5 = *(ITEM->getItem(11));

	m_vArmorList.push_back(tempArmor1);
	m_vArmorList.push_back(tempArmor2);
	m_vArmorList.push_back(tempArmor3);
	m_vArmorList.push_back(tempArmor4);
	m_vArmorList.push_back(tempArmor5);

	Citem tempShoes1 = *(ITEM->getItem(14));
	Citem tempShoes2 = *(ITEM->getItem(15));
	Citem tempShoes3 = *(ITEM->getItem(16));
	Citem tempShoes4 = *(ITEM->getItem(17));
	Citem tempShoes5 = *(ITEM->getItem(18));

	m_vShoesList.push_back(tempShoes1);
	m_vShoesList.push_back(tempShoes2);
	m_vShoesList.push_back(tempShoes3);
	m_vShoesList.push_back(tempShoes4);
	m_vShoesList.push_back(tempShoes5);

	Citem tempGloves1 = *(ITEM->getItem(21));
	Citem tempGloves2 = *(ITEM->getItem(22));
	Citem tempGloves3 = *(ITEM->getItem(23));
	Citem tempGloves4 = *(ITEM->getItem(24));
	Citem tempGloves5 = *(ITEM->getItem(25));

	m_vGlovesList.push_back(tempGloves1);
	m_vGlovesList.push_back(tempGloves2);
	m_vGlovesList.push_back(tempGloves3);
	m_vGlovesList.push_back(tempGloves4);
	m_vGlovesList.push_back(tempGloves5);

	Citem tempPendant1 = *(ITEM->getItem(28));
	Citem tempPendant2 = *(ITEM->getItem(29));
	Citem tempPendant3 = *(ITEM->getItem(30));
	Citem tempPendant4 = *(ITEM->getItem(31));
	Citem tempPendant5 = *(ITEM->getItem(32));

	m_vPendantList.push_back(tempPendant1);
	m_vPendantList.push_back(tempPendant2);
	m_vPendantList.push_back(tempPendant3);
	m_vPendantList.push_back(tempPendant4);
	m_vPendantList.push_back(tempPendant5);

	m_vEquipList.push_back(m_equipWeapon);
	m_vEquipList.push_back(m_equipArmor);
	m_vEquipList.push_back(m_equipShoes);
	m_vEquipList.push_back(m_equipGloves);
	m_vEquipList.push_back(m_equipPendant);

	for (int i = 0; i < 5; i++)
	{
		ZeroMemory(&m_equipItem[i], sizeof(EquipItem));
		ZeroMemory(&m_selectItem, sizeof(SelectItem));
	}

	//this->setItemId();
	return S_OK;
}

void Cinventory::release()
{
}

void Cinventory::update()
{
}

void Cinventory::addItem(Citem* item)
{
	switch (item->getType())
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		m_vWeaponList.push_back(*item);
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		m_vArmorList.push_back(*item);
		break;
	case ITEMTYPE::ITEMTYPE_SHOES:
		m_vShoesList.push_back(*item);
		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		m_vGlovesList.push_back(*item);
		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		m_vPendantList.push_back(*item);
		break;
	default:
		break;
	}
}

// 랜더 포인트는 다른곳에서
void Cinventory::equipItem()
{
	if (m_selectItem.m_item != nullptr)
	{
		m_tempItem[static_cast<int>(m_selectItem.m_item->getType())] = *m_selectItem.m_item;
		ITEMTYPE type = m_selectItem.m_item->getType();
		m_equipItem[static_cast<int>(type)].isEquip = true;
		m_equipItem[static_cast<int>(type)].m_item = &m_tempItem[static_cast<int>(m_selectItem.m_item->getType())];
		m_equipItem[static_cast<int>(type)].m_itemIndex = m_selectItem.m_itemIndex;
	}
}

void Cinventory::setEquipRender(ITEMTYPE type, POINT renderPoint)
{
	m_equipItem[static_cast<int>(type)].m_renderPoint = renderPoint;
}


void Cinventory::UnEquipItem(Citem* item)
{
}

// 삭제할 아이템 타입을 비교하여 해당 리스트에서 아이템 제거

//bool Cinventory::checkEquipItem(ITEMTYPE type)
//{
//	//if (m_selectItem == nullptr)
//	//	return false;
//	//if (m_equipItem[static_cast<int>(type)].m_item->getItemId() == m_selectItem->m_item->getItemId())
//	//	return false;
//	//else
//	//	return true;
//}

// 제거할때 고유 아이디로 제거해야할 필요가 있음.. 지금은 일단 동일 이름기준 제거
void Cinventory::AbandonItem()
{
	if (m_selectItem.isSelect == false)
		return;

	ITEMTYPE type = m_selectItem.m_item->getType();
	if (m_equipItem[static_cast<int>(type)].isEquip)
	{
		if (m_equipItem[static_cast<int>(type)].m_item->getItemId() == m_selectItem.m_item->getItemId())
			return;
	}

	if (m_equipItem[static_cast<int>(type)].isEquip)
	{
		if (m_equipItem[static_cast<int>(type)].m_itemIndex > m_selectItem.m_itemIndex)
			m_equipItem[static_cast<int>(type)].m_itemIndex--;
	}

	switch (type)
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		for (auto iter = m_vWeaponList.begin(); iter != m_vWeaponList.end(); ++iter)
		{
			if ((*iter).getItemId() == m_selectItem.m_item->getItemId())
			{
				m_vWeaponList.erase(iter);
				break;
			}
		}
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		for (auto iter = m_vArmorList.begin(); iter != m_vArmorList.end(); ++iter)
		{
			if ((*iter).getName() == m_selectItem.m_item->getName())
			{
				m_vArmorList.erase(iter);
				break;
			}
		}
		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		for (auto iter = m_vGlovesList.begin(); iter != m_vGlovesList.end(); ++iter)
		{
			if ((*iter).getName() == m_selectItem.m_item->getName())
			{
				m_vGlovesList.erase(iter);
				break;
			}
		}
		break;
	case ITEMTYPE::ITEMTYPE_SHOES:
		for (auto iter = m_vShoesList.begin(); iter != m_vShoesList.end(); ++iter)
		{
			if ((*iter).getName() == m_selectItem.m_item->getName())
			{
				m_vShoesList.erase(iter);
				break;
			}
		}
		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		for (auto iter = m_vPendantList.begin(); iter != m_vPendantList.end(); ++iter)
		{
			if ((*iter).getName() == m_selectItem.m_item->getName())
			{
				m_vPendantList.erase(iter);
				break;
			}
		}
		break;
	}
}


EquipItem* Cinventory::getEquipItem(ITEMTYPE type)
{
	return &m_equipItem[static_cast<int>(type)];
}


void Cinventory::setSelectItem(Citem* item, int index, POINT point, bool isSelect)
{
	m_selectItem.m_item = item;
	m_selectItem.m_itemIndex = index;
	m_selectItem.m_renderPoint = point;
	m_selectItem.isSelect = isSelect;
}

void Cinventory::clearSelectItem()
{
	ZeroMemory(&m_selectItem, sizeof(SelectItem));
}

void Cinventory::clearEquipItem(ITEMTYPE type)
{
	ZeroMemory(&m_equipItem[static_cast<int>(type)], sizeof(EquipItem));
}

//// 사실 인벤토리에서 아이템 생성은 임시.. 상점에서 해야할일 일단 무기만 적용
//// 뭔가 이상
//void Cinventory::setItemId()
//{
//	int i = 0;
//	for (auto iter = m_vWeaponList.begin(); iter != m_vWeaponList.end(); ++iter)
//	{
//		(*iter).setItemId(i);
//		i++;
//	}
//}
