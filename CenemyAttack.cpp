#include "framework.h"
#include "CenemyAttack.h"

CenemyAttack::CenemyAttack(){}

CenemyAttack::~CenemyAttack(){}

HRESULT CenemyAttack::init()
{
	ANIMATION->addDefAnimation("¿¤¸®¸àÅ»½ºÅ³¾Ö´Ï", "¿¤¸®¸àÅ»½ºÅ³1", 10, false, true);
	ANIMATION->addDefAnimation("¸®Ä¡½ºÅ³¾Ö´Ï", "¸®Ä¡½ºÅ³", 15, false, true);

	return S_OK;
}

void CenemyAttack::release()
{
}

void CenemyAttack::update(const char* aniName)
{
	for (m_viSkill = m_vSkill.begin(); m_viSkill != m_vSkill.end();)
	{
		m_viSkill->m_x += cosf(m_viSkill->m_angle) * m_viSkill->m_speed;
		m_viSkill->m_y -= sinf(m_viSkill->m_angle) * m_viSkill->m_speed;

		m_viSkill->m_rc = RectMakeCenter(m_viSkill->m_x, m_viSkill->m_y,
			m_viSkill->m_skillImage->getFrameWidth(),
			m_viSkill->m_skillImage->getFrameHeight());

		if (m_viSkill->m_y > WINSIZEY || m_viSkill->m_y<0 || m_viSkill->m_x>WINSIZEX || m_viSkill->m_x < 0)
		{
			m_viSkill = m_vSkill.erase(m_viSkill);
		}
		else ++m_viSkill;
	}
	ANIMATION->findAnimation(aniName);
	ANIMATION->resume(aniName);
	//move();	
}

void CenemyAttack::render()
{
	for (m_viSkill = m_vSkill.begin(); m_viSkill != m_vSkill.end(); ++m_viSkill)
	{
		Rectangle(getMapDC(), m_viSkill->m_rc.left, m_viSkill->m_rc.top, m_viSkill->m_rc.right, m_viSkill->m_rc.bottom);
		m_viSkill->m_skillImage->aniRender(getMapDC(), m_viSkill->m_rc.left, m_viSkill->m_rc.top,m_viSkill->m_ani);
		
	}
}

void CenemyAttack::fire(float x, float y, float angle, float speed, const char* fileName, const char* aniName)
{
	tagSkill skill;
	ZeroMemory(&skill, sizeof(tagSkill));
	skill.m_skillImage = new image;
	skill.m_skillImage = IMAGE->findImage(fileName);
	skill.m_ani = ANIMATION->findAnimation(aniName);
	skill.m_angle = angle;
	skill.m_speed = speed;
	skill.m_x = skill.m_fireX = x;
	skill.m_y = skill.m_fireY = y;
	skill.m_rc = RectMakeCenter(skill.m_x, skill.m_y, skill.m_skillImage->getFrameWidth(), skill.m_skillImage->getFrameHeight());
	m_vSkill.push_back(skill);
}

void CenemyAttack::move()
{
	//for (m_viSkill = m_vSkill.begin(); m_viSkill != m_vSkill.end();)
	//{
	//	m_viSkill->m_x += cosf(m_viSkill->m_angle) * m_viSkill->m_speed;
	//	m_viSkill->m_y -= sinf(m_viSkill->m_angle) * m_viSkill->m_speed;

	//	m_viSkill->m_rc = RectMakeCenter(m_viSkill->m_x, m_viSkill->m_y, 
	//		m_viSkill->m_skillImage->getFrameWidth(), 
	//		m_viSkill->m_skillImage->getFrameHeight());

	//	if (m_viSkill->m_y > WINSIZEY || m_viSkill->m_y<0 || m_viSkill->m_x>WINSIZEX || m_viSkill->m_x < 0)
	//	{
	//		m_viSkill = m_vSkill.erase(m_viSkill);
	//	}
	//	else ++m_viSkill;
	//}
	ANIMATION->findAnimation("¿¤¸®¸àÅ»½ºÅ³¾Ö´Ï");
	ANIMATION->resume("¿¤¸®¸àÅ»½ºÅ³¾Ö´Ï");

	ANIMATION->findAnimation("¸®Ä¡½ºÅ³¾Ö´Ï");
	ANIMATION->resume("¸®Ä¡½ºÅ³¾Ö´Ï");
}

void CenemyAttack::removeBullet(int arrNum)
{
	m_vSkill.erase(m_vSkill.begin() + arrNum);
}
