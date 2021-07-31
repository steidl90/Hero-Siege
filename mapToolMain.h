#pragma once
#include"gameNode.h"
#include<list>
/*
	왼쪽 타일 부분
	맵에 그려지는 클래스입니다

*/
class mapToolSub;
class camera;
class mapToolMain : public gameNode
{

	typedef list<tagTile*> tileMemory;

private:

	camera* m_camera;

	tagTile _tiles[TILEX * TILEY];
	tagTile temp_tiles[TILEX * TILEY];

	tagCurrentTile _currentTile; // 공용

	tagDragTileIndex m_currentDragTile; // 공용

	tileMemory m_lTileMemory;
	tileMemory::iterator m_liTileMemory;

	int _ctrSelect; // 공용

	vector<int> m_vSelectTileIndex;

	// 버튼 클릭 여부 
	bool m_isButtonClick;
	//토글 느낌으로 쓰는 키업 변수
	bool m_isKeyUp;

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

	void setMainMapCurrentTile(tagCurrentTile tile) { _currentTile = tile; }
	void setMainMapDragTile(tagDragTileIndex tile) { m_currentDragTile = tile; }
	void setMainMapSelect(int select) { _ctrSelect = select; }
	void setCameraMemory(camera* c) { m_camera = c; }

	void pushTile();
	void setTile(tagTile* tileDst, tagTile* tileSour);
	tileMemory* getMemoryTile() { return &m_lTileMemory; }
	tagTile* getTagTile() { return _tiles; }

	void indexCalculate(vector<int> vInt, int* x1, int* y1, int* x2, int* y2);
};

