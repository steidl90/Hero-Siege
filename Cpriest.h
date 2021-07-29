#pragma once
#include "Cunit.h"
class Cpriest :public Cunit
{
private:


public:
	Cpriest();
	~Cpriest();

	HRESULT init();
	void release();
	void update();
	void render();
};

