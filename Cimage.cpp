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

    IMAGE->addFrameImage("������", "images/������.bmp", 1134, 242, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��������", "images/��������.bmp", 1520, 182, 10, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("��������", "images/��������.bmp", 308, 75, 4, 1, true, RGB(255, 0, 255));



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
