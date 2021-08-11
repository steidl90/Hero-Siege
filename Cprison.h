#pragma once
#include "Cenemy.h"
class Cprison :public Cenemy
{
private:


public:
	Cprison();
	~Cprison();

	virtual HRESULT init(POINT position, float HP, float damage, float exp,float trace);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void attack();
	virtual void die();
	virtual void animation();
	virtual bool enemyCooltime();
};

