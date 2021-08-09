#pragma once
#include "Cobject.h"
#include "frameObject.h"
class camera;
class Ctown :public Cobject
{
private:
	camera* m_camera;
private:
	tagCurrentTile _currentTile;
	tagTile _tiles[TILEX * TILEY];
	tagTileImage _tilesImage[TILEX * TILEY];
	tagFrameObjectInfo m_frameObjectInfo[TILEX * TILEY];
	vector<tagFrameObject> m_frameObject;

	DWORD _attribute[TILEX * TILEY];
	int _pos[2];

public:
	Ctown();
	~Ctown();

	HRESULT init();
	void release();
	void update();
	void render();

	void setCameraMemory(camera* camera) { m_camera = camera; }

	void load();
	void cullingRender();

	DWORD* getAttribute() { return _attribute; }
	tagTile* getMap() { return _tiles; }
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	void initFrameObject();
	void setFrameObject(int x, int y, KINDFRAMEOBJECT frameKind, int index);

	string getImageName(OBJECTIMAGE image);

	//void attackBlock(int tileN);
};

