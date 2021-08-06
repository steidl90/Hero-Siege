#include "framework.h"
#include "CsceneSelect.h"

CsceneSelect::CsceneSelect()
{
}

CsceneSelect::~CsceneSelect()
{
}

HRESULT CsceneSelect::init()
{
	isSelect = true;
	IMAGE->findImage("����ȭ��");

	int fps = 8;

	IMAGE->findImage("���þƸ���");
	ANIMATION->addDefAnimation("�Ƹ���", "���þƸ���", fps, false, true);
	m_ani[0] = ANIMATION->findAnimation("�Ƹ���");

	IMAGE->findImage("���õ���");
	ANIMATION->addDefAnimation("����", "���õ���", fps, false, true);
	m_ani[1] = ANIMATION->findAnimation("����");

	IMAGE->findImage("���õ��󽽷��̾�");
	ANIMATION->addDefAnimation("���󽽷��̾�", "���õ��󽽷��̾�", fps, false, true);
	m_ani[2] = ANIMATION->findAnimation("���󽽷��̾�");

	IMAGE->findImage("���÷���");
	ANIMATION->addDefAnimation("����", "���÷���", fps, false, true);
	m_ani[3] = ANIMATION->findAnimation("����");

	IMAGE->findImage("���øӷδ�");
	ANIMATION->addDefAnimation("�ӷδ�", "���øӷδ�", fps, false, true);
	m_ani[4] = ANIMATION->findAnimation("�ӷδ�");

	IMAGE->findImage("���ø�ũ��");
	ANIMATION->addDefAnimation("��ũ��", "���ø�ũ��", fps, false, true);
	m_ani[5] = ANIMATION->findAnimation("��ũ��");

	IMAGE->findImage("���ó�ũ�θǼ�");
	ANIMATION->addDefAnimation("��ũ�θǼ�", "���ó�ũ�θǼ�", fps, false, true);
	m_ani[6] = ANIMATION->findAnimation("��ũ�θǼ�");

	IMAGE->findImage("���ó븶��");
	ANIMATION->addDefAnimation("�븶��", "���ó븶��", fps, false, true);
	m_ani[7] = ANIMATION->findAnimation("�븶��");

	IMAGE->findImage("�����ȶ��");
	ANIMATION->addDefAnimation("�ȶ��", "�����ȶ��", fps, false, true);
	m_ani[8] = ANIMATION->findAnimation("�ȶ��");

	IMAGE->findImage("�������̷�");
	ANIMATION->addDefAnimation("���̷�", "�������̷�", fps, false, true);
	m_ani[9] = ANIMATION->findAnimation("���̷�");

	IMAGE->findImage("���÷����");
	ANIMATION->addDefAnimation("�����", "���÷����", fps, false, true);
	m_ani[10] = ANIMATION->findAnimation("�����");

	IMAGE->findImage("���û繫����");
	ANIMATION->addDefAnimation("�繫����", "���û繫����", fps, false, true);
	m_ani[11] = ANIMATION->findAnimation("�繫����");

	IMAGE->findImage("���û���");
	ANIMATION->addDefAnimation("����", "���û���", fps, false, true);
	m_ani[12] = ANIMATION->findAnimation("����");

	IMAGE->findImage("���ý�ƽ��");
	ANIMATION->addDefAnimation("��ƽ��", "���ý�ƽ��", fps, false, true);
	m_ani[13] = ANIMATION->findAnimation("��ƽ��");

	IMAGE->findImage("����ȭ��Ʈ������");
	ANIMATION->addDefAnimation("ȭ��Ʈ������", "����ȭ��Ʈ������", fps, false, true);
	m_ani[14] = ANIMATION->findAnimation("ȭ��Ʈ������");

	m_playerRc = RectMakeCenter(400, 250, IMAGE->findImage("���þƸ���")->getFrameWidth(), IMAGE->findImage("���þƸ���")->getFrameHeight());
	m_Rc1 = RectMakeCenter(520, 250, IMAGE->findImage("���õ���")->getFrameWidth(), IMAGE->findImage("���õ���")->getFrameHeight());
	m_Rc2 = RectMakeCenter(640, 250, IMAGE->findImage("���õ��󽽷��̾�")->getFrameWidth(), IMAGE->findImage("���õ��󽽷��̾�")->getFrameHeight());
	m_Rc3 = RectMakeCenter(760, 265, IMAGE->findImage("���÷���")->getFrameWidth(), IMAGE->findImage("���÷���")->getFrameHeight());
	m_Rc4 = RectMakeCenter(900, 250, IMAGE->findImage("���øӷδ�")->getFrameWidth(), IMAGE->findImage("���øӷδ�")->getFrameHeight());

	m_Rc5 = RectMakeCenter(400, 400, IMAGE->findImage("���ø�ũ��")->getFrameWidth(), IMAGE->findImage("���ø�ũ��")->getFrameHeight());
	m_Rc6 = RectMakeCenter(520, 400, IMAGE->findImage("���ó�ũ�θǼ�")->getFrameWidth(), IMAGE->findImage("���ó�ũ�θǼ�")->getFrameHeight());
	m_Rc7 = RectMakeCenter(640, 400, IMAGE->findImage("���ó븶��")->getFrameWidth(), IMAGE->findImage("���ó븶��")->getFrameHeight());
	m_Rc8 = RectMakeCenter(760, 400, IMAGE->findImage("�����ȶ��")->getFrameWidth(), IMAGE->findImage("�����ȶ��")->getFrameHeight());
	m_Rc9 = RectMakeCenter(880, 400, IMAGE->findImage("�������̷�")->getFrameWidth(), IMAGE->findImage("�������̷�")->getFrameHeight());

	m_Rc10 = RectMakeCenter(385, 550, IMAGE->findImage("���÷����")->getFrameWidth(), IMAGE->findImage("���÷����")->getFrameHeight());
	m_Rc11 = RectMakeCenter(505, 535, IMAGE->findImage("���û繫����")->getFrameWidth(), IMAGE->findImage("���û繫����")->getFrameHeight());
	m_Rc12 = RectMakeCenter(640, 555, IMAGE->findImage("���û���")->getFrameWidth(), IMAGE->findImage("���û���")->getFrameHeight());
	m_Rc13 = RectMakeCenter(760, 550, IMAGE->findImage("���ý�ƽ��")->getFrameWidth(), IMAGE->findImage("���ý�ƽ��")->getFrameHeight());
	m_Rc14 = RectMakeCenter(880, 550, IMAGE->findImage("����ȭ��Ʈ������")->getFrameWidth(), IMAGE->findImage("����ȭ��Ʈ������")->getFrameHeight());

	return S_OK;
}

