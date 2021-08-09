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
	
}