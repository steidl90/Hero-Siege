#pragma once
#include"gameNode.h"

/*
	������ Ÿ�� �κ�

	�̹����� �׸��� ���� �� Ŭ�����Դϴ�

*/

// ���� ������ Ÿ�� ���� �������� ���� ��������
class mapToolMain;

class mapToolSub : public gameNode
{

private:

	mapToolMain* m_mapToolmain;

	tagSampleTile _sampleTiles[SAMPLETILEX * SAMPLETILEY];

	tagCurrentTile _currentTile; // ����

	tagDragTileIndex m_currentDragTile; // ����

	// ��ư Ŭ�� ���� 
	bool m_isButtonClick;
	// Ÿ�� Ŭ�� ����
	bool m_isTileClick;
	//��� �������� ���� Ű�� ����
	bool m_isKeyUp;
	int _ctrSelect; // ����
	int _pos[2];

	RECT _terrain;
	RECT _object;
	RECT _erase;
	RECT _save;
	RECT _load;
	RECT m_fill;

public:

	HRESULT init();
	void release();
	void update();
	void render(/*HDC hdc*/);

	void maptoolSetup();
	void setMap();

	void mapSave();
	void mapLoad();

	void dragTileInit();
	void setMapToolMainMemory(mapToolMain* mt) { m_mapToolmain = mt; }
};

