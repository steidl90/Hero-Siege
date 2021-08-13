#include "framework.h"
#include "Cshop.h"
#include "Cplayer.h"
HRESULT Cshop::init()
{
	// 일반 등급 아이템만 가져와서 push
	for (int i = 0; i < ITEM->getTotalItemCount(); i++)
	{
		if (ITEM->getItem(i)->getItemGradeInt() == 1) continue;

		m_vTotalList.push_back(*(ITEM->getItem(i)));
	}
	return S_OK;
}

void Cshop::release()
{
}

void Cshop::update()
{
}

void Cshop::buyItem(Citem* item)
{
	if (m_player->getGold() >= item->getBuyPrice())
	{
		m_myInventory->addItem(item);
		m_player->setGold(m_player->getGold() - item->getBuyPrice());
	}
}

void Cshop::sellItem(Citem* item)
{
	vector<Citem*>::iterator iter;
	int i = 0;
	for (iter = m_myInventory->getvEquipList()->begin(); iter != m_myInventory->getvEquipList()->end(); ++iter, i++)
	{
		if (static_cast<int>(item->getType()) == i)
		{
			if ((*iter) != nullptr)
			{
				if ((*iter)->getItemId() == item->getItemId()) break;
				else
				{
					m_player->setGold(m_player->getGold() + item->getBuyPrice());
					m_myInventory->AbandonItem(item);
				}
			}
			else
			{
				m_player->setGold(m_player->getGold() + item->getBuyPrice());
				m_myInventory->AbandonItem(item);
			}
		}
	}
}
