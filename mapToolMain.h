#pragma once
#include"gameNode.h"
#include"frameObject.h"
#include<list>
/*
	왼쪽 타일 부분
	맵에 그려지는 클래스입니다
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

	tagCurrentTile _currentTile; // 공용

	tagDragTileIndex m_currentDragTile; // 공용

	int _ctrSelect; // 공용

	int m_subTile; //오른쪽 타일, 공용

	tileMemory m_lTileMemory;

	tileImageMemory m_lTileImageMemory;

	vector<int> m_vSelectTileIndex;

	vector<frameObject*> m_frameObject;

	frameObject* m_test;

	// 버튼 클릭 여부 
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

	// 공용 데이터 받아오기
	void setMainMapCurrentTile(tagCurrentTile tile) { _currentTile = tile; }
	void setMainMapDragTile(tagDragTileIndex tile) { m_currentDragTile = tile; }
	void setMainMapSelect(int select) { _ctrSelect = select; }
	void setSubTile(int sub) { m_subTile = sub; }

	void setCameraMemory(camera* c) { m_camera = c; }

	void setFrameObject(int x, int y);

	// 뒤로가기 구현위해 필요한 함수들
	void pushTile();
	void setTile(tagTile* tileDst, tagTile* tileSour, tagTileImage* tileImgDst, tagTileImage* tileImgSour);
	tileMemory* getMemoryTile() { return &m_lTileMemory; }
	tileImageMemory* getMemoryTileImage() { return &m_lTileImageMemory; }


	void indexCalculate(vector<int> vInt, int* x1, int* y1, int* x2, int* y2);

	// 코드 간략화를 위한 함수들

	void drawTerrain(int index);
	void drawObject(int index);
	void cullingRender();
};

