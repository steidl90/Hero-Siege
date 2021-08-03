#pragma once
#define CAMERAWIDTH (WINSIZEX - 700)
#define CAMERAHEIGHT WINSIZEY
#define MAPTOOLPOINT (WINSIZEX - 30)

#define MAPSIZE TILEX * TILESIZE

/*
	���� Ÿ���� (��) Ŭ�������� ����� enum class, ����ü��

	�� Ÿ���� (�׸���) Ŭ�������� ����� �͵� ���⿡ ����!
*/

#define TILESIZE  36		//���� Ÿ�� �̹��� ������
#define TILEX	  50		//�� Ÿ�� x�� ���� 
#define TILEY     50		//�� Ÿ�� y�� ����


#define TILESIZEX TILEX * TILESIZE	// �� Ÿ�� ��ü x�� ������(����)
#define TILESIZEY TILEY * TILESIZE

// ����
// ���� Ÿ�� ����
#define SAMPLETILEX 18
#define SAMPLETILEY 8

// ������ ����� ���,  ���� �������� CRTL�� ���� �� Ÿ�� �Ӽ����� ���
enum class CTRL
{
	CTRL_TERRAINDRAW,
	CTRL_OBJDRAW,
	CTRL_ERASER,
	CTRL_FILL
};

//���� �Ӽ� ����
enum class TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//������Ʈ �Ӽ� ����
//(ex : ���� ���ʿ�  ��ġ, �����̰ų� �μ����ų��ϴ� ��ȭ�� �ټ��ִ� ��ü)
enum class OBJECT
{
	OBJ_BLOCK1,
	OBJ_BLOCK3,
	OBJ_BLOCKS,
	OBJ_NONE
};

//������ Ÿ�� ���� ���� �뵵
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

//Ÿ�� ����ü (�ʿ� �׸� Ÿ��)
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

//���� (����) Ÿ�� ����ü
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

//���� Ÿ�� ����ü
struct tagCurrentTile
{
	int frame_x;
	int frame_y;

	char* terrainImage[20];
	char* objImage[20];
};

// �巡�� �ҽ� ���� Ÿ�� �ε��� x,y ���� �� Ÿ�� �ε��� x, y ����
struct tagDragTileIndex
{
	int index_StartX;
	int index_StartY;
	int index_EndX;
	int index_EndY;

	// ���� �ʿ��� �̿�
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