#pragma once
#include "Cunit.h"
class Cmonk :public Cunit
{
private:


public:
	Cmonk();
	~Cmonk();

	HRESULT init();
	void release();
	void update();
	void render();
};

