#include "framework.h"
#include "Cplayer.h"
#include "Cimage.h"
Cplayer::Cplayer()
{
}

Cplayer::~Cplayer()
{
}

HRESULT Cplayer::init()
{
	
   //DIRECTIONS
   direction= DIRECTIONS::DOWN;
   beforeDirection= DIRECTIONS::DOWN;

   //IMAGE
   playerIdle = IMAGE->findImage("플레이어아래쪽");
   playerAttack= IMAGE->findImage("플레이어아래쪽공격");
   playerMove=IMAGE->findImage("플레이어아래쪽걷기");

    //MOVE
   ANIMATION->addDefAnimation("플레이어위쪽걷기", "플레이어위쪽걷기",10, false, true);
   ANIMATION->addDefAnimation("플레이어아래쪽걷기", "플레이어아래쪽걷기", 10, false, true);
   ANIMATION->addDefAnimation("플레이어왼쪽걷기", "플레이어왼쪽걷기", 10, false, true);
   ANIMATION->addDefAnimation("플레이어오른쪽걷기", "플레이어오른쪽걷기", 10, false, true);

    //IDLE
   ANIMATION->addDefAnimation("플레이어위쪽", "플레이어위쪽", 10, false, true);
   ANIMATION->addDefAnimation("플레이어아래쪽", "플레이어아래쪽", 10, false, true);
   ANIMATION->addDefAnimation("플레이어왼쪽", "플레이어왼쪽", 10, false, true);
   ANIMATION->addDefAnimation("플레이어오른쪽", "플레이어오른쪽", 10, false, true);

    //ATTACK
   ANIMATION->addDefAnimation("플레이어위쪽공격", "플레이어위쪽공격", 10, false, true);
   ANIMATION->addDefAnimation("플레이어아래쪽공격", "플레이어아래쪽공격", 10, false, true);
   ANIMATION->addDefAnimation("플레이어왼쪽공격", "플레이어왼쪽공격", 10, false, true);
   ANIMATION->addDefAnimation("플레이어오른쪽공격", "플레이어오른쪽공격", 10, false, true);

   //기본상태
   playerIdleAni = ANIMATION->findAnimation("플레이어아래쪽");
   playerAttackAni = ANIMATION->findAnimation("플레이어아래쪽공격");
   playerMoveAni = ANIMATION->findAnimation("플레이어아래쪽걷기");
   
   //렉트
   playerIdleRc = RectMakeCenter(WINSIZEX/2, WINSIZEY/2, playerIdle->getFrameWidth(), playerIdle->getHeight());
   playerAttackRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, playerAttack->getFrameWidth(), playerAttack->getHeight());
   playerMoveRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, playerMove->getFrameWidth(), playerMove->getFrameHeight());

   playerX = WINSIZEX / 2;
   playerY = WINSIZEY / 2;
    return S_OK;
}

void Cplayer::release()
{
}

void Cplayer::update()
{
}

void Cplayer::render()
{
	playerMove->aniRender(getMapDC(), playerMoveRc.left,playerMoveRc.top, playerMoveAni);

}

void Cplayer::setPlayerPosition()
{
}

void Cplayer::move()
{
	float elpasedTime = TIME->getElapsedTime();
	float moveSpeed = elpasedTime * speed;

	bool isMoving = false;

	if (InputManager->isStayKeyDown(VK_UP))
	{
		playerY -= moveSpeed;
		direction = DIRECTIONS::UP;
		isMoving = true;
	}
	else if (InputManager->isStayKeyDown(VK_DOWN))
	{
		playerY += moveSpeed;
		direction = DIRECTIONS::DOWN;
		isMoving = true;
	}

	if (InputManager->isStayKeyDown(VK_LEFT))
	{
		playerX -= moveSpeed;
		direction = DIRECTIONS::LEFT;
		isMoving = true;
	}
	else if (InputManager->isStayKeyDown(VK_RIGHT))
	{
		playerX += moveSpeed;
		direction = DIRECTIONS::RIGHT;
		isMoving = true;
	}
	playerMoveRc = RectMakeCenter(playerX, playerY, playerMoveAni->getFrameWidth(), playerMoveAni->getFrameHeight());

}

void Cplayer::moveAnimation()
{
	switch (direction);
}
