#pragma once
#include"Citem.h"

class Cinventory
{
	
	vector<Citem*> m_vItemList;
	vector<Citem*>::iterator m_viItemList;



public:

	Cinventory();
	~Cinventory();

	HRESULT init();
	void release();
	void update();

	void addItem(Citem* item);
	void EquipItem(Citem* item);
	void UnEquipItem(Citem* item);
	void AbandonItem(Citem* item);

	//void render();
};

