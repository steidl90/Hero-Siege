#include "framework.h"
#include "Cmevius.h"
Cmevius::Cmevius()
{
    m_meviusImage = nullptr;
}

Cmevius::~Cmevius()
{
}

HRESULT Cmevius::init(POINT position, float hp, float p1Damage1, float p1Damage2, float p1Damage3)
{
    m_em = new CenemyManager;
    m_player = new Cplayer;

    m_hpBar = new CprogressBar;
    m_hpBar->init("images/hp.bmp", "images/hp_back.bmp", m_x, m_y, 596, 16);
    m_hpBar->setGauge(m_hp, m_maxHp);

    //m_meviusImage = IMAGE->findImage("보스");
    m_meviusAttackImage = IMAGE->findImage("애니공");
	ANIMATION->addDefAnimation("애니공중", "보스공중", 10, false, true);
    ANIMATION->addDefAnimation("애니보스", "보스", 5, false, true);
    ANIMATION->addDefAnimation("애니캐스팅", "보스캐스팅", 10, false, false);
    ANIMATION->addDefAnimation("애니캐스팅2", "보스캐스팅", 10, true, false);
    ANIMATION->addDefAnimation("애니걷기", "보스걷기", 3, false, false);
    ANIMATION->addDefAnimation("애니공", "보스공", 10, false, true);
    EFFECT->addEffect("라이트닝", "images/Lightning.bmp", 576, 402, 72, 402, 1, 0.25f, 100);
    EFFECT->addEffect("스텀프", "images/Stomp.bmp", 819*2, 78*2, 91*2, 78*2, 1, 0.2f, 200);

    m_meviusAnimation = ANIMATION->findAnimation("애니보스");

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

   // m_meviusRc = RectMake(m_x, m_y, m_meviusImage->getFrameWidth(), m_meviusImage->getFrameHeight());
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


    //등장씬 시작
   if (m_isAppear)
   {
       m_isLevitating = true;
       m_isEffect = true;
       m_isAppear = false;
   }
   
   if (m_isEffect)
   {
       m_effectCount++;
     if (m_effectCount % 4 == 0)
     {
         EFFECT->play("라이트닝", RND->getFromIntTo(100, WINSIZEX - 100), RND->getFromIntTo(100, WINSIZEY - 100));
     }
   }
    m_bossAngle + 0.4;
    appear();
    if (m_isCasting && InputManager->isOnceKeyDown('3'))
    {
        m_meviusImage = IMAGE->findImage("보스캐스팅");
        m_meviusAnimation = ANIMATION->findAnimation("애니캐스팅2");
        ANIMATION->start("애니캐스팅2");
        defaultState();
    }

    
    if (m_meviusImage != nullptr) {
        m_meviusRc = RectMake(m_x, m_y, m_meviusImage->getFrameWidth(), m_meviusImage->getFrameHeight());
    }
    bossFireMove("애니공");
}

void Cmevius::render()
{
    //TCHAR str[100];
    //wsprintf(str, "left : %d right : %d  top : %d  bottom : %d", m_meviusRc.left, m_meviusRc.right, m_meviusRc.top, m_meviusRc.bottom);
    //TextOut(getMemDC(), 100, 100, str, lstrlen(str));
    //TCHAR str1[100];
    //wsprintf(str1, "idle : %d walk : %d  casting : %d", m_isIdle,m_isWalking,m_isCasting);
    //TextOut(getMemDC(), 100, 130, str1, lstrlen(str1));
    if (m_meviusImage != nullptr) {
        Rectangle(getMapDC(), m_meviusRc.left, m_meviusRc.top, m_meviusRc.right, m_meviusRc.bottom);
        m_meviusImage->aniRender(getMapDC(), m_x, m_y, m_meviusAnimation);
        EFFECT->render();
    }
    bossFireRender();
}

void Cmevius::bossFire(float x, float y, float angle, float speed, float range, const char* fileName, const char* aniName)
{
    tagBossAttack bossAttack;
    ZeroMemory(&bossAttack, sizeof(tagPlayerSkill));
    bossAttack.m_bossAttackImage = new image;
    bossAttack.m_bossAttackImage = IMAGE->findImage(fileName);
    bossAttack.m_bossAttackAni = ANIMATION->findAnimation(aniName);
    bossAttack.m_angle = angle;
    bossAttack.m_speed = speed;
    bossAttack.m_attackX = bossAttack.m_fireX = x;
    bossAttack.m_attackY = bossAttack.m_fireY = y;
    bossAttack.m_range = range;
    bossAttack.m_attackRc = RectMakeCenter(bossAttack.m_attackX, bossAttack.m_attackY, bossAttack.m_bossAttackImage->getFrameWidth(), bossAttack.m_bossAttackImage->getFrameHeight());
    m_vBossAttack.push_back(bossAttack);
}

void Cmevius::bossFireMove(const char* aniName)
{
    for (m_viBossAttack = m_vBossAttack.begin(); m_viBossAttack != m_vBossAttack.end();)
    {
        m_viBossAttack->m_fireX += cosf(m_viBossAttack->m_angle) * m_viBossAttack->m_speed;
        m_viBossAttack->m_fireY -= sinf(m_viBossAttack->m_angle) * m_viBossAttack->m_speed;

        m_viBossAttack->m_attackRc = RectMakeCenter(m_viBossAttack->m_fireX, m_viBossAttack->m_fireY,
            m_viBossAttack->m_bossAttackImage->getFrameWidth(),
            m_viBossAttack->m_bossAttackImage->getFrameHeight());

        if (m_viBossAttack->m_range < UTIL::getDistance(m_viBossAttack->m_fireX, m_viBossAttack->m_fireY, m_viBossAttack->m_attackX, m_viBossAttack->m_attackY))
        {
            m_viBossAttack = m_vBossAttack.erase(m_viBossAttack);
        }
        else ++m_viBossAttack;
    }
    ANIMATION->findAnimation(aniName);
    ANIMATION->resume(aniName);
}

