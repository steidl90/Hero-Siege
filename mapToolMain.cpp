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

	//���� Ÿ�� �׸���
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
	// �� ���� - rect ����!
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

	// �� ���� - Ÿ�� �Ӽ� ����!
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
	//���콺 ��ǥ ����!!!
	POINT cameraMouse = m_ptMouse;
	cameraMouse.x += m_camera->getCameraPoint().x;
	cameraMouse.y += m_camera->getCameraPoint().y;

	//�� Ÿ�� ����

	for (size_t i = 0; i < TILEX * TILEY; i++)
	{

		// ���� �� �ʿ��� ������ �� �� Ÿ�Ͽ� �׷����� �ʵ��� ī�޶� ���� �ȿ����� Ÿ�� ���� �۵�
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
						// Ÿ���� ��������� �ٷ� push
						if (m_vSelectTileIndex.empty())
						{
							m_vSelectTileIndex.push_back(i);
							break;
						}
						// Ÿ���� �Ѱ� ���õǾ� ���� ��
						else if (m_vSelectTileIndex.size() == 1)
						{
							if (m_vSelectTileIndex[0] == i)	// ���� Ÿ�� ������ ��� break;
								break;
							else
							{
								m_vSelectTileIndex.push_back(i);	// �ٸ� Ÿ���� ��� push �� �׷��ֱ� / �ʱ�ȭ

								int j, k;
								int l, m;
								int startX, startY;
								int endX, endY;
								this->indexCalculate(m_vSelectTileIndex, &startX, &startY, &endX, &endY);
								// k�� ���õ� Ÿ�� 2���� ���� �ε��� y ��, m �� ū y ��
								// j�� ���õ� Ÿ�� 2���� ���� �ε��� x ��, l �� ū x ��
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
	//�ø�Ʈ
	if (frameX == 1 && frameY == 0)
	{
		return TERRAIN::TR_CEMENT;
	}
	//�縷
	else if (frameX == 2 && frameY == 0)
	{
		return TERRAIN::TR_DESERT;
	}
	//�ܵ�
	else if (frameX == 3 && frameY == 0)
	{
		return TERRAIN::TR_GRASS;
	}
	//�ܵ�
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
	// ũ�� ���� ����
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

	// ũ�� ���� ����

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
