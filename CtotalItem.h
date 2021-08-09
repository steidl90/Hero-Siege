#pragma once
#include"rootHeader.h"
#include"singleton.h"

class Citem;
class CtotalItem : public Singleton<CtotalItem>
{
	vector<Citem*> m_totalItem;
	vector<string> itemList;

	string m_bigImage;
	string m_smallImage;
	string m_name;
	ITEMTYPE m_Type;
	int m_atk;
	int m_def;
	int m_hp;
	int m_mp;
	int m_critical;
	int m_criticalAtk;
	int m_speed;
	int m_limitLevel;
	int m_itemBuyPrice;
	int m_id;
	// 아이템 등급 추가해야함
	POINT m_frame;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void itemInit();

	Citem* getItem(int id);
};

