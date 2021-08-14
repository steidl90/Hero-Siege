#pragma once
#include "Cunit.h"
#include "CenemyManager.h"
#include "Cplayer.h"
#include "CprogressBar.h"
struct tagBossAttack
{
	image* m_bossAttackImage;
	RECT m_attackRc;
	animation* m_bossAttackAni;

	float m_attackX, m_attackY;
	float m_fireX, m_fireY;
	float m_radius;
	float m_angle;
	float m_speed;
	float m_range;

	bool m_fire;
};
enum class BOSS_STATE
{
	BOSS_STATE_IDLE,
	BOSS_STATE_WALKING,
	BOSS_STATE_CASTING,
	BOSS_STATE_LEVITATING,
	BOSS_STATE_DIE
};
class Cmevius :public Cunit
{
private:
	CprogressBar* m_hpBar;

	vector<tagBossAttack> m_vBossAttack;
	vector<tagBossAttack>::iterator m_viBossAttack;

	image* m_meviusImage;
	animation* m_meviusAnimation;
	effect* m_meviusEffect;
	BOSS_STATE m_meviusState;

	image* m_meviusAttackImage;

	CenemyManager* m_em;
	Cplayer* m_player;

	RECT m_meviusRc;		//보스 이미지 RC
	RECT m_meviusSkillRc;	//보스 스킬 RC(가시공)
	RECT m_meviusCallRc;	//보스 소환 인식 범위 RC
	RECT m_meviusDamageRc;	//보스 타격 RC

	float m_x, m_y;
	float m_speed;
	float m_time;
	float m_bossAngle;

	float m_maxHp;
	float m_hp;
	float m_def;
	float m_exp;
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

	HRESULT init(POINT position,float hp, float p1Damage1, float p1Damage2, float p1Damage3);
	void release();
	void update();
	void render();
	void bossFire(float x, float y, float angle, float speed, float range, const char* fileName, const char* aniName);
	void bossFireMove(const char* aniName);
	void bossFireRender();
	void appear();
	void defaultState();
	void phase1();
	void phase2();
	void phase3();




	void meviusState();
	void coolTime(float time,bool idle, bool walk, bool cast);

	vector<tagBossAttack> getvBossAttack() { return m_vBossAttack; };
	vector<tagBossAttack>::iterator getviBossAttack() { return m_viBossAttack; }
};

