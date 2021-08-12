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

	RECT m_meviusRc;		//���� �̹��� RC
	RECT m_meviusSkillRc;	//���� ��ų RC(���ð�)
	RECT m_meviusCallRc;	//���� ��ȯ �ν� ���� RC
	RECT m_meviusDamageRc;	//���� Ÿ�� RC

	float m_x, m_y;
	float m_speed;

	float m_hp;
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

	HRESULT init();
	void release();
	void update();
	void render();

	void meviusState();
	void coolTime(float time,bool idle, bool walk, bool cast);

};

