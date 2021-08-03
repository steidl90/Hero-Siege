#pragma once
#define CAMERAWIDTH (WINSIZEX - 700)
#define CAMERAHEIGHT WINSIZEY
#define MAPTOOLPOINT (WINSIZEX - 30)

#define MAPSIZE TILEX * TILESIZE

/*
	샘플 타일쪽 (툴) 클래스에서 사용할 enum class, 구조체와

	맵 타일쪽 (그리기) 클래스에서 사용할 것들 여기에 선언!
*/

#define TILESIZE  36		//샘플 타일 이미지 사이즈
#define TILEX	  50		//맵 타일 x축 개수 
#define TILEY     50		//맵 타일 y축 개수


#define TILESIZEX TILEX * TILESIZE	// 맵 타일 전체 x축 사이즈(길이)
#define TILESIZEY TILEY * TILESIZE

// 툴용
// 샘플 타일 갯수
#define SAMPLETILEX 18
#define SAMPLETILEY 8

// 툴에서 사용할 기능,  현재 선택중인 CRTL에 따라 맵 타일 속성정의 등등
enum class CTRL
{
	CTRL_TERRAINDRAW,
	CTRL_OBJDRAW,
	CTRL_ERASER,
	CTRL_FILL
};

//지형 속성 종류
enum class TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//오브젝트 속성 종류
//(ex : 지형 위쪽에  배치, 움직이거나 부서지거나하는 변화를 줄수있는 물체)
enum class OBJECT
{
	OBJ_BLOCK1,
	OBJ_BLOCK3,
	OBJ_BLOCKS,
	OBJ_NONE
};

//오른쪽 타일 종류 변경 용도
enum class KINDSUBTILE
{
	KINDSUBTILE_DEFAULT,
	KINDSUBTILE_TREEONE,
	KINDSUBTILE_TREETWO,
	KINDSUBTILE_TREETHREE,
	KINDSUBTILE_HOUSEONE,
	KINDSUBTILE_HOUSETWO,
	KINDSUBTILE_HOUSETHREE,
	KINDSUBTILE_OBJECTONE,
	KINDSUBTILE_OBJECTTWO,
};

//타일 구조체 (맵에 그릴 타일)
struct tagTile
{

	TERRAIN terrain;
	OBJECT obj;
	RECT  rc;

	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;

};

//샘플 (툴용) 타일 구조체
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

//현재 타일 구조체
struct tagCurrentTile
{
	int frame_x;
	int frame_y;

	char* terrainImage[20];
	char* objImage[20];
};

// 드래그 할시 시작 타일 인덱스 x,y 정보 끝 타일 인덱스 x, y 정보
struct tagDragTileIndex
{
	int index_StartX;
	int index_StartY;
	int index_EndX;
	int index_EndY;

	// 메인 맵에서 이용
	int frame_StartX;
	int frame_StartY;
	int frame_EndX;
	int frame_EndY;

	char* terrainImage[20];
	char* objImage[20];
};

struct tagTileImage
{
	char* terrainImage[20];
	char* objImage[20];
};