#pragma once
#include"image.h"
#include"Cimage.h"
#include"rootHeader.h"
static image* backBuffer = IMAGE->addImage("backbuffer", WINSIZEX, WINSIZEY);
static image* mapBuffer = IMAGE->addImage("mapBuffer", MAPSIZE, MAPSIZE);

class gameNode
{

	//image* _backBuffer;	//백버퍼
	//void setBackBuffer();//백버퍼 셋팅

	HDC _hdc;
	bool  _managerInit;

public:
	gameNode();
	virtual~gameNode();

	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);

	image* getBackBuffer()const { return backBuffer; }
	image* getMapBuffer() const { return mapBuffer; }

	HDC getHDC()const { return _hdc; }
	HDC getMemDC()const { return backBuffer->getMemDC(); }
	HDC getMapDC()const { return mapBuffer->getMemDC(); }


	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};