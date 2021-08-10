#pragma once
#include "Cenemy.h"

class Celemental :public Cenemy
{
private:

public:
	Celemental();
	~Celemental();

	virtual HRESULT init(POINT position, int HP);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();
	virtual void attack();
	virtual void animation();
	virtual bool enemyCooltime();

};
