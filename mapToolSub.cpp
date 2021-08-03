#include"framework.h"
#include "mapToolSub.h"
#include "mapToolMain.h"

HRESULT mapToolSub::init()
{

	maptoolSetup();
	m_subTile = 0;
	m_isKeyUp = true;
	isTileLine = false;
	return S_OK;
}

void mapToolSub::release()
{
}

void mapToolSub::update()
{
	//왼쪽 타일맵 그리드 on off
	if (isTileLine)
	{
		for (int i = 0; i < TILEX; i++)
		{
			LineMake(getMapDC(), 0, i * TILESIZE, MAPSIZE, i * TILESIZE);
			LineMake(getMapDC(), i * TILESIZE, 0, i * TILESIZE, MAPSIZE);
		}
	}

	// 입력 명령 집합
	this->inputFunction();
	
	setMap();

	// 전방참조, 데이터 mainTool로 보내주기
	m_mapToolmain->setMainMapSelect(_ctrSelect);
	m_mapToolmain->setMainMapDragTile(m_currentDragTile);
	m_mapToolmain->setMainMapCurrentTile(_currentTile);
}

void mapToolSub::render()
{
	//오른쪽 타일 이미지
	if (m_subTile == 0)IMAGE->render("tilemap", getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth(), 0);
	if (m_subTile == 1)IMAGE->render("나무장작", getMemDC(), MAPTOOLPOINT - IMAGE->findImage("나무장작")->getWidth(), 0);
	//if (m_subTile == 2)IMAGE->render("나무장작", getMemDC(), MAPTOOLPOINT - IMAGE->findImage("나무장작")->getWidth(), 0);
	//if (m_subTile == 0)IMAGE->render("tilemap", getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth(), 0);

	//오른쪽 타일 그리드
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		LineMake(getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth(), i * TILESIZE, MAPTOOLPOINT, i * TILESIZE);
	}
	for (int i = 0; i < SAMPLETILEX; i++)
	{
		LineMake(getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth() + i * TILESIZE, 0, MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth() + i * TILESIZE, IMAGE->findImage("tilemap")->getHeight());
	}

	SetTextColor(getMemDC(), RGB(0, 0, 0));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 160, TEXT("지형    - 1"), lstrlen("지형    - 1"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 180, TEXT("오브젝트    - 2"), lstrlen("오브젝트    - 2"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 200, TEXT("지우개    - E"), lstrlen("지우개    - E"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 220, TEXT("세이브    - 컨트롤+S"), lstrlen("세이브    - 컨트롤+S"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 240, TEXT("로드    - 컨트롤+V"), lstrlen("로드    - 컨트롤+V"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 260, TEXT("채우기    - 3"), lstrlen("채우기    - 3"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 280, TEXT("뒤로가기    - 컨트롤+Z"), lstrlen("뒤로가기    - 컨트롤+Z"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 300, TEXT("타일맵 그리드    - F1(on),F2(off)"), lstrlen("타일맵 그리드    - F1(on),F2(off)"));

	this->clickAlphaRender();
}

void mapToolSub::maptoolSetup()
{

	_ctrSelect = static_cast<int>(CTRL::CTRL_TERRAINDRAW);

	//샘플 맵 셋팅 모든 타일 인덱싱
	for (size_t i = 0; i < SAMPLETILEY; i++)
	{
		for (size_t j = 0; j < SAMPLETILEX; j++)
		{
			_sampleTiles[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTiles[i * SAMPLETILEX + j].terrainFrameY = i;

			//렉트 생성
			if (m_subTile == 0)
			{
				SetRect(&_sampleTiles[i * SAMPLETILEX + j].rcTile,
					(MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth()) + j * TILESIZE,
					i * TILESIZE, (MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth()) + j * TILESIZE + TILESIZE,
					i * TILESIZE + TILESIZE);
			}
			if (m_subTile == 1)
			{
				SetRect(&_sampleTiles[i * SAMPLETILEX + j].rcTile,
					(MAPTOOLPOINT - IMAGE->findImage("나무장작")->getWidth()) + j * TILESIZE,
					i * TILESIZE, (MAPTOOLPOINT - IMAGE->findImage("나무장작")->getWidth()) + j * TILESIZE + TILESIZE,
					i * TILESIZE + TILESIZE);
			}
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

// 코드 간략화를 위한 함수들

void mapToolSub::inputFunction()
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

	if (InputManager->isOnceKeyDown('1'))
	{
		_ctrSelect = static_cast<int>(CTRL::CTRL_TERRAINDRAW);
	}
	else if (InputManager->isOnceKeyDown('2'))
	{
		_ctrSelect = static_cast<int>(CTRL::CTRL_OBJDRAW);
	}
	else if (InputManager->isOnceKeyDown('E'))
	{
		_ctrSelect = static_cast<int>(CTRL::CTRL_ERASER);
		memset(&m_currentDragTile, 0, sizeof(tagDragTileIndex));
	}
	else if (InputManager->isStayKeyDown(VK_CONTROL) && InputManager->isOnceKeyDown('S'))
	{
		this->mapSave();
	}
	else if (InputManager->isStayKeyDown(VK_CONTROL) && InputManager->isOnceKeyDown('V'))
	{
		this->mapLoad();
	}
	else if (InputManager->isOnceKeyDown('3'))
	{
		_ctrSelect = static_cast<int>(CTRL::CTRL_FILL);
	}
	else if (InputManager->isStayKeyDown(VK_CONTROL) && InputManager->isOnceKeyDown('Z'))
	{
		// 뒤로가기 -> 저장해뒀던 타일 정보를 다시 대입,  동적할당받은 타일 반환
		if (m_mapToolmain->getMemoryTile()->size() == 1)
		{
			m_mapToolmain->setTile(m_mapToolmain->getTagTile(), m_mapToolmain->getMemoryTile()->back());
		}
		else
		{
			tagTile* temp2 = m_mapToolmain->getMemoryTile()->back();
			m_mapToolmain->getMemoryTile()->pop_back();
			m_mapToolmain->setTile(m_mapToolmain->getTagTile(), m_mapToolmain->getMemoryTile()->back());
			SAFE_DELETE(temp2);
		}
	}

	// 샘플 타일 전환
	if (InputManager->isOnceKeyDown(VK_TAB))
	{
		if (m_subTile <= 7)m_subTile++;
		if (m_subTile > 7)m_subTile = 0;
		maptoolSetup();
	}

	//왼쪽 타일맵 그리드 on off
	if (InputManager->isOnceKeyDown(VK_F1)) isTileLine = true;
	if (InputManager->isOnceKeyDown(VK_F2)) isTileLine = false;
}

void mapToolSub::clickAlphaRender()
{
	// 샘플타일 마우스 클릭시 타일 이미지 알파랜더
	if (m_isTileClick && _ctrSelect != static_cast<int>(CTRL::CTRL_ERASER))
	{
		if (_ctrSelect == static_cast<int>(CTRL::CTRL_FILL))
		{
			if (m_subTile == 0)IMAGE->findImage("tilemap")->alphaframeRender(getMemDC(), m_ptMouse.x - 10, m_ptMouse.y - 10, _currentTile.frame_x, _currentTile.frame_y, 128);
		}
		else
		{
			// 드래그로 범위 선택
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
