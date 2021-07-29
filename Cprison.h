#pragma once
#include "Cunit.h"
class Cprison :public Cunit
{
private:


public:
	Cprison();
	~Cprison();

	HRESULT init();
	void release();
	void update();
	void render();
};

