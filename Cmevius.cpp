#include "framework.h"
#include "Cmevius.h"
Cmevius::Cmevius()
{
    m_meviusImage = nullptr;
}

Cmevius::~Cmevius()
{
}

HRESULT Cmevius::init()
{
    m_em = new CenemyManager;
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

    m_x = WINSIZEX / 2;
    m_y = -50;
    m_speed = 2;
    return S_OK;
}

void Cmevius::release()
{
    SAFE_DELETE(m_meviusImage);
}

void Cmevius::update()
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

    if (m_isCasting && InputManager->isOnceKeyDown('3'))
    {
        m_meviusImage = IMAGE->findImage("보스캐스팅");
        m_meviusAnimation = ANIMATION->findAnimation("애니캐스팅2");
        ANIMATION->start("애니캐스팅2");

    }

    if (InputManager->isOnceKeyDown('2'))
    {
        init();
    }
    if (m_meviusImage != nullptr) {
        m_meviusRc = RectMake(m_x, m_y, m_meviusImage->getFrameWidth(), m_meviusImage->getFrameHeight());
    }
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
        m_meviusImage->aniRender(getMapDC(), m_x, m_y, m_meviusAnimation);
        EFFECT->render();

    }
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
    case BOSS_STATE::BOSS_STATE_LEVITATIN:
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
        //EFFECT->play("라이트닝", RND->getFromIntTo(100, WINSIZEX - 100), RND->getFromIntTo(100, WINSIZEY - 100));
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