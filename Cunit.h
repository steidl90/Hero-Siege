#pragma once
#include "gameNode.h"
class Cunit :public gameNode
{
private:
	/*
	�÷��̾�, �̳ʹ̵��� �������� �ʿ��� �κ��� ���⿡ ������
	�÷��̾�, �̳ʹ̵��� �������� �ʿ��� �κ��� ���⿡ ������
	�÷��̾�, �̳ʹ̵��� �������� �ʿ��� �κ��� ���⿡ ������
	*/

public:
	Cunit();
	~Cunit();

	HRESULT init();
	void release();
	void update();
	void render();

	//============== get ==============//



	//============== set ==============//


};

