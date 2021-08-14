#include "framework.h"
#include "Cmevius.h"
Cmevius::Cmevius()
{
    m_meviusImage = nullptr;
}

Cmevius::~Cmevius()
{
}

HRESULT Cmevius::init(POINT position, int hp, float p1Damage1, float p1Damage2, float p1Damage3)
{
    m_em = new CenemyManager;
    m_player = new Cplayer;
    
    m_attack = new CenemyAttack;
    m_attack->init(100,1000,false,"보스스킬애니");
    m_hpBar = new CprogressBar;
    m_hpBar->init("images/hp.bmp", "images/hp_back.bmp", m_x, m_y, 596, 16);
    m_hpBar->setGauge(m_hp, m_maxHp);

	ANIMATION->addDefAnimation("애니공중", "보스공중", 10, false, true);
    ANIMATION->addDefAnimation("애니보스", "보스", 5, false, true);
    ANIMATION->addDefAnimation("애니캐스팅", "보스캐스팅", 10, false, false);
    ANIMATION->addDefAnimation("애니캐스팅2", "보스캐스팅", 10, true, false);
    ANIMATION->addDefAnimation("애니걷기", "보스걷기", 3, false, false);
    ANIMATION->addDefAnimation("애니공", "보스공", 10, false, true);
    EFFECT->addEffect("라이트닝", "images/Lightning.bmp", 576, 402, 72, 402, 1, 0.25f, 100);
    EFFECT->addEffect("스텀프", "images/Stomp.bmp", 819*2, 78*2, 91*2, 78*2, 1, 0.2f, 200);

    m_isAppear = true;
    m_isEffect = false;
    m_isLevitating = false;
	m_isWalking = false;
	m_isCasting = false;
	m_isIdle = false;
	m_isDie = false;

    m_x = position.x ;
    m_y = position.y;
    m_speed = 2;

    m_hp = m_maxHp = hp;
    //m_def = def;
    //m_exp = exp;

    m_skillDamagePattern1= p1Damage1;
    m_skillDamagePattern2= p1Damage2;
    m_skillDamagePattern3= p1Damage3;

    return S_OK;
}

void Cmevius::release()
{
    SAFE_DELETE(m_meviusImage);
}

void Cmevius::update()
{
    m_hpBar->setGauge(m_hp, m_maxHp);
    m_hpBar->mapUpdate(344,70);
    m_attack->update();
    //등장씬 시작
   if (m_isAppear)
   {
       m_isLevitating = true;
       m_isAppear = false;
   }

    if (m_isLevitating)
    {
        m_effectCount++;
        if (m_effectCount % 4 == 0)
        {
            EFFECT->play("라이트닝", RND->getFromIntTo(100, WINSIZEX - 100), RND->getFromIntTo(100, WINSIZEY - 100));
        }
        m_meviusImage = IMAGE->findImage("보스공중");
        m_meviusAnimation = ANIMATION->findAnimation("애니공중");
        ANIMATION->start("애니공중");
        if (m_meviusRc.top <= 400) m_y += m_speed;
		else
		{
			m_coolTime++;
			if (m_coolTime == 50)
			{
				m_isEffect = false;
                m_isLevitating = false;
				m_isWalking = true;
                m_isIdle = true;
			EFFECT->play("스텀프", m_meviusRc.left + (m_meviusRc.right - m_meviusRc.left) / 2, m_meviusRc.bottom);
			}
		}
	}
	if (m_isWalking)
	{
		m_meviusImage = IMAGE->findImage("보스걷기");
		m_meviusAnimation = ANIMATION->findAnimation("애니걷기");
		ANIMATION->start("애니걷기");
		m_isWalking = false;
	}

	if (!m_isAppear && !m_isWalking && m_meviusRc.top <= 450)
	{
		m_y += 0.2f;
	}

    if (m_meviusRc.top >= 450 && m_isIdle)
    {
        meviusphase1();
        m_meviusImage = IMAGE->findImage("보스");
        m_meviusAnimation = ANIMATION->findAnimation("애니보스");
        ANIMATION->resume("애니보스");
    }
    //등장씬 끝

    if ( InputManager->isOnceKeyDown('2'))
    {
        m_meviusImage = IMAGE->findImage("보스캐스팅");
        m_meviusAnimation = ANIMATION->findAnimation("애니캐스팅2");
        ANIMATION->resume("애니캐스팅2");
        m_isIdle = true;

    }
    if (m_meviusImage != nullptr) {
        m_meviusRc = RectMake(m_x, m_y, m_meviusImage->getFrameWidth(), m_meviusImage->getFrameHeight());
    }
}

void Cmevius::render()
{
    if (m_meviusImage != nullptr) 
    {
        EFFECT->render();
        m_attack->render();
        m_meviusImage->aniRender(getMapDC(), m_x, m_y, m_meviusAnimation);

        m_hpBar->mapBossRender();
        IMAGE->findImage("보스체력바")->render(getMemDC(),300,50 );
        TCHAR strhp[128];
        TCHAR strcoolTime[128];
        SetTextColor(getMemDC(), RGB(255, 255, 255));
        SetTextAlign(getMemDC(), TA_CENTER);
        sprintf_s(strhp, "%d/%d", m_hp, m_maxHp);
        TextOut(getMemDC(), 640, 70, strhp, strlen(strhp));
        SetTextAlign(getMemDC(), TA_LEFT);

    }
}

void Cmevius::meviusphase1()
{
    if (m_meviusImage != nullptr){
        if (meviusCooltime(10)){
            for (size_t i = 0; i < 1; i++){
                int count = 4;
                m_angle += 0.05;
                float tempAngle = 2 / (float)count;
                for (size_t j = 0; j < count; j++) {
                    m_attack->fire(m_meviusRc.right - (m_meviusRc.right - m_meviusRc.left) / 2,
                        m_meviusRc.bottom - (m_meviusRc.bottom - m_meviusRc.top) / 2,
                        (i * 0.2) + PI * tempAngle * j + m_angle, 2.5f, "보스공", "보스스킬애니");
                }}}}
}

void Cmevius::meviusphase2()
{
}

void Cmevius::meviusphase3()
{
}

//void Cmevius::coolTime(float time, bool idle, bool walk, bool cast)
//{
//    TIME->getWorldTime();
//    float waitTime;
//    waitTime = TIME->getWorldTime();
//    if (waitTime + time <= TIME->getWorldTime())
//    {
//        m_isWalking = walk;
//        m_isCasting = cast;
//        m_isIdle = idle;
//    }
//}

bool Cmevius::meviusCooltime(int skillcount)
{
    m_coolTime++;
    m_skillCount = skillcount;

    if (m_coolTime % skillcount == 0)
    {
        m_coolTime = 0;
        return true;
    }
    return false;
}
