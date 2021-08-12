#pragma once
<<<<<<< HEAD
#include "Cenemy.h"
#include "CprogressBar.h"
class Cprison :public Cenemy
=======
#include "Cunit.h"
class Cprison :public Cunit
>>>>>>> parent of 35abb8d (몬스터 최종)
{
private:
	CprogressBar* m_hpBar;


public:
	Cprison();
	~Cprison();

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

