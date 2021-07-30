#pragma once
#include"gameNode.h"

/*
	오른쪽 타일 부분
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

	int _ctrSelect; // 공용

public:

	HRESULT init();
	void release();
	void update();
	void render(/*HDC hdc*/);

	void maptoolSetup();
	void setMap();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

	tagTile* getMainMapTile() { return _tiles; }

	void setMainMapCurrentTile(tagCurrentTile tile) { _currentTile = tile; }
	void setMainMapSelect(int select) { _ctrSelect = select; }
	void setCameraMemory(camera* c) { m_camera = c; }
};

