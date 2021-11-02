#pragma once

#include "gameNode.h"
#include "saveLoadTest.h"

#include "stageManager.h"

class playGround : public gameNode
{
private:

	stageManager* sM;	//�������� �Ŵ���
	int readyCount;		//Ŭ�� ��

	bool start;			//���� ���� ����
	bool gameClear;		//���� Ŭ���� ����
	bool gameStart;		//���� ����

	int _stage;			//�������� ��ȣ

public:
	playGround() {};
	~playGround() {};

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

};