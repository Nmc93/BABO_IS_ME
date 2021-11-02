#pragma once
#include "gameNode.h"

struct winEvent
{
	RECT eRc;	//게임 클리어 이벤트 렉트
	POINT rcP;	//게임 클리어 이벤트 렉트 좌표
	image* img;	//게임 이미지
	POINT imgP;	//게임 이미지 좌표

	int imgNum;

};

class effect : public gameNode
{
private:

	winEvent _wE[9];

	int _cNum;	//등장 위치
	int _iCount;//이미지 생성

	bool clearB;	//승리

public:

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	void clear(bool tr);	//게임 클리어 이미지
};

