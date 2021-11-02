#include "pch.h"
#include "playGround.h"

//���� �ʱ�ȭ
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

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();
}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();
	TIMEMANAGER->getElapsedTime();
	//=================================================
	
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) gameStart = true;

	if (gameStart)
	{
		if (readyCount < 200) readyCount++;

		//���� �غ� �ð� ��
		if (readyCount == 200)
		{
			start = true;
		}

		//���� Ŭ�����
		if (KEYMANAGER->isOnceKeyUp(VK_RETURN) && gameClear)
		{
			if (_stage <= 3)_stage++;
			start = false;
			gameClear = false;
			sM->release();
			sM->init(_stage);
		}

		//start Ȱ��ȭ��(���� ���� �� , ���� Ŭ��� �ƴҶ�)
		if (start && !gameClear)
		{
			//�÷��̾� �̵� �Է�
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

		//�������� �Ŵ��� ������Ʈ
		sM->update();

		//���� Ŭ���� Ȯ�� �κ�
		if (sM->getgameSet())
		{
			gameClear = true;
		}

		//�ڷΰ��� Ű
		if (KEYMANAGER->isOnceKeyDown('Z') && readyCount >= 9) sM->cBack();

		//F1~3 Ŭ���� ���� UI ���
		if (KEYMANAGER->isOnceKeyDown(VK_F1)) sM->BaseControl(true, false, false);
		if (KEYMANAGER->isOnceKeyDown(VK_F2)) sM->BaseControl(false, true, false);
		if (KEYMANAGER->isOnceKeyDown(VK_F3)) sM->BaseControl(false, false, true);

		//=================================================
	}
}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============
	
	//�������� �Ŵ��� ����
	sM->render();
	
	//TAP Ŭ���� ���� ������ �� �÷��� �ð� ���
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		TIMEMANAGER->render(getMemDC());
	}

	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);
}