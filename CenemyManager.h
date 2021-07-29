#pragma once
#include "Cunit.h"
#include "Celemental.h"
#include "Cmonk.h"
#include "Cpriest.h"
#include "Cprison.h"
#include "Cslime.h"
#include "CenemyAttack.h"

//enemy 행동패턴용도
enum class ENEMYTYPE {
	ENEMYTYPE_A,
	ENEMYTYPE_B,
	ENEMYTYPE_C,
	ENEMYTYPE_D,
	ENEMYTYPE_E
};

class CenemyManager :public Cunit
{
private:
	Celemental* m_elemental;
	Cmonk* m_monk;
	Cpriest* m_priest;
	Cprison* m_prison;
	Cslime* m_slime;


public:
	CenemyManager();
	~CenemyManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

