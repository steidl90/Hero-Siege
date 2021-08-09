#pragma once
#include "Cunit.h"
#include "CenemyAttack.h"
enum class MONK_DIRECTION
{
	MONK_DIRECTION_UP,
	MONK_DIRECTION_DOWN,
	MONK_DIRECTION_LEFT,
	MONK_DIRECTION_RIGHT
};
enum class MONK_STATE
{
	MONK_STATE_UP,
	MONK_STATE_DOWN,
	MONK_STATE_LEFT,
	MONK_STATE_RIGHT
};
class Cmonk :public Cunit
{
private:
	
	MONK_DIRECTION m_direction;
	MONK_DIRECTION m_beforeDirection;

	MONK_STATE m_state;

	image*			m_monk;
	image*			m_monkAttack;
	image*			m_monkDie;

	animation*		m_monkAni;
	animation*		m_monkAttackAni;
	animation*		m_monkDieAni;

	RECT			m_monkRc;
	RECT			m_monkAttackRc;

	float m_speed;
	float m_x, m_y;

	bool isWalking;
	bool isAttack;
	bool isDie;

public:
	Cmonk();
	~Cmonk();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();
	void moveAni();
	void attack();
	void Die();
};

