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



	if (!isKeyDown) //현재 마우스의 절대 좌표값 표현 용도
	{
		m_currentX =  camera_x1 + m_ptMouse.x;
		m_currentY =  camera_y1 + m_ptMouse.y;
	}
	if (InputManager->isStayKeyDown(VK_RBUTTON))
	{
		isKeyDown = true;

		m_nextX = camera_x1 + m_ptMouse.x;
		m_nextY = camera_y1 + m_ptMouse.y;
		if (m_nextX < m_currentX) //마우스를 왼쪽으로 이동시키면 화면이 오른쪽으로 이동한다
		{
			camera_x1 += m_currentX - m_nextX;
		}
		else if (m_nextX > m_currentX) //마우스를 오른쪽으로 이동시키면 화면이 왼쪽으로 이동한다
		{
			camera_x1 -= m_nextX - m_currentX;
		}
		if (m_nextY < m_currentY) //마우스를 위쪽으로 이동시키면 화면이 아래쪽으로 이동한다
		{
			camera_y1 += m_currentY - m_nextY;
		}
		else if (m_nextY > m_currentY) //마우스를 아래쪽으로 이동시키면 화면이 위쪽으로 이동한다
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
	sprintf_s(str, "카메라 x1 : %d, 카메라 y1: %d, 카메라 x2: %d, 카메라 y2: %d ", camera_x1, camera_y1, camera_x2, camera_y2);
	sprintf_s(str2, "타겟 x1 : %d, 타겟 y1 : %d", target_x, target_y);
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