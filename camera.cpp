#include"framework.h"
#include "camera.h"

HRESULT camera::init()
{

	camera_width = CAMERAWIDTH;
	camera_height = CAMERAHEIGHT;
	return S_OK;

	isKeyDown = false;
}

void camera::release()
{
}

void camera::update()
{

	//camera_x1 = /*target_x - */camera_width / 2;
	//camera_y1 = /*target_y - */camera_height / 2;



	if (!isKeyDown) //���� ���콺�� ���� ��ǥ�� ǥ�� �뵵
	{
		m_currentX =  camera_x1 + m_ptMouse.x;
		m_currentY =  camera_y1 + m_ptMouse.y;
	}
	if (InputManager->isStayKeyDown(VK_RBUTTON))
	{
		isKeyDown = true;

		m_nextX = camera_x1 + m_ptMouse.x;
		m_nextY = camera_y1 + m_ptMouse.y;
		if (m_nextX < m_currentX) //���콺�� �������� �̵���Ű�� ȭ���� ���������� �̵��Ѵ�
		{
			camera_x1 += m_currentX - m_nextX;
		}
		else if (m_nextX > m_currentX) //���콺�� ���������� �̵���Ű�� ȭ���� �������� �̵��Ѵ�
		{
			camera_x1 -= m_nextX - m_currentX;
		}
		if (m_nextY < m_currentY) //���콺�� �������� �̵���Ű�� ȭ���� �Ʒ������� �̵��Ѵ�
		{
			camera_y1 += m_currentY - m_nextY;
		}
		else if (m_nextY > m_currentY) //���콺�� �Ʒ������� �̵���Ű�� ȭ���� �������� �̵��Ѵ�
		{
			camera_y1 -= m_nextY - m_currentY;
		}
	}
	else isKeyDown = false;

	camera_x2 = camera_x1 + camera_width;
	camera_y2 = camera_y1 + camera_height;


	if (camera_x1 < 0)
	{
		camera_x1 = 0;
		camera_x2 = camera_width;
	}
	if (camera_y1 < 0)
	{
		camera_y1 = 0;
		camera_y2 = camera_height;
	}

	if (camera_x2 > MAPSIZE)
	{
		camera_x2 = MAPSIZE;
		camera_x1 = camera_x2 - camera_width;

	}
	if (camera_y2 > MAPSIZE)
	{
		camera_y2 = MAPSIZE;
		camera_y1 = camera_y2 - camera_height;
	}


}

void camera::render()
{
	char str[100];
	char str2[100];
	sprintf_s(str, "ī�޶� x1 : %d, ī�޶� y1: %d, ī�޶� x2: %d, ī�޶� y2: %d ", camera_x1, camera_y1, camera_x2, camera_y2);
	sprintf_s(str2, "Ÿ�� x1 : %d, Ÿ�� y1 : %d", target_x, target_y);
	//HPEN pen;
	//pen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));

	SetTextColor(getMemDC(), RGB(255, 255, 0));
	TextOut(getMemDC(), WINSIZEX / 2 - 500, 20, str, lstrlen(str));
	TextOut(getMemDC(), WINSIZEX / 2 - 500, 35, str2, lstrlen(str2));

	/*LineMake(getMemDC(), camera_x1, camera_y1, camera_x1, camera_y2);
	LineMake(getMemDC(), camera_x1, camera_y1, camera_x2, camera_y1);
	LineMake(getMemDC(), camera_x2, camera_y1, camera_x2, camera_y2);
	LineMake(getMemDC(), camera_x1, camera_y2, camera_x2, camera_y2);*/

	//HPEN oldPen;
	//oldPen = (HPEN)::SelectObject(getMapDC(), (HGDIOBJ)pen);
	//pen = (HPEN)::SelectObject(getMapDC(), oldPen);
	//DeleteObject(pen);
}