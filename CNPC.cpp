#include "framework.h"
#include "CNPC.h"

HRESULT CNPC::init()
{
    a = true;
    //가노르
    m_garNorImage = IMAGE->findImage("NPC가노르");
    ANIMATION->addDefAnimation("가노르","NPC가노르",10,false,true);
    m_garNorAni = ANIMATION->findAnimation("가노르");
    m_garNorX = 1000;
    m_garNorY = 520;
    
    //샵키퍼
    m_shopKeeperImage = IMAGE->findImage("NPC샵키퍼");
    ANIMATION->addDefAnimation("샵키퍼", "NPC샵키퍼",10, false, true);
    m_shopKeeperAni = ANIMATION->findAnimation("샵키퍼");
    m_shopKeeperX = 450;
    m_shopKeeperY = 560;

    //블랙마켓
    m_blackMarketImage = IMAGE->findImage("NPC블랙마켓");
    ANIMATION->addDefAnimation("블랙마켓", "NPC블랙마켓",10, false, true);
    m_blackMarketAni = ANIMATION->findAnimation("블랙마켓");
    m_blackMarketX = 1320;
    m_blackMarketY = 660;

    //에드워드
    m_edwardImage = IMAGE->findImage("NPC에드워드");
    ANIMATION->addDefAnimation("에드워드", "NPC에드워드", 10, false, true);
    m_edwardAni = ANIMATION->findAnimation("에드워드");
    m_edwardX = 670;
    m_edwardY = 530;

    //에릭
    m_ericImage = IMAGE->findImage("NPC에릭");
    ANIMATION->addDefAnimation("에릭", "NPC에릭", 10, false, true);
    m_ericAni = ANIMATION->findAnimation("에릭");
    m_ericX = 315;
    m_ericY = 210;

    //할스테인
    m_halsteinImage = IMAGE->findImage("NPC할스테인");
    ANIMATION->addDefAnimation("할스테인", "NPC할스테인", 10, false, true);
    m_halsteinAni = ANIMATION->findAnimation("할스테인");
    m_halsteinX = 1490;
    m_halsteinY = 510;
   
    //카일리아
    m_kaylaImage=IMAGE->findImage("NPC카일리아");
    ANIMATION->addDefAnimation("카일리아", "NPC카일리아", 10, false, true);
    m_kaylaAni = ANIMATION->findAnimation("카일리아");
    m_kaylaX = 440;
    m_kaylaY = 1120;

    //사캐스터
    m_sarcasterImage = IMAGE->findImage("NPC사캐스터");
    ANIMATION->addDefAnimation("사캐스터", "NPC사캐스터", 10, false, true);
    m_sarcasterAni = ANIMATION->findAnimation("사캐스터");
    m_sarcasterX = 200;
    m_sarcasterY = 1480;

    //토스테인
    m_torsteinImage = IMAGE->findImage("NPC토스테인");
    ANIMATION->addDefAnimation("토스테인", "NPC토스테인", 10, false, true);
    m_torsteinAni = ANIMATION->findAnimation("토스테인");
    m_torsteinX = 1150;
    m_torsteinY = 1360;

    //위치
    m_witchImage = IMAGE->findImage("NPC위치");
    ANIMATION->addDefAnimation("위치", "NPC위치", 10, false, true);
    m_witchAni = ANIMATION->findAnimation("위치");
    m_witchX = 520;
    m_witchY = 220;

    return S_OK;
}

void CNPC::release()
{
}

void CNPC::update()
{
    m_garNorRc = RectMake(m_garNorX, m_garNorY, m_garNorImage->getFrameWidth(), m_garNorImage->getFrameHeight());
    m_shopKeeperRc = RectMake(m_shopKeeperX, m_shopKeeperY, m_shopKeeperImage->getFrameWidth(), m_shopKeeperImage->getFrameHeight());
    m_blackMarketRc = RectMake(m_blackMarketX, m_blackMarketY, m_blackMarketImage->getFrameWidth(), m_blackMarketImage->getFrameHeight());
    m_edwardRc = RectMake(m_edwardX, m_edwardY, m_edwardImage->getFrameWidth(), m_edwardImage->getFrameHeight());
    m_ericRc = RectMake(m_ericX, m_ericY, m_ericImage->getFrameWidth(), m_ericImage->getFrameHeight());
    m_halsteinRc = RectMake(m_halsteinX, m_halsteinY, m_halsteinImage->getFrameWidth(), m_halsteinImage->getFrameHeight());
    m_kaylaRc = RectMake(m_kaylaX, m_kaylaY, m_kaylaImage->getFrameWidth(), m_kaylaImage->getFrameHeight());
    m_sarcasterRc = RectMake(m_sarcasterX, m_sarcasterY, m_sarcasterImage->getFrameWidth(), m_sarcasterImage->getFrameHeight());
    m_torsteinRc = RectMake(m_torsteinX, m_torsteinY, m_torsteinImage->getFrameWidth(), m_torsteinImage->getFrameHeight());
    m_witchRc = RectMake(m_witchX, m_witchY, m_witchImage->getFrameWidth(), m_witchImage->getFrameHeight());
}

