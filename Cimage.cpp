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
    /*  모든 이미지 이미지매니저에 추가하는 용도  */
    /*  모든 이미지 이미지매니저에 추가하는 용도  */
    /*  모든 이미지 이미지매니저에 추가하는 용도  */
    /*  나눠진 섹션에서 프레임이미지랑 아닌 이미지랑 구별해라  */
    /*  나눠진 섹션에서 프레임이미지랑 아닌 이미지랑 구별해라  */
    /*  나눠진 섹션에서 프레임이미지랑 아닌 이미지랑 구별해라  */

    //=================Player=================//
    IMAGE->addFrameImage("플레이어위쪽걷기", "images/WalkingAmazonUp-3.bmp", 756, 118, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("플레이어위쪽", "images/IdleAmazoneUP-1.bmp", 696,107, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("플레이어위쪽공격", "images/AttackAmazoneUp.bmp", 1368, 231, 6, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("플레이어오른쪽걷기", "images/WalkingAmazonRight-3.bmp", 756, 118, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("플레이어오른쪽", "images/IdleAmazoneRight-1.bmp", 696, 107, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("플레이어오른쪽공격", "images/AttackAmazoneRight.bmp", 1368, 231, 6, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("플레이어왼쪽걷기", "images/WalkingAmazonLeft-3.bmp", 756, 118, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("플레이어왼쪽", "images/IdleAmazoneLeft-1.bmp", 696, 107, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("플레이어왼쪽공격", "images/AttackAmazoneLeft.bmp", 1368, 231, 6, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("플레이어아래쪽걷기", "images/WalkingAmazonDown-3.bmp", 756, 118, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("플레이어아래쪽", "images/IdleAmazoneDown-1.bmp", 696, 107, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("플레이어아래쪽공격", "images/AttackAmazoneDown.bmp", 1368, 231, 6, 1, true, RGB(255, 0, 255));




    //=================NPC====================//
    IMAGE->addFrameImage("NPC블랙마켓", "images/BlackMarketNPC.bmp", 798, 121, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC에드워드", "images/Edward.bmp", 136, 34, 4, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC에릭", "images/Eric.bmp", 120, 31, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC가노르", "images/GarNor.bmp", 280, 34, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC할스테인", "images/Halstein.bmp", 152, 46, 4, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC카일리아", "images/Kayla.bmp", 120, 32, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC사캐스터", "images/Sarcaster.bmp", 184, 33, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC샵키퍼", "images/ShopKeeper.bmp", 184, 37, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC토스테인", "images/Torstein.bmp", 612, 41, 17, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("NPC위치", "images/Witch.bmp", 120, 62, 5, 1, true, RGB(255, 0, 255));

    


    //=================Enemy=================//
    IMAGE->addFrameImage("리치", "images/Priest.bmp", 300, 316, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("리치공격", "images/PriestAttack.bmp", 848, 316, 16, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("리치사망", "images/PriestDie.bmp", 490, 564, 10, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("리치스킬", "images/PriestSkill.bmp", 696, 61, 12, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("엘리멘탈", "images/Elemental.bmp", 252, 268, 4, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("엘리멘탈스킬", "images/ElementalSkill1.bmp", 162, 18, 6, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("슬라임", "images/GreenSlime.bmp", 138, 18, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("슬라임공격", "images/GreenSlimeAttack.bmp", 480, 152, 12, 4, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("몽크", "images/Monk.bmp", 264, 300, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("몽크공격", "images/MonkAttack.bmp", 360, 336, 5, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("몽크사망", "images/MonkDie.bmp", 912, 444, 12, 4, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("교도관", "images/PrisonGuard.bmp", 456, 320, 8, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("교도관공격", "images/PrisonGuardAttack.bmp", 1120, 440, 8, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("교도관사망", "images/PrisonGuardDie.bmp", 1261, 360, 13, 4, true, RGB(255, 0, 255));


    //=================Boss==================//
    IMAGE->addFrameImage("보스", "images/Mevius.bmp", 360, 143, 4, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("보스캐스팅", "images/MeviusCasting.bmp", 1800, 143, 20, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("보스체인", "images/MeviusChains.bmp", 211, 17, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("보스공중", "images/MeviusLevitating.bmp", 90, 146, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("보스빛", "images/MeviusLight.bmp", 87, 1042, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("보스몬스터", "images/MeviusMonster.bmp", 1218, 153, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("보스걷기", "images/MeviusWalking.bmp", 720, 148, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("보스걷기1", "images/MeviusWalking-1.bmp", 2160, 444, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("보스걷기2", "images/MeviusWalking-2.bmp", 1440, 296, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("보스벽", "images/MeviusWall.bmp", 256, 192, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("보스공", "images/MeviusSpikeBall.bmp", 329, 54, 7, 1, true, RGB(255, 0, 255));


    //=================Object=================//
    IMAGE->addFrameImage("제너레이터", "images/Generator.bmp", 485, 67, 5, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("용광로", "images/Furnace.bmp", 280, 30, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("램프", "images/Lamp.bmp", 960, 98, 16, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("웨이포인트", "images/WayPoint.bmp", 1304, 137, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("포탈", "images/Portal.bmp", 330, 66, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("게이트", "images/Gate.bmp", 468, 87, 6, 1, true, RGB(255, 0, 255));
    
    IMAGE->addFrameImage("큰풀", "images/GrassBig.bmp", 408, 31, 12, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("작은풀1", "images/GrassSmall1.bmp", 152, 19, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("작은풀2", "images/GrassSmall2.bmp", 160, 17, 8, 1, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("커피집", "images/CoffeeHouse.bmp", 904, 152, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("풍차날개", "images/WindmillWing.bmp", 2016, 339, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("tilemap1", "images/Tile2.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("tilemap", "images/Tile4.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("오브젝트타일1", "images/ObjectTile.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("오브젝트타일2", "images/ObjectTile2.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("오브젝트타일3", "images/ObjectTile3.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("오브젝트타일4", "images/ObjectTile4.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("오브젝트타일5", "images/ObjectTile5.bmp", 648, 504, 18, 14, true, RGB(255, 0, 255));


    //=================item=================//
    IMAGE->addFrameImage("신발빅", "images/신발빅.bmp", 384, 320, 7, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("신발스몰", "images/신발스몰.bmp", 224, 128, 7, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("갑옷빅", "images/갑옷빅.bmp", 528, 528, 6, 6, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("갑옷스몰", "images/갑옷스몰.bmp", 264, 264, 6, 6, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("무기빅", "images/무기빅.bmp", 623, 111, 7, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("펜던트빅", "images/펜던트빅.bmp", 384, 256, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("펜던트스몰", "images/펜던트스몰.bmp", 210, 140, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("장갑빅", "images/장갑빅.bmp", 576, 192, 9, 3, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("장갑스몰", "images/장갑스몰.bmp", 288, 96, 9, 3, true, RGB(255, 0, 255));

    //==================UI==================//
    IMAGE->addImage("선택씬배경", "images/SelectMap.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
    IMAGE->addImage("시작화면", "images/StartImage.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
    IMAGE->addImage("새게임버튼비활성화", "images/NewGame1.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("새게임버튼활성화", "images/NewGame2.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("불러오기버튼비활성화", "images/LoadGame1.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("불러오기버튼활성화", "images/LoadGame2.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("나가기버튼비활성화", "images/GameOut1.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("나가기버튼활성화", "images/GameOut2.bmp", 338, 62, true, RGB(255, 0, 255));
    IMAGE->addImage("선택그림자", "images/Shadow.bmp", 40, 21, true, RGB(255, 0, 255));
    IMAGE->addImage("선택효과", "images/SelectEffect.bmp", 44, 25, true, RGB(255, 0, 255));
    IMAGE->addImage("SkillUi", "images/HUD.bmp", 361, 112, true, RGB(255, 0, 255));
    IMAGE->addImage("StateUi", "images/StateUI.bmp", 318, 100, true, RGB(255, 0, 255));
    IMAGE->addImage("MiniMapUi", "images/MinimapUI.bmp", 284 * 0.74, 357 * 0.74, true, RGB(255, 0, 255));
    IMAGE->addImage("선택테두리", "images/inventorySelectUI1.bmp", 207, 88, true, RGB(255, 0, 255));
    IMAGE->addImage("장착테두리", "images/inventorySelectUI2.bmp", 207, 88, true, RGB(255, 0, 255));
    IMAGE->addImage("스킬잠금", "images/Skill_Lock.bmp", 38, 40, true, RGB(255, 0, 255));
    IMAGE->addImage("스킬Q", "images/Skill_Q.bmp", 38, 38, true, RGB(255, 0, 255));
    IMAGE->addImage("스킬W", "images/Skill_W.bmp", 38, 38, true, RGB(255, 0, 255));
    IMAGE->addImage("스킬E", "images/Skill_E.bmp", 38, 38, true, RGB(255, 0, 255));
    IMAGE->addImage("스킬R", "images/Skill_R.bmp", 38, 38, true, RGB(255, 0, 255));
    IMAGE->addImage("플레이어체력바", "images/player_hp_bar.bmp", 49, 15, true, RGB(255, 0, 255));
    IMAGE->addImage("레벨업", "images/LevelUP.bmp", 183 * 1.5, 55 * 1.5, true, RGB(255, 0, 255));

    IMAGE->addFrameImage("버튼1", "images/Button1.bmp", 208, 39, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("버튼2", "images/Button2.bmp", 210, 41, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("인벤토리1", "images/Inventory1.bmp", 469, 473, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("인벤토리2", "images/Inventory2.bmp", 389, 465, 1, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("인벤토리3", "images/Inventory3.bmp", 858, 473, 1, 1, true, RGB(255, 0, 255));


    IMAGE->addFrameImage("선택아마존", "images/Choose/ChooseAmazon.bmp", 372, 138, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택데몬", "images/Choose/ChooseDemon.bmp", 528, 92, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택데몬슬레이어", "images/Choose/ChooseDemonSlayer.bmp", 264, 80, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택랜서", "images/Choose/ChooseLancer.bmp", 468, 130, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택머로더", "images/Choose/ChooseMarauder.bmp", 900, 120, 10, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택마크맨", "images/Choose/ChooseMarksman.bmp", 504, 74, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택네크로맨서", "images/Choose/ChooseNecroMancer.bmp", 416, 66, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택노마드", "images/Choose/ChooseNomad.bmp", 1080, 98, 9, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택팔라딘", "images/Choose/ChoosePaladin.bmp", 432, 80, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택파이렛", "images/Choose/ChoosePirate.bmp", 1020, 90, 15, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택레드넥", "images/Choose/ChooseRedneck.bmp", 468, 70, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택사무라이", "images/Choose/ChooseSamurai.bmp", 672, 98, 8, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택샤먼", "images/Choose/ChooseShaman.bmp", 456, 86, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택스틱맨", "images/Choose/ChooseStickMan.bmp", 276, 84, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("선택화이트메이지", "images/Choose/ChooseWhiteMage.bmp", 360, 74, 6, 1, true, RGB(255, 0, 255));

    //==================ECT=================//
    IMAGE->addFrameImage("히트", "images/Hit.bmp", 414, 71, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("퀘스트1", "images/Quest1.bmp", 48, 25, 3, 1, true, RGB(255, 0, 255));

    IMAGE->addImage("퀘스트2", "images/Quest2.bmp", 9, 25, true, RGB(255, 0, 255));





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
