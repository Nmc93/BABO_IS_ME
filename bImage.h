#pragma once
#include "gameNode.h"
#include "object.h"

#include <vector>

class bImage : public gameNode
{
private:

	char word[128];
public:

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	image* getImage(string word);	//�׽�Ʈ�� �̹��� �ֱ�

	void imageChange(vector<object*>& ob);//�ൿ�� ���� �̹��� ��ȭ
	
	void iTypeinit(vector<object*>& ob);//�̹��� ��ȣ�ۿ� �� �ʱ�ȭ
	void iTypeLr(vector<object*>& ob);	//�̹����� ���� ��ȣ�ۿ�
	void iTypeUd(vector<object*>& ob);	//�̹����� ���� ��ȣ�ۿ�
};