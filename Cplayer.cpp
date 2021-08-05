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
   playerIdle = IMAGE->findImage("�÷��̾�Ʒ���");
   playerAttack= IMAGE->findImage("�÷��̾�Ʒ��ʰ���");
   playerMove=IMAGE->findImage("�÷��̾�Ʒ��ʰȱ�");

    //MOVE
   ANIMATION->addDefAnimation("�÷��̾����ʰȱ�", "�÷��̾����ʰȱ�",10, false, true);
   ANIMATION->addDefAnimation("�÷��̾�Ʒ��ʰȱ�", "�÷��̾�Ʒ��ʰȱ�", 10, false, true);
   ANIMATION->addDefAnimation("�÷��̾���ʰȱ�", "�÷��̾���ʰȱ�", 10, false, true);
   ANIMATION->addDefAnimation("�÷��̾�����ʰȱ�", "�÷��̾�����ʰȱ�", 10, false, true);

    //IDLE
   ANIMATION->addDefAnimation("�÷��̾�����", "�÷��̾�����", 10, false, true);
   ANIMATION->addDefAnimation("�÷��̾�Ʒ���", "�÷��̾�Ʒ���", 10, false, true);
   ANIMATION->addDefAnimation("�÷��̾����", "�÷��̾����", 10, false, true);
   ANIMATION->addDefAnimation("�÷��̾������", "�÷��̾������", 10, false, true);

    //ATTACK
   ANIMATION->addDefAnimation("�÷��̾����ʰ���", "�÷��̾����ʰ���", 10, false, true);
   ANIMATION->addDefAnimation("�÷��̾�Ʒ��ʰ���", "�÷��̾�Ʒ��ʰ���", 10, false, true);
   ANIMATION->addDefAnimation("�÷��̾���ʰ���", "�÷��̾���ʰ���", 10, false, true);
   ANIMATION->addDefAnimation("�÷��̾�����ʰ���", "�÷��̾�����ʰ���", 10, false, true);

   //�⺻����
   playerIdleAni = ANIMATION->findAnimation("�÷��̾�Ʒ���");
   playerAttackAni = ANIMATION->findAnimation("�÷��̾�Ʒ��ʰ���");
   playerMoveAni = ANIMATION->findAnimation("�÷��̾�Ʒ��ʰȱ�");
   
   //��Ʈ
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