void CNPC::render()
{
    
    if(InputManager->isToggleKey(VK_F1)) getNpcRectangle();
     
    //가노르
    m_garNorImage->aniRender(getMapDC(), m_garNorX, m_garNorY, m_garNorAni);
    IMAGE->findImage("선택그림자")->alphaRender(getMapDC(), m_garNorX, m_garNorY)
    //샵키퍼
    m_shopKeeperImage->aniRender(getMapDC(), m_shopKeeperX, m_shopKeeperY, m_shopKeeperAni);
    //블랙마켓
    m_blackMarketImage->aniRender(getMapDC(), m_blackMarketX, m_blackMarketY, m_blackMarketAni);
    //에드워드
    m_edwardImage->aniRender(getMapDC(), m_edwardX, m_edwardY, m_edwardAni);
    //에릭
    m_ericImage->aniRender(getMapDC(), m_ericX, m_ericY, m_ericAni);
    //할스테인
    m_halsteinImage->aniRender(getMapDC(), m_halsteinX, m_halsteinY, m_halsteinAni);
    //카일리아
    m_kaylaImage->aniRender(getMapDC(), m_kaylaX, m_kaylaY, m_kaylaAni);
    //사캐스터
    m_sarcasterImage->aniRender(getMapDC(), m_sarcasterX, m_sarcasterY, m_sarcasterAni);
    //토스테인
    m_torsteinImage->aniRender(getMapDC(), m_torsteinX, m_torsteinY, m_torsteinAni);
    //위치
    m_witchImage->aniRender(getMapDC(), m_witchX, m_witchY, m_witchAni);
    if (a)
    {
        getNpcAni();
        a = false;
    }
}

void CNPC::getNpcAni()
{
    ANIMATION->start("가노르");
    ANIMATION->start("샵키퍼");
    ANIMATION->start("블랙마켓");
    ANIMATION->start("에드워드");
    ANIMATION->start("에릭");
    ANIMATION->start("할스테인");
    ANIMATION->start("카일리아");
    ANIMATION->start("사캐스터");
    ANIMATION->start("토스테인");
    ANIMATION->start("위치");

}

void CNPC::getNpcRectangle()
{
    Rectangle(getMapDC(),m_garNorRc.left, m_garNorRc.top, m_garNorRc.right, m_garNorRc.bottom);
    Rectangle(getMapDC(), m_shopKeeperRc.left, m_shopKeeperRc.top, m_shopKeeperRc.right, m_shopKeeperRc.bottom);
    Rectangle(getMapDC(), m_blackMarketRc.left, m_blackMarketRc.top, m_blackMarketRc.right, m_blackMarketRc.bottom);
    Rectangle(getMapDC(), m_edwardRc.left, m_edwardRc.top, m_edwardRc.right, m_edwardRc.bottom);
    Rectangle(getMapDC(), m_ericRc.left, m_ericRc.top, m_ericRc.right, m_ericRc.bottom);
    Rectangle(getMapDC(), m_halsteinRc.left, m_halsteinRc.top, m_halsteinRc.right, m_halsteinRc.bottom);
    Rectangle(getMapDC(), m_kaylaRc.left, m_kaylaRc.top, m_kaylaRc.right, m_kaylaRc.bottom);
    Rectangle(getMapDC(), m_sarcasterRc.left, m_sarcasterRc.top, m_sarcasterRc.right, m_sarcasterRc.bottom);
    Rectangle(getMapDC(), m_torsteinRc.left, m_torsteinRc.top, m_torsteinRc.right, m_torsteinRc.bottom);
    Rectangle(getMapDC(), m_witchRc.left, m_witchRc.top, m_witchRc.right, m_witchRc.bottom);
}
