#pragma once
#include "Cunit.h"
#include "CplayerSkill.h"

enum class DIRECTIONS
{
	DIRECTIONS_LEFT,
	DIRECTIONS_UP,
	DIRECTIONS_RIGHT,
	DIRECTIONS_DOWN,
	DIRECTIONS_IDLE
};

class Cplayer :public Cunit
{
private:
	CplayerSkill* m_playerSkill;

	DIRECTIONS direction;
	DIRECTIONS beforeDirection;

	SKILL skillState;

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

	int m_skillX, m_skillY;
	int m_count;

	int m_maxHp;
	int m_maxMp;
	int m_maxExp;
	int m_saveDate;

	float m_playerX, m_playerY;
	float m_angle;

	float m_time;

	bool isMoving;
	bool isAttack;
	bool isLive;
	bool isIdle;
	bool isRect;

	tagTile* m_CheckTile;
	ATTRIBUTE* m_attribute;

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

	void playerSkillControl();
	void playerSkillRender();

	RECT* getplayerMoveRC() { return &playerMoveRc; }
	float getplayerX() const { return m_playerX; }
	float getplayerY() const { return m_playerY; }

	int getSaveDate() { return m_saveDate; }
	int getMaxHp() { return m_maxHp; }
	void setMaxHp(int hp) { m_maxHp = hp; }
	int getMaxMp() { return m_maxMp; }
	int getMaxExp() { return m_maxExp; }

	RECT* getPlayerAttackRC() { return &playerAttackRc; }

	void blockCheck(float speed, RECT* playerRC, DIRECTIONS direct);
	void setCheckTile(tagTile* tile) { m_CheckTile = tile; }
	void setAttribute(ATTRIBUTE* att) { m_attribute = att; }
};

