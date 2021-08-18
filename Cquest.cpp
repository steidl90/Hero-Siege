#include "framework.h"
#include "Cquest.h"
#include "Cplayer.h"

Cquest::Cquest()
{
	m_player = nullptr;
}

Cquest::~Cquest()
{
}

HRESULT Cquest::init()
{
	m_npc = new CNPC;
	m_dialogImage = IMAGE->findImage("대화창");
	m_dialogBGImage = IMAGE->findImage("대화창배경");
	m_buttonImage = IMAGE->findImage("버튼");

	m_x[0] = 1020;
	m_y[0] = 520;

	m_x[1] = WINSIZEX/2-270;
	m_y[1] = WINSIZEY/2-300;

	m_x[2] = WINSIZEX/2+3;
	m_y[2] = WINSIZEY/2-50;
	m_quest = 0;
	m_maxQuest = 50;


	ANIMATION->addDefAnimation("퀘스트애니", "퀘스트1", 6, false, true);
	ANIMATION->addDefAnimation("퀘스트2애니", "퀘스트2", 6, false, true);
	ANIMATION->addDefAnimation("퀘스트3애니", "퀘스트3", 1, false, true);
	m_questImage = IMAGE->findImage("퀘스트1");
	m_questAni = ANIMATION->findAnimation("퀘스트애니");
	ANIMATION->start("퀘스트애니");

	m_isDialog = false;
	m_isQuesting = false;
	m_isComplete = false;

	return S_OK;
}

void Cquest::release()
{
}

void Cquest::update()
{

		dialog();
		if (m_isDialog && InputManager->isOnceKeyDown('F'))
		{
			acceptQuest();
		}
		if (m_npc != nullptr)
		{
		m_questRc = RectMake(m_x[0], m_y[0], m_questImage->getFrameWidth(), m_questImage->getFrameHeight());
		m_dialogRc = RectMake(m_x[1], m_y[1], m_dialogImage->getFrameWidth(), m_dialogImage->getFrameHeight());
		m_buttonRc = RectMake(m_x[2], m_y[2], m_buttonImage->getFrameWidth(), m_buttonImage->getFrameHeight());
		}
}

void Cquest::render()
{
	if (m_npc != nullptr)
	{
		if (collision())
		{
			m_buttonImage->render(getMemDC(), m_x[2], m_y[2]);
			if (m_isDialog)
			{
				m_dialogImage->render(getMemDC(), m_x[1], m_y[1]);
				m_dialogBGImage->render(getMemDC(), m_x[1], m_y[1]);

			}
		}
		m_questImage->aniRender(getMapDC(), m_x[0], m_y[0], m_questAni);
	}
		if (m_isQuesting)
		{
			TCHAR str[256];
			sprintf_s(str, "이노야 마을");
			TextOut(getMemDC(), WINSIZEX - 165, 200, str, strlen(str));
			TCHAR queststr[256];
			sprintf_s(queststr, "%d/%d", m_quest, m_maxQuest);
			TextOut(getMemDC(), WINSIZEX - 165, 400, queststr, strlen(queststr));
		}
}

bool Cquest::collision()
{
	if(m_npc != nullptr)
	{ 
	RECT temp;
	if (IntersectRect(&temp, m_player->getplayerMoveRC(), m_npc->getGaNorRect()))
	{
		return true;
	}
	return false;

	}
	return false;
}

void Cquest::dialog()
{
	if (collision())
	{
		if (!m_isDialog)
		{
			if (InputManager->isOnceKeyDown('F'))
			{
				m_isDialog = !m_isDialog;
			}
		}
	}
}

void Cquest::acceptQuest()
{
	m_isQuesting = true;
	m_isDialog = false;
	m_questImage = IMAGE->findImage("퀘스트3");
	m_questAni = ANIMATION->findAnimation("퀘스트3애니");
	ANIMATION->start("퀘스트3애니");
}

void Cquest::completedQuest()
{
	m_questImage = IMAGE->findImage("퀘스트2");
	m_questAni = ANIMATION->findAnimation("퀘스트2애니");
	ANIMATION->start("퀘스트2애니");
}
