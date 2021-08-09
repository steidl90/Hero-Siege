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
	animation* m_prisonAni;
	RECT m_prisonRc;

	image* m_prisonAttack;
	animation* m_prisonAttackAni;
	RECT m_prisonAttackRc;

	image* m_prisonDie;
	animation* m_prisonDieAni;
	RECT m_prisonDieRc;

	PRISON_STATE m_prisonState;
	RECT m_prisonCallRc;

	//CenemyAttack* m_prisonAttack;


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

	void animation();

	void move();
	void attack();
	void die();

	void ReturnIdleAnimation();
};

