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
    



    //=================Enemy=================//
    IMAGE->addFrameImage("리치", "images/Priest.bmp", 300, 316, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("리치공격", "images/PriestAttack.bmp", 848, 316, 16, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("리치사망", "images/PriestDie.bmp", 490, 564, 10, 4, true, RGB(255, 0, 255));



    //=================Object=================//




    //=================etc=================//





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
