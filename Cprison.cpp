#include "framework.h"
#include "Cprison.h"

Cprison::Cprison()
{
}

Cprison::~Cprison()
{
}

HRESULT Cprison::init()
{

    ANIMATION->addAnimation("ÇÁ¸®Áð¾Æ·¡ÂÊ", "ÇÁ¸®Áð", 0, 0, 8, false, true);
    ANIMATION->addAnimation("ÇÁ¸®Áð¿ÞÂÊ", "ÇÁ¸®Áð", 0, 0, 8, false, true);
    ANIMATION->addAnimation("ÇÁ¸®Áð¿À¸¥ÂÊ", "ÇÁ¸®Áð", 0, 0, 8, false, true);
    ANIMATION->addAnimation("ÇÁ¸®ÁðÀ§ÂÊ", "ÇÁ¸®Áð", 0, 0, 8, false, true);

    ANIMATION->addAnimation("ÇÁ¸®Áð", "ÇÁ¸®Áð", 0, 0, 8, false, true);
    ANIMATION->addAnimation("ÇÁ¸®Áð", "ÇÁ¸®Áð", 0, 0, 8, false, true);
    ANIMATION->addAnimation("ÇÁ¸®Áð", "ÇÁ¸®Áð", 0, 0, 8, false, true);
    ANIMATION->addAnimation("ÇÁ¸®Áð", "ÇÁ¸®Áð", 0, 0, 8, false, true);
    
    ANIMATION->addAnimation("ÇÁ¸®Áð", "ÇÁ¸®Áð", 0, 0, 8, false, true);
    ANIMATION->addAnimation("ÇÁ¸®Áð", "ÇÁ¸®Áð", 0, 0, 8, false, true);
    ANIMATION->addAnimation("ÇÁ¸®Áð", "ÇÁ¸®Áð", 0, 0, 8, false, true);
    ANIMATION->addAnimation("ÇÁ¸®Áð", "ÇÁ¸®Áð", 0, 0, 8, false, true);

    return S_OK;
}

void Cprison::release()
{
}

void Cprison::update()
{
}

void Cprison::render()
{
}
