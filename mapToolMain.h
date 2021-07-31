#pragma once
#include"gameNode.h"

/*
	왼쪽 타일 부분
	맵에 그려지는 클래스입니다

*/
class mapToolSub;
class camera;
class mapToolMain : public gameNode
{

private:

	camera* m_camera;

	tagTile _tiles[TILEX * TILEY];

	tagCurrentTile _currentTile; // 공용

	tagDragTileIndex m_currentDragTile; // 공용

	int _ctrSelect; // 공용

	vector<int> m_vSelectTileIndex;

	// 버튼 클릭 여부 
	bool m_isButtonClick;
	//토글 느낌으로 쓰는 키업 변수
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

