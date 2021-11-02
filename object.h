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

//����� ������
struct saveData
{
	image* img;			//������Ʈ �̹���

	RECT rc;				//������Ʈ ��Ʈ
	POINT pt;				//xy ��ȣ
	int speed;				//������Ʈ ���ǵ�

	POINT frame;			//������Ʈ �̹��� ��ȣ
	int iNum;				//��� �̹��� ��ȣ

	ImageType iType;		//�̹��� Ÿ��
	actType aType;			//�ൿ Ÿ��
	moveType mType;			//�̵� Ÿ��

	int count;				//�̹��� ī��Ʈ
	int sleep;				//���� ���°���?

	bool active;			//�ൿ ����
	bool interaction;		//��ȣ�ۿ�

};

class object : public gameNode
{
private:

	saveData sD;
	list<saveData>				dataList;	//������ ����
	list<saveData>::iterator	idataList;	//������ ����

	image* _img;			//������Ʈ �̹���
	POINT _imgPt;			//�̹��� ��ġ

	RECT _rc;				//������Ʈ ��Ʈ
	POINT _pt;				//xy ��ȣ
	int _speed;				//������Ʈ ���ǵ�

	POINT _frame;			//������Ʈ �̹��� ��ȣ
	int _iNum;				//��� �̹��� ��ȣ

	ImageType _iType;		//�̹��� Ÿ��
	actType _aType;			//�ൿ Ÿ��
	moveType _mType;		//�̵� Ÿ��

	int _count;				//�̹��� ī��Ʈ
	int _sleep;				//���� ���°���?

	bool _active;			//�ൿ ����
	bool _interaction;		//��ȣ�ۿ�

public:

	object() {};
	~object() {};

	virtual HRESULT init();							//�ʱ�ȭ �Լ�
	virtual HRESULT init(POINT xy);//�ʱ�ȭ �Լ�
	virtual void release();							//�޸� ���� �Խ�
	virtual void update();							//�����ϴ� �Լ�
	virtual void render();							//�׸��� �Լ�

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

	RECT getRect() { return _rc; }; //�׽�Ʈ�� getRect

	//���� �ҷ�����

	void dSave();
	void dLoad();
};

