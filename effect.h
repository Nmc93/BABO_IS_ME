#pragma once
#include "gameNode.h"

struct winEvent
{
	RECT eRc;	//���� Ŭ���� �̺�Ʈ ��Ʈ
	POINT rcP;	//���� Ŭ���� �̺�Ʈ ��Ʈ ��ǥ
	image* img;	//���� �̹���
	POINT imgP;	//���� �̹��� ��ǥ

	int imgNum;

};

class effect : public gameNode
{
private:

	winEvent _wE[9];

	int _cNum;	//���� ��ġ
	int _iCount;//�̹��� ����

	bool clearB;	//�¸�

public:

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	void clear(bool tr);	//���� Ŭ���� �̹���
};

