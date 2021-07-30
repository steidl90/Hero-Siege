#include"framework.h"
#include "mapToolMain.h"
#include "mapToolSub.h"
#include "camera.h"

HRESULT mapToolMain::init()
{

	maptoolSetup();

	return S_OK;
}

void mapToolMain::release()
{
}

void mapToolMain::update()
{
	if (InputManager->isStayKeyDown(VK_LBUTTON))setMap();

}

void mapToolMain::render()
{
	for (size_t i = 0; i < TILEX * TILEY; i++)
	{

		if (m_camera->getCameraPoint().x - TILESIZE * 2 < _tiles[i].rc.left && m_camera->getCameraPoint().y - TILESIZE * 2 < _tiles[i].rc.top &&
			m_camera->getCameraPoint2().x + TILESIZE * 2 > _tiles[i].rc.right && m_camera->getCameraPoint2().y + TILESIZE * 2 > _tiles[i].rc.bottom)
		{
			IMAGE->frameRender("tilemap", getMapDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
			//Rectangle(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].rc.right, _tiles[i].rc.bottom);
		}

		if (_tiles[i].obj == OBJECT::OBJ_NONE)continue;

		IMAGE->frameRender("tilemap", getMapDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].objFrameX, _tiles[i].objFrameY);

	}

	for (int i = 0; i < TILEX; i++)
	{
		LineMake(getMapDC(), 0, i * TILESIZE, MAPSIZE, i * TILESIZE);
	}
	for (int i = 0; i < TILEY; i++)
	{
		LineMake(getMapDC(), i * TILESIZE, 0, i * TILESIZE, MAPSIZE);
	}

}

void mapToolMain::maptoolSetup()
{
	// ∏  ºº∆√ - rect ºº∆√!
	for (size_t i = 0; i < TILEY; i++)
	{
		for (size_t j = 0; j < TILEX; j++)
		{
			SetRect(&_tiles[i * TILEX + j].rc,
				j * TILESIZE,
				i * TILESIZE,
				j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}

	// ∏  ºº∆√ - ≈∏¿œ º”º∫ ºº∆√!
	for (size_t i = 0; i < TILEX * TILEY; i++)
	{
		_tiles[i].terrainFrameX = 0;
		_tiles[i].terrainFrameY = 7;

		_tiles[i].objFrameX = 0;
		_tiles[i].objFrameX = 0;

		_tiles[i].terrain = terrainSelect(_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
		_tiles[i].obj = OBJECT::OBJ_NONE;
	}
}

void mapToolMain::setMap()
{
	//∏∂øÏΩ∫ ¡¬«• ∫∏¡§!!!
	POINT cameraMouse = m_ptMouse;
	cameraMouse.x += m_camera->getCameraPoint().x;
	cameraMouse.y += m_camera->getCameraPoint().y;

	//∏  ≈∏¿œ ºº∆√

	for (size_t i = 0; i < TILEX * TILEY; i++)
	{

		if (m_camera->getCameraPoint().x <= _tiles[i].rc.left && m_camera->getCameraPoint().y <= _tiles[i].rc.top &&
			m_camera->getCameraPoint2().x >= _tiles[i].rc.right && m_camera->getCameraPoint2().y >= _tiles[i].rc.bottom)
		{
			if (PtInRect(&_tiles[i].rc, cameraMouse))
			{
				switch ((CTRL)_ctrSelect)
				{

				case CTRL::CTRL_TERRAINDRAW:
				{
					int j, k;
					int l, m;
					for (j = m_currentDragTile.index_StartY, l = m_currentDragTile.frame_StartY; j <= m_currentDragTile.index_EndY; j++, l++)
					{
						for (k = m_currentDragTile.index_StartX, m = m_currentDragTile.frame_StartX; k <= m_currentDragTile.index_EndX; k++, m++)
						{
							_tiles[i + k + j * TILEX].terrainFrameX = m;
							_tiles[i + k + j * TILEX].terrainFrameY = l;
							_tiles[i + k + j * TILEX].terrain = terrainSelect(1, 0);
						}
					}
				}
				break;
				case CTRL::CTRL_OBJDRAW:
				{
					int j, k;
					int l, m;
					for (j = m_currentDragTile.index_StartY, l = m_currentDragTile.frame_StartY; j <= m_currentDragTile.index_EndY; j++, l++)
					{
						for (k = m_currentDragTile.index_StartX, m = m_currentDragTile.frame_StartX; k <= m_currentDragTile.index_EndX; k++, m++)
						{
							_tiles[i + k + j * TILEX].objFrameX = m;
							_tiles[i + k + j * TILEX].objFrameY = l;
							_tiles[i + k + j * TILEX].obj = objSelect(1, 0);
						}
					}
				}
				break;
				default:
					_tiles[i].obj = OBJECT::OBJ_NONE;
					break;
				}
				InvalidateRect(m_hWnd, NULL, false);
				break;
			}
		}
	}
}

TERRAIN mapToolMain::terrainSelect(int frameX, int frameY)
{
	//Ω√∏‡∆Æ
	if (frameX == 1 && frameY == 0)
	{
		return TERRAIN::TR_CEMENT;
	}
	//ªÁ∏∑
	else if (frameX == 2 && frameY == 0)
	{
		return TERRAIN::TR_DESERT;
	}
	//¿‹µ
	else if (frameX == 3 && frameY == 0)
	{
		return TERRAIN::TR_GRASS;
	}
	//¿‹µ
	else if (frameX == 4 && frameY == 0)
	{
		return TERRAIN::TR_WATER;
	}
	return TERRAIN::TR_GRASS;
}

OBJECT mapToolMain::objSelect(int frameX, int frameY)
{
	return OBJECT::OBJ_BLOCK1;
}