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
	IMAGE->findImage("선택화면");

	int fps = 8;

	IMAGE->findImage("선택아마존");
	ANIMATION->addDefAnimation("아마존", "선택아마존", fps, false, true);
	m_ani[0] = ANIMATION->findAnimation("아마존");

	IMAGE->findImage("선택데몬");
	ANIMATION->addDefAnimation("데몬", "선택데몬", fps, false, true);
	m_ani[1] = ANIMATION->findAnimation("데몬");

	IMAGE->findImage("선택데몬슬레이어");
	ANIMATION->addDefAnimation("데몬슬레이어", "선택데몬슬레이어", fps, false, true);
	m_ani[2] = ANIMATION->findAnimation("데몬슬레이어");

	IMAGE->findImage("선택랜서");
	ANIMATION->addDefAnimation("랜서", "선택랜서", fps, false, true);
	m_ani[3] = ANIMATION->findAnimation("랜서");

	IMAGE->findImage("선택머로더");
	ANIMATION->addDefAnimation("머로더", "선택머로더", fps, false, true);
	m_ani[4] = ANIMATION->findAnimation("머로더");

	IMAGE->findImage("선택마크맨");
	ANIMATION->addDefAnimation("마크맨", "선택마크맨", fps, false, true);
	m_ani[5] = ANIMATION->findAnimation("마크맨");

	IMAGE->findImage("선택네크로맨서");
	ANIMATION->addDefAnimation("네크로맨서", "선택네크로맨서", fps, false, true);
	m_ani[6] = ANIMATION->findAnimation("네크로맨서");

	IMAGE->findImage("선택노마드");
	ANIMATION->addDefAnimation("노마드", "선택노마드", fps, false, true);
	m_ani[7] = ANIMATION->findAnimation("노마드");

	IMAGE->findImage("선택팔라딘");
	ANIMATION->addDefAnimation("팔라딘", "선택팔라딘", fps, false, true);
	m_ani[8] = ANIMATION->findAnimation("팔라딘");

	IMAGE->findImage("선택파이렛");
	ANIMATION->addDefAnimation("파이렛", "선택파이렛", fps, false, true);
	m_ani[9] = ANIMATION->findAnimation("파이렛");

	IMAGE->findImage("선택레드넥");
	ANIMATION->addDefAnimation("레드넥", "선택레드넥", fps, false, true);
	m_ani[10] = ANIMATION->findAnimation("레드넥");

	IMAGE->findImage("선택사무라이");
	ANIMATION->addDefAnimation("사무라이", "선택사무라이", fps, false, true);
	m_ani[11] = ANIMATION->findAnimation("사무라이");

	IMAGE->findImage("선택샤먼");
	ANIMATION->addDefAnimation("샤먼", "선택샤먼", fps, false, true);
	m_ani[12] = ANIMATION->findAnimation("샤먼");

	IMAGE->findImage("선택스틱맨");
	ANIMATION->addDefAnimation("스틱맨", "선택스틱맨", fps, false, true);
	m_ani[13] = ANIMATION->findAnimation("스틱맨");

	IMAGE->findImage("선택화이트메이지");
	ANIMATION->addDefAnimation("화이트메이지", "선택화이트메이지", fps, false, true);
	m_ani[14] = ANIMATION->findAnimation("화이트메이지");

	m_playerRc = RectMakeCenter(400, 250, IMAGE->findImage("선택아마존")->getFrameWidth(), IMAGE->findImage("선택아마존")->getFrameHeight());
	m_Rc1 = RectMakeCenter(520, 250, IMAGE->findImage("선택데몬")->getFrameWidth(), IMAGE->findImage("선택데몬")->getFrameHeight());
	m_Rc2 = RectMakeCenter(640, 250, IMAGE->findImage("선택데몬슬레이어")->getFrameWidth(), IMAGE->findImage("선택데몬슬레이어")->getFrameHeight());
	m_Rc3 = RectMakeCenter(760, 265, IMAGE->findImage("선택랜서")->getFrameWidth(), IMAGE->findImage("선택랜서")->getFrameHeight());
	m_Rc4 = RectMakeCenter(900, 250, IMAGE->findImage("선택머로더")->getFrameWidth(), IMAGE->findImage("선택머로더")->getFrameHeight());

	m_Rc5 = RectMakeCenter(400, 400, IMAGE->findImage("선택마크맨")->getFrameWidth(), IMAGE->findImage("선택마크맨")->getFrameHeight());
	m_Rc6 = RectMakeCenter(520, 400, IMAGE->findImage("선택네크로맨서")->getFrameWidth(), IMAGE->findImage("선택네크로맨서")->getFrameHeight());
	m_Rc7 = RectMakeCenter(640, 400, IMAGE->findImage("선택노마드")->getFrameWidth(), IMAGE->findImage("선택노마드")->getFrameHeight());
	m_Rc8 = RectMakeCenter(760, 400, IMAGE->findImage("선택팔라딘")->getFrameWidth(), IMAGE->findImage("선택팔라딘")->getFrameHeight());
	m_Rc9 = RectMakeCenter(880, 400, IMAGE->findImage("선택파이렛")->getFrameWidth(), IMAGE->findImage("선택파이렛")->getFrameHeight());

	m_Rc10 = RectMakeCenter(385, 550, IMAGE->findImage("선택레드넥")->getFrameWidth(), IMAGE->findImage("선택레드넥")->getFrameHeight());
	m_Rc11 = RectMakeCenter(505, 535, IMAGE->findImage("선택사무라이")->getFrameWidth(), IMAGE->findImage("선택사무라이")->getFrameHeight());
	m_Rc12 = RectMakeCenter(640, 555, IMAGE->findImage("선택샤먼")->getFrameWidth(), IMAGE->findImage("선택샤먼")->getFrameHeight());
	m_Rc13 = RectMakeCenter(760, 550, IMAGE->findImage("선택스틱맨")->getFrameWidth(), IMAGE->findImage("선택스틱맨")->getFrameHeight());
	m_Rc14 = RectMakeCenter(880, 550, IMAGE->findImage("선택화이트메이지")->getFrameWidth(), IMAGE->findImage("선택화이트메이지")->getFrameHeight());

	return S_OK;
}

