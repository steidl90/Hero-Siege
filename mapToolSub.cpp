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

	// 좌클릭, 맵 셋팅
	if (InputManager->isStayKeyDown(VK_LBUTTON))
	{
		m_isButtonClick = true;
	}
	else
	{
		m_isButtonClick = false;
	}
	setMap();

	// 우클릭, 취소, 드래그 초기화
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

	TextOut(getMemDC(), CAMERAWIDTH + 100, WINSIZEY / 2, TEXT("지형"), lstrlen("지형"));
	TextOut(getMemDC(), CAMERAWIDTH + 200, WINSIZEY / 2, TEXT("오브젝트"), lstrlen("오브젝트"));
	TextOut(getMemDC(), CAMERAWIDTH + 300, WINSIZEY / 2, TEXT("지우개"), lstrlen("지우개"));
	TextOut(getMemDC(), CAMERAWIDTH + 100, WINSIZEY / 2 + 100, TEXT("세이브"), lstrlen("세이브"));
	TextOut(getMemDC(), CAMERAWIDTH + 200, WINSIZEY / 2 + 100, TEXT("로드"), lstrlen("로드"));
	TextOut(getMemDC(), CAMERAWIDTH + 300, WINSIZEY / 2 + 100, TEXT("채우기"), lstrlen("채우기"));

	// 마우스 클릭시 타일 이미지 알파값

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

	//샘플 맵 셋팅
	for (size_t i = 0; i < SAMPLETILEY; i++)
	{
		for (size_t j = 0; j < SAMPLETILEX; j++)
		{
			_sampleTiles[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTiles[i * SAMPLETILEX + j].terrainFrameY = i;

			//좌표값설정
			SetRect(&_sampleTiles[i * SAMPLETILEX + j].rcTile,
				(MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth()) + j * TILESIZE,
				i * TILESIZE, (MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth()) + j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}

}

void mapToolSub::setMap()
{
	// 채우기 기능 선택후 버튼 클릭시
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
		//오른쪽 샘플 클릭하는 순간
		if (m_isButtonClick)
		{
			//처음 좌클릭으로 셋맵 호출후 클릭 눌려있는동안에 처음 한번 타일정보 입력받고 마우스클릭DOWN에서 UP 될때 다시 허용
			// 상태변화에 따라 1회만 실행되게 하는 keyUp 변수
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
		// 버튼 클릭이 false가 되면 -> 마우스 클릭 때는 순간
		if (!m_isButtonClick)
		{
			// 상태변화에 따라 1회만 실행되게 하는 keyUp 변수
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


						// 타일 숫자 크기 정렬
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
	// 메인 맵에서 타일에 적용할 프레임 x,y값 설정
	m_currentDragTile.frame_StartX = m_currentDragTile.index_StartX;
	m_currentDragTile.frame_StartY = m_currentDragTile.index_StartY;
	m_currentDragTile.frame_EndX = m_currentDragTile.index_EndX;
	m_currentDragTile.frame_EndY = m_currentDragTile.index_EndY;

	// 메인 맵에서 타일에 그려주기 위한 인덱스를 계산하기 쉽게 0,0을 시작 x,y로 만듬
	m_currentDragTile.index_StartX = m_currentDragTile.index_StartX - m_currentDragTile.frame_StartX;
	m_currentDragTile.index_StartY = m_currentDragTile.index_StartY - m_currentDragTile.frame_StartY;
	m_currentDragTile.index_EndX = m_currentDragTile.index_EndX - m_currentDragTile.frame_StartX;
	m_currentDragTile.index_EndY = m_currentDragTile.index_EndY - m_currentDragTile.frame_StartY;
}
