#pragma once
#include "Cunit.h"
class Cprison :public Cunit
{
private:


public:
	Cprison();
	~Cprison();

	virtual HRESULT init(POINT position, int HP);
	virtual void attack();
	virtual void die();
	virtual void animation();
};

