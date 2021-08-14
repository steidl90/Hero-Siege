#pragma once
#include "Cobject.h"
class CNPC : public Cobject
{
private:
	RECT m_garNorRc; //¿¹½Ã
	image* m_garNorImage;
	animation* m_garNorAni;
	int m_garNorX;
	int m_garNorY;

	RECT m_shopKeeperRc;
	image* m_shopKeeperImage;
	animation* m_shopKeeperAni;
	int m_shopKeeperX;
	int m_shopKeeperY;

	RECT m_blackMarketRc;
	image* m_blackMarketImage;
	animation* m_blackMarketAni;
	int m_blackMarketX;
	int m_blackMarketY;

	RECT m_edwardRc;
	image* m_edwardImage;
	animation* m_edwardAni;
	int m_edwardX;
	int m_edwardY;

	RECT m_ericRc;
	image* m_ericImage;
	animation* m_ericAni;
	int m_ericX;
	int m_ericY;

	RECT m_halsteinRc;
	image* m_halsteinImage;
	animation* m_halsteinAni;
	int m_halsteinX;
	int m_halsteinY;

	bool a;
public:
	HRESULT init();
	void release();
	void update();
	void render();
	void getNpcAni();
	
	RECT* getGaNorRect() { return &m_garNorRc; }
};

