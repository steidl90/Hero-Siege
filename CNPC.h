#pragma once
#include "Cobject.h"
class CNPC : public Cobject
{
private:
	RECT m_npc1; //����
public:
	HRESULT init();
	void release();
	void update();
	void render();
};

