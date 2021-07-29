#pragma once
#include "Cunit.h"
class CplayerSkill :public Cunit
{
private:

public:
	CplayerSkill();
	~CplayerSkill();

	HRESULT init();
	void release();
	void update();
	void render();
};

