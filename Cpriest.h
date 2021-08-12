#pragma once
#include "Cenemy.h"
#include "CprogressBar.h"
class Cpriest :public Cenemy
{
private:
	CprogressBar* m_hpBar;

public:
	Cpriest();
	~Cpriest();

<<<<<<< HEAD
	virtual HRESULT init(POINT position, float HP, float damage, int exp,float trace);
	virtual void release();
	virtual void update();
	virtual void render();
=======
	virtual HRESULT init(POINT position, int HP);
>>>>>>> parent of 35abb8d (몬스터 최종)
	virtual void attack();
	virtual void die();
	virtual void animation();
};

