#pragma once
#include "Cobject.h"

class camera;
class CTown :public Cobject
{
private:
	camera* m_camera;
	
private:
	tagCurrentTile _currentTile;
	tagTile _tiles[TILEX * TILEY];
	tagTileImage _tilesImage[TILEX * TILEY];
	DWORD _attribute[TILEX * TILEY];
	int _pos[2];

public:
	CTown();
	~CTown();

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

	//void attackBlock(int tileN);
};

