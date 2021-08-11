#pragma once
#include"Citem.h"

class Cshop
{

private:

	vector<Citem> m_vTotalList;

public:

	HRESULT init();
	void release();
	void update();
	//void render();

	vector<Citem>* getTotalList() { return &m_vTotalList; }

};

