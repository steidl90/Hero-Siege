#include "framework.h"
#include "CtotalItem.h"
#include"Citem.h"

// 추후에 ReadFile로 불러온 값으로 아이템 정보들 생성
HRESULT CtotalItem::init()
{
	// 큰이미지 / 작은이미지 / 템이름 / 타입 / 공격력 / 방어력 / 체력 / 마나 / 크리율 /
	// 크리데미지 / 스피드 / 제한레벨 / 가격 / 프레임 x,y

	Citem* inputItem = new Citem("무기빅", "무기빅", "일반 창", ITEMTYPE::ITEMTYPE_WEAPON, 30, 0, 0, 10, 20,
		20, 0, 10, 1000, PointMake(0, 0));
	Citem* inputItem2 = new Citem("갑옷빅", "갑옷스몰", "일반 갑옷", ITEMTYPE::ITEMTYPE_ARMOR, 0, 30, 100, 10, 0,
		0, 0, 10, 1000, PointMake(0, 0));
	Citem* inputItem3 = new Citem("갑옷빅", "갑옷스몰", "강화 갑옷", ITEMTYPE::ITEMTYPE_ARMOR, 0, 50, 200, 10, 0,
		0, 0, 15, 1500, PointMake(1, 0));
	Citem* inputItem4 = new Citem("무기빅", "무기빅", "강화 창", ITEMTYPE::ITEMTYPE_WEAPON, 50, 0, 0, 20, 30,
		30, 0, 15, 1500, PointMake(1, 0));


	m_totalItem.push_back(inputItem);
	m_totalItem.push_back(inputItem2);
	m_totalItem.push_back(inputItem3);
	m_totalItem.push_back(inputItem4);

	return S_OK;
}

void CtotalItem::release()
{

}

void CtotalItem::update(){}

void CtotalItem::render(){}

// id를 통해 필요한 아이템 return
Citem* CtotalItem::getItem(int id)
{
	return m_totalItem[id];
}