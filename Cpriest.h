#pragma once
#include "Cenemy.h"
class Cpriest :public Cenemy
{
private:

public:
	Cpriest();
	~Cpriest();

	virtual HRESULT init(POINT position, int HP);
	virtual void attack();
	virtual void die();
	virtual void animation();
};

