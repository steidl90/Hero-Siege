#pragma once
#include "Cenemy.h"
class Cslime :public Cenemy
{
private:


public:
	Cslime();
	~Cslime();

	virtual HRESULT init(POINT position, float HP, float damage, float exp,float trace);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void attack();
	virtual void animation();
	virtual bool enemyCooltime();
};

