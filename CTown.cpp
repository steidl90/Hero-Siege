#include "framework.h"
#include "CTown.h"
#include "camera.h"

CTown::CTown()
{
}

CTown::~CTown()
{
}

HRESULT CTown::init()
{
    load();
    return S_OK;
}

void CTown::release()
{
}

void CTown::update()
{
}

void CTown::render()
{
	this->cullingRender();
}

void CTown::load()
{
    HANDLE file;
    DWORD read;

    file = CreateFile("tileMap.map",
        GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    ReadFile(file, _tilesImage, sizeof(tagTileImage) * TILEX * TILEY, &read, NULL);
    ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
    ReadFile(file, _pos, sizeof(int) * 2, &read, NULL);
    CloseHandle(file);
}

void CTown::cullingRender()
{
	// Ÿ�� ���� ����ȭ
	// ī�޶� �»�� ��ǥ ���غ��� ���ϴ� ��ǥ������ Ÿ�� �ε����� �������ϰ� ����
	int index_X1 = m_camera->getCameraPoint().x / TILESIZE;
	int index_Y1 = m_camera->getCameraPoint().y / TILESIZE;
	int index_X2 = m_camera->getCameraPoint2().x / TILESIZE;
	int index_Y2 = m_camera->getCameraPoint2().y / TILESIZE;

	int startX = index_X1;
	int startY = index_Y1;
	int endX = index_X2;
	int endY = index_Y2;

	// �ε��� �����ʰ� ����ó��
	/*if (endY > 49)
		endY = 49;
	if (endX > 49)
		endX = 49;*/

	for (startY = index_Y1; startY <= endY; startY++)
	{
		for (startX = index_X1; startX <= endX; startX++)
		{
			if (_tilesImage[startX + startY * TILEX].terrainImage == "")
				_tilesImage[startX + startY * TILEX].terrainImage = "tilemap";
			IMAGE->frameRender(_tilesImage[startX + startY * TILEX].terrainImage, getMapDC(), _tiles[startX + startY * TILEX].rc.left, _tiles[startX + startY * TILEX].rc.top, _tiles[startX + startY * TILEX].terrainFrameX, _tiles[startX + startY * TILEX].terrainFrameY);

			if (_tilesImage[startX + startY * TILEX].objImage == "")
				_tilesImage[startX + startY * TILEX].objImage = "������ƮŸ��1";
			if (_tiles[startX + startY * TILEX].obj == OBJECT::OBJ_NONE)continue;
			IMAGE->frameRender(_tilesImage[startX + startY * TILEX].objImage, getMapDC(), _tiles[startX + startY * TILEX].rc.left, _tiles[startX + startY * TILEX].rc.top, _tiles[startX + startY * TILEX].objFrameX, _tiles[startX + startY * TILEX].objFrameY);
		}
	}
}
