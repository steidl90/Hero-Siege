#include "framework.h"
#include "CNPC.h"

HRESULT CNPC::init()
{
    a = true;
    //���븣
    m_garNorImage = IMAGE->findImage("NPC���븣");
    ANIMATION->addDefAnimation("���븣","NPC���븣",10,false,true);
    m_garNorAni = ANIMATION->findAnimation("���븣");
    m_garNorX = 1000;
    m_garNorY = 520;
    
    //��Ű��
    m_shopKeeperImage = IMAGE->findImage("NPC��Ű��");
    ANIMATION->addDefAnimation("��Ű��", "NPC��Ű��",10, false, true);
    m_shopKeeperAni = ANIMATION->findAnimation("��Ű��");
    m_shopKeeperX = 450;
    m_shopKeeperY = 560;

    //������
    m_blackMarketImage = IMAGE->findImage("NPC������");
    ANIMATION->addDefAnimation("������", "NPC������",10, false, true);
    m_blackMarketAni = ANIMATION->findAnimation("������");
    m_blackMarketX = 1320;
    m_blackMarketY = 660;

    //�������
    m_edwardImage = IMAGE->findImage("NPC�������");
    ANIMATION->addDefAnimation("�������", "NPC�������", 10, false, true);
    m_edwardAni = ANIMATION->findAnimation("�������");
    m_edwardX = 670;
    m_edwardY = 530;

    //����
    m_ericImage = IMAGE->findImage("NPC����");
    ANIMATION->addDefAnimation("����", "NPC����", 10, false, true);
    m_ericAni = ANIMATION->findAnimation("����");
    m_ericX = 315;
    m_ericY = 210;

    //�ҽ�����
    m_halsteinImage = IMAGE->findImage("NPC�ҽ�����");
    ANIMATION->addDefAnimation("�ҽ�����", "NPC�ҽ�����", 10, false, true);
    m_halsteinAni = ANIMATION->findAnimation("�ҽ�����");
    m_halsteinX = 1490;
    m_halsteinY = 510;
   
    //ī�ϸ���
    m_kaylaImage=IMAGE->findImage("NPCī�ϸ���");
    ANIMATION->addDefAnimation("ī�ϸ���", "NPCī�ϸ���", 10, false, true);
    m_kaylaAni = ANIMATION->findAnimation("ī�ϸ���");
    m_kaylaX = 440;
    m_kaylaY = 1120;

    //��ĳ����
    m_sarcasterImage = IMAGE->findImage("NPC��ĳ����");
    ANIMATION->addDefAnimation("��ĳ����", "NPC��ĳ����", 10, false, true);
    m_sarcasterAni = ANIMATION->findAnimation("��ĳ����");
    m_sarcasterX = 200;
    m_sarcasterY = 1480;

    //�佺����
    m_torsteinImage = IMAGE->findImage("NPC�佺����");
    ANIMATION->addDefAnimation("�佺����", "NPC�佺����", 10, false, true);
    m_torsteinAni = ANIMATION->findAnimation("�佺����");
    m_torsteinX = 1150;
    m_torsteinY = 1360;

    //��ġ
    m_witchImage = IMAGE->findImage("NPC��ġ");
    ANIMATION->addDefAnimation("��ġ", "NPC��ġ", 10, false, true);
    m_witchAni = ANIMATION->findAnimation("��ġ");
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
     
    //���븣
    m_garNorImage->aniRender(getMapDC(), m_garNorX, m_garNorY, m_garNorAni);
    IMAGE->findImage("���ñ׸���")->alphaRender(getMapDC(), m_garNorX, m_garNorY)
    //��Ű��
    m_shopKeeperImage->aniRender(getMapDC(), m_shopKeeperX, m_shopKeeperY, m_shopKeeperAni);
    //������
    m_blackMarketImage->aniRender(getMapDC(), m_blackMarketX, m_blackMarketY, m_blackMarketAni);
    //�������
    m_edwardImage->aniRender(getMapDC(), m_edwardX, m_edwardY, m_edwardAni);
    //����
    m_ericImage->aniRender(getMapDC(), m_ericX, m_ericY, m_ericAni);
    //�ҽ�����
    m_halsteinImage->aniRender(getMapDC(), m_halsteinX, m_halsteinY, m_halsteinAni);
    //ī�ϸ���
    m_kaylaImage->aniRender(getMapDC(), m_kaylaX, m_kaylaY, m_kaylaAni);
    //��ĳ����
    m_sarcasterImage->aniRender(getMapDC(), m_sarcasterX, m_sarcasterY, m_sarcasterAni);
    //�佺����
    m_torsteinImage->aniRender(getMapDC(), m_torsteinX, m_torsteinY, m_torsteinAni);
    //��ġ
    m_witchImage->aniRender(getMapDC(), m_witchX, m_witchY, m_witchAni);
    if (a)
    {
        getNpcAni();
        a = false;
    }
}

void CNPC::getNpcAni()
{
    ANIMATION->start("���븣");
    ANIMATION->start("��Ű��");
    ANIMATION->start("������");
    ANIMATION->start("�������");
    ANIMATION->start("����");
    ANIMATION->start("�ҽ�����");
    ANIMATION->start("ī�ϸ���");
    ANIMATION->start("��ĳ����");
    ANIMATION->start("�佺����");
    ANIMATION->start("��ġ");

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
