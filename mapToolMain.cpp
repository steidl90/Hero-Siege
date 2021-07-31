#include"framework.h"
#include "mapToolMain.h"
#include "mapToolSub.h"
#include "camera.h"

HRESULT mapToolMain::init()
{

	maptoolSetup();

	m_isKeyUp = true;

	return S_OK;
}

void mapToolMain::release()
{
}

void mapToolMain::update()
{
	if (InputManager->isStayKeyDown(VK_LBUTTON))
	{
		setMap();
		m_isButtonClick = true;
	}
	else
	{
		m_isButtonClick = false;
	}
	if(_ctrSelect == static_cast<int>(CTRL::CTRL_FILL))
		this->fillMap();

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

	//왼쪽 타일 그리드
	/*for (int i = 0; i < TILEX; i++)
	{
		LineMake(getMapDC(), 0, i * TILESIZE, MAPSIZE, i * TILESIZE);
	}
	for (int i = 0; i < TILEY; i++)
	{
		LineMake(getMapDC(), i * TILESIZE, 0, i * TILESIZE, MAPSIZE);
	}*/

}

void mapToolMain::maptoolSetup()
{
	// 맵 세팅 - rect 세팅!
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

	// 맵 세팅 - 타일 속성 세팅!
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
	//마우스 좌표 보정!!!
	POINT cameraMouse = m_ptMouse;
	cameraMouse.x += m_camera->getCameraPoint().x;
	cameraMouse.y += m_camera->getCameraPoint().y;

	//맵 타일 세팅

	for (size_t i = 0; i < TILEX * TILEY; i++)
	{

		// 샘플 툴 쪽에서 눌렀을 때 맵 타일에 그려지지 않도록 카메라 범위 안에서만 타일 세팅 작동
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
				case CTRL::CTRL_FILL:
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

void mapToolMain::fillMap()
{

	if (m_isButtonClick)
	{
		if (m_isKeyUp)
		{
			POINT cameraMouse = m_ptMouse;
			cameraMouse.x += m_camera->getCameraPoint().x;
			cameraMouse.y += m_camera->getCameraPoint().y;


			for (size_t i = 0; i < TILEX * TILEY; i++)
			{
				if (m_camera->getCameraPoint().x <= _tiles[i].rc.left && m_camera->getCameraPoint().y <= _tiles[i].rc.top &&
					m_camera->getCameraPoint2().x >= _tiles[i].rc.right && m_camera->getCameraPoint2().y >= _tiles[i].rc.bottom)
				{
					if (PtInRect(&_tiles[i].rc, cameraMouse))
					{
						// 타일이 비어있을땐 바로 push
						if (m_vSelectTileIndex.empty())
						{
							m_vSelectTileIndex.push_back(i);
							break;
						}
						// 타일이 한개 선택되어 있을 때
						else if (m_vSelectTileIndex.size() == 1)
						{
							if (m_vSelectTileIndex[0] == i)	// 같은 타일 선택일 경우 break;
								break;
							else
							{
								m_vSelectTileIndex.push_back(i);	// 다른 타일일 경우 push 및 그려주기 / 초기화

								int j, k;
								int l, m;
								int startX, startY;
								int endX, endY;
								this->indexCalculate(m_vSelectTileIndex, &startX, &startY, &endX, &endY);
								// k는 선택된 타일 2개중 작은 인덱스 y 값, m 은 큰 y 값
								// j는 선택된 타일 2개중 작은 인덱스 x 값, l 은 큰 x 값
								for (k = startY; k <= endY; k++)
								{
									for (j = startX; j <= endX; j++)
									{
										_tiles[j + k * TILEX].terrainFrameX = _currentTile.frame_x;
										_tiles[j + k * TILEX].terrainFrameY = _currentTile.frame_y;
										_tiles[j + k * TILEX].terrain = terrainSelect(1, 0);
									}
								}
								m_vSelectTileIndex.clear();
								break;
							}
						}
						InvalidateRect(m_hWnd, NULL, false);
						break;
					}
				}
			}
			m_isKeyUp = false;
		}
	}
	else
	{
		m_isKeyUp = true;
	}
	
}

TERRAIN mapToolMain::terrainSelect(int frameX, int frameY)
{
	//시멘트
	if (frameX == 1 && frameY == 0)
	{
		return TERRAIN::TR_CEMENT;
	}
	//사막
	else if (frameX == 2 && frameY == 0)
	{
		return TERRAIN::TR_DESERT;
	}
	//잔디
	else if (frameX == 3 && frameY == 0)
	{
		return TERRAIN::TR_GRASS;
	}
	//잔디
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

void mapToolMain::indexCalculate(vector<int> vInt, int* x1, int* y1, int* x2, int* y2)
{
	int temp;
	// 크기 순서 정렬
	if (vInt[0] > vInt[1])
	{
		temp = vInt[0];
		vInt[0] = vInt[1];
		vInt[1] = temp;
	}

	*x1 = vInt[0] % TILEX;
	*y1 = vInt[0] / TILEX;
	*x2 = vInt[1] % TILEX;
	*y2 = vInt[1] / TILEX;

	// 크기 순서 정렬

	if (*x1 > *x2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
	}
	if (*y1 > *y2)
	{
		temp = *y1;
		*y1 = *y2;
		*y2 = temp;
	}
}
