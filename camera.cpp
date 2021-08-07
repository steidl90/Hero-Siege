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

	SetTextColor(getMemDC(), RGB(255, 255, 0));
	TextOut(getMemDC(), WINSIZEX / 2 - 500, 20, str, lstrlen(str));
	TextOut(getMemDC(), WINSIZEX / 2 - 500, 35, str2, lstrlen(str2));
}