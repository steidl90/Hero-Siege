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
    IMAGE->addFrameImage("�÷��̾����ʰȱ�", "images/WalkingAmazonUp-3.bmp", 756, 118, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾�����", "images/IdleAmazoneUP-1.bmp", 696,107, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾����ʰ���", "images/AttackAmazoneUp.bmp", 1368, 231, 6, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("�÷��̾�����ʰȱ�", "images/WalkingAmazonRight-3.bmp", 756, 118, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾������", "images/IdleAmazoneRight-1.bmp", 696, 107, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾�����ʰ���", "images/AttackAmazoneRight.bmp", 1368, 231, 6, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("�÷��̾���ʰȱ�", "images/WalkingAmazonLeft-3.bmp", 756, 118, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾����", "images/IdleAmazoneLeft-1.bmp", 696, 107, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾���ʰ���", "images/AttackAmazoneLeft.bmp", 1368, 231, 6, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("�÷��̾�Ʒ��ʰȱ�", "images/WalkingAmazonDown-3.bmp", 756, 118, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾�Ʒ���", "images/IdleAmazoneDown-1.bmp", 696, 107, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�÷��̾�Ʒ��ʰ���", "images/AttackAmazoneDown.bmp", 1368, 231, 6, 1, true, RGB(255, 0, 255));




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
    IMAGE->addFrameImage("������Ż��ų", "images/ElementalSkill1.bmp", 162, 18, 6, 1, true, RGB(255, 0, 255));

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
    IMAGE->addFrameImage("�����ȱ�1", "images/MeviusWalking-1.bmp", 2160, 444, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�����ȱ�2", "images/MeviusWalking-2.bmp", 1440, 296, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������", "images/MeviusWall.bmp", 256, 192, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("������", "images/MeviusSpikeBall.bmp", 329, 54, 7, 1, true, RGB(255, 0, 255));


    //=================Object=================//
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
    IMAGE->addFrameImage("tilemap1", "images/Tile2.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("tilemap", "images/Tile4.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
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
    IMAGE->addImage("���þ����", "images/SelectMap.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
    IMAGE->addImage("����ȭ��", "images/StartImage.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
    IMAGE->addImage("�����ӹ�ư��Ȱ��ȭ", "images/NewGame1.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("�����ӹ�ưȰ��ȭ", "images/NewGame2.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("�ҷ������ư��Ȱ��ȭ", "images/LoadGame1.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("�ҷ������ưȰ��ȭ", "images/LoadGame2.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("�������ư��Ȱ��ȭ", "images/GameOut1.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("�������ưȰ��ȭ", "images/GameOut2.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("���ñ׸���", "images/Shadow.bmp", 40, 21, true, RGB(255, 0, 255));
    IMAGE->addImage("����ȿ��", "images/SelectEffect.bmp", 44, 25, true, RGB(255, 0, 255));
    IMAGE->addImage("SkillUi", "images/HUD.bmp", 361, 112, true, RGB(255, 0, 255));
    IMAGE->addImage("StateUi", "images/StateUI.bmp", 318, 100, true, RGB(255, 0, 255));
    IMAGE->addImage("MiniMapUi", "images/MinimapUI.bmp", 284 * 0.74, 357 * 0.74, true, RGB(255, 0, 255));
    IMAGE->addImage("�����׵θ�", "images/inventorySelectUI1.bmp", 207, 88, true, RGB(255, 0, 255));
    IMAGE->addImage("�����׵θ�", "images/inventorySelectUI2.bmp", 207, 88, true, RGB(255, 0, 255));
    IMAGE->addImage("��ų���", "images/Skill_Lock.bmp", 38, 40, true, RGB(255, 0, 255));
    IMAGE->addImage("��ųQ", "images/Skill_Q.bmp", 38, 38, true, RGB(255, 0, 255));
    IMAGE->addImage("��ųW", "images/Skill_W.bmp", 38, 38, true, RGB(255, 0, 255));
    IMAGE->addImage("��ųE", "images/Skill_E.bmp", 38, 38, true, RGB(255, 0, 255));
    IMAGE->addImage("��ųR", "images/Skill_R.bmp", 38, 38, true, RGB(255, 0, 255));
    IMAGE->addImage("�÷��̾�ü�¹�", "images/player_hp_bar.bmp", 49, 15, true, RGB(255, 0, 255));
    IMAGE->addImage("������", "images/LevelUP.bmp", 183 * 1.5, 55 * 1.5, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("��ư1", "images/Button1.bmp", 208, 39, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��ư2", "images/Button2.bmp", 210, 41, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�κ��丮1", "images/Inventory1.bmp", 469, 473, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�κ��丮2", "images/Inventory2.bmp", 389, 465, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�κ��丮3", "images/Inventory3.bmp", 858, 473, 1, 1, true, RGB(255, 0, 255));


    IMAGE->addFrameImage("���þƸ���", "images/Choose/ChooseAmazon.bmp", 372, 138, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���õ���", "images/Choose/ChooseDemon.bmp", 528, 92, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���õ��󽽷��̾�", "images/Choose/ChooseDemonSlayer.bmp", 264, 80, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���÷���", "images/Choose/ChooseLancer.bmp", 468, 130, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���øӷδ�", "images/Choose/ChooseMarauder.bmp", 900, 120, 10, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���ø�ũ��", "images/Choose/ChooseMarksman.bmp", 504, 74, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���ó�ũ�θǼ�", "images/Choose/ChooseNecroMancer.bmp", 416, 66, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���ó븶��", "images/Choose/ChooseNomad.bmp", 1080, 98, 9, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�����ȶ��", "images/Choose/ChoosePaladin.bmp", 432, 80, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("�������̷�", "images/Choose/ChoosePirate.bmp", 1020, 90, 15, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���÷����", "images/Choose/ChooseRedneck.bmp", 468, 70, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���û繫����", "images/Choose/ChooseSamurai.bmp", 672, 98, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���û���", "images/Choose/ChooseShaman.bmp", 456, 86, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("���ý�ƽ��", "images/Choose/ChooseStickMan.bmp", 276, 84, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("����ȭ��Ʈ������", "images/Choose/ChooseWhiteMage.bmp", 360, 74, 6, 1, true, RGB(255, 0, 255));

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
