#include "framework.h"
#include "CNPC.h"

HRESULT CNPC::init()
{
    //가노르
    m_garNorImage = IMAGE->findImage("NPC가노르");
    ANIMATION->addDefAnimation("가노르","NPC가노르",2,false,true);
    m_garNorX = 1000;
    m_garNorY = 508;
    
    //샵키퍼
    m_shopKeeperImage = IMAGE->findImage("NPC샵키퍼");
    ANIMATION->addDefAnimation("샵키퍼", "NPC샵키퍼",10, false, true);
    m_shopKeeperX = 450;
    m_shopKeeperY = 546;

    //블랙마켓
    m_blackMarketImage = IMAGE->findImage("NPC블랙마켓");
    ANIMATION->addDefAnimation("블랙마켓", "NPC블랙마켓",10, false, true);
    m_blackMarketX = 1320;
    m_blackMarketY = 648;

    //에드워드
    m_edwardImage = IMAGE->findImage("NPC에드워드");
    ANIMATION->addDefAnimation("에드워드", "NPC에드워드", 2, false, true);
    m_edwardX = 670;
    m_edwardY = 518;

    //에릭
    m_ericImage = IMAGE->findImage("NPC에릭");
    ANIMATION->addDefAnimation("에릭", "NPC에릭", 2, false, true);
    m_ericX = 315;
    m_ericY = 198;

    //할스테인
    m_halsteinImage = IMAGE->findImage("NPC할스테인");
    ANIMATION->addDefAnimation("할스테인", "NPC할스테인", 2, false, true);
    m_halsteinX = 1490;
    m_halsteinY = 490;
    return S_OK;

    //카일리아
}

void CNPC::release()
{
}

void CNPC::update()
{
    //getNpcAni();

    m_garNorRc = RectMake(m_garNorX, m_garNorY, m_garNorImage->getFrameWidth(), m_garNorImage->getFrameHeight());
    m_shopKeeperRc = RectMake(m_shopKeeperX, m_shopKeeperY, m_shopKeeperImage->getFrameWidth(), m_shopKeeperImage->getFrameHeight());
    m_blackMarketRc = RectMake(m_blackMarketX, m_blackMarketY, m_blackMarketImage->getFrameWidth(), m_blackMarketImage->getFrameHeight());
    m_edwardRc = RectMake(m_edwardX, m_edwardY, m_edwardImage->getFrameWidth(), m_edwardImage->getFrameHeight());
    m_ericRc = RectMake(m_ericX, m_ericY, m_ericImage->getFrameWidth(), m_ericImage->getFrameHeight());
    m_halsteinRc = RectMake(m_halsteinX, m_halsteinY, m_halsteinImage->getFrameWidth(), m_halsteinImage->getFrameHeight());
}

void CNPC::render()
{

    //가노르
    //Rectangle(getMapDC(),m_garNorRc.left, m_garNorRc.top, m_garNorRc.right, m_garNorRc.bottom);
    m_garNorImage->aniRender(getMapDC(), m_garNorX, m_garNorY, m_garNorAni);
    //샵키퍼
    //Rectangle(getMapDC(), m_shopKeeperRc.left, m_shopKeeperRc.top, m_shopKeeperRc.right, m_shopKeeperRc.bottom);
    m_shopKeeperImage->aniRender(getMapDC(), m_shopKeeperX, m_shopKeeperY, m_shopKeeperAni);
    //블랙마켓
    //Rectangle(getMapDC(), m_blackMarketRc.left, m_blackMarketRc.top, m_blackMarketRc.right, m_blackMarketRc.bottom);
    m_blackMarketImage->aniRender(getMapDC(), m_blackMarketX, m_blackMarketY, m_blackMarketAni);
    //에드워드
   // Rectangle(getMapDC(), m_edwardRc.left, m_edwardRc.top, m_edwardRc.right, m_edwardRc.bottom);
    m_edwardImage->aniRender(getMapDC(), m_edwardX, m_edwardY, m_edwardAni);
    //에릭
    //Rectangle(getMapDC(), m_ericRc.left, m_ericRc.top, m_ericRc.right, m_ericRc.bottom);
    m_ericImage->aniRender(getMapDC(), m_ericX, m_ericY, m_ericAni);
    //할스테인
    //Rectangle(getMapDC(), m_halsteinRc.left, m_halsteinRc.top, m_halsteinRc.right, m_halsteinRc.bottom);
    m_halsteinImage->aniRender(getMapDC(), m_halsteinX, m_halsteinY, m_halsteinAni);

    if (a)
    {
        a = false;
    }
}

void CNPC::getNpcAni()
{
    //가노르
    m_garNorAni = ANIMATION->findAnimation("가노르");
    ANIMATION->resume("가노르");

    //샵키퍼
    m_shopKeeperAni = ANIMATION->findAnimation("샵키퍼");
    ANIMATION->start("샵키퍼");
    
    //블랙마켓
    m_blackMarketAni = ANIMATION->findAnimation("블랙마켓");
    ANIMATION->start("블랙마켓");

    //에드워드
    m_edwardAni = ANIMATION->findAnimation("에드워드");
    ANIMATION->start("에드워드");

    //에릭
    m_ericAni= ANIMATION->findAnimation("에릭");
    ANIMATION->start("에릭");

    //할스테인
    m_halsteinAni= ANIMATION->findAnimation("할스테인");
    ANIMATION->start("할스테인");

}
