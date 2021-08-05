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

    //IMAGE->addFrameImage("����", "images/Mevius.bmp", 360, 143, 4, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("����ĳ����", "images/MeviusCasting.bmp", 1800, 143, 20, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("����ü��", "images/MeviusChains.bmp", 211, 17, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("��������", "images/MeviusLevitating.bmp", 90, 146, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("������", "images/MeviusLight.bmp", 87, 1042, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("��������", "images/MeviusMonster.bmp", 1218, 153, 6, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("�����ȱ�", "images/MeviusWalking.bmp", 720, 148, 8, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("������", "images/MeviusWall.bmp", 256, 192, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("������", "images/MeviusSpikeBall.bmp", 329, 54, 7, 1, true, RGB(255, 0, 255));
    //Cimage* m_mevius;
    //image* m_meviusImage;
    //animation* m_meviusAnimation;
    //effect* m_meviusEffect;

	ANIMATION->addDefAnimation("�ִϰ���", "��������", 10, false, true);
    ANIMATION->addDefAnimation("�ִϺ���", "����", 5, false, true);
    ANIMATION->addDefAnimation("�ִ�ĳ����", "����ĳ����", 10, false, false);
    ANIMATION->addDefAnimation("�ִϰȱ�", "�����ȱ�2", 10, false, false);
    ANIMATION->addDefAnimation("�ִϰ�", "������", 10, false, true);
    EFFECT->addEffect("����Ʈ��", "images/Lightning.bmp", 576, 402, 72, 402, 1, 0.35f, 100);
    EFFECT->addEffect("������", "images/Stomp.bmp", 819*2, 78*2, 91*2, 78*2, 1, 0.2f, 200);
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
    if (m_effectCount % 10 == 0) 
    {
        EFFECT->play("����Ʈ��", RND->getFromIntTo(100, WINSIZEX - 100), RND->getFromIntTo(100, WINSIZEY - 100));
        EFFECT->play("����Ʈ��", RND->getFromIntTo(100, WINSIZEX - 100), RND->getFromIntTo(100, WINSIZEY - 100));
    }

    if (InputManager->isOnceKeyDown(VK_LBUTTON))
    {
        EFFECT->play("����Ʈ��", m_ptMouse.x, m_ptMouse.y);
    }

    if (InputManager->isOnceKeyDown('1'))
    {
        m_isAppear = true;
    }

    if (m_isAppear)
    {
        m_meviusImage = IMAGE->findImage("��������");
        m_meviusAnimation = ANIMATION->findAnimation("�ִϰ���");
        ANIMATION->start("�ִϰ���");
        if (m_meviusRc.top <= 200)
        {
            m_y += m_speed;
        }
        else
        {
            m_isAppear = false;
            m_isWalking = true;
        EFFECT->play("������", m_meviusRc.left +(m_meviusRc.right- m_meviusRc.left)/2, m_meviusRc.bottom);
        }
    }

    if (m_isWalking)
    {
        m_isWalking = false;
        m_meviusImage = IMAGE->findImage("�����ȱ�2");
        m_meviusAnimation = ANIMATION->findAnimation("�ִϰȱ�");
        ANIMATION->start("�ִϰȱ�");
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
    //wsprintf(str, "x : %d y : %d", , m_y);
    //TextOut(getMemDC(), 100, 100, str, lstrlen(str));
    if (m_meviusImage != nullptr) {
        //Rectangle(getMemDC(), m_meviusRc.left, m_meviusRc.top, m_meviusRc.right, m_meviusRc.bottom);
        m_meviusImage->aniRender(getMemDC(), m_x, m_y, m_meviusAnimation);
        
    }
}

void Cmevius::meviusState()
{
    switch (m_meviusState)
    {
    case BOSS_STATE::BOSS_STATE_IDLE:
        m_meviusImage = IMAGE->findImage("����");
        m_meviusAnimation = ANIMATION->findAnimation("�ִϺ���");
        ANIMATION->start("�ִϺ���");
        break;
    case BOSS_STATE::BOSS_STATE_WALKING:
        m_meviusImage = IMAGE->findImage("�����ȱ�");
        m_meviusAnimation = ANIMATION->findAnimation("�ִϰȱ�");
        ANIMATION->start("�ִϰȱ�");
        break;
    case BOSS_STATE::BOSS_STATE_CASTING:
        m_meviusImage = IMAGE->findImage("����ĳ����");
        m_meviusAnimation = ANIMATION->findAnimation("�ִ�ĳ����");
        ANIMATION->start("�ִ�ĳ����");
        break;
    case BOSS_STATE::BOSS_STATE_LEVITATIN:
        m_meviusImage = IMAGE->findImage("��������");
        m_meviusAnimation = ANIMATION->findAnimation("�ִϰ���");
        ANIMATION->start("�ִϰ���");
        break;
    case BOSS_STATE::BOSS_STATE_DIE:
        m_isDie = true;
        break;
    }
}
