#pragma once
#include "Cobject.h"
class Citem;
class CdropItem : public Cobject
{

	vector<Citem> m_vDropItemList;
	vector<DropItem> m_vDropItem;
	vector<DropItem>::iterator m_viDropItem;

public:


	HRESULT init();
	void release();
	void update();
	void render();


	Citem getItem();
	void makeItem(float x, float y);
	void removeItem(int num);
};

