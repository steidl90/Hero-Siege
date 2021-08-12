#pragma once
#include "Cunit.h"
#include "CenemyManager.h"
#include "Cplayer.h"
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
	image* m_meviusImage;
	animation* m_meviusAnimation;
	effect* m_meviusEffect;
	BOSS_STATE m_meviusState;

	CenemyManager* m_em;
	Cplayer* m_player;

	RECT m_meviusRc;		//보스 이미지 RC
	RECT m_meviusSkillRc;	//보스 스킬 RC(가시공)
	RECT m_meviusCallRc;	//보스 소환 인식 범위 RC
	RECT m_meviusDamageRc;	//보스 타격 RC

	float m_x, m_y;
	float m_speed;

	float m_hp;
	float m_skillDamagePattern1;
	float m_skillDamagePattern2;
	float m_skillDamagePattern3;

	int m_effectCount;
	int m_coolTime;

	bool m_isEffect;		//이펙트상태
	bool m_isAppear;		//등장상태
	bool m_isLevitating;	//떠있는 상태
	bool m_isWalking;		//걷는상태
	bool m_isCasting;		//캐스팅상태
	bool m_isIdle;			//일반상태
	bool m_isDie;			//죽은상태

public:
	Cmevius();
	~Cmevius();

	HRESULT init();
	void release();
	void update();
	void render();

	void meviusState();
	void coolTime(float time,bool idle, bool walk, bool cast);

};

