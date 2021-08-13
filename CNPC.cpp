#include "framework.h"
#include "CNPC.h"

HRESULT CNPC::init()
{
    //���븣
    m_garNorImage = IMAGE->findImage("NPC���븣");
    ANIMATION->addDefAnimation("���븣","NPC���븣",2,false,true);
    m_garNorX = 1000;
    m_garNorY = 508;
    
    //��Ű��
    m_shopKeeperImage = IMAGE->findImage("NPC��Ű��");
    ANIMATION->addDefAnimation("��Ű��", "NPC��Ű��",10, false, true);
    m_shopKeeperX = 450;
    m_shopKeeperY = 546;

    //������
    m_blackMarketImage = IMAGE->findImage("NPC������");
    ANIMATION->addDefAnimation("������", "NPC������",10, false, true);
    m_blackMarketX = 1320;
    m_blackMarketY = 648;

    //�������
    m_edwardImage = IMAGE->findImage("NPC�������");
    ANIMATION->addDefAnimation("�������", "NPC�������", 2, false, true);
    m_edwardX = 670;
    m_edwardY = 518;

    //����
    m_ericImage = IMAGE->findImage("NPC����");
    ANIMATION->addDefAnimation("����", "NPC����", 2, false, true);
    m_ericX = 315;
    m_ericY = 198;

    //�ҽ�����
    m_halsteinImage = IMAGE->findImage("NPC�ҽ�����");
    ANIMATION->addDefAnimation("�ҽ�����", "NPC�ҽ�����", 2, false, true);
    m_halsteinX = 1490;
    m_halsteinY = 490;
    return S_OK;

    //ī�ϸ���
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

    //���븣
    //Rectangle(getMapDC(),m_garNorRc.left, m_garNorRc.top, m_garNorRc.right, m_garNorRc.bottom);
    m_garNorImage->aniRender(getMapDC(), m_garNorX, m_garNorY, m_garNorAni);
    //��Ű��
    //Rectangle(getMapDC(), m_shopKeeperRc.left, m_shopKeeperRc.top, m_shopKeeperRc.right, m_shopKeeperRc.bottom);
    m_shopKeeperImage->aniRender(getMapDC(), m_shopKeeperX, m_shopKeeperY, m_shopKeeperAni);
    //������
    //Rectangle(getMapDC(), m_blackMarketRc.left, m_blackMarketRc.top, m_blackMarketRc.right, m_blackMarketRc.bottom);
    m_blackMarketImage->aniRender(getMapDC(), m_blackMarketX, m_blackMarketY, m_blackMarketAni);
    //�������
   // Rectangle(getMapDC(), m_edwardRc.left, m_edwardRc.top, m_edwardRc.right, m_edwardRc.bottom);
    m_edwardImage->aniRender(getMapDC(), m_edwardX, m_edwardY, m_edwardAni);
    //����
    //Rectangle(getMapDC(), m_ericRc.left, m_ericRc.top, m_ericRc.right, m_ericRc.bottom);
    m_ericImage->aniRender(getMapDC(), m_ericX, m_ericY, m_ericAni);
    //�ҽ�����
    //Rectangle(getMapDC(), m_halsteinRc.left, m_halsteinRc.top, m_halsteinRc.right, m_halsteinRc.bottom);
    m_halsteinImage->aniRender(getMapDC(), m_halsteinX, m_halsteinY, m_halsteinAni);

    if (a)
    {
        a = false;
    }
}

void CNPC::getNpcAni()
{
    //���븣
    m_garNorAni = ANIMATION->findAnimation("���븣");
    ANIMATION->resume("���븣");

    //��Ű��
    m_shopKeeperAni = ANIMATION->findAnimation("��Ű��");
    ANIMATION->start("��Ű��");
    
    //������
    m_blackMarketAni = ANIMATION->findAnimation("������");
    ANIMATION->start("������");

    //�������
    m_edwardAni = ANIMATION->findAnimation("�������");
    ANIMATION->start("�������");

    //����
    m_ericAni= ANIMATION->findAnimation("����");
    ANIMATION->start("����");

    //�ҽ�����
    m_halsteinAni= ANIMATION->findAnimation("�ҽ�����");
    ANIMATION->start("�ҽ�����");

}