void Cmevius::bossFireRender()
{
    for (m_viBossAttack = m_vBossAttack.begin(); m_viBossAttack != m_vBossAttack.end(); ++m_viBossAttack)
    {
        Rectangle(getMapDC(), m_viBossAttack->m_attackRc.left, m_viBossAttack->m_attackRc.top, m_viBossAttack->m_attackRc.right, m_viBossAttack->m_attackRc.bottom);
        m_viBossAttack->m_bossAttackImage->aniRender(getMapDC(), m_viBossAttack->m_attackRc.left, m_viBossAttack->m_attackRc.top, m_viBossAttack->m_bossAttackAni);

    }
}

void Cmevius::appear()
{
    if (m_isAppear)
    {
        m_isLevitating = true;
        m_isEffect = true;
        m_isAppear = false;
    }

    if (m_isEffect)
    {
        m_effectCount++;
        if (m_effectCount % 4 == 0)
        {
            EFFECT->play("라이트닝", RND->getFromIntTo(100, WINSIZEX - 100), RND->getFromIntTo(100, WINSIZEY - 100));
        }
    }

    if (m_isLevitating)
    {
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
                //m_coolTime = 0;
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
        m_meviusImage = IMAGE->findImage("보스");
        m_meviusAnimation = ANIMATION->findAnimation("애니보스");
        ANIMATION->start("애니보스");
        m_isIdle = false;
        m_isCasting = true;
    }
    //등장씬 끝
}

void Cmevius::defaultState()
{
    for (size_t i = 0; i < 15; i++)
    {
        bossFire(m_meviusRc.left + (m_meviusRc.right - m_meviusRc.left) / 2, m_meviusRc.top + (m_meviusRc.bottom - m_meviusRc.top) / 2,(m_bossAngle+i)*0.42, 5.0f, 400, "보스공", "애니공");
        bossFire(m_meviusRc.left + (m_meviusRc.right - m_meviusRc.left) / 2, m_meviusRc.top + (m_meviusRc.bottom - m_meviusRc.top) / 2, PI*(m_bossAngle + i) * 0.24, 4.0f, 400, "보스공", "애니공");
        bossFire(m_meviusRc.left + (m_meviusRc.right - m_meviusRc.left) / 2, m_meviusRc.top + (m_meviusRc.bottom - m_meviusRc.top) / 2, PI*1.5*(m_bossAngle + i) * 0.2, 3.0f, 400, "보스공", "애니공");

    }

    if (InputManager->isOnceKeyDown('2'))
    {
    }
    if (m_meviusImage != nullptr) {
        m_meviusRc = RectMake(m_x, m_y, m_meviusImage->getFrameWidth(), m_meviusImage->getFrameHeight());
    }
}


void Cmevius::phase1()
{
    //TCHAR str[100];
    //wsprintf(str, "left : %d right : %d  top : %d  bottom : %d", m_meviusRc.left, m_meviusRc.right, m_meviusRc.top, m_meviusRc.bottom);
    //TextOut(getMemDC(), 100, 100, str, lstrlen(str));
    //TCHAR str1[100];
    //wsprintf(str1, "idle : %d walk : %d  casting : %d", m_isIdle,m_isWalking,m_isCasting);
    //TextOut(getMemDC(), 100, 130, str1, lstrlen(str1));
    if (m_meviusImage != nullptr) {
        m_hpBar->mapBossRender();
        IMAGE->findImage("보스체력바")->render(getMemDC(),300,50 );
        m_meviusImage->aniRender(getMapDC(), m_x, m_y, m_meviusAnimation);
        EFFECT->render();
    }
}

void Cmevius::phase2()
{
}

void Cmevius::phase3()
{
}

void Cmevius::meviusState()
{
    switch (m_meviusState)
    {
    case BOSS_STATE::BOSS_STATE_IDLE:
        m_meviusImage = IMAGE->findImage("보스");
        m_meviusAnimation = ANIMATION->findAnimation("애니보스");
        ANIMATION->start("애니보스");
        break;
    case BOSS_STATE::BOSS_STATE_WALKING:
        m_meviusImage = IMAGE->findImage("보스걷기");
        m_meviusAnimation = ANIMATION->findAnimation("애니걷기");
        ANIMATION->start("애니걷기");
        break;
    case BOSS_STATE::BOSS_STATE_CASTING:
        m_meviusImage = IMAGE->findImage("보스캐스팅");
        m_meviusAnimation = ANIMATION->findAnimation("애니캐스팅");
        ANIMATION->start("애니캐스팅");
        break;
    case BOSS_STATE::BOSS_STATE_LEVITATING:
        m_meviusImage = IMAGE->findImage("보스공중");
        m_meviusAnimation = ANIMATION->findAnimation("애니공중");
        ANIMATION->start("애니공중");
        break;
    case BOSS_STATE::BOSS_STATE_DIE:
        m_isDie = true;
        break;
    }

    m_effectCount++;
    if (m_effectCount % 4 == 0)
    {
        EFFECT->play("라이트닝", RND->getFromIntTo(100, WINSIZEX - 100), RND->getFromIntTo(100, WINSIZEY - 100));
    }


}

void Cmevius::coolTime(float time, bool idle, bool walk, bool cast)
{
    TIME->getWorldTime();
    float waitTime;
    waitTime = TIME->getWorldTime();
    if (waitTime + time <= TIME->getWorldTime())
    {
        m_isWalking = walk;
        m_isCasting = cast;
        m_isIdle = idle;
    }
}