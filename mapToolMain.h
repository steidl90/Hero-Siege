#pragma once
#include"gameNode.h"
#include"frameObject.h"
#include<list>
/*
	���� Ÿ�� �κ�
	�ʿ� �׷����� Ŭ�����Դϴ�
*/

class camera;
class mapToolMain : public gameNode
{
	typedef list<tagTile*> tileMemory;
	typedef list<tagTileImage*> tileImageMemory;
private:

	camera* m_camera;

	tagTile _tiles[TILEX * TILEY];

	tagTileImage _tilesImage[TILEX * TILEY];

	tagCurrentTile _currentTile; // ����

	tagDragTileIndex m_currentDragTile; // ����

	int _ctrSelect; // ����

	int m_subTile; //������ Ÿ��, ����

	tileMemory m_lTileMemory;

	tileImageMemory m_lTileImageMemory;

	vector<int> m_vSelectTileIndex;

	vector<frameObject*> m_frameObject;

	frameObject* m_test;

	// ��ư Ŭ�� ���� 
	bool m_isButtonClick;

	int m_isDifferentTile;

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
	tagTileImage* getMainMapTileImage() { return _tilesImage; }

	// ���� ������ �޾ƿ���
	void setMainMapCurrentTile(tagCurrentTile tile) { _currentTile = tile; }
	void setMainMapDragTile(tagDragTileIndex tile) { m_currentDragTile = tile; }
	void setMainMapSelect(int select) { _ctrSelect = select; }
	void setSubTile(int sub) { m_subTile = sub; }

	void setCameraMemory(camera* c) { m_camera = c; }

	void setFrameObject(int x, int y);

	// �ڷΰ��� �������� �ʿ��� �Լ���
	void pushTile();
	void setTile(tagTile* tileDst, tagTile* tileSour, tagTileImage* tileImgDst, tagTileImage* tileImgSour);
	tileMemory* getMemoryTile() { return &m_lTileMemory; }
	tileImageMemory* getMemoryTileImage() { return &m_lTileImageMemory; }


	void indexCalculate(vector<int> vInt, int* x1, int* y1, int* x2, int* y2);

	// �ڵ� ����ȭ�� ���� �Լ���

	void drawTerrain(int index);
	void drawObject(int index);
	void cullingRender();
};

