#pragma once
#include"gameNode.h"

class Citem
{

private:
	image* m_itemImage;
	string m_itemName;
	string m_itemDescription;
	ITEMTYPE m_itemType;
	int m_itemAbility;
	int m_itemPrice;

public:
	Citem();
	Citem(image* image, string name, string description, ITEMTYPE type, int ability, int price);
	~Citem();

	image* getItemImage()const { return m_itemImage; }
	string getItemName()const { return m_itemName; }
	string getItemDescription()const { return m_itemDescription; }
	ITEMTYPE getItemType()const { return m_itemType; }
	int getItemAbility()const { return m_itemAbility; }
	int getItemPrice()const { return m_itemPrice; }


};

