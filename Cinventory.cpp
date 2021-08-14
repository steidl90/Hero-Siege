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

	Citem tempWeapon = *(ITEM->getItem(0));
	Citem tempWeapon2 = *(ITEM->getItem(1));
	Citem tempWeapon3 = *(ITEM->getItem(2));
	Citem tempWeapon4 = *(ITEM->getItem(3));
	Citem tempWeapon5 = *(ITEM->getItem(4));
	m_vWeaponList.push_back(&tempWeapon);
	m_vWeaponList.push_back(&tempWeapon2);
	m_vWeaponList.push_back(&tempWeapon3);
	m_vWeaponList.push_back(&tempWeapon4);
	m_vWeaponList.push_back(&tempWeapon5);

	Citem tempWeapon = *(ITEM->getItem(7));
	Citem tempWeapon2 = *(ITEM->getItem(8));
	Citem tempWeapon3 = *(ITEM->getItem(9));
	Citem tempWeapon4 = *(ITEM->getItem(10));
	Citem tempWeapon5 = *(ITEM->getItem(11));

	m_vArmorList.push_back(&tempWeapon);
	m_vArmorList.push_back(&tempWeapon2);
	m_vArmorList.push_back(&tempWeapon3);
	m_vArmorList.push_back(&tempWeapon4);
	m_vArmorList.push_back(&tempWeapon5);

	m_vEquipList.push_back(m_equipWeapon);
	m_vEquipList.push_back(m_equipArmor);
	m_vEquipList.push_back(m_equipShoes);
	m_vEquipList.push_back(m_equipGloves);
	m_vEquipList.push_back(m_equipPendant);

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
		m_vWeaponList.push_back(item);
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		m_vArmorList.push_back(item);
		break;
	case ITEMTYPE::ITEMTYPE_SHOES:
		m_vShoesList.push_back(item);
		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		m_vGlovesList.push_back(item);
		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		m_vPendantList.push_back(item);
		break;
	default:
		break;
	}
}


void Cinventory::UnEquipItem(Citem* item)
{
}

// 삭제할 아이템 타입을 비교하여 해당 리스트에서 아이템 제거

// 제거할때 고유 아이디로 제거해야할 필요가 있음.. 지금은 일단 동일 이름기준 제거
void Cinventory::AbandonItem(Citem* item)
{
	switch (item->getType())
	{
	case ITEMTYPE::ITEMTYPE_WEAPON:
		for (auto iter = m_vWeaponList.begin(); iter != m_vWeaponList.end(); ++iter)
		{
			if ((**iter).getItemId() == item->getItemId())
			{
				m_vWeaponList.erase(iter);
				break;
			}
		}
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		for (auto iter = m_vArmorList.begin(); iter != m_vArmorList.end(); ++iter)
		{
			if ((**iter).getName() == item->getName())
			{
				m_vArmorList.erase(iter);
				break;
			}
		}
		break;
	case ITEMTYPE::ITEMTYPE_GLOVES:
		for (auto iter = m_vGlovesList.begin(); iter != m_vGlovesList.end(); ++iter)
		{
			if ((**iter).getName() == item->getName())
			{
				m_vGlovesList.erase(iter);
				break;
			}
		}
		break;
	case ITEMTYPE::ITEMTYPE_SHOES:
		for (auto iter = m_vShoesList.begin(); iter != m_vShoesList.end(); ++iter)
		{
			if ((**iter).getName() == item->getName())
			{
				m_vShoesList.erase(iter);
				break;
			}
		}
		break;
	case ITEMTYPE::ITEMTYPE_PENDANT:
		for (auto iter = m_vPendantList.begin(); iter != m_vPendantList.end(); ++iter)
		{
			if ((**iter).getName() == item->getName())
			{
				m_vPendantList.erase(iter);
				break;
			}
		}
		break;
	default:
		break;
	}
}

EquipItem* Cinventory::getEquipItem(ITEMTYPE type)
{
	return &m_equipItem[static_cast<int>(type)];
}

void Cinventory::setEquipItem(ITEMTYPE type, Citem* item, int index, POINT point, bool isEquip)
{
	m_equipItem[static_cast<int>(type)].m_equipItem = item;
	m_equipItem[static_cast<int>(type)].m_itemIndex = index;
	m_equipItem[static_cast<int>(type)].m_renderPoint = point;
	m_equipItem[static_cast<int>(type)].isEquip = isEquip;
}

void Cinventory::setSelectItem(Citem* item, int index, POINT point, bool isSelect)
{
	m_selectItem->m_item = item;
	m_selectItem->m_itemIndex = index;
	m_selectItem->m_renderPoint = point;
	m_selectItem->isSelect = isSelect;
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
