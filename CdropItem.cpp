#include "framework.h"
#include "CdropItem.h"
#include "Citem.h"
HRESULT CdropItem::init()
{
	for (int i = 0; i < ITEM->getTotalItemCount(); i++)
	{
		m_vDropItemList.push_back(*ITEM->getItem(i));
	}
	return S_OK;
}

void CdropItem::release()
{
}

void CdropItem::update()
{
}

void CdropItem::render()
{
	TCHAR str[128];
	for (m_viDropItem = m_vDropItem.begin(); m_viDropItem != m_vDropItem.end(); ++m_viDropItem)
	{
		// Rectangle(getMapDC(), m_viDropItem->itemRect.left, m_viDropItem->itemRect.top, m_viDropItem->itemRect.right, m_viDropItem->itemRect.bottom);
		IMAGE->findImage(m_viDropItem->item->getSmallImage())->frameRender(getMapDC()
			, m_viDropItem->itemRect.left, m_viDropItem->itemRect.top
			, m_viDropItem->item->getFrame().x, m_viDropItem->item->getFrame().y);

		sprintf_s(str, "%s", m_viDropItem->item->getName().c_str());
		SetBkMode(getMapDC(), TRANSPARENT);
		SetTextColor(getMapDC(), RGB(255, 255, 255));
		TextOut(getMapDC(), m_viDropItem->x - (IMAGE->findImage(m_viDropItem->item->getSmallImage())->getFrameWidth() / 2), m_viDropItem->y - 10, str, lstrlen(str));
	}
}

Citem* CdropItem::getItem()
{
	int isDrop, itemType, dropItem = 0;
	isDrop = RND->getInt(2);
	itemType = RND->getInt(5);


	if (isDrop == 1)
	{
		if (itemType == 0) // ¹«±â
		{
			dropItem = RND->getFromIntTo(1, 5);
		}
		else if (itemType == 1) // °©¿Ê
		{
			dropItem = RND->getFromIntTo(8, 12);
		}
		else if (itemType == 2) // ½Å¹ß
		{
			dropItem = RND->getFromIntTo(15, 19);
		}
		else if (itemType == 3) // Àå°©
		{
			dropItem = RND->getFromIntTo(22, 26);
		}
		else if (itemType == 4) // ¾Ç¼¼
		{
			dropItem = RND->getFromIntTo(29, 33);
		}
   		return &m_vDropItemList[dropItem];
	}
	else
	{
		return &m_vDropItemList[20];
	}

}

void CdropItem::makeItem(float x, float y)
{
	//if (this->getItem() == nullptr) return;
	DropItem tempItem;
	tempItem.item = this->getItem();
	tempItem.itemRect = RectMake(x, y, IMAGE->findImage(tempItem.item->getSmallImage())->getFrameWidth(),
		IMAGE->findImage(tempItem.item->getSmallImage())->getFrameHeight());
	tempItem.x = x;
	tempItem.y = y;
	m_vDropItem.push_back(tempItem);
}

void CdropItem::removeItem(int num)
{
	m_vDropItem.erase(m_vDropItem.begin() + num);
}
