#pragma once
#include "Cunit.h"
#include "CenemyAttack.h"

//enum class ELEMENTAL_STATE
//{
//	ELEMENTAL_STATE_LEFT,
//	ELEMENTAL_STATE_RIGHT,
//	ELEMENTAL_STATE_TOP,
//	ELEMENTAL_STATE_BOTTOM,
//	ELEMENTAL_STATE_IDLE
//};
//
//class Celemental :public Cunit
//{
//private:
//	Cimage* m_elemental;
//	image* m_elementalImage;
//	animation* m_elementalAnimation;
//	effect* m_elementalEffect;
//
//	ELEMENTAL_STATE m_elementalState;
//
//	RECT m_elementalRc;			//������Ż �̹��� RC
//	RECT m_elementalSkillRc;	//������Ż ��ų RC
//	RECT m_elementalCallRc;		//������Ż ��ȯ �ν� ���� RC
//	RECT m_elementalDamageRc;	//������Ż Ÿ�� RC
//
//	float m_x, m_y;
//	float m_speed;
//
//	CenemyAttack* m_enemyAttack;
//
//
//
//public:
//	Celemental();
//	~Celemental();
//
//	HRESULT init();
//	void release();
//	void update();
//	void render();
//};

enum class PRIEST_STATE
{
	PRIEST_STATE_IDLE,
	
	PRIEST_STATE_WALK_UP,
	PRIEST_STATE_WALK_DOWN,
	PRIEST_STATE_WALK_LEFT,
	PRIEST_STATE_WALK_RIGHT,

	PRIEST_STATE_ATTACK_UP,
	PRIEST_STATE_ATTACK_DOWN,
	PRIEST_STATE_ATTACK_LEFT,
	PRIEST_STATE_ATTACK_RIGHT,

	PRIEST_STATE_DIE_UP,
	PRIEST_STATE_DIE_DOWN,
	PRIEST_STATE_DIE_LEFT,
	PRIEST_STATE_DIE_RIGHT,

};

class Cpriest :public Cunit
{
private:
	image* m_priestImage;
	animation* m_priestAnimation;
	effect* m_priestEffect;

	PRIEST_STATE m_priestState;

	RECT m_priestRc;			//������Ż �̹��� RC
	//RECT m_priestSkillRc;	//������Ż ��ų RC
	RECT m_priestCallRc;		//������Ż ��ȯ �ν� ���� RC
	RECT m_priestDamageRc;	//������Ż Ÿ�� RC

	float m_x, m_y;
	float m_speed;
	bool isDie;
	CenemyAttack* m_enemyAttack;

public:
	Cpriest();
	~Cpriest();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

