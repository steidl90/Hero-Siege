#pragma once
#include "Cobject.h"
class Cdungeon :public Cobject
{
private:

public:
	Cdungeon();
	~Cdungeon();

	HRESULT init();
	void release();
	void update();
	void render();
};

