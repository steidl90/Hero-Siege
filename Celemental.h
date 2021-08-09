#pragma once
#include "Cenemy.h"

class Celemental :public Cenemy
{
private:

public:
	Celemental();
	~Celemental();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();
	virtual void animation();
};
