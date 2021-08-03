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
	//���� Ÿ�ϸ� �׸��� on off
	if (isTileLine)
	{
		for (int i = 0; i < TILEX; i++)
		{
			LineMake(getMapDC(), 0, i * TILESIZE, MAPSIZE, i * TILESIZE);
			LineMake(getMapDC(), i * TILESIZE, 0, i * TILESIZE, MAPSIZE);
		}
	}

	// �Է� ��� ����
	this->inputFunction();
	
	setMap();

	// ��������, ������ mainTool�� �����ֱ�
	m_mapToolmain->setMainMapSelect(_ctrSelect);
	m_mapToolmain->setMainMapDragTile(m_currentDragTile);
	m_mapToolmain->setMainMapCurrentTile(_currentTile);
}

void mapToolSub::render()
{
	//������ Ÿ�� �̹���
	if (m_subTile == 0)IMAGE->render("tilemap", getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth(), 0);
	if (m_subTile == 1)IMAGE->render("��������", getMemDC(), MAPTOOLPOINT - IMAGE->findImage("��������")->getWidth(), 0);
	//if (m_subTile == 2)IMAGE->render("��������", getMemDC(), MAPTOOLPOINT - IMAGE->findImage("��������")->getWidth(), 0);
	//if (m_subTile == 0)IMAGE->render("tilemap", getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth(), 0);

	//������ Ÿ�� �׸���
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		LineMake(getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth(), i * TILESIZE, MAPTOOLPOINT, i * TILESIZE);
	}
	for (int i = 0; i < SAMPLETILEX; i++)
	{
		LineMake(getMemDC(), MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth() + i * TILESIZE, 0, MAPTOOLPOINT - IMAGE->findImage("tilemap")->getWidth() + i * TILESIZE, IMAGE->findImage("tilemap")->getHeight());
	}

	SetTextColor(getMemDC(), RGB(0, 0, 0));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 160, TEXT("����    - 1"), lstrlen("����    - 1"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 180, TEXT("������Ʈ    - 2"), lstrlen("������Ʈ    - 2"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 200, TEXT("���찳    - E"), lstrlen("���찳    - E"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 220, TEXT("���̺�    - ��Ʈ��+S"), lstrlen("���̺�    - ��Ʈ��+S"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 240, TEXT("�ε�    - ��Ʈ��+V"), lstrlen("�ε�    - ��Ʈ��+V"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 260, TEXT("ä���    - 3"), lstrlen("ä���    - 3"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 280, TEXT("�ڷΰ���    - ��Ʈ��+Z"), lstrlen("�ڷΰ���    - ��Ʈ��+Z"));
	TextOut(getMemDC(), CAMERAWIDTH + 30, WINSIZEY / 2 + 300, TEXT("Ÿ�ϸ� �׸���    - F1(on),F2(off)"), lstrlen("Ÿ�ϸ� �׸���    - F1(on),F2(off)"));

	this->clickAlphaRender();
}

void mapToolSub::maptoolSetup()
{

	_ctrSelect = static_cast<int>(CTRL::CTRL_TERRAINDRAW);

	//���� �� ���� ��� Ÿ�� �ε���
	for (size_t i = 0; i < SAMPLETILEY; i++)
	{
		for (size_t j = 0; j < SAMPLETILEX; j++)
		{
			_sampleTiles[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTiles[i * SAMPLETILEX + j].terrainFrameY = i;

			//��Ʈ ����
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
					(MAPTOOLPOINT - IMAGE->findImage("��������")->getWidth()) + j * TILESIZE,
					i * TILESIZE, (MAPTOOLPOINT - IMAGE->findImage("��������")->getWidth()) + j * TILESIZE + TILESIZE,
					i * TILESIZE + TILESIZE);
			}
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

// �ڵ� ����ȭ�� ���� �Լ���

void mapToolSub::inputFunction()
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
		// �ڷΰ��� -> �����ص״� Ÿ�� ������ �ٽ� ����,  �����Ҵ���� Ÿ�� ��ȯ
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

	// ���� Ÿ�� ��ȯ
	if (InputManager->isOnceKeyDown(VK_TAB))
	{
		if (m_subTile <= 7)m_subTile++;
		if (m_subTile > 7)m_subTile = 0;
		maptoolSetup();
	}

	//���� Ÿ�ϸ� �׸��� on off
	if (InputManager->isOnceKeyDown(VK_F1)) isTileLine = true;
	if (InputManager->isOnceKeyDown(VK_F2)) isTileLine = false;
}

void mapToolSub::clickAlphaRender()
{
	// ����Ÿ�� ���콺 Ŭ���� Ÿ�� �̹��� ���ķ���
	if (m_isTileClick && _ctrSelect != static_cast<int>(CTRL::CTRL_ERASER))
	{
		if (_ctrSelect == static_cast<int>(CTRL::CTRL_FILL))
		{
			if (m_subTile == 0)IMAGE->findImage("tilemap")->alphaframeRender(getMemDC(), m_ptMouse.x - 10, m_ptMouse.y - 10, _currentTile.frame_x, _currentTile.frame_y, 128);
		}
		else
		{
			// �巡�׷� ���� ����
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
