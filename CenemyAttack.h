#pragma once
#include "Cunit.h"
class CenemyAttack :public Cunit
{
private:

public:
	CenemyAttack();
	~CenemyAttack();

	HRESULT init();
	void release();
	void update();
	void render();
};

