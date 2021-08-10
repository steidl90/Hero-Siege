#pragma once
#include "Cunit.h"
class Cslime :public Cunit
{
private:


public:
	Cslime();
	~Cslime();

	virtual HRESULT init(POINT position, int HP);
	virtual void attack();
	virtual void die();
	virtual void animation();
};