void CsceneSelect::release()
{
}

void CsceneSelect::update()
{
	if (isSelect)
	{
		ANIMATION->start("아마존");
		ANIMATION->start("데몬");
		ANIMATION->start("데몬슬레이어");
		ANIMATION->start("랜서");
		ANIMATION->start("머로더");

		ANIMATION->start("마크맨");
		ANIMATION->start("네크로맨서");
		ANIMATION->start("노마드");
		ANIMATION->start("팔라딘");
		ANIMATION->start("파이렛");

		ANIMATION->start("레드넥");
		ANIMATION->start("사무라이");
		ANIMATION->start("샤먼");
		ANIMATION->start("스틱맨");
		ANIMATION->start("화이트메이지");
		isSelect = false;
	}

	if (PtInRect(&m_playerRc, m_ptMouse) && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		SCENE->changeScene("마을");
	}
	
}

void CsceneSelect::render()
{
	IMAGE->render("선택화면", getMapDC());

	IMAGE->findImage("선택아마존")->aniRender(getMapDC(), m_playerRc.left, m_playerRc.top, m_ani[0]);
	IMAGE->findImage("선택데몬")->aniRender(getMapDC(), m_Rc1.left, m_Rc1.top, m_ani[1]);
	IMAGE->findImage("선택데몬슬레이어")->aniRender(getMapDC(), m_Rc2.left, m_Rc2.top, m_ani[2]);
	IMAGE->findImage("선택랜서")->aniRender(getMapDC(), m_Rc3.left, m_Rc3.top, m_ani[3]);
	IMAGE->findImage("선택머로더")->aniRender(getMapDC(), m_Rc4.left, m_Rc4.top, m_ani[4]);

	IMAGE->findImage("선택마크맨")->aniRender(getMapDC(), m_Rc5.left, m_Rc5.top, m_ani[5]);
	IMAGE->findImage("선택네크로맨서")->aniRender(getMapDC(), m_Rc6.left, m_Rc6.top, m_ani[6]);
	IMAGE->findImage("선택노마드")->aniRender(getMapDC(), m_Rc7.left, m_Rc7.top, m_ani[7]);
	IMAGE->findImage("선택팔라딘")->aniRender(getMapDC(), m_Rc8.left, m_Rc8.top, m_ani[8]);
	IMAGE->findImage("선택파이렛")->aniRender(getMapDC(), m_Rc9.left, m_Rc9.top, m_ani[9]);

	IMAGE->findImage("선택레드넥")->aniRender(getMapDC(), m_Rc10.left, m_Rc10.top, m_ani[10]);
	IMAGE->findImage("선택사무라이")->aniRender(getMapDC(), m_Rc11.left, m_Rc11.top, m_ani[11]);
	IMAGE->findImage("선택샤먼")->aniRender(getMapDC(), m_Rc12.left, m_Rc12.top, m_ani[12]);
	IMAGE->findImage("선택스틱맨")->aniRender(getMapDC(), m_Rc13.left, m_Rc13.top, m_ani[13]);
	IMAGE->findImage("선택화이트메이지")->aniRender(getMapDC(), m_Rc14.left, m_Rc14.top, m_ani[14]);

	/*char str[100];
	sprintf_s(str, "%d", isSelect);
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, lstrlen(str));*/

}
