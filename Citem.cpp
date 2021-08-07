#include "framework.h"
#include "Citem.h"

Citem::Citem()
{
}

Citem::Citem(image* image, string name, string description, ITEMTYPE type, int ability, int price)
	:m_itemImage(image), m_itemName(name), m_itemDescription(description), m_itemAbility(ability), m_itemPrice(price)
{
}

Citem::~Citem()
{
}
