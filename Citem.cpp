#include "framework.h"
#include "Citem.h"

Citem::Citem()
{
}

Citem::~Citem()
{
}

HRESULT Citem::init()
{
	return S_OK;
}

void Citem::release()
{
}

void Citem::update()
{
}

void Citem::render()
{
}

void Citem::load()
{
    HANDLE file;
    DWORD read;

    file = CreateFile("tileMap.map",
        GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    /*ReadFile(file, m_itemKind, sizeof(item), &read, NULL);
    ReadFile(file, m_itemType, sizeof(item), &read, NULL);*/
    CloseHandle(file);
}
