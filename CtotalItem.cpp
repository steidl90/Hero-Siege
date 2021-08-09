#include "framework.h"
#include "CtotalItem.h"
#include"Citem.h"

// ���Ŀ� ReadFile�� �ҷ��� ������ ������ ������ ����
HRESULT CtotalItem::init()
{
	// ū�̹��� / �����̹��� / ���̸� / Ÿ�� / ���ݷ� / ���� / ü�� / ���� / ũ���� /
	// ũ�������� / ���ǵ� / ���ѷ��� / ���� / ������ x,y

	Citem* inputItem = new Citem("�����", "�����", "�Ϲ� â", ITEMTYPE::ITEMTYPE_WEAPON, 30, 0, 0, 10, 20,
		20, 0, 10, 1000, PointMake(0, 0));
	Citem* inputItem2 = new Citem("���ʺ�", "���ʽ���", "�Ϲ� ����", ITEMTYPE::ITEMTYPE_ARMOR, 0, 30, 100, 10, 0,
		0, 0, 10, 1000, PointMake(0, 0));
	Citem* inputItem3 = new Citem("���ʺ�", "���ʽ���", "��ȭ ����", ITEMTYPE::ITEMTYPE_ARMOR, 0, 50, 200, 10, 0,
		0, 0, 15, 1500, PointMake(1, 0));
	Citem* inputItem4 = new Citem("�����", "�����", "��ȭ â", ITEMTYPE::ITEMTYPE_WEAPON, 50, 0, 0, 20, 30,
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

// id�� ���� �ʿ��� ������ return
Citem* CtotalItem::getItem(int id)
{
	return m_totalItem[id];
}