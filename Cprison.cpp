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

    ANIMATION->addAnimation("������Ʒ���", "������", 0, 0, 8, false, true);
    ANIMATION->addAnimation("���������", "������", 0, 0, 8, false, true);
    ANIMATION->addAnimation("�����������", "������", 0, 0, 8, false, true);
    ANIMATION->addAnimation("����������", "������", 0, 0, 8, false, true);

    ANIMATION->addAnimation("������", "������", 0, 0, 8, false, true);
    ANIMATION->addAnimation("������", "������", 0, 0, 8, false, true);
    ANIMATION->addAnimation("������", "������", 0, 0, 8, false, true);
    ANIMATION->addAnimation("������", "������", 0, 0, 8, false, true);
    
    ANIMATION->addAnimation("������", "������", 0, 0, 8, false, true);
    ANIMATION->addAnimation("������", "������", 0, 0, 8, false, true);
    ANIMATION->addAnimation("������", "������", 0, 0, 8, false, true);
    ANIMATION->addAnimation("������", "������", 0, 0, 8, false, true);

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
