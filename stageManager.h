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

	bImage* _bmg;	// �̹���
	aType* _aType;	//�Ӽ�(�ൿ) Ÿ��

	//��
	RECT pRc[WINSIZEY / PSIZE][WINSIZEX / PSIZE];//���� �⺻ ���� ��Ʈ(ȭ�� y / ĭ ũ��)(ȭ�� x / ĭ ũ��)
	image* _img;
	bool baseView;	//���� �̵� ĭ ��� ����
	bool rectView;	//������Ʈ ��Ʈ ��� ����
	bool textView;	//�׽�Ʈ �ؽ�Ʈ ��¿���

	char a[128];	//�׽�Ʈ �ؽ�Ʈ

	//������Ʈ
	typedef vector<object*>	ob;	//������Ʈ

	ob	_ob;
	//iob _iob;

	int _sleepCount;	//����� �̹��� ��ȯ
	int _stage;			//�������� ��ȣ
	bool _fin;

public:

	virtual HRESULT init();//�ʱ�ȭ �Լ�
	virtual HRESULT init(int stage);//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	void BaseControl(bool prc, bool orc, bool ttt);	//������ ��Ʈ�ѷ�(0: ���� 1:����)(�� ��輱, ������Ʈ ��Ʈ)
	void createStage(int level);				//�������� ����

	//Ÿ�� ����
	void ATypeControl(moveType act);		//Ű���带 ������ �� �ൿ�� ���� ó��
	//void ITypeControl();					//Ű���带 ������ �� �ൿ�� ���� ó��
	
	//AŸ��
	void setAstate(aType* atype) { if (_aType) delete _aType; _aType = atype; }
	void getAstate(moveType key,int objnum, ob& ob) { _aType->setAction(key,objnum,ob); }

	//���� ����
	bool getgameSet();
	void setgameSet();

	//�ǵ�����
	void cBack();

};

