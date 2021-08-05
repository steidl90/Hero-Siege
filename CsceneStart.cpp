#include "framework.h"
#include "CsceneStart.h"

CsceneStart::CsceneStart()
{
}

CsceneStart::~CsceneStart()
{
}

HRESULT CsceneStart::init()
{
	m_startX = WINSIZEX - 300;
	m_startY = 350;
	m_loadX = WINSIZEX - 300;
	m_loadY = 450;
	m_exitX = WINSIZEX - 300;
	m_exitY = 550;

	IMAGE->findImage("시작화면");
	IMAGE->findImage("새게임버튼비활성화");
	IMAGE->findImage("새게임버튼활성화");
	IMAGE->findImage("불러오기버튼비활성화");
	IMAGE->findImage("불러오기버튼활성화");
	IMAGE->findImage("나가기버튼비활성화");
	IMAGE->findImage("나가기버튼활성화");

	m_newStartRc = RectMakeCenter(m_startX, m_startY, IMAGE->findImage("새게임버튼비활성화")->getWidth(), IMAGE->findImage("새게임버튼비활성화")->getHeight());
	m_loadRc = RectMakeCenter(m_loadX, m_loadY, IMAGE->findImage("불러오기버튼비활성화")->getWidth(), IMAGE->findImage("불러오기버튼비활성화")->getHeight());
	m_exitRc = RectMakeCenter(m_exitX, m_exitY, IMAGE->findImage("나가기버튼비활성화")->getWidth(), IMAGE->findImage("나가기버튼비활성화")->getHeight());

	return S_OK;
}

void CsceneStart::release()
{
}

void CsceneStart::update()
{
	if (PtInRect(&m_newStartRc, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))	SCENE->changeScene("선택화면");
}

void CsceneStart::render()
{
	IMAGE->render("시작화면", getMapDC());
	if (PtInRect(&m_newStartRc, m_ptMouse)) IMAGE->render("새게임버튼활성화", getMapDC(), m_newStartRc.left, m_newStartRc.top);
	else IMAGE->render("새게임버튼비활성화", getMapDC(), m_newStartRc.left, m_newStartRc.top);
	if (PtInRect(&m_loadRc, m_ptMouse)) IMAGE->render("불러오기버튼활성화", getMapDC(), m_loadRc.left, m_loadRc.top);
	else IMAGE->render("불러오기버튼비활성화", getMapDC(), m_loadRc.left, m_loadRc.top);
	if (PtInRect(&m_exitRc, m_ptMouse)) IMAGE->render("나가기버튼활성화", getMapDC(), m_exitRc.left, m_exitRc.top);
	else IMAGE->render("나가기버튼비활성화", getMapDC(), m_exitRc.left, m_exitRc.top);

}
