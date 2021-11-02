#pragma once
#include <vector>

#include "gameNode.h"
#include "object.h"
#include "bImage.h"

#include "aType.h"
#include "effect.h"

//#define STAGE1 4


class stageManager : public gameNode
{
private:

	effect* ef;

	bImage* _bmg;	// 이미지
	aType* _aType;	//속성(행동) 타입

	//맵
	RECT pRc[WINSIZEY / PSIZE][WINSIZEX / PSIZE];//게임 기본 판의 렉트(화면 y / 칸 크기)(화면 x / 칸 크기)
	image* _img;
	bool baseView;	//게임 이동 칸 출력 여부
	bool rectView;	//오브젝트 렉트 출력 여부
	bool textView;	//테스트 텍스트 출력여부

	char a[128];	//테스트 텍스트

	//오브젝트
	typedef vector<object*>	ob;	//오브젝트

	ob	_ob;
	//iob _iob;

	int _sleepCount;	//잠수시 이미지 변환
	int _stage;			//스테이지 번호
	bool _fin;

public:

	virtual HRESULT init();//초기화 함수
	virtual HRESULT init(int stage);//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	void BaseControl(bool prc, bool orc, bool ttt);	//개발자 컨트롤러(0: 비설정 1:설정)(맵 경계선, 오브젝트 렉트)
	void createStage(int level);				//스테이지 생성

	//타입 변경
	void ATypeControl(moveType act);		//키보드를 눌렀을 때 행동에 따른 처리
	//void ITypeControl();					//키보드를 눌렀을 때 행동에 따른 처리
	
	//A타입
	void setAstate(aType* atype) { if (_aType) delete _aType; _aType = atype; }
	void getAstate(moveType key,int objnum, ob& ob) { _aType->setAction(key,objnum,ob); }

	//게임 종료
	bool getgameSet();
	void setgameSet();

	//되돌리기
	void cBack();

};

