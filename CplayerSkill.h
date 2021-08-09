#pragma once
#include "Cunit.h"

enum class  SKILL
{
	SKILL_LEFT,
	SKILL_UP,
	SKILL_RIGHT,
	SKILL_DOWN
};
class CplayerSkill :public Cunit
{
private:
	SKILL skillDirection;
	RECT skillBoxRc;
public:
	CplayerSkill();
	~CplayerSkill();

	HRESULT init();
	void release();
	void update();
	void render();
	void skillQ();
	void skillW();
	void skillE();
};

