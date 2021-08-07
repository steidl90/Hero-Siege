#pragma once
#include "Cunit.h"
#include "CenemyAttack.h"

enum class ELEMENTAL_STATE
{
	ELEMENTAL_STATE_LEFT,
	ELEMENTAL_STATE_RIGHT,
	ELEMENTAL_STATE_TOP,
	ELEMENTAL_STATE_BOTTOM,
	ELEMENTAL_STATE_IDLE
};

class Celemental :public Cunit
{
private:
	image* m_elementalImage;
	animation* m_elementalAnimation;
	effect* m_elementalEffect;

	ELEMENTAL_STATE m_elementalState;

	RECT m_elementalRc;			//������Ż �̹��� RC
	RECT m_elementalSkillRc;	//������Ż ��ų RC
	RECT m_elementalCallRc;		//������Ż ��ȯ �ν� ���� RC
	RECT m_elementalDamageRc;	//������Ż Ÿ�� RC

	float m_x, m_y;
	float m_speed;
	float a;
	CenemyAttack* m_enemyAttack;



public:
	Celemental();
	~Celemental();

	HRESULT init();
	void release();
	void update();
	void render();
};
