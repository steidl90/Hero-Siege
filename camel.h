#pragma once
#include"gameNode.h"
#include"camera.h"
#include"rootHeader.h"

class mapToolMain;
enum class DIRECTION
{
	LEFT, RIGHT, TOP, DOWN, IDLE
};
class camel : public gameNode
{
private:

	image* _camel;
	image* _red;
	animation* _ani1;
	animation* _ani2;
	animation* _ani3;

	mapToolMain* _map;



	RECT _redRc;
	int _x;
	int _y;
	int _speed;
	int m_currentX;
	int m_currentY;

	int m_nextX;
	int m_nextY;

	bool isKeyDown;

	int tileX;
	int tileY;

	int m_count;
	DIRECTION direct;

	animation* _ani;

	bool isUp;
	bool isRight;
	bool isDown;
	bool isLeft;

public:
	camel();
	~camel();

	HRESULT init();
	void release();
	void update();
	void render();

	void playerMove();

	RECT* getPlayRc() { return &_redRc; }
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	void setSpeed(int sp) { _speed = sp; }

	void setMapMemory(mapToolMain* mt) { _map = mt; }
};

