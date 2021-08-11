#pragma once
#include "Cenemy.h"

class Celemental :public Cenemy
{
private:

public:
	Celemental();
	~Celemental();

	virtual HRESULT init(POINT position, float HP, float damage, float exp,float trace);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void attack();
	virtual void animation();
	virtual bool enemyCooltime();

};
