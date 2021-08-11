#include "framework.h"
#include "Cshop.h"

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