void CsceneSelect::release()
{
}

void CsceneSelect::update()
{
	if (isSelect)
	{
		ANIMATION->start("�Ƹ���");
		ANIMATION->start("����");
		ANIMATION->start("���󽽷��̾�");
		ANIMATION->start("����");
		ANIMATION->start("�ӷδ�");

		ANIMATION->start("��ũ��");
		ANIMATION->start("��ũ�θǼ�");
		ANIMATION->start("�븶��");
		ANIMATION->start("�ȶ��");
		ANIMATION->start("���̷�");

		ANIMATION->start("�����");
		ANIMATION->start("�繫����");
		ANIMATION->start("����");
		ANIMATION->start("��ƽ��");
		ANIMATION->start("ȭ��Ʈ������");
		isSelect = false;
	}

	if (PtInRect(&m_playerRc, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		SCENE->changeScene("����");
	}
	
}

void CsceneSelect::render()
{
	IMAGE->render("����ȭ��", getMapDC());

	IMAGE->findImage("���þƸ���")->aniRender(getMapDC(), m_playerRc.left, m_playerRc.top, m_ani[0]);
	IMAGE->findImage("���õ���")->aniRender(getMapDC(), m_Rc1.left, m_Rc1.top, m_ani[1]);
	IMAGE->findImage("���õ��󽽷��̾�")->aniRender(getMapDC(), m_Rc2.left, m_Rc2.top, m_ani[2]);
	IMAGE->findImage("���÷���")->aniRender(getMapDC(), m_Rc3.left, m_Rc3.top, m_ani[3]);
	IMAGE->findImage("���øӷδ�")->aniRender(getMapDC(), m_Rc4.left, m_Rc4.top, m_ani[4]);

	IMAGE->findImage("���ø�ũ��")->aniRender(getMapDC(), m_Rc5.left, m_Rc5.top, m_ani[5]);
	IMAGE->findImage("���ó�ũ�θǼ�")->aniRender(getMapDC(), m_Rc6.left, m_Rc6.top, m_ani[6]);
	IMAGE->findImage("���ó븶��")->aniRender(getMapDC(), m_Rc7.left, m_Rc7.top, m_ani[7]);
	IMAGE->findImage("�����ȶ��")->aniRender(getMapDC(), m_Rc8.left, m_Rc8.top, m_ani[8]);
	IMAGE->findImage("�������̷�")->aniRender(getMapDC(), m_Rc9.left, m_Rc9.top, m_ani[9]);

	IMAGE->findImage("���÷����")->aniRender(getMapDC(), m_Rc10.left, m_Rc10.top, m_ani[10]);
	IMAGE->findImage("���û繫����")->aniRender(getMapDC(), m_Rc11.left, m_Rc11.top, m_ani[11]);
	IMAGE->findImage("���û���")->aniRender(getMapDC(), m_Rc12.left, m_Rc12.top, m_ani[12]);
	IMAGE->findImage("���ý�ƽ��")->aniRender(getMapDC(), m_Rc13.left, m_Rc13.top, m_ani[13]);
	IMAGE->findImage("����ȭ��Ʈ������")->aniRender(getMapDC(), m_Rc14.left, m_Rc14.top, m_ani[14]);

	/*char str[100];
	sprintf_s(str, "%d", isSelect);
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, lstrlen(str));*/

}
