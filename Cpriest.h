#pragma once
#include "Cunit.h"
#include "CenemyAttack.h"

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

	PRIEST_STATE m_priestState;
	CenemyAttack* m_enemyAttack;

	RECT m_priestRc;		
	RECT m_priestCallRc;	
	RECT m_priestDamageRc;	

	float m_x, m_y;
	float m_speed;

	bool isDie;

public:
	Cpriest();
	~Cpriest();

	HRESULT init();
	void release();
	void update();
	void render();
};

