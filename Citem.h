#pragma once
#include "Cobject.h"

enum class ITEMKIND
{
	ITEMKIND_ONE,
	ITEMKIND_TWO
};

enum class ITEMTYPE
{
	ITEMTYPE_ONE,
	ITEMTYPE_TWO,
	ITEMTYPE_THREE
};

struct item
{
	ITEMKIND itemKind;
	ITEMTYPE itemType;
};

class Citem : public Cobject
{
private:
	item item;

public:
	Citem();
	~Citem();

	HRESULT init();
	void release();
	void update();
	void render();

	void load();
};

