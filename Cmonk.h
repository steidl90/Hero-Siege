#pragma once
#include "Cenemy.h"
class Cmonk :public Cenemy
{
private:


public:
	Cmonk();
	~Cmonk();

	virtual HRESULT init(POINT position, int HP);
	virtual void update();
	virtual void attack();
	virtual void die();
	virtual void animation();
};

