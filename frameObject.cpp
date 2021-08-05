#include "framework.h"
#include "frameObject.h"

HRESULT frameObject::init(int x, int y)
{

	
	m_ani = ANIMATION->findAnimation("큰풀모션");
	
	m_x = x;
	m_y = y;
	return S_OK;
}

void frameObject::release()
{
	ANIMATION->release();
}

void frameObject::update()
{

}

void frameObject::render()
{
	IMAGE->findImage("큰풀")->aniRender(getMapDC(), m_x, m_y, m_ani);
}
