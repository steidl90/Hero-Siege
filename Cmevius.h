#pragma once
#include "Cunit.h"
enum class BOSS_STATE
{
	BOSS_STATE_IDLE,
	BOSS_STATE_WALKING,
	BOSS_STATE_CASTING,
	BOSS_STATE_LEVITATIN,
	BOSS_STATE_DIE
};
class Cmevius :public Cunit
{
private:
	Cimage* m_mevius;
	image* m_meviusImage;
	animation* m_meviusAnimation;
	effect* m_meviusEffect;

	BOSS_STATE m_meviusState;

	RECT m_meviusRc;
	RECT m_meviusSkillRc;
	RECT m_meviusCallRc;

	float m_x, m_y;
	float m_speed;
	int m_effectCount;
	bool m_isAppear;
	bool m_isWalking;
	bool m_isCasting;
	bool m_isIdle;
	bool m_isDie;

public:
	Cmevius();
	~Cmevius();

	HRESULT init();
	void release();
	void update();
	void render();

	void meviusState();
};

