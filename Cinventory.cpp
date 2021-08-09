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
	m_vWeaponList.push_back(tempWeapon);
	m_vWeaponList.push_back(tempWeapon2);

	m_vArmorList.push_back(*(ITEM->getItem(2)));
	m_vArmorList.push_back(*(ITEM->getItem(3)));
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
}

void Cinventory::EquipItem(Citem* item)
{
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
			if ((*iter).getName() == item->getName())
			{
				m_vWeaponList.erase(iter);
				break;
			}
		}
		break;
	case ITEMTYPE::ITEMTYPE_ARMOR:
		for (auto iter = m_vArmorList.begin(); iter != m_vArmorList.end(); ++iter)
		{
			if ((*iter).getName() == item->getName())
			{
				m_vArmorList.erase(iter);
				break;
			}
		}
		break;
	default:
		break;
	}
}
