#include "framework.h"
#include "CenemyAttack.h"

CenemyAttack::CenemyAttack(){}

CenemyAttack::~CenemyAttack(){}

HRESULT CenemyAttack::init(int skillMax, float range, const char* aniName)
{
	ANIMATION->addDefAnimation("¿¤¸®¸àÅ»½ºÅ³¾Ö´Ï", "¿¤¸®¸àÅ»½ºÅ³", 10, false, true);
	ANIMATION->addDefAnimation("¸®Ä¡½ºÅ³¾Ö´Ï", "¸®Ä¡½ºÅ³", 15, false, true);
	
	m_ani = aniName;
	m_skillMax = skillMax;
	m_range = range;

	return S_OK;
}

void CenemyAttack::release()
{
}

void CenemyAttack::update()
{
	for (m_viSkill = m_vSkill.begin(); m_viSkill != m_vSkill.end();)
	{
		m_viSkill->m_x += cosf(m_viSkill->m_angle) * m_viSkill->m_speed;
		m_viSkill->m_y -= sinf(m_viSkill->m_angle) * m_viSkill->m_speed;

		m_viSkill->m_rc = RectMakeCenter(m_viSkill->m_x, m_viSkill->m_y,
			m_viSkill->m_skillImage->getFrameWidth(),
			m_viSkill->m_skillImage->getFrameHeight());
		if (m_range < UTIL::getDistance(m_viSkill->m_x, m_viSkill->m_y, m_viSkill->m_fireX, m_viSkill->m_fireY))
		{
			m_viSkill = m_vSkill.erase(m_viSkill);
		}
		else ++m_viSkill;
	}
	ANIMATION->findAnimation(m_ani);
	ANIMATION->resume(m_ani);
}

void CenemyAttack::render()
{
	for (m_viSkill = m_vSkill.begin(); m_viSkill != m_vSkill.end(); ++m_viSkill)
	{
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

void CenemyAttack::removeSkill(int arrNum)
{
	m_vSkill.erase(m_vSkill.begin() + arrNum);
}
