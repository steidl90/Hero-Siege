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
}

void mapToolMain::maptoolSetup()
{
	// ¸Ê ¼¼ÆÃ - rect ¼¼ÆÃ!
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

	// ¸Ê ¼¼ÆÃ - Å¸ÀÏ ¼Ó¼º ¼¼ÆÃ!
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
	//¸¶¿ì½º ÁÂÇ¥ º¸Á¤!!!
	POINT cameraMouse = m_ptMouse;
	cameraMouse.x += m_camera->getCameraPoint().x;
	cameraMouse.y += m_camera->getCameraPoint().y;

	//¸Ê Å¸ÀÏ ¼¼ÆÃ

	for (size_t i = 0; i < TILEX * TILEY; i++)
	{

		if (m_camera->getCameraPoint().x < _tiles[i].rc.left && m_camera->getCameraPoint().y < _tiles[i].rc.top &&
			m_camera->getCameraPoint2().x > _tiles[i].rc.right && m_camera->getCameraPoint2().y > _tiles[i].rc.bottom)
		{
			if (PtInRect(&_tiles[i].rc, cameraMouse))
			{
				switch ((CTRL)_ctrSelect)
				{

				case CTRL::CTRL_TERRAINDRAW:
				{

					_tiles[i].terrainFrameX = _currentTile.frame_x;
					_tiles[i].terrainFrameY = _currentTile.frame_y;
					_tiles[i].terrain = terrainSelect(_currentTile.frame_x, _currentTile.frame_y);

				}
				break;
				case CTRL::CTRL_OBJDRAW:
				{
					_tiles[i].objFrameX = _currentTile.frame_x;
					_tiles[i].objFrameY = _currentTile.frame_y;
					_tiles[i].obj = objSelect(_currentTile.frame_x, _currentTile.frame_y);
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
	//½Ã¸àÆ®
	if (frameX == 1 && frameY == 0)
	{
		return TERRAIN::TR_CEMENT;
	}
	//»ç¸·
	else if (frameX == 2 && frameY == 0)
	{
		return TERRAIN::TR_DESERT;
	}
	//ÀÜµð
	else if (frameX == 3 && frameY == 0)
	{
		return TERRAIN::TR_GRASS;
	}
	//ÀÜµð
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