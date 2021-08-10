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

	image* m_walkImage;
	animation* m_walkAni;
	RECT m_walkRc;

	image* m_attackImage;
	animation* m_attackAni;
	RECT m_attackRc;

	image* m_dieImage;
	animation* m_dieAni;
	RECT m_dieRc;

	effect* m_effect;
	STATE m_state;
	RECT m_traceRc;		

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
	virtual void attack();
	virtual void die();
	virtual void animation();

	virtual bool enemyCoolTime();

};

