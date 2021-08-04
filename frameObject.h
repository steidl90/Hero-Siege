#pragma once
#include"gameNode.h"
class frameObject : public gameNode
{
	RECT m_objectRect;
	animation* m_ani;

	int m_x;
	int m_y;

public:
	HRESULT init(int x, int y);
	void release();
	void update();
	void render();
};

