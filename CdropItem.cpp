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
	for (m_viDropItem = m_vDropItem.begin(); m_viDropItem != m_vDropItem.end(); ++m_viDropItem)
	{
		Rectangle(getMapDC(), m_viDropItem->itemRect.left, m_viDropItem->itemRect.top, m_viDropItem->itemRect.right, m_viDropItem->itemRect.bottom);
		IMAGE->findImage(m_viDropItem->item->getSmallImage())->frameRender(getMapDC()
			, m_viDropItem->itemRect.left, m_viDropItem->itemRect.top
			, m_viDropItem->item->getFrame().x, m_viDropItem->item->getFrame().y);
	}
}

Citem CdropItem::getItem()
{
	int isDrop, itemType, dropItem = 0;
	isDrop = RND->getInt(2);
	itemType = RND->getInt(5);


	if (isDrop == 1)
	{
		if (itemType == 0) // ����
		{
			dropItem = RND->getFromIntTo(1, 5);
		}
		else if (itemType == 1) // ����
		{
			dropItem = RND->getFromIntTo(8, 12);
		}
		else if (itemType == 2) // �Ź�
		{
			dropItem = RND->getFromIntTo(15, 19);
		}
		else if (itemType == 3) // �尩
		{
			dropItem = RND->getFromIntTo(22, 26);
		}
		else if (itemType == 4) // �Ǽ�
		{
			dropItem = RND->getFromIntTo(29, 33);
		}
	}
	/*IMAGE->findImage(m_vDropItemList[dropItem].getSmallImage())->frameRender(getMapDC(), m_x, m_y
		, m_vDropItemList[dropItem].getFrame().x, m_vDropItemList[dropItem].getFrame().y);
	TextOut(getMapDC(), m_x, m_y, m_vDropItemList[dropItem].getName().c_str(), lstrlen(m_vDropItemList[dropItem].getName().c_str()));*/
   	return m_vDropItemList[dropItem];

}

void CdropItem::makeItem(float x, float y)
{
	DropItem tempItem;
	tempItem.item = &this->getItem();
  	int i = 0;
	tempItem.itemRect = RectMake(x, y, IMAGE->findImage(tempItem.item->getSmallImage())->getFrameWidth(),
		IMAGE->findImage(tempItem.item->getSmallImage())->getFrameHeight());
	tempItem.x = x;
	tempItem.y = y;
	m_vDropItem.push_back(tempItem);
}

void CdropItem::removeItem(int num)
{
}
