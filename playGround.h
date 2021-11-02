#pragma once

#include "gameNode.h"
#include "saveLoadTest.h"

#include "stageManager.h"

class playGround : public gameNode
{
private:

	stageManager* sM;	//스테이지 매니저
	int readyCount;		//클릭 텀

	bool start;			//게임 진행 여부
	bool gameClear;		//게임 클리어 여부
	bool gameStart;		//게임 시작

	int _stage;			//스테이지 번호

public:
	playGround() {};
	~playGround() {};

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

};