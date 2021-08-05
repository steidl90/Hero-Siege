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
	IMAGE->findImage("����ȭ��");

	IMAGE->findImage("���þƸ���");
	ANIMATION->addDefAnimation("�Ƹ���", "���þƸ���", 5, false, true);
	m_ani[0] = ANIMATION->findAnimation("�Ƹ���");

	IMAGE->findImage("���õ���");
	ANIMATION->addDefAnimation("����", "���õ���", 5, false, true);
	m_ani[1] = ANIMATION->findAnimation("����");

	IMAGE->findImage("���õ��󽽷��̾�");
	ANIMATION->addDefAnimation("���󽽷��̾�", "���õ��󽽷��̾�", 5, false, true);
	m_ani[2] = ANIMATION->findAnimation("���󽽷��̾�");

	IMAGE->findImage("���÷���");
	ANIMATION->addDefAnimation("����", "���÷���", 5, false, true);
	m_ani[3] = ANIMATION->findAnimation("����");

	IMAGE->findImage("���øӷδ�");
	ANIMATION->addDefAnimation("�ӷδ�", "���øӷδ�", 5, false, true);
	m_ani[4] = ANIMATION->findAnimation("�ӷδ�");

	IMAGE->findImage("���ø�ũ��");
	ANIMATION->addDefAnimation("��ũ��", "���ø�ũ��", 5, false, true);
	m_ani[5] = ANIMATION->findAnimation("��ũ��");

	IMAGE->findImage("���ó�ũ�θǼ�");
	ANIMATION->addDefAnimation("��ũ�θǼ�", "���ó�ũ�θǼ�", 5, false, true);
	m_ani[6] = ANIMATION->findAnimation("��ũ�θǼ�");

	IMAGE->findImage("���ó븶��");
	ANIMATION->addDefAnimation("�븶��", "���ó븶��", 5, false, true);
	m_ani[7] = ANIMATION->findAnimation("�븶��");

	IMAGE->findImage("�����ȶ��");
	ANIMATION->addDefAnimation("�ȶ��", "�����ȶ��", 5, false, true);
	m_ani[8] = ANIMATION->findAnimation("�ȶ��");

	IMAGE->findImage("�������̷�");
	ANIMATION->addDefAnimation("���̷�", "�������̷�", 5, false, true);
	m_ani[9] = ANIMATION->findAnimation("���̷�");

	IMAGE->findImage("���÷����");
	ANIMATION->addDefAnimation("�����", "���÷����", 5, false, true);
	m_ani[10] = ANIMATION->findAnimation("�����");

	IMAGE->findImage("���û繫����");
	ANIMATION->addDefAnimation("�繫����", "���û繫����", 5, false, true);
	m_ani[11] = ANIMATION->findAnimation("�繫����");

	IMAGE->findImage("���û���");
	ANIMATION->addDefAnimation("����", "���û���", 5, false, true);
	m_ani[12] = ANIMATION->findAnimation("����");

	IMAGE->findImage("���ý�ƽ��");
	ANIMATION->addDefAnimation("��ƽ��", "���ý�ƽ��", 5, false, true);
	m_ani[13] = ANIMATION->findAnimation("��ƽ��");

	IMAGE->findImage("����ȭ��Ʈ������");
	ANIMATION->addDefAnimation("ȭ��Ʈ������", "����ȭ��Ʈ������", 5, false, true);
	m_ani[14] = ANIMATION->findAnimation("ȭ��Ʈ������");

	m_playerRc = RectMakeCenter(430, 300, IMAGE->findImage("���þƸ���")->getFrameWidth(), IMAGE->findImage("���þƸ���")->getFrameHeight());
	m_Rc1 = RectMakeCenter(530, 300, IMAGE->findImage("���õ���")->getFrameWidth(), IMAGE->findImage("���õ���")->getFrameHeight());
	m_Rc2 = RectMakeCenter(630, 300, IMAGE->findImage("���õ��󽽷��̾�")->getFrameWidth(), IMAGE->findImage("���õ��󽽷��̾�")->getFrameHeight());
	m_Rc3 = RectMakeCenter(730, 300, IMAGE->findImage("���÷���")->getFrameWidth(), IMAGE->findImage("���÷���")->getFrameHeight());
	m_Rc4 = RectMakeCenter(830, 300, IMAGE->findImage("���øӷδ�")->getFrameWidth(), IMAGE->findImage("���øӷδ�")->getFrameHeight());

	m_Rc5 = RectMakeCenter(430, 400, IMAGE->findImage("���ø�ũ��")->getFrameWidth(), IMAGE->findImage("���ø�ũ��")->getFrameHeight());
	m_Rc6 = RectMakeCenter(530, 400, IMAGE->findImage("���ó�ũ�θǼ�")->getFrameWidth(), IMAGE->findImage("���ó�ũ�θǼ�")->getFrameHeight());
	m_Rc7 = RectMakeCenter(630, 400, IMAGE->findImage("���ó븶��")->getFrameWidth(), IMAGE->findImage("���ó븶��")->getFrameHeight());
	m_Rc8 = RectMakeCenter(730, 400, IMAGE->findImage("�����ȶ��")->getFrameWidth(), IMAGE->findImage("�����ȶ��")->getFrameHeight());
	m_Rc9 = RectMakeCenter(830, 400, IMAGE->findImage("�������̷�")->getFrameWidth(), IMAGE->findImage("�������̷�")->getFrameHeight());

	m_Rc10 = RectMakeCenter(430, 500, IMAGE->findImage("���÷����")->getFrameWidth(), IMAGE->findImage("���÷����")->getFrameHeight());
	m_Rc11 = RectMakeCenter(530, 500, IMAGE->findImage("���û繫����")->getFrameWidth(), IMAGE->findImage("���û繫����")->getFrameHeight());
	m_Rc12 = RectMakeCenter(630, 500, IMAGE->findImage("���û���")->getFrameWidth(), IMAGE->findImage("���û���")->getFrameHeight());
	m_Rc13 = RectMakeCenter(730, 500, IMAGE->findImage("���ý�ƽ��")->getFrameWidth(), IMAGE->findImage("���ý�ƽ��")->getFrameHeight());
	m_Rc14 = RectMakeCenter(830, 500, IMAGE->findImage("����ȭ��Ʈ������")->getFrameWidth(), IMAGE->findImage("����ȭ��Ʈ������")->getFrameHeight());

	return S_OK;
}

void CsceneSelect::release()
{
}

void CsceneSelect::update()
{
	if (InputManager->isOnceKeyDown(VK_F10))
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

}
