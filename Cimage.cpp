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
    /*  ∏µÁ ¿ÃπÃ¡ˆ ¿ÃπÃ¡ˆ∏≈¥œ¿˙ø° √ﬂ∞°«œ¥¬ øÎµµ  */
    /*  ∏µÁ ¿ÃπÃ¡ˆ ¿ÃπÃ¡ˆ∏≈¥œ¿˙ø° √ﬂ∞°«œ¥¬ øÎµµ  */
    /*  ∏µÁ ¿ÃπÃ¡ˆ ¿ÃπÃ¡ˆ∏≈¥œ¿˙ø° √ﬂ∞°«œ¥¬ øÎµµ  */
    /*  ≥™¥≤¡¯ ºΩº«ø°º≠ «¡∑π¿”¿ÃπÃ¡ˆ∂˚ æ∆¥— ¿ÃπÃ¡ˆ∂˚ ±∏∫∞«ÿ∂Û  */
    /*  ≥™¥≤¡¯ ºΩº«ø°º≠ «¡∑π¿”¿ÃπÃ¡ˆ∂˚ æ∆¥— ¿ÃπÃ¡ˆ∂˚ ±∏∫∞«ÿ∂Û  */
    /*  ≥™¥≤¡¯ ºΩº«ø°º≠ «¡∑π¿”¿ÃπÃ¡ˆ∂˚ æ∆¥— ¿ÃπÃ¡ˆ∂˚ ±∏∫∞«ÿ∂Û  */

    //=================Player=================//
    



    //=================Enemy=================//
    IMAGE->addFrameImage("∏Æƒ°", "images/Priest.bmp", 300, 316, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("∏Æƒ°∞¯∞›", "images/PriestAttack.bmp", 848, 316, 16, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("∏Æƒ°ªÁ∏¡", "images/PriestDie.bmp", 490, 564, 10, 4, true, RGB(255, 0, 255));



    //=================Object=================//

    IMAGE->addFrameImage("≥™π´∫Ú", "images/≥™π´∫Ú.bmp", 1134, 242, 6, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("≥™π´Ω∫∏Ù", "images/≥™π´Ω∫∏Ù.bmp", 1520, 182, 10, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("≥™π´¿Â¿€", "images/≥™π´¿Â¿€.bmp", 308, 75, 4, 1, true, RGB(255, 0, 255));



    //=================item=================//
    IMAGE->addFrameImage("Ω≈πﬂ∫Ú", "images/Ω≈πﬂ∫Ú.bmp", 384, 320, 7, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("Ω≈πﬂΩ∫∏Ù", "images/Ω≈πﬂΩ∫∏Ù.bmp", 224, 128, 7, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("∞©ø ∫Ú", "images/∞©ø ∫Ú.bmp", 528, 528, 6, 6, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("∞©ø Ω∫∏Ù", "images/∞©ø Ω∫∏Ù.bmp", 264, 264, 6, 6, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("π´±‚∫Ú", "images/π´±‚∫Ú.bmp", 623, 111, 7, 1, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("∆Ê¥¯∆Æ∫Ú", "images/∆Ê¥¯∆Æ∫Ú.bmp", 384, 256, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("∆Ê¥¯∆ÆΩ∫∏Ù", "images/∆Ê¥¯∆ÆΩ∫∏Ù.bmp", 210, 140, 6, 4, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("¿Â∞©∫Ú", "images/¿Â∞©∫Ú.bmp", 576, 192, 9, 3, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("¿Â∞©Ω∫∏Ù", "images/¿Â∞©Ω∫∏Ù.bmp", 288, 96, 9, 3, true, RGB(255, 0, 255));





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
