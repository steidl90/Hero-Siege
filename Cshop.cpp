#include "framework.h"
#include "Cshop.h"

HRESULT Cshop::init()
{
	// �Ϲ� ��� �����۸� �����ͼ� push
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
