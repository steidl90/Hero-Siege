#pragma once
#include "Cunit.h"
#include "CplayerSkill.h"

enum class DIRECTIONS
{
	DIRECTIONS_LEFT,
	DIRECTIONS_UP,
	DIRECTIONS_RIGHT,
	DIRECTIONS_DOWN
};


class Cplayer :public Cunit
{
private:
	CplayerSkill* m_playerSkill;

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

	animation* playerIdleAni;
	animation* playerAttackAni;
	animation* playerMoveAni;

	RECT playerAttackRc;
	RECT playerMoveRc;

	int m_maxHp;
	int m_maxMp;
	int m_maxExp;

	float m_playerX, m_playerY;
	float m_angle;
	bool isMoving;
	bool isAttack;
	bool isLive;
	bool isIdle;


	float time;
	bool isRect;

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
	void isAttackRender();

	RECT* getplayerMoveRC() { return &playerMoveRc; }
	float getplayerX() const { return m_playerX; }
	float getplayerY() const { return m_playerY; }

	int getMaxHp() { return m_maxHp; }
	int getMaxMp() { return m_maxMp; }
	int getMaxExp() { return m_maxExp; }

	RECT* getPlayerAttackRC() { return &playerAttackRc; }
};

