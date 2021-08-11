#pragma once
#include "Cunit.h"
#include "CplayerSkill.h"
#include "CprogressBar.h"

enum class DIRECTIONS
{
	DIRECTIONS_LEFT,
	DIRECTIONS_UP,
	DIRECTIONS_RIGHT,
	DIRECTIONS_DOWN
};

//enum class STATE
//{
//	STATE_IDLE,
//	STATE_LEFT,
//	STATE_RIGHT,
//	STATE_UP,
//	STATE_DOWN
//};


class Cplayer :public Cunit
{
private:
	CplayerSkill* m_playerSkill;
	CprogressBar* m_hpBar;
	CprogressBar* m_mpBar;

	DIRECTIONS direction;
	DIRECTIONS beforeDirection;

	//대기
	image* playerDown;
	image* playerUp;
	image* playerLeft;
	image* playerRight;

	//무브
	image* playerMoveDown;
	image* playerMoveUp;
	image* playerMoveLeft;
	image* playerMoveRight;

	//공격
	image* playerAttackDown;
	image* playerAttackUp;
	image* playerAttackLeft;
	image* playerAttackRight;

	//라이트닝
	image* playerSkillLightning;
	animation* playerLightningAni;

	animation* playerIdleAni;
	animation* playerAttackAni;
	animation* playerMoveAni;

	

	RECT playerAttackRc;
	RECT playerMoveRc;

	//스킬RECT
	RECT lightningCenterRc;
	RECT lightningRightRc;
	RECT lightningLeftRc;
	RECT lightningUpRc;
	RECT lightningDownRc;


	int m_skillX, y;
	int m_count;

	int m_maxHp;
	int m_maxMp;

	float m_playerX, m_playerY;
	float m_angle;

	float m_time;

	bool isMoving;
	bool isAttack;
	bool isLive;
	bool isIdle;
	bool isRect;

	bool isSkillLeft;
	bool isSkillLeft2;
	bool isSkillLeft3;
	bool isSkillLeft4;
public:
	Cplayer();
	~Cplayer();

	HRESULT init();
	void release();
	void update();
	void render();
	void moveControl();
	void moveAnimation();
	void playerStateRender();

	RECT* getplayerMoveRC() { return &playerMoveRc; }
	float getplayerX() const { return m_playerX; }
	float getplayerY() const { return m_playerY; }

	int getMaxHp() { return m_maxHp; }

	
};

