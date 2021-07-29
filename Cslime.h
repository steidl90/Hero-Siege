#pragma once
#include "Cunit.h"
class Cslime :public Cunit
{
private:


public:
	Cslime();
	~Cslime();

	HRESULT init();
	void release();
	void update();
	void render();
};

