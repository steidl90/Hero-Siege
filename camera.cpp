#include"framework.h"
#include "camera.h"

HRESULT camera::init()
{

	camera_width = CAMERAWIDTH;
	camera_height = CAMERAHEIGHT;
	return S_OK;

}

void camera::release()
{
}

void camera::update()
{


	camera_x1 = target_x - camera_width / 2;
	camera_y1 = target_y - camera_height / 2;
	camera_x2 = camera_x1 + camera_width;
	camera_y2 = camera_y1 + camera_height;


	if (camera_x1 <= 0)
	{
		camera_x1 = 0;
		camera_x2 = camera_width;
	}
	if (camera_y1 <= 0)
	{
		camera_y1 = 0;
		camera_y2 = camera_height;
	}

	if (camera_x2 >= 2500)
	{
		camera_x2 = 2500;
		camera_x1 = camera_x2 - camera_width;

	}
	if (camera_y2 >= WINSIZEY + 500)
	{
		camera_y2 = WINSIZEY + 500;
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

	LineMake(getMemDC(), camera_x1, camera_y1, camera_x1, camera_y2);
	LineMake(getMemDC(), camera_x1, camera_y1, camera_x2, camera_y1);
	LineMake(getMemDC(), camera_x2, camera_y1, camera_x2, camera_y2);
	LineMake(getMemDC(), camera_x1, camera_y2, camera_x2, camera_y2);

	//HPEN oldPen;
	//oldPen = (HPEN)::SelectObject(getMapDC(), (HGDIOBJ)pen);
	//pen = (HPEN)::SelectObject(getMapDC(), oldPen);
	//DeleteObject(pen);
}