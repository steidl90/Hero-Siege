#pragma once
#include"gameNode.h"

/*
	���� Ÿ�� �κ�
	�ʿ� �׷����� Ŭ�����Դϴ�

*/
class mapToolSub;
class camera;
class mapToolMain : public gameNode
{

private:

	camera* m_camera;

	tagTile _tiles[TILEX * TILEY];

	tagCurrentTile _currentTile; // ����

	tagDragTileIndex m_currentDragTile; // ����

	int _ctrSelect; // ����

	vector<int> m_vSelectTileIndex;

	// ��ư Ŭ�� ���� 
	bool m_isButtonClick;
	//��� �������� ���� Ű�� ����
	bool m_isKeyUp;

public:

	HRESULT init();
	void release();
	void update();
	void render(/*HDC hdc*/);

	void maptoolSetup();
	void setMap();
	void fillMap();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

	tagTile* getMainMapTile() { return _tiles; }

	void setMainMapCurrentTile(tagCurrentTile tile) { _currentTile = tile; }
	void setMainMapDragTile(tagDragTileIndex tile) { m_currentDragTile = tile; }
	void setMainMapSelect(int select) { _ctrSelect = select; }
	void setCameraMemory(camera* c) { m_camera = c; }

	void indexCalculate(vector<int> vInt, int* x1, int* y1, int* x2, int* y2);
};

