#pragma once
#include"singleton.h"

class Citem;
class CtotalItem : public Singleton<CtotalItem>
{
	vector<Citem*> m_totalItem;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	Citem* getItem(int id);
};

