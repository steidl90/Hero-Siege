#pragma once
#include"gameNode.h"

/*
	왼쪽 타일 부분

	이미지로 그리기 위한 툴 클래스입니다

*/

// 메인 맵툴의 타일 정보 가져오기 위한 전방참조
class mapToolMain;

class mapToolSub : public gameNode
{

private:

	mapToolMain* m_mapToolmain;

	tagSampleTile _sampleTiles[SAMPLETILEX * SAMPLETILEY];

	tagCurrentTile _currentTile; // 공용

	int _ctrSelect; // 공용
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

