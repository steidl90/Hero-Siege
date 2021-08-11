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
	Citem tempWeapon3 = *(ITEM->getItem(2));
	Citem tempWeapon4 = *(ITEM->getItem(3));
	Citem tempWeapon5 = *(ITEM->getItem(4));
	m_vWeaponList.push_back(tempWeapon);
	m_vWeaponList.push_back(tempWeapon2);
	m_vWeaponList.push_back(tempWeapon3);
	m_vWeaponList.push_back(tempWeapon4);
	m_vWeaponList.push_back(tempWeapon5);

	// �ΰ��� ��� �ẽ ū �ǹ̴� x
	m_vArmorList.push_back(*(ITEM->getItem(7)));
	m_vArmorList.push_back(*(ITEM->getItem(8)));
	m_vArmorList.push_back(*(ITEM->getItem(9)));
	m_vArmorList.push_back(*(ITEM->getItem(10)));
	m_vArmorList.push_back(*(ITEM->getItem(11)));

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
			if ((*iter).getItemId() == item->getItemId())
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

//// ��� �κ��丮���� ������ ������ �ӽ�.. �������� �ؾ����� �ϴ� ���⸸ ����
//// ���� �̻�
//void Cinventory::setItemId()
//{
//	int i = 0;
//	for (auto iter = m_vWeaponList.begin(); iter != m_vWeaponList.end(); ++iter)
//	{
//		(*iter).setItemId(i);
//		i++;
//	}
//}
