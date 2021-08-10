#pragma once
#include "Cunit.h"
#include "Cenemy.h"

//enemy 행동패턴용도
enum class ENEMYTYPE {
	ENEMYTYPE_A,
	ENEMYTYPE_B,
	ENEMYTYPE_C,
	ENEMYTYPE_D,
	ENEMYTYPE_E
};

class CenemyManager :public Cenemy
{
private:
	typedef vector<Cenemy*> m_vEnemy;
	typedef vector<Cenemy*>::iterator m_viEnemy;


private:

	float m_angle;

public:
	CenemyManager();
	~CenemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//======================몬스터 세팅======================

	void setElemental(int setenemy, int x, int y, int distanceX, int distanceY, int pattern);
	void setPriest(int setenemy, int x, int y, int distanceX, int distanceY, int pattern);
	void setMonk(int setenemy, int x, int y, int distanceX, int distanceY, int pattern);
	void setPrison(int setenemy, int x, int y, int distanceX, int distanceY, int pattern);
	void setSlime(int setenemy, int x, int y, int distanceX, int distanceY, int pattern);

	void elementalSkill();
	void priestSkill();
	void monkAttack();
	void prisonAttack();
	void slimeAttack();

	void removeElemental(int arrNum);
	void removePriest(int arrNum);
	void removeMonk(int arrNum);
	void removePrison(int arrNum);
	void removeSlime(int arrNum);
};

