#include"framework.h"
#include "mapToolSub.h"
#include "mapToolMain.h"

HRESULT mapToolSub::init()
{

	maptoolSetup();

	_terrain = RectMakeCenter(CAMERAWIDTH + 100, WINSIZEY / 2, 50, 50);
	_object = RectMakeCenter(CAMERAWIDTH + 200, WINSIZEY / 2, 50, 50);
	_erase = RectMakeCenter(CAMERAWIDTH + 300, WINSIZEY / 2, 50, 50);
	_save = RectMakeCenter(CAMERAWIDTH + 100, WINSIZEY / 2 + 100, 50, 50);
	_load = RectMakeCenter(CAMERAWIDTH + 200, WINSIZEY / 2 + 100, 50, 50);
	m_fill = RectMakeCenter(CAMERAWIDTH + 300, WINSIZEY / 2 + 100, 50, 50);

	m_isKeyUp = true;

	return S_OK;
}

void mapToolSub::release()
{
}

void mapToolSub::update()
{

	// ��Ŭ��, �� ����
	if (InputManager->isStayKeyDown(VK_LBUTTON))
	{
		m_isButtonClick = true;
	}
	else
	{
		m_isButtonClick = false;
	}
	setMap();

	// ��Ŭ��, ���, �巡�� �ʱ�ȭ
	if (InputManager->isOnceKeyDown(VK_RBUTTON))
	{
		m_isTileClick = false;
		memset(&m_currentDragTile, 0, sizeof(tagDragTileIndex));
		_ctrSelect = static_cast<int>(CTRL::CTRL_ERASER);
	}

	

	if (PtInRect(&_terrain, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		_ctrSelect = static_cast<int>(CTRL::CTRL_TERRAINDRAW);
	}
	else if (PtInRect(&_object, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		_ctrSelect = static_cast<int>(CTRL::CTRL_OBJDRAW);
	}
	else if (PtInRect(&_erase, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		_ctrSelect = static_cast<int>(CTRL::CTRL_ERASER);
		memset(&m_currentDragTile, 0, sizeof(tagDragTileIndex));
	}
	else if (PtInRect(&_save, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		this->mapSave();
	}
	else if (PtInRect(&_load, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		this->mapLoad();
	}
	else if (PtInRect(&m_fill, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		_ctrSelect = static_cast<int>(CTRL::CTRL_FILL);
	}

	m_mapToolmain->setMainMapSelect(_ctrSelect);
	m_mapToolmain->setMainMapDragTile(m_currentDragTile);
	m_mapToolmain->setMainMapCurrentTile(_currentTile);
}

void mapToolSub::render()
{
	IMAGE->render("tilemap", getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth(), 0);

	for (int i = 0; i < SAMPLETILEY; i++)
	{
		LineMake(getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth(), i * TILESIZE, MAPTOOLPOINT, i * TILESIZE);
	}
	for (int i = 0; i < SAMPLETILEX; i++)
	{
		LineMake(getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth() + i * TILESIZE, 0, MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth() + i * TILESIZE, IMAGE->findImage("tilemap")->getHeight());
	}

	Rectangle(getMemDC(), _terrain.left, _terrain.top, _terrain.right, _terrain.bottom);
	Rectangle(getMemDC(), _object.left, _object.top, _object.right, _object.bottom);
	Rectangle(getMemDC(), _erase.left, _erase.top, _erase.right, _erase.bottom);
	Rectangle(getMemDC(), _save.left, _save.top, _save.right, _save.bottom);
	Rectangle(getMemDC(), _load.left, _load.top, _load.right, _load.bottom);
	Rectangle(getMemDC(), m_fill.left, m_fill.top, m_fill.right, m_fill.bottom);

	SetTextColor(getMemDC(), RGB(0, 0, 0));

	TextOut(getMemDC(), CAMERAWIDTH + 100, WINSIZEY / 2, TEXT("����"), lstrlen("����"));
	TextOut(getMemDC(), CAMERAWIDTH + 200, WINSIZEY / 2, TEXT("������Ʈ"), lstrlen("������Ʈ"));
	TextOut(getMemDC(), CAMERAWIDTH + 300, WINSIZEY / 2, TEXT("���찳"), lstrlen("���찳"));
	TextOut(getMemDC(), CAMERAWIDTH + 100, WINSIZEY / 2 + 100, TEXT("���̺�"), lstrlen("���̺�"));
	TextOut(getMemDC(), CAMERAWIDTH + 200, WINSIZEY / 2 + 100, TEXT("�ε�"), lstrlen("�ε�"));
	TextOut(getMemDC(), CAMERAWIDTH + 300, WINSIZEY / 2 + 100, TEXT("ä���"), lstrlen("ä���"));

	// ���콺 Ŭ���� Ÿ�� �̹��� ���İ�

	if (m_isTileClick && _ctrSelect != static_cast<int>(CTRL::CTRL_ERASER))
	{
		if (_ctrSelect == static_cast<int>(CTRL::CTRL_FILL))
		{
			IMAGE->findImage("tilemap")->alphaframeRender(getMemDC(), m_ptMouse.x - 10 , m_ptMouse.y - 10, _currentTile.frame_x, _currentTile.frame_y, 128);
		}
		else
		{
			int countI, i;
			int countJ, j;

			for (countI = 0, i = m_currentDragTile.frame_StartY; i <= m_currentDragTile.frame_EndY; countI++, i++)
			{
				for (countJ = 0, j = m_currentDragTile.frame_StartX; j <= m_currentDragTile.frame_EndX; countJ++, j++)
				{
					IMAGE->findImage("tilemap")->alphaframeRender(getMemDC(), m_ptMouse.x + countJ * TILESIZE, m_ptMouse.y + countI * TILESIZE, j, i, 128);
				}
			}
		}
	}
}

void mapToolSub::maptoolSetup()
{

	_ctrSelect = static_cast<int>(CTRL::CTRL_TERRAINDRAW);

	//���� �� ����
	for (size_t i = 0; i < SAMPLETILEY; i++)
	{
		for (size_t j = 0; j < SAMPLETILEX; j++)
		{
			_sampleTiles[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTiles[i * SAMPLETILEX + j].terrainFrameY = i;

			//��ǥ������
			SetRect(&_sampleTiles[i * SAMPLETILEX + j].rcTile,
				(MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth()) + j * TILESIZE,
				i * TILESIZE, (MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth()) + j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}

}

void mapToolSub::setMap()
{
	// ä��� ��� ������ ��ư Ŭ����
	if (_ctrSelect == static_cast<int>(CTRL::CTRL_FILL))
	{
		if (m_isButtonClick)
		{
			for (size_t i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
			{
				if (PtInRect(&_sampleTiles[i].rcTile, m_ptMouse))
				{
					_currentTile.frame_x = _sampleTiles[i].terrainFrameX;
					_currentTile.frame_y = _sampleTiles[i].terrainFrameY;
					m_isTileClick = true;
					break;
				}
			}
		}
	}
	else
	{
		//������ ���� Ŭ���ϴ� ����
		if (m_isButtonClick)
		{
			//ó�� ��Ŭ������ �¸� ȣ���� Ŭ�� �����ִµ��ȿ� ó�� �ѹ� Ÿ������ �Է¹ް� ���콺Ŭ��DOWN���� UP �ɶ� �ٽ� ���
			// ���º�ȭ�� ���� 1ȸ�� ����ǰ� �ϴ� keyUp ����
			if (m_isKeyUp)
			{
				for (size_t i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
				{
					if (PtInRect(&_sampleTiles[i].rcTile, m_ptMouse))
					{
						m_currentDragTile.index_StartX = _sampleTiles[i].terrainFrameX;
						m_currentDragTile.index_StartY = _sampleTiles[i].terrainFrameY;

						m_isKeyUp = false;
						break;
					}
				}
			}
		}
		// ��ư Ŭ���� false�� �Ǹ� -> ���콺 Ŭ�� ���� ����
		if (!m_isButtonClick)
		{
			// ���º�ȭ�� ���� 1ȸ�� ����ǰ� �ϴ� keyUp ����
			if (!m_isKeyUp)
			{
				for (size_t i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
				{
					if (PtInRect(&_sampleTiles[i].rcTile, m_ptMouse))
					{
						m_currentDragTile.index_EndX = _sampleTiles[i].terrainFrameX;
						m_currentDragTile.index_EndY = _sampleTiles[i].terrainFrameY;
						
						m_isTileClick = true;
						m_isKeyUp = true;


						// Ÿ�� ���� ũ�� ����
						if (m_currentDragTile.index_StartX > m_currentDragTile.index_EndX)
						{
							int temp;
							temp = m_currentDragTile.index_StartX;
							m_currentDragTile.index_StartX = m_currentDragTile.index_EndX;
							m_currentDragTile.index_EndX = temp;
						}

						if (m_currentDragTile.index_StartY > m_currentDragTile.index_EndY)
						{
							int temp;
							temp = m_currentDragTile.index_StartY;
							m_currentDragTile.index_StartY = m_currentDragTile.index_EndY;
							m_currentDragTile.index_EndY = temp;
						}

						this->dragTileInit();
						m_mapToolmain->setMainMapDragTile(m_currentDragTile);
						break;
					}
				}
			}
		}
	}
}

void mapToolSub::mapSave()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("tileMap.map",
		GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


	WriteFile(file, m_mapToolmain->getMainMapTile(), sizeof(tagTile) * TILEX * TILEY, &write, NULL);
	WriteFile(file, _pos, sizeof(int) * 2, &write, NULL);
	CloseHandle(file);
}

void mapToolSub::mapLoad()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("tileMap.map",
		GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, m_mapToolmain->getMainMapTile(), sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	ReadFile(file, _pos, sizeof(int) * 2, &read, NULL);
	CloseHandle(file);
}

void mapToolSub::dragTileInit()
{
	// ���� �ʿ��� Ÿ�Ͽ� ������ ������ x,y�� ����
	m_currentDragTile.frame_StartX = m_currentDragTile.index_StartX;
	m_currentDragTile.frame_StartY = m_currentDragTile.index_StartY;
	m_currentDragTile.frame_EndX = m_currentDragTile.index_EndX;
	m_currentDragTile.frame_EndY = m_currentDragTile.index_EndY;

	// ���� �ʿ��� Ÿ�Ͽ� �׷��ֱ� ���� �ε����� ����ϱ� ���� 0,0�� ���� x,y�� ����
	m_currentDragTile.index_StartX = m_currentDragTile.index_StartX - m_currentDragTile.frame_StartX;
	m_currentDragTile.index_StartY = m_currentDragTile.index_StartY - m_currentDragTile.frame_StartY;
	m_currentDragTile.index_EndX = m_currentDragTile.index_EndX - m_currentDragTile.frame_StartX;
	m_currentDragTile.index_EndY = m_currentDragTile.index_EndY - m_currentDragTile.frame_StartY;
}
