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
	Celemental* m_elemental;
	Cmonk* m_monk;
	Cpriest* m_priest;
	Cprison* m_prison;
	Cslime* m_slime;

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

	vector<Celemental*> getvElemental() { return m_vElemental; }
	vector<Celemental*> getviElemental() { return m_viElemental; }

	vector<Cpriest*> getvPriest() { return m_vPriest; }
	vector<Cpriest*> getviPriest() { return m_viPriest; }

	vector<Cmonk*> getvMonk() { return m_vMonk; }
	vector<Cmonk*> getviMonk() { return m_viMonk; }

	vector<Cprison*> getvPrison() { return m_vPrison; }
	vector<Cprison*> getviPrison() { return m_viPrison; }

	vector<Cslime*> getvSlime() { return m_vSlime; }
	vector<Cslime*> getviSlime() { return m_viSlime; }
};

