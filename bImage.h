#pragma once
#include "gameNode.h"
#include "object.h"

#include <vector>

class bImage : public gameNode
{
private:

	char word[128];
public:

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	image* getImage(string word);	//테스트용 이미지 넣기

	void imageChange(vector<object*>& ob);//행동에 따른 이미지 변화
	
	void iTypeinit(vector<object*>& ob);//이미지 상호작용 전 초기화
	void iTypeLr(vector<object*>& ob);	//이미지에 따른 상호작용
	void iTypeUd(vector<object*>& ob);	//이미지에 따른 상호작용
};