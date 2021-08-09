#pragma once
#include "Cunit.h"
#include "CenemyAttack.h"
enum class PRISON_STATE
{
	PRISON_STATE_IDLE,

	PRISON_STATE_WALK_UP,
	PRISON_STATE_WALK_DOWN,
	PRISON_STATE_WALK_LEFT,
	PRISON_STATE_WALK_RIGHT,

	PRISON_STATE_ATTACK_UP,
	PRISON_STATE_ATTACK_DOWN,
	PRISON_STATE_ATTACK_LEFT,
	PRISON_STATE_ATTACK_RIGHT,

	PRISON_STATE_DIE_UP,
	PRISON_STATE_DIE_DOWN,
	PRISON_STATE_DIE_LEFT,
	PRISON_STATE_DIE_RIGHT,

};

class Cprison :public Cunit
{
private:
	image* m_prison;
	//image* m_prisonAttack;

	animation* m_prisonAni;
	animation* m_prisonAttackAni;

	PRISON_STATE m_prisonState;
	CenemyAttack* m_prisonAttack;

	RECT m_prisonRc;
	RECT m_prisonCallRc;
	RECT m_prisonAttackRc;

	float m_x, m_y;
	float m_speed;

	bool isWalking;
	bool isAttack;
	bool isDie;

public:
	Cprison();
	~Cprison();

	HRESULT init();
	void release();
	void update();
	void render();
};

