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

	virtual void move();
	virtual void attack();
	virtual void die();
	virtual void animation();

	virtual bool enemyCoolTime();
};

