#pragma once
#include"image.h"
#include"Cimage.h"

static image* backBuffer = IMAGE->addImage("backbuffer", WINSIZEX, WINSIZEY);
static image* screenbuffer = IMAGE->addImage("screenbuffer", WINSIZEX*2, WINSIZEY);

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
	HDC getHDC()const { return _hdc; }
	HDC getMemDC()const { return backBuffer->getMemDC(); }

	image* getScreenBuffer()const { return screenbuffer; }
	HDC getScreenDC()const { return screenbuffer->getMemDC(); }

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};