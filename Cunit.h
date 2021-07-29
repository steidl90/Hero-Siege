#pragma once
#include "gameNode.h"
class Cunit :public gameNode
{
private:
	/*
	플레이어, 이너미들이 공통으로 필요한 부분은 여기에 만들어라
	플레이어, 이너미들이 공통으로 필요한 부분은 여기에 만들어라
	플레이어, 이너미들이 공통으로 필요한 부분은 여기에 만들어라
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

