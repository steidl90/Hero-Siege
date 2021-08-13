#pragma once
#include"Citem.h"
#include"Cinventory.h"
// 오류나면 전방참조

class Cplayer;
class Cshop
{
private:
	Cplayer* m_player;
	Cinventory* m_myInventory;
private:

	vector<Citem> m_vTotalList;

public:

	HRESULT init();
	void release();
	void update();
	//void render();

	vector<Citem>* getTotalList() { return &m_vTotalList; }

	void buyItem(Citem* item);
	void sellItem(Citem* item);

	void setPlayerMemory(Cplayer* p) { m_player = p; }
	void setInventoryMemory(Cinventory* inven) { m_myInventory = inven; }

	Cplayer* getPlayer() {	return m_player; };
	Cinventory* getInventory() { return m_myInventory; };
};

