#pragma once
#include "Cobject.h"
class CTown :public Cobject
{
private:

public:
	CTown();
	~CTown();

	HRESULT init();
	void release();
	void update();
	void render();
};

