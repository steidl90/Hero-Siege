#pragma once
#include "Cunit.h"
class Celemental :public Cunit
{
private:


public:
	Celemental();
	~Celemental();

	HRESULT init();
	void release();
	void update();
	void render();
};
