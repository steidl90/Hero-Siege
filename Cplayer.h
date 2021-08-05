#pragma once
#include "Cunit.h"

class Ciamge;

enum class  DIRECTIONS
{
	LEFT,
	UP,
	RIGHT,
	DOWN
};

enum class STATE
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};
class Cplayer :public Cunit
{
private:

	DIRECTIONS direction;
	DIRECTIONS beforeDirection;

	STATE state;

	int playerX, playerY;
	image* playerIdle;
	image* playerMove;
	image* playerAttack;

	animation* playerIdleAni;
	animation* playerAttackAni;
	animation* playerMoveAni;

	RECT playerIdleRc;
	RECT playerAttackRc;
	RECT playerMoveRc;


	float speed = 100.0f;


public:
	Cplayer();
	~Cplayer();

	HRESULT init();
	void release();
	void update();
	void render();
	void setPlayerPosition();
	void move();
	void moveAnimation();
	RECT* getplayerMoveRC() { return &playerMoveRc; }
};

