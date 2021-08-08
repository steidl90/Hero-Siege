#pragma once
#include "Cunit.h"
#include "CenemyAttack.h"
enum class MONK_STATE
{
	MONK_STATE_IDLE,

	MONK_STATE_WALK_UP,
	MONK_STATE_WALK_DOWN,
	MONK_STATE_WALK_LEFT,
	MONK_STATE_WALK_RIGHT,

	MONK_STATE_ATTACK_UP,
	MONK_STATE_ATTACK_DOWN,
	MONK_STATE_ATTACK_LEFT,
	MONK_STATE_ATTACK_RIGHT,

	MONK_STATE_DIE_UP,
	MONK_STATE_DIE_DOWN,
	MONK_STATE_DIE_LEFT,
	MONK_STATE_DIE_RIGHT,
};
class Cmonk :public Cunit
{
private:

	image*			m_monkImage;
	animation*		m_monkAnimation;

	RECT			m_monkRc;
	RECT			m_monkCallRc;
	RECT			m_monkDamageRc;
	RECT			m_monkAttackRc;

	CenemyAttack*	m_enemyAttack;
	MONK_STATE		m_monkState;

	float m_x, m_y;
	float m_speed;

	bool isDie;
	bool isAttack;

public:
	Cmonk();
	~Cmonk();

	HRESULT init();
	void release();
	void update();
	void render();
};

