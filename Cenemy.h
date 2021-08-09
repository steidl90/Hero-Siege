#pragma once
#include "Cunit.h"

enum class STATE
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	IDLE
};

class Cenemy : public Cunit
{
protected:
	class CenemyAttack* m_enemyAttack;

	image* m_image;
	animation* m_ani;
	effect* m_effect;

	STATE m_state;

	RECT m_rc;			
	RECT m_callRc;		
	RECT m_attackRc;	

	float m_x, m_y;
	float m_speed;

	bool isIdle;
	bool isWalking;
	bool isAttack;
	bool isDie;
	

public:

	Cenemy();
	~Cenemy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();
	virtual void moveAni();
	virtual void attack();
	virtual void Die();

};

