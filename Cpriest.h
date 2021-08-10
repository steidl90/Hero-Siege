#pragma once
#include "Cenemy.h"
class Cpriest :public Cenemy
{
private:

public:
	Cpriest();
	~Cpriest();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

