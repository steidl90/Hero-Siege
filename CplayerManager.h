#pragma once
#include "Cunit.h"


class CplayerManager :public Cunit
{
private:


public:
	CplayerManager();
	~CplayerManager();

	HRESULT init();
	void release();
	void update();
	void render();
};