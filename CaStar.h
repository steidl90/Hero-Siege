#pragma once
#include "gameNode.h"

#define TILE_X 20
#define TILE_Y 20
#define WIDTH  35
#define HEIGHT 35
#define BIGNUM 5000

enum class TILE_TYPE
{
	TILE_TYPE_EMPTY,
	TILE_TYPE_START,
	TILE_TYPE_END,
	TILE_TYPE_WALL
};

enum class ASTAR_STATE
{
	ASTAR_STATE_SEARCHING,
	ASTAR_STATE_FOUND,
	ASTAR_STATE_NOWAY,
	ASTAR_STATE_END
};
struct aStarTile
{
	RECT rc;
	COLORREF color;
	bool walkable;		
	bool listOn;		
	int i, j;
	int F, G, H;
	char str[128];
	aStarTile* parent;	
	TILE_TYPE type;		
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


