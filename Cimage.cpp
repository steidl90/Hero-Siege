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
    



    //=================Enemy=================//
    IMAGE->addFrameImage("��ġ", "images/Priest.bmp", 300, 316, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��ġ����", "images/PriestAttack.bmp", 848, 316, 16, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��ġ���", "images/PriestDie.bmp", 490, 564, 10, 4, true, RGB(255, 0, 255));



    //=================Object=================//




    //=================item=================//
    IMAGE->addFrameImage("�Ź�", "images/�Ź�.bmp", 384, 320, 6, 5, true, RGB(255, 0, 255));





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
