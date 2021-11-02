#include "pch.h"
#include "playGround.h"

//시작 초기화
HRESULT playGround::init()
{
	gameNode::init(true);
	//=================================================
	
	_stage = 0;

	sM = new stageManager;
	sM->init();
	
	start = false;
	gameClear = false;

	gameStart = false;

	readyCount = 0;

	//=================================================
	return S_OK;
}

//메모리 해제는 여기다 해라!!!!
void playGround::release()
{
	gameNode::release();
}

//연산처리는 여기다가!
void playGround::update()
{
	gameNode::update();
	TIMEMANAGER->getElapsedTime();
	//=================================================
	
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) gameStart = true;

	if (gameStart)
	{
		if (readyCount < 200) readyCount++;

		//게임 준비 시간 후
		if (readyCount == 200)
		{
			start = true;
		}

		//게임 클리어시
		if (KEYMANAGER->isOnceKeyUp(VK_RETURN) && gameClear)
		{
			if (_stage <= 3)_stage++;
			start = false;
			gameClear = false;
			sM->release();
			sM->init(_stage);
		}

		//start 활성화시(게임 시작 시 , 게임 클리어가 아닐때)
		if (start && !gameClear)
		{
			//플레이어 이동 입력
			if (KEYMANAGER->isStayKeyDown(VK_LEFT) && readyCount >= 9)
			{
				sM->ATypeControl(LEFT);
				readyCount = 0;
			}
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && readyCount >= 9)
			{
				sM->ATypeControl(RIGHT);
				readyCount = 0;
			}
			if (KEYMANAGER->isStayKeyDown(VK_UP) && readyCount >= 9)
			{
				sM->ATypeControl(UP);
				readyCount = 0;
			}
			if (KEYMANAGER->isStayKeyDown(VK_DOWN) && readyCount >= 9)
			{
				sM->ATypeControl(DOWN);
				readyCount = 0;
			}
		}

		//스테이지 매니저 업데이트
		sM->update();

		//게임 클리어 확인 부분
		if (sM->getgameSet())
		{
			gameClear = true;
		}

		//뒤로가기 키
		if (KEYMANAGER->isOnceKeyDown('Z') && readyCount >= 9) sM->cBack();

		//F1~3 클릭시 게임 UI 출력
		if (KEYMANAGER->isOnceKeyDown(VK_F1)) sM->BaseControl(true, false, false);
		if (KEYMANAGER->isOnceKeyDown(VK_F2)) sM->BaseControl(false, true, false);
		if (KEYMANAGER->isOnceKeyDown(VK_F3)) sM->BaseControl(false, false, true);

		//=================================================
	}
}

//여기다 그려줘라!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============
	
	//스테이지 매니저 랜더
	sM->render();
	
	//TAP 클릭시 게임 프레임 및 플레이 시간 출력
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		TIMEMANAGER->render(getMemDC());
	}

	//=============== 밑에도 건들지마라 ================
	_backBuffer->render(getHDC(), 0, 0);
}