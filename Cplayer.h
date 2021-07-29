#pragma once
#include "Cunit.h"
class Cplayer :public Cunit
{
private:

public:
	Cplayer();
	~Cplayer();

	HRESULT init();
	void release();
	void update();
	void render();
};

