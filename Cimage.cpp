#include "framework.h"
#include "Cimage.h"

Cimage::Cimage()
{
}

Cimage::~Cimage()
{
}

HRESULT Cimage::init()
{
    /*  ��� �̹��� �̹����Ŵ����� �߰��ϴ� �뵵  */
    /*  ��� �̹��� �̹����Ŵ����� �߰��ϴ� �뵵  */
    /*  ��� �̹��� �̹����Ŵ����� �߰��ϴ� �뵵  */
    /*  ������ ���ǿ��� �������̹����� �ƴ� �̹����� �����ض�  */
    /*  ������ ���ǿ��� �������̹����� �ƴ� �̹����� �����ض�  */
    /*  ������ ���ǿ��� �������̹����� �ƴ� �̹����� �����ض�  */

    //=================Player=================//
    IMAGE->addFrameImage("�÷��̾����ʰȱ�", "images/WalkingAmazonUp.bmp", 168, 59, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾�����", "images/IdleAmazoneUP.bmp", 168, 59, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾����ʰ���", "images/AttackAmazonUp.bmp", 186, 112, 6, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("�÷��̾�����ʰȱ�", "images/WalkingAmazonRight.bmp", 384, 44, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾������", "images/IdleAmazoneRight.bmp", 384, 44, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾�����ʰ���", "images/AttackAmazonRight.bmp", 666, 43, 6, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("�÷��̾���ʰȱ�", "images/WalkingAmazonLeft.bmp", 384, 44, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾����", "images/IdleAmazoneLeft.bmp", 384, 44, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾���ʰ���", "images/AttackAmazonLeft.bmp", 666, 43, 6, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("�÷��̾�Ʒ��ʰȱ�", "images/WalkingAmazonDown.bmp", 186, 69, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾�Ʒ���", "images/IdleAmazoneDown.bmp", 186, 69, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾�Ʒ��ʰ���", "images/AttackAmazonDown.bmp", 192, 120, 6, 1, true, RGB(255, 0, 255));


    //=================NPC====================//
    IMAGE->addFrameImage("NPC������", "images/BlackMarketNPC.bmp", 798, 121, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC�������", "images/Edward.bmp", 136, 34, 4, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC����", "images/Eric.bmp", 120, 31, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC���븣", "images/GarNor.bmp", 280, 34, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC�ҽ�����", "images/Halstein.bmp", 152, 46, 4, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPCī�ϸ���", "images/Kayla.bmp", 120, 32, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC��ĳ����", "images/Sarcaster.bmp", 184, 33, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC��Ű��", "images/ShopKeeper.bmp", 184, 37, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC�佺����", "images/Torstein.bmp", 612, 41, 17, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC��ġ", "images/Witch.bmp", 120, 62, 5, 1, true, RGB(255, 0, 255));

    


    //=================Enemy=================//
    IMAGE->addFrameImage("��ġ", "images/Priest.bmp", 300, 316, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��ġ����", "images/PriestAttack.bmp", 848, 316, 16, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��ġ���", "images/PriestDie.bmp", 490, 564, 10, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��ġ��ų", "images/PriestSkill.bmp", 696, 61, 12, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("������Ż", "images/Elemental.bmp", 252, 268, 4, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������Ż��ų1", "images/ElementalSkill1.bmp", 162, 18, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������Ż��ų2", "images/ElementalSkill2.bmp", 480, 40, 8, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("������", "images/GreenSlime.bmp", 138, 18, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�����Ӱ���", "images/GreenSlimeAttack.bmp", 480, 152, 12, 4, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("��ũ", "images/Monk.bmp", 264, 300, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��ũ����", "images/MonkAttack.bmp", 360, 336, 5, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��ũ���", "images/MonkDie.bmp", 912, 444, 12, 4, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("������", "images/PrisonGuard.bmp", 456, 320, 8, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("����������", "images/PrisonGuardAttack.bmp", 1120, 440, 8, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���������", "images/PrisonGuardDie.bmp", 1261, 360, 13, 4, true, RGB(255, 0, 255));


    //=================Boss==================//
    IMAGE->addFrameImage("����", "images/Mevius.bmp", 360, 143, 4, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("����ĳ����", "images/MeviusCasting.bmp", 1800, 143, 20, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("����ü��", "images/MeviusChains.bmp", 211, 17, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��������", "images/MeviusLevitating.bmp", 90, 146, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������", "images/MeviusLight.bmp", 87, 1042, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��������", "images/MeviusMonster.bmp", 1218, 153, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�����ȱ�", "images/MeviusWalking.bmp", 720, 148, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������", "images/MeviusWall.bmp", 256, 192, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������", "images/MeviusSpikeBall.bmp", 329, 54, 7, 1, true, RGB(255, 0, 255));


    //=================Object=================//
    //IMAGE->addFrameImage("������", "images/������.bmp", 1020, 200, 6, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("��������", "images/��������.bmp", 1520, 182, 10, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("��������", "images/Tile-2.bmp", 648, 288, 18, 8, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("���", "images/Pillar.bmp", 222, 87, 6, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("��Ÿ������", "images/FanceVertical.bmp", 8, 88, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("��Ÿ������", "images/FanceHorizontal.bmp", 72, 24, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("â��", "images/Chest.bmp", 83, 49, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("ǳ��", "images/Windmill.bmp", 152, 343, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("��1", "images/House1.bmp", 378, 432, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("��2", "images/House2.bmp", 458, 290, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("��3", "images/House3.bmp", 482, 332, 1, 1, true, RGB(255, 0, 255));
    //IMAGE->addFrameImage("��4", "images/House4.bmp", 226, 221, 1, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("���ʷ�����", "images/Generator.bmp", 485, 67, 5, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�뱤��", "images/Furnace.bmp", 280, 30, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("����", "images/Lamp.bmp", 960, 98, 16, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��������Ʈ", "images/WayPoint.bmp", 1304, 137, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��Ż", "images/Portal.bmp", 330, 66, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("����Ʈ", "images/Gate.bmp", 468, 87, 6, 1, true, RGB(255, 0, 255));
    
    IMAGE->addFrameImage("ūǮ", "images/GrassBig.bmp", 408, 31, 12, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("����Ǯ1", "images/GrassSmall1.bmp", 152, 19, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("����Ǯ2", "images/GrassSmall2.bmp", 160, 17, 8, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("Ŀ����", "images/CoffeeHouse.bmp", 904, 152, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("ǳ������", "images/WindmillWing.bmp", 2016, 339, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������ƮŸ��1", "images/ObjectTile.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������ƮŸ��2", "images/ObjectTile2.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������ƮŸ��3", "images/ObjectTile3.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������ƮŸ��4", "images/ObjectTile4.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������ƮŸ��5", "images/ObjectTile5.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));


    //=================item=================//
    IMAGE->addFrameImage("�Źߺ�", "images/�Źߺ�.bmp", 384, 320, 7, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�Ź߽���", "images/�Ź߽���.bmp", 224, 128, 7, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���ʺ�", "images/���ʺ�.bmp", 528, 528, 6, 6, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���ʽ���", "images/���ʽ���.bmp", 264, 264, 6, 6, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�����", "images/�����.bmp", 623, 111, 7, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���Ʈ��", "images/���Ʈ��.bmp", 384, 256, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���Ʈ����", "images/���Ʈ����.bmp", 210, 140, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�尩��", "images/�尩��.bmp", 576, 192, 9, 3, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�尩����", "images/�尩����.bmp", 288, 96, 9, 3, true, RGB(255, 0, 255));

    //==================UI==================//
    IMAGE->addFrameImage("������", "images/LevelUP.bmp", 183, 55, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("HUD", "images/HUD.bmp", 361, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��ư1", "images/Button1.bmp", 208, 39, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��ư2", "images/Button2.bmp", 210, 41, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�κ��丮1", "images/Inventory1.bmp", 469, 473, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�κ��丮2", "images/Inventory2.bmp", 389, 465, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�κ��丮3", "images/Inventory3.bmp", 858, 473, 1, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("���þƸ���", "images/ChooseAmazon.bmp", 186, 69, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���õ���", "images/ChooseDemon.bmp", 264, 46, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���õ��󽽷��̾�", "images/ChooseDemonSlayer.bmp", 132, 40, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���÷���", "images/ChooseLancer.bmp", 234, 65, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���øӷδ�", "images/ChooseMarauder.bmp", 450, 60, 10, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���ø�ũ��", "images/ChooseMarksman.bmp", 252, 37, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���ó�ũ�θǼ�", "images/ChooseNecroMancer.bmp", 208, 33, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���ó븶��", "images/ChooseNomad.bmp", 540, 49, 9, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�����ȶ��", "images/ChoosePaladin.bmp", 216, 40, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�������̷�", "images/ChoosePirate.bmp", 510, 45, 15, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���÷����", "images/ChooseRedneck.bmp", 234, 35, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���û繫����", "images/ChooseSamurai.bmp", 336, 49, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���û���", "images/ChooseShaman.bmp", 228, 43, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���ý�ƽ��", "images/ChooseStickMan.bmp", 138, 42, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("����ȭ��Ʈ������", "images/ChooseWhiteMage.bmp", 180, 37, 6, 1, true, RGB(255, 0, 255));

    //==================ECT=================//
    IMAGE->addFrameImage("��Ʈ", "images/Hit.bmp", 414, 71, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("����Ʈ1", "images/Quest1.bmp", 48, 25, 3, 1, true, RGB(255, 0, 255));

    IMAGE->addImage("����Ʈ2", "images/Quest2.bmp", 9, 25, true, RGB(255, 0, 255));





    return S_OK;
}

void Cimage::release()
{
}

void Cimage::update()
{
}

void Cimage::render()
{
}
