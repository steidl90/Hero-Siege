#pragma once
#include"mapToolMain.h"
#include"mapToolSub.h"


class camera; // ī�޶� Ŭ���� ��ǥ���� �̿��ϱ� ���� ���漱������ ��������

class mapToolManager : public gameNode
{

	mapToolMain* m_mainMapTool;
	mapToolSub* m_subMapTool;
	camera* m_camera;

	int m_subTile;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void setCameraMemory(camera* c) { m_camera = c; }
};
