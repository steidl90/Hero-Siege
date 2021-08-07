#pragma once
#include "Cunit.h"

enum class  DIRECTIONS
{
	DIRECTIONS_LEFT,
	DIRECTIONS_UP,
	DIRECTIONS_RIGHT,
	DIRECTIONS_DOWN
};

enum class STATE
{
	STATE_IDLE,
	STATE_LEFT,
	STATE_RIGHT,
	STATE_UP,
	STATE_DOWN
};

class Cplayer :public Cunit
{
private:

	DIRECTIONS direction;
	DIRECTIONS beforeDirection;

	STATE state;

	int playerX, playerY;

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


	float speed = 100.0f;

	bool isMoving = true;
	bool isAttack;
	bool isLive = true;
	bool isIdle;

public:
	Cplayer();
	~Cplayer();

	HRESULT init();
	void release();
	void update();
	void render();
	//void setPlayerPosition(RECT rc);
	void move();
	void moveAnimation();
	void attack();

	RECT* getplayerMoveRC() { return &playerMoveRc; }
};

