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

	IMAGE->findImage("����ȭ��");
	IMAGE->findImage("�����ӹ�ư��Ȱ��ȭ");
	IMAGE->findImage("�����ӹ�ưȰ��ȭ");
	IMAGE->findImage("�ҷ������ư��Ȱ��ȭ");
	IMAGE->findImage("�ҷ������ưȰ��ȭ");
	IMAGE->findImage("�������ư��Ȱ��ȭ");
	IMAGE->findImage("�������ưȰ��ȭ");

	m_newStartRc = RectMakeCenter(m_startX, m_startY, IMAGE->findImage("�����ӹ�ư��Ȱ��ȭ")->getWidth(), IMAGE->findImage("�����ӹ�ư��Ȱ��ȭ")->getHeight());
	m_loadRc = RectMakeCenter(m_loadX, m_loadY, IMAGE->findImage("�ҷ������ư��Ȱ��ȭ")->getWidth(), IMAGE->findImage("�ҷ������ư��Ȱ��ȭ")->getHeight());
	m_exitRc = RectMakeCenter(m_exitX, m_exitY, IMAGE->findImage("�������ư��Ȱ��ȭ")->getWidth(), IMAGE->findImage("�������ư��Ȱ��ȭ")->getHeight());

	return S_OK;
}

void CsceneStart::release()
{
}

void CsceneStart::update()
{
	if (PtInRect(&m_newStartRc, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))	SCENE->changeScene("����ȭ��");
}

void CsceneStart::render()
{
	IMAGE->render("����ȭ��", getMapDC());
	if (PtInRect(&m_newStartRc, m_ptMouse)) IMAGE->render("�����ӹ�ưȰ��ȭ", getMapDC(), m_newStartRc.left, m_newStartRc.top);
	else IMAGE->render("�����ӹ�ư��Ȱ��ȭ", getMapDC(), m_newStartRc.left, m_newStartRc.top);
	if (PtInRect(&m_loadRc, m_ptMouse)) IMAGE->render("�ҷ������ưȰ��ȭ", getMapDC(), m_loadRc.left, m_loadRc.top);
	else IMAGE->render("�ҷ������ư��Ȱ��ȭ", getMapDC(), m_loadRc.left, m_loadRc.top);
	if (PtInRect(&m_exitRc, m_ptMouse)) IMAGE->render("�������ưȰ��ȭ", getMapDC(), m_exitRc.left, m_exitRc.top);
	else IMAGE->render("�������ư��Ȱ��ȭ", getMapDC(), m_exitRc.left, m_exitRc.top);

}
