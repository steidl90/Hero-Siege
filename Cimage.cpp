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



    //=================Object=================//
    IMAGE->addFrameImage("나무빅", "images/나무빅.bmp", 1020, 200, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("나무스몰", "images/나무스몰.bmp", 1520, 182, 10, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("나무장작", "images/나무장작.bmp", 308, 75, 4, 1, true, RGB(255, 0, 255));



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
