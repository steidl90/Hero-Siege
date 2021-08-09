#pragma once
#include "gameNode.h"

#define TILE_X 50
#define TILE_Y 20
#define WIDTH  35
#define HEIGHT 35
#define BIGNUM 5000

enum class TILE_TYPE		//타일속성
{
	TILE_TYPE_EMPTY,		//갈수있는곳
	TILE_TYPE_START,		//몬스터위치
	TILE_TYPE_END,			//플레이어 위치
	TILE_TYPE_WALL			//벽
};

enum class ASTAR_STATE
{
	ASTAR_STATE_SEARCHING,		//검색중
	ASTAR_STATE_FOUND,			//발견
	ASTAR_STATE_NOWAY,			//못가는곳
	ASTAR_STATE_END
};
struct aStarTile
{
	RECT rc;
	COLORREF color;
	bool walkable;				//지나갈수 있는가
	bool listOn;				//오픈리스트에 추가되었는지 여부
	int i, j;
	int F, G, H;
	char str[128];
	aStarTile* parent;			//부모타일 주소
	TILE_TYPE type;				//타일 속성
};

class CaStar :public gameNode
{
private:
	aStarTile _tile[TILE_X][TILE_Y];
	vector<aStarTile*> _openList;
	vector<aStarTile*> _closeList;

	ASTAR_STATE _astarState;
	TILE_TYPE _selectType;
	COLORREF _selectedTypeColor;

	int _startX, _startY;
	int _endX, _endY;
	int _lastIndex;

	bool _startPointSet;
	bool _endPointSet;

	int Ci;
	int Cj;
	int Cg;

	RECT rc[6];
	HBRUSH newBrush, oldBrush;
	HFONT newFont, oldFont;

public:
	CaStar();
	~CaStar();

	HRESULT init();
	void release();
	void update();
	void render();

	void tileComposition();	
	void tileInitializing();
	void addOpenList();		
	void caculateH();		
	void caculateF();		
	void addCloseList();	
	void checkArrive();		
	void showWay(aStarTile* tile);
	void typeColor(TILE_TYPE type);
};


