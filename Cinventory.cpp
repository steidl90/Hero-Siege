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
	Citem tempWeapon2 = *(ITEM->getItem(3));
	m_vWeaponList.push_back(tempWeapon);
	m_vWeaponList.push_back(tempWeapon2);

	m_vArmorList.push_back(*(ITEM->getItem(1)));
	m_vArmorList.push_back(*(ITEM->getItem(2)));
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

void Cinventory::AbandonItem(Citem* item)
{
}
