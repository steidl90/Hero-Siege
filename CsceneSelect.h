#pragma once
#include "gameNode.h"
class CsceneSelect : public gameNode
{
private:
	RECT m_playerRc;
	RECT m_Rc1;
	RECT m_Rc2;
	RECT m_Rc3;
	RECT m_Rc4;
	RECT m_Rc5;
	RECT m_Rc6;
	RECT m_Rc7;
	RECT m_Rc8;
	RECT m_Rc9;
	RECT m_Rc10;
	RECT m_Rc11;
	RECT m_Rc12;
	RECT m_Rc13;
	RECT m_Rc14;

	image* m_image[15];
	animation* m_ani[15];

	bool isSelect;
public:
	CsceneSelect();
	~CsceneSelect();

	HRESULT init();
	void release();
	void update();
	void render();

};