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
	// �ϴ� push�Ҷ� Ÿ�� ����ó�� ����.. �׳� �����

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

// ������ ������ Ÿ���� ���Ͽ� �ش� ����Ʈ���� ������ ����

// �����Ҷ� ���� ���̵�� �����ؾ��� �ʿ䰡 ����.. ������ �ϴ� ���� �̸����� ����
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
