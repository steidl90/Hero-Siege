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

	RECT m_meviusRc;		//���� �̹��� RC
	RECT m_meviusSkillRc;	//���� ��ų RC(���ð�)
	RECT m_meviusCallRc;	//���� ��ȯ �ν� ���� RC
	RECT m_meviusDamageRc;	//���� Ÿ�� RC

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

	bool m_isEffect;		//����Ʈ����
	bool m_isAppear;		//�������
	bool m_isLevitating;	//���ִ� ����
	bool m_isWalking;		//�ȴ»���
	bool m_isCasting;		//ĳ���û���
	bool m_isIdle;			//�Ϲݻ���
	bool m_isDie;			//��������

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

