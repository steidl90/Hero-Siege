#pragma once
#include "Cunit.h"
class Cmevius :public Cunit
{
private:


public:
	Cmevius();
	~Cmevius();

	HRESULT init();
	void release();
	void update();
	void render();
};

