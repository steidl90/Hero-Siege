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


	return S_OK;
}

void mapToolSub::release()
{
}

void mapToolSub::update()
{
	// 좌클릭, 맵 셋팅
	if (InputManager->isStayKeyDown(VK_LBUTTON))setMap();

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
	}
	else if (PtInRect(&_save, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		this->mapSave();
	}
	else if (PtInRect(&_load, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		this->mapLoad();
	}

	m_mapToolmain->setMainMapSelect(_ctrSelect);
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

	/*TextOut(getMapDC(), WINSIZEX / 2 + 100, WINSIZEY / 2, TEXT("지형"), lstrlen("지형"));
	TextOut(getMapDC(), WINSIZEX / 2 + 200, WINSIZEY / 2, TEXT("오브젝트"), lstrlen("오브젝트"));
	TextOut(getMapDC(), WINSIZEX / 2 + 300, WINSIZEY / 2, TEXT("지우개"), lstrlen("지우개"));
	TextOut(getMapDC(), WINSIZEX / 2 + 100, WINSIZEY / 2 + 100, TEXT("세이브"), lstrlen("세이브"));
	TextOut(getMapDC(), WINSIZEX / 2 + 200, WINSIZEY / 2 + 100, TEXT("로드"), lstrlen("로드"));*/
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
	//오른쪽 샘플 클릭하는 순간
	for (size_t i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
	{
		if (PtInRect(&_sampleTiles[i].rcTile, m_ptMouse))
		{
			_currentTile.frame_x = _sampleTiles[i].terrainFrameX;
			_currentTile.frame_y = _sampleTiles[i].terrainFrameY;
			break;
		}
	}

	m_mapToolmain->setMainMapCurrentTile(_currentTile);
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