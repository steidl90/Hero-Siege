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

    //IMAGE->addFrameImage("보스", "images/Mevius.bmp", 360, 143, 4, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("보스캐스팅", "images/MeviusCasting.bmp", 1800, 143, 20, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("보스체인", "images/MeviusChains.bmp", 211, 17, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("보스공중", "images/MeviusLevitating.bmp", 90, 146, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("보스빛", "images/MeviusLight.bmp", 87, 1042, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("보스몬스터", "images/MeviusMonster.bmp", 1218, 153, 6, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("보스걷기", "images/MeviusWalking.bmp", 720, 148, 8, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("보스벽", "images/MeviusWall.bmp", 256, 192, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("보스공", "images/MeviusSpikeBall.bmp", 329, 54, 7, 1, true, RGB(255, 0, 255));
    //Cimage* m_mevius;
    //image* m_meviusImage;
    //animation* m_meviusAnimation;
    //effect* m_meviusEffect;

	ANIMATION->addDefAnimation("애니공중", "보스공중", 10, false, true);
    ANIMATION->addDefAnimation("애니보스", "보스", 5, false, true);
    ANIMATION->addDefAnimation("애니캐스팅", "보스캐스팅", 10, false, false);
    ANIMATION->addDefAnimation("애니캐스팅2", "보스캐스팅", 10, true, false);
    ANIMATION->addDefAnimation("애니걷기", "보스걷기", 3, false, false);
    ANIMATION->addDefAnimation("애니공", "보스공", 10, false, true);
    EFFECT->addEffect("라이트닝", "images/Lightning.bmp", 576, 402, 72, 402, 1, 0.25f, 100);
    EFFECT->addEffect("스텀프", "images/Stomp.bmp", 819*2, 78*2, 91*2, 78*2, 1, 0.2f, 200);

    m_isEffect = false;
    m_isAppear = false;
	m_isWalking = false;
	m_isCasting = false;
	m_isIdle = false;
	m_isDie = false;

    m_x = WINSIZEX / 2;
    m_y = -50;
    m_speed = 1;
    return S_OK;
}

void Cmevius::release()
{
    SAFE_DELETE(m_meviusImage);
}

void Cmevius::update()
{
    m_effectCount++;

    if (InputManager->isOnceKeyDown(VK_LBUTTON))
    {
        EFFECT->play("라이트닝", m_ptMouse.x, m_ptMouse.y);
    }

    if (InputManager->isOnceKeyDown('1'))
    {
        m_isAppear = true;
        m_isEffect = true;
    }

    if (m_isEffect)
    {
        if (m_effectCount % 4 == 0)
        {
            EFFECT->play("라이트닝", RND->getFromIntTo(100, WINSIZEX - 100), RND->getFromIntTo(100, WINSIZEY - 100));
            //EFFECT->play("라이트닝", RND->getFromIntTo(100, WINSIZEX - 100), RND->getFromIntTo(100, WINSIZEY - 100));
        }
    }

    if (m_isAppear)
    {
        m_meviusImage = IMAGE->findImage("보스공중");
        m_meviusAnimation = ANIMATION->findAnimation("애니공중");
        ANIMATION->start("애니공중");
        if (m_meviusRc.top <= 200)
		{
			m_y += m_speed;
		}
		else
		{
			m_coolTime++;
			if (m_coolTime == 50)
			{
				m_isEffect = false;
				m_isAppear = false;
				m_isWalking = true;
                m_isIdle = true;
			EFFECT->play("스텀프", m_meviusRc.left + (m_meviusRc.right - m_meviusRc.left) / 2, m_meviusRc.bottom);
                m_coolTime = 0;
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

	if (!m_isAppear && !m_isWalking && m_meviusRc.top <= 230)
	{
		m_y += 0.2f;
	}

    if (m_meviusRc.top >= 230 && m_isIdle)
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
    TCHAR str[100];
    wsprintf(str, "left : %d right : %d  top : %d  bottom : %d", m_meviusRc.left, m_meviusRc.right, m_meviusRc.top, m_meviusRc.bottom);
    TextOut(getMemDC(), 100, 100, str, lstrlen(str));
    TCHAR str1[100];
    wsprintf(str1, "idle : %d walk : %d  casting : %d", m_isIdle,m_isWalking,m_isCasting);
    TextOut(getMemDC(), 100, 130, str1, lstrlen(str1));
    if (m_meviusImage != nullptr) {
        Rectangle(getMapDC(), m_meviusRc.left, m_meviusRc.top, m_meviusRc.right, m_meviusRc.bottom);
        m_meviusImage->aniRender(getMapDC(), m_x, m_y, m_meviusAnimation);
        
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
