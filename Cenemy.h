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
	class Cplayer* m_player;

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
	float m_returnX, m_returnY;
	float m_speed;
	float m_hp;
	float m_damage;

	bool m_isIdle;
	bool m_isWalking;
	bool m_isAttack;
	bool m_isDie;

	int m_cooltimeCount;
	int m_rndskillCount;

public:

	Cenemy();
	~Cenemy();

	virtual HRESULT init(POINT position,int HP);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();
	virtual void attack();
	virtual void die();
	virtual void animation();

	virtual bool enemyCooltime();

	virtual RECT getRect() { return m_walkRc; }

};

