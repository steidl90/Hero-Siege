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
	image* m_Image;
	animation* m_Animation;
	effect* m_Effect;

	STATE m_state;

	RECT m_Rc;			//ø§∏Æ∏‡≈ª ¿ÃπÃ¡ˆ RC
	RECT m_CallRc;		//ø§∏Æ∏‡≈ª º“»Ø ¿ŒΩƒ π¸¿ß RC
	RECT m_DamageRc;	//ø§∏Æ∏‡≈ª ≈∏∞› RC

	float m_x, m_y;
	float m_speed;
	bool isDie;

	class CenemyAttack* m_enemyAttack;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

