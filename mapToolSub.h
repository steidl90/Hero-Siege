#pragma once
#include"gameNode.h"

/*
	���� Ÿ�� �κ�

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

	int _ctrSelect; // ����
	int _pos[2];

	RECT _terrain;
	RECT _object;
	RECT _erase;
	RECT _save;
	RECT _load;

public:

	HRESULT init();
	void release();
	void update();
	void render(/*HDC hdc*/);

	void maptoolSetup();
	void setMap();

	void mapSave();
	void mapLoad();

	void setMapToolMainMemory(mapToolMain* mt) { m_mapToolmain = mt; }
};

