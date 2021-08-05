#pragma once
#include "gameNode.h"
class CsceneStart : public gameNode
{
private:

public:
	CsceneStart();
	~CsceneStart();

	HRESULT init();
	void release();
	void update();
	void render();
};

