#pragma once
#include "CNPC.h"
class Cquest : public CNPC
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();
};

