#pragma once
#include "gameNode.h"
class Cunit :public gameNode
{
private:


public:
	Cunit();
	~Cunit();

	HRESULT init();
	void release();
	void update();
	void render();
};

