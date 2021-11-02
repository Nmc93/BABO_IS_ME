#pragma once
#include "gameNode.h"
#include <list>

enum ImageType
{
	BABA,
	KEKE,
	ROCK,
	WORD_BABA,
	WORD_KEKE,
	WORD_ROCK,
	WORD_IS,
	WORD_YOU,
	WORD_WIN,
	WORD_PUSH,
	WORD_STOP,
	FLAG,
	WORD_FLAG,
	WORD_A,
	WORD_C,
	WORD_E,
	WORD_G,
	WORD_L,
	WORD_M,
	WORD_R,
	CATTAIL,
	LEAF,
	PINE,
	PINES
};
enum actType
{
	YOU,
	WIN,
	PUSH,
	STOP,
	ASTOP
};
enum moveType
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	MSTOP
};

//저장용 데이터
struct saveData
{
	image* img;			//오브젝트 이미지

	RECT rc;				//오브젝트 렉트
	POINT pt;				//xy 번호
	int speed;				//오브젝트 스피드

	POINT frame;			//오브젝트 이미지 번호
	int iNum;				//사용 이미지 번호

	ImageType iType;		//이미지 타입
	actType aType;			//행동 타입
	moveType mType;			//이동 타입

	int count;				//이미지 카운트
	int sleep;				//어디다 쓰는거지?

	bool active;			//행동 수락
	bool interaction;		//상호작용

};

class object : public gameNode
{
private:

	saveData sD;
	list<saveData>				dataList;	//데이터 저장
	list<saveData>::iterator	idataList;	//데이터 저장

	image* _img;			//오브젝트 이미지
	POINT _imgPt;			//이미지 위치

	RECT _rc;				//오브젝트 렉트
	POINT _pt;				//xy 번호
	int _speed;				//오브젝트 스피드

	POINT _frame;			//오브젝트 이미지 번호
	int _iNum;				//사용 이미지 번호

	ImageType _iType;		//이미지 타입
	actType _aType;			//행동 타입
	moveType _mType;		//이동 타입

	int _count;				//이미지 카운트
	int _sleep;				//어디다 쓰는거지?

	bool _active;			//행동 수락
	bool _interaction;		//상호작용

public:

	object() {};
	~object() {};

	virtual HRESULT init();							//초기화 함수
	virtual HRESULT init(POINT xy);//초기화 함수
	virtual void release();							//메모리 해제 함슈
	virtual void update();							//연산하는 함수
	virtual void render();							//그리기 함수

	void draw();
	void move();

	//setter
	void setVariable(POINT pt) {_pt = pt;};
	void setVariable(POINT pt, ImageType itype, actType atype, moveType mtype);
	void setVariable(int x,int y);

	void setImage(image* img) { _img = img; }
	void setMtype(moveType mtype) { _mType = mtype; }
	void setItype(ImageType itype) { _iType = itype; }
	void setAtype(actType atype) { _aType = atype; }
	void setInum(int inum) { _iNum = inum; }
	void setActive(bool active) { _active = active; }

	void setInteraction(bool efecto) { _interaction = efecto; }

	//getter
	POINT getPoint() {return _pt;}
	POINT getFrame() {return _frame;}

	moveType getMtype() { return _mType; }
	ImageType getItype() { return _iType; }
	actType getAtype() { return _aType; }
	int getInum() { return _iNum; }

	bool getActive() { return _active; }
	bool getInteraction() { return _interaction; }

	RECT getRect() { return _rc; }; //테스트용 getRect

	//저장 불러오기

	void dSave();
	void dLoad();
};

