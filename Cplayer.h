#pragma once
#include "Cunit.h"
#include "CplayerSkill.h"
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

	CplayerSkill* m_playerSkill;

	DIRECTIONS direction;
	DIRECTIONS beforeDirection;

	//���
	image* playerDown;
	image* playerUp;
	image* playerLeft;
	image* playerRight;

	//����
	image* playerMoveDown;
	image* playerMoveUp;
	image* playerMoveLeft;
	image* playerMoveRight;

	//����
	image* playerAttackDown;
	image* playerAttackUp;
	image* playerAttackLeft;
	image* playerAttackRight;

	animation* playerIdleAni;
	animation* playerAttackAni;
	animation* playerMoveAni;

	RECT playerAttackRc;
	RECT playerMoveRc;

	float m_playerX, m_playerY;

	float m_speed;
	float m_angle;
	bool isMoving;
	bool isAttack;
	bool isLive;
	bool isIdle;

	// ���̽�Ÿ �߰�
	vector<POINT>* m_fastLoadLocation;
	int endCount;
	int startCount;

	bool resetMove;
	bool isButtonClick;
	bool isKeyup;

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

	// ���̽�Ÿ �߰�
	void setFastLoadLocation(vector<POINT>* vp) { m_fastLoadLocation = vp; }
	void mouseMoveAstar();
};

