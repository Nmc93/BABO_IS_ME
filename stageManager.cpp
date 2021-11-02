#include "pch.h"
#include "stageManager.h"

//���� ���� init
HRESULT stageManager::init()
{
	//�̹��� Ŭ����
	_bmg = new bImage;
	_bmg->init();

	//�� �̹���
	_img = new image;
	_img = _bmg->getImage("backGround");

	//ȿ�� Ŭ����
	ef = new effect;
	ef->init();

	//���� ��������
	createStage(0);

	//ȿ�� Ȱ��ȭ
	baseView = false;
	rectView = false;
	textView = false;
	_fin = false;

	//�ൿ Ÿ��
	_aType = new you;
	_sleepCount = 0;

	return S_OK;
}

//�������� �Ѿ�� init
HRESULT stageManager::init(int stage)
{
	_stage = stage;

	createStage(_stage);

	ef->init();

	baseView = false;
	rectView = false;
	textView = false;
	_fin = false;

	_sleepCount = 0;

	return S_OK;
}

void stageManager::release()
{
	_ob.clear();
	vector<object*>().swap(_ob);
}

void stageManager::update()
{
	if (_sleepCount < 1000) _sleepCount++;
	
	//������Ʈ ������Ʈ
	for (int i = 0; i < _ob.size(); i++)
	{
		_ob[i]->update();
	}

	//iŸ�� ����
	_bmg->imageChange(_ob);

	_bmg->iTypeLr(_ob);
	_bmg->iTypeUd(_ob);

	//��� �� ����
	if (_sleepCount > 900)
	{
		for (int i = 0; i < _ob.size(); i++) _ob[i]->setInum(0);
	}

	setgameSet();
	ef->update();
	ef->clear(_fin);
}

void stageManager::render()
{
	_img->render(getMemDC());

	//������Ʈ ���
	for (int i = 0; i < _ob.size(); i++)
	{
		//������Ʈ ��Ʈ ���(TEST)
		if (rectView)
		{
			if (_stage == 1)
			{
				RECT tRc = _ob[i]->getRect();
				HBRUSH hb = CreateSolidBrush(RGB(0, 100, 0));
				HBRUSH ohb = (HBRUSH)SelectObject(getMemDC(), (HGDIOBJ)hb);
				Rectangle(getMemDC(), tRc);
				hb = (HBRUSH)SelectObject(getMemDC(), (HGDIOBJ)ohb);
				DeleteObject(hb);
			}
			else
			{
				RECT tRc = _ob[i]->getRect();
				HBRUSH hb = CreateSolidBrush(RGB(50, 50, 50));
				HBRUSH ohb = (HBRUSH)SelectObject(getMemDC(), (HGDIOBJ)hb);
				Rectangle(getMemDC(), tRc);
				hb = (HBRUSH)SelectObject(getMemDC(), (HGDIOBJ)ohb);
				DeleteObject(hb);
			}
		}
		_ob[i]->render();
	}

	//���� �ʵ� ���(TEST)
	if (baseView)
	{
		for (int i = 0; i < WINSIZEY / PSIZE; i++)
		{
			for (int j = 0; j < WINSIZEX / PSIZE; j++)
			{
				HPEN hp = CreatePen(PS_SOLID, 1, RGB(100, 100, 100));
				HPEN ohp = (HPEN)SelectObject(getMemDC(), (HGDIOBJ)hp);
				HBRUSH hb = (HBRUSH)GetStockObject(NULL_BRUSH);
				HBRUSH ohb = (HBRUSH)SelectObject(getMemDC(), (HGDIOBJ)hb);
				Rectangle(getMemDC(), pRc[j][i]);
				hb = (HBRUSH)SelectObject(getMemDC(), (HGDIOBJ)ohb);
				hp = (HPEN)SelectObject(getMemDC(), (HGDIOBJ)ohp);
				DeleteObject(hb);
				DeleteObject(hp);
			}
		}
	}
	//�׽�Ʈ �ؽ�Ʈ ���
	if (textView)
	{
		sprintf_s(a, "0 : %d, 1 : %d", _ob[0]->getPoint().x, _ob[0]->getPoint().y);
		TextOut(getMemDC(), 0, 0, a, strlen(a));
	}

	ef->render();
}

//��Ʈ�ѷ�
void stageManager::BaseControl(bool prc, bool orc , bool ttt)
{
	//�� ��輱
	if (baseView && prc)
	{
		baseView = false;
	}
	else if (!baseView && prc)
	{
		baseView = true;
	}

	//������Ʈ ��Ʈ
	if (rectView && orc)
	{
		rectView = false;
	}
	else if (!rectView && orc)
	{
		rectView = true;
	}

	//�׽�Ʈ �ؽ�Ʈ
	if (textView && ttt)
	{
		textView = false;
	}
	else if (!textView && ttt)
	{
		textView = true;
	}
}

//�������� ����
void stageManager::createStage(int level)
{
	switch (level)
	{
		
	case 0: // �������� 0

		//���� �ʵ� ����
		for (int i = 0; i < WINSIZEY / PSIZE; i++)
		{
			for (int j = 0; j < WINSIZEX / PSIZE; j++)
			{
				pRc[j][i] = RectMake(j * PSIZE, i * PSIZE, PSIZE, PSIZE);
			}
		}
		//���� ��� ����
		_img = _bmg->getImage("backGround");

		for (int i = 0; i < STAGE0; i++)
		{
			object* obj;
			obj = new object;
			obj->init({ 11,0 });
			_ob.push_back(obj);
		}
		_ob[49]->setVariable({ 10,10 }, BABA, YOU, LEFT);
		_ob[1]->setVariable({ 1,8 }, WORD_BABA, PUSH, LEFT);
		_ob[2]->setVariable({ 1,9 }, WORD_IS, PUSH, LEFT);
		_ob[3]->setVariable({ 1,10 }, WORD_YOU, PUSH, LEFT);
		_ob[4]->setVariable({ 2,10 }, WORD_WIN, PUSH, LEFT);
		_ob[5]->setVariable({ 9,6 }, WORD_ROCK, PUSH, LEFT);
		_ob[6]->setVariable({ 9,7 }, WORD_IS, PUSH, LEFT);
		_ob[7]->setVariable({ 9,8 }, WORD_STOP, PUSH, LEFT);
		_ob[8]->setVariable({ 7,4 }, ROCK,ASTOP,LEFT);
		_ob[9]->setVariable({ 7,5 }, ROCK,ASTOP,LEFT);
		_ob[10]->setVariable({ 7,6 }, ROCK,ASTOP,LEFT);
		_ob[11]->setVariable({ 7,7 }, ROCK,ASTOP,LEFT);
		_ob[12]->setVariable({ 7,8 }, ROCK,ASTOP,LEFT);
		_ob[13]->setVariable({ 7,9 }, ROCK,ASTOP,LEFT);
		_ob[14]->setVariable({ 7,10 }, ROCK,ASTOP,LEFT);
		_ob[15]->setVariable({ 7,11 }, ROCK,ASTOP,LEFT);
		_ob[16]->setVariable({ 7,12 }, ROCK,ASTOP,LEFT);
		_ob[17]->setVariable({ 7,13 }, ROCK,ASTOP,LEFT);
		_ob[18]->setVariable({ 8,13 }, ROCK,ASTOP,LEFT);
		_ob[19]->setVariable({ 9,13 }, ROCK,ASTOP,LEFT);
		_ob[20]->setVariable({ 10,13 }, ROCK,ASTOP,LEFT);
		_ob[21]->setVariable({ 11,13 }, ROCK,ASTOP,LEFT);
		_ob[22]->setVariable({ 12,13 }, ROCK,ASTOP,LEFT);
		_ob[23]->setVariable({ 13,13 }, ROCK,ASTOP,LEFT);
		_ob[24]->setVariable({ 14,13 }, ROCK,ASTOP,LEFT);
		_ob[25]->setVariable({ 15,13 }, ROCK,ASTOP,LEFT);
		_ob[26]->setVariable({ 16,13 }, ROCK,ASTOP,LEFT);
		_ob[27]->setVariable({ 16,12 }, ROCK,ASTOP,LEFT);
		_ob[28]->setVariable({ 16,11 }, ROCK,ASTOP,LEFT);
		_ob[29]->setVariable({ 16,10 }, ROCK,ASTOP,LEFT);
		_ob[30]->setVariable({ 16,9 }, ROCK,ASTOP,LEFT);
		_ob[31]->setVariable({ 16,8 }, ROCK,ASTOP,LEFT);
		_ob[32]->setVariable({ 16,7 }, ROCK,ASTOP,LEFT);
		_ob[33]->setVariable({ 16,6 }, ROCK,ASTOP,LEFT);
		_ob[34]->setVariable({ 16,5 }, ROCK,ASTOP,LEFT);
		_ob[35]->setVariable({ 16,4 }, ROCK,ASTOP,LEFT);
		_ob[36]->setVariable({ 15,4 }, ROCK,ASTOP,LEFT);
		_ob[37]->setVariable({ 14,4 }, ROCK,ASTOP,LEFT);
		_ob[38]->setVariable({ 13,4 }, ROCK,ASTOP,LEFT);
		_ob[39]->setVariable({ 12,4 }, ROCK,ASTOP,LEFT);
		_ob[40]->setVariable({ 11,4 }, ROCK,ASTOP,LEFT);
		_ob[41]->setVariable({ 10,4 }, ROCK,ASTOP,LEFT);
		_ob[42]->setVariable({ 9,4 }, ROCK,ASTOP,LEFT);
		_ob[43]->setVariable({ 8,4 }, ROCK,ASTOP,LEFT);
		//==========
		_ob[44]->setVariable({ 9,16 }, CATTAIL,ASTOP,LEFT);
		_ob[45]->setVariable({ 14,17 }, CATTAIL,ASTOP,LEFT);
		_ob[46]->setVariable({ 13,8 }, PINE,ASTOP,LEFT);
		_ob[47]->setVariable({ 13,7 }, LEAF,ASTOP,LEFT);
		_ob[48]->setVariable({ 14,8 }, LEAF,ASTOP,LEFT);
		_ob[0]->setVariable({ 12,11 }, PINES, ASTOP, LEFT);

		break;
	case 1:	// ��������1
	{
		//���� �ʵ� ����
		for (int i = 0; i < WINSIZEY / PSIZE; i++)
		{
			for (int j = 0; j < WINSIZEX / PSIZE; j++)
			{
				pRc[j][i] = RectMake(j * PSIZE, i * PSIZE, PSIZE, PSIZE);
			}
		}
		//���� ��� ����
		_img = _bmg->getImage("backGround1");

		for (int i = 0; i < STAGE1; i++)
		{
			object* obj;
			obj = new object;
			obj->init({11,8});
			_ob.push_back(obj);
		}
		_ob[49]->setVariable({ 10,10 }, BABA, YOU, LEFT);
		_ob[1]->setVariable({ 9,7 }, WORD_BABA, PUSH, LEFT);
		_ob[2]->setVariable({ 10,7 }, WORD_IS, PUSH, LEFT);
		_ob[3]->setVariable({ 11,7 }, WORD_YOU, PUSH, LEFT);
		_ob[4]->setVariable({ 8,16 }, WORD_WIN, PUSH, LEFT);
		_ob[5]->setVariable({ 12,17 }, WORD_ROCK, PUSH, LEFT);
		_ob[6]->setVariable({ 13,17 }, WORD_IS, PUSH, LEFT);
		_ob[7]->setVariable({ 14,17 }, WORD_STOP, PUSH, LEFT);
	//��
		_ob[8]->setVariable({ 7,4 }, ROCK, ASTOP, LEFT);
		_ob[9]->setVariable({ 7,5 }, ROCK, ASTOP, LEFT);
		_ob[10]->setVariable({ 7,6 }, ROCK, ASTOP, LEFT);
		_ob[11]->setVariable({ 7,7 }, ROCK, ASTOP, LEFT);
		_ob[12]->setVariable({ 7,8 }, ROCK, ASTOP, LEFT);
		_ob[13]->setVariable({ 7,9 }, ROCK, ASTOP, LEFT);
		_ob[14]->setVariable({ 7,10 }, ROCK, ASTOP, LEFT);
		_ob[15]->setVariable({ 7,11 }, ROCK, ASTOP, LEFT);
		_ob[16]->setVariable({ 7,12 }, ROCK, ASTOP, LEFT);
		_ob[17]->setVariable({ 7,13 }, ROCK, ASTOP, LEFT);
		_ob[18]->setVariable({ 8,13 }, ROCK, ASTOP, LEFT);
		_ob[19]->setVariable({ 9,13 }, ROCK, ASTOP, LEFT);
		_ob[20]->setVariable({ 10,13 }, ROCK, ASTOP, LEFT);
		_ob[21]->setVariable({ 11,13 }, ROCK, ASTOP, LEFT);
		_ob[22]->setVariable({ 12,13 }, ROCK, ASTOP, LEFT);
		_ob[23]->setVariable({ 13,13 }, ROCK, ASTOP, LEFT);
		_ob[24]->setVariable({ 14,13 }, ROCK, ASTOP, LEFT);
		_ob[25]->setVariable({ 15,13 }, ROCK, ASTOP, LEFT);
		_ob[26]->setVariable({ 16,13 }, ROCK, ASTOP, LEFT);
		_ob[27]->setVariable({ 16,12 }, ROCK, ASTOP, LEFT);
		_ob[28]->setVariable({ 16,11 }, ROCK, ASTOP, LEFT);
		_ob[29]->setVariable({ 16,10 }, ROCK, ASTOP, LEFT);
		_ob[30]->setVariable({ 16,9 }, ROCK, ASTOP, LEFT);
		_ob[31]->setVariable({ 16,8 }, ROCK, ASTOP, LEFT);
		_ob[32]->setVariable({ 16,7 }, ROCK, ASTOP, LEFT);
		_ob[33]->setVariable({ 16,6 }, ROCK, ASTOP, LEFT);
		_ob[34]->setVariable({ 16,5 }, ROCK, ASTOP, LEFT);
		_ob[35]->setVariable({ 16,4 }, ROCK, ASTOP, LEFT);
		_ob[36]->setVariable({ 15,4 }, ROCK, ASTOP, LEFT);
		_ob[37]->setVariable({ 14,4 }, ROCK, ASTOP, LEFT);
		_ob[38]->setVariable({ 13,4 }, ROCK, ASTOP, LEFT);
		_ob[39]->setVariable({ 12,4 }, ROCK, ASTOP, LEFT);
		_ob[40]->setVariable({ 11,4 }, ROCK, ASTOP, LEFT);
		_ob[41]->setVariable({ 10,4 }, ROCK, ASTOP, LEFT);
		_ob[42]->setVariable({ 9,4 }, ROCK, ASTOP, LEFT);
		_ob[43]->setVariable({ 8,4 }, ROCK, ASTOP, LEFT);
		//==========
		_ob[44]->setVariable({ 11,10 }, WORD_KEKE, PUSH, LEFT);
		_ob[45]->setVariable({ 12,10 }, WORD_IS, PUSH, LEFT);
		_ob[46]->setVariable({ 13,10 }, WORD_PUSH, PUSH, LEFT);
		_ob[47]->setVariable({ 6,6 }, PINE, ASTOP, LEFT);
		_ob[48]->setVariable({ 14,7 }, WORD_ROCK, PUSH, LEFT);
		_ob[0]->setVariable({ 12,11 }, PINES, ASTOP, LEFT);

		break;
	}
	case 2:	// ��������2
		//���� �ʵ� ����
		for (int i = 0; i < WINSIZEY / PSIZE; i++)
		{
			for (int j = 0; j < WINSIZEX / PSIZE; j++)
			{
				pRc[j][i] = RectMake(j * PSIZE, i * PSIZE, PSIZE, PSIZE);
			}
		}
		//���� ��� ����
		_img = _bmg->getImage("backGround2");

		for (int i = 0; i < STAGE2; i++)
		{
			object* obj;
			obj = new object;
			obj->init({1,6});
			_ob.push_back(obj);
		}
		_ob[0]->setVariable({ 1,6 }, KEKE, YOU, LEFT);
		_ob[1]->setVariable({ 8,8 }, WORD_KEKE, PUSH, LEFT);
		_ob[2]->setVariable({ 8,9 }, WORD_IS, PUSH, LEFT);
		_ob[3]->setVariable({ 8,10 }, WORD_YOU, PUSH, LEFT);

		_ob[4]->setVariable({ 0,5 }, ROCK, ASTOP, LEFT);
		_ob[5]->setVariable({ 1,5 }, ROCK, ASTOP, LEFT);
		_ob[6]->setVariable({ 2,5 }, ROCK, ASTOP, LEFT);
		_ob[7]->setVariable({ 3,5 }, ROCK, ASTOP, LEFT);
		_ob[8]->setVariable({ 4,5 }, ROCK, ASTOP, LEFT);
		_ob[9]->setVariable({ 5,5 }, ROCK, ASTOP, LEFT);
		_ob[10]->setVariable({ 5,6 }, ROCK, ASTOP, LEFT);
		_ob[11]->setVariable({ 5,7 }, ROCK, ASTOP, LEFT);
		_ob[12]->setVariable({ 5,8 }, ROCK, ASTOP, LEFT);
		_ob[13]->setVariable({ 5,9 }, ROCK, ASTOP, LEFT);
		_ob[14]->setVariable({ 5,10 }, ROCK, ASTOP, LEFT);
		_ob[15]->setVariable({ 5,11 }, ROCK, ASTOP, LEFT);
		_ob[16]->setVariable({ 5,12 }, ROCK, ASTOP, LEFT);
		_ob[17]->setVariable({ 5,13 }, ROCK, ASTOP, LEFT);
		_ob[18]->setVariable({ 4,13 }, ROCK, ASTOP, LEFT);
		_ob[19]->setVariable({ 3,13 }, ROCK, ASTOP, LEFT);
		_ob[20]->setVariable({ 2,13 }, ROCK, ASTOP, LEFT);
		_ob[21]->setVariable({ 1,13 }, ROCK, ASTOP, LEFT);
		_ob[22]->setVariable({ 0,13 }, ROCK, ASTOP, LEFT);
		_ob[23]->setVariable({ 6,7 }, ROCK, ASTOP, LEFT);
		_ob[24]->setVariable({ 7,7 }, ROCK, ASTOP, LEFT);
		_ob[25]->setVariable({ 8,7 }, ROCK, ASTOP, LEFT);
		_ob[26]->setVariable({ 8,11 }, ROCK, ASTOP, LEFT);
		_ob[27]->setVariable({ 7,11 }, ROCK, ASTOP, LEFT);
		_ob[28]->setVariable({ 6,11 }, ROCK, ASTOP, LEFT);

		_ob[29]->setVariable({ 6,8 }, BABA, ASTOP, LEFT);

		_ob[30]->setVariable({ 7,9 }, WORD_ROCK, PUSH, LEFT);
		_ob[31]->setVariable({ 9,9 }, WORD_STOP, PUSH, LEFT);

		_ob[32]->setVariable({ 3,10 }, WORD_BABA, PUSH, LEFT);
		_ob[33]->setVariable({ 3,9 }, WORD_IS, PUSH, LEFT);
		_ob[34]->setVariable({ 2,9 }, WORD_YOU, PUSH, LEFT);

		_ob[35]->setVariable({ 12,11 }, WORD_WIN, PUSH, LEFT);


		break;
	case 3:	// ��������3
		//���� �ʵ� ����
		for (int i = 0; i < WINSIZEY / PSIZE; i++)
		{
			for (int j = 0; j < WINSIZEX / PSIZE; j++)
			{
				pRc[j][i] = RectMake(j * PSIZE, i * PSIZE, PSIZE, PSIZE);
			}
		}
		//���� ��� ����
		_img = _bmg->getImage("backGround3");

		for (int i = 0; i < STAGE3; i++)
		{
			object* obj;
			obj = new object;
			obj->init({ 0,0 });
			_ob.push_back(obj);
		}
		_ob[0]->setVariable({ 10,4 }, WORD_BABA, PUSH, LEFT);
		_ob[1]->setVariable({ 11,4 }, WORD_IS, PUSH, LEFT);
		_ob[2]->setVariable({ 12,4 }, WORD_YOU, PUSH, LEFT);
		_ob[3]->setVariable({ 7,9 }, WORD_G, PUSH, LEFT);
		_ob[4]->setVariable({ 8,9 }, WORD_A, PUSH, LEFT);
		_ob[5]->setVariable({ 9,9 }, WORD_M, PUSH, LEFT);
		_ob[6]->setVariable({ 10,9 }, WORD_E, PUSH, LEFT);
		_ob[7]->setVariable({ 12,9 }, WORD_C, PUSH, LEFT);
		_ob[8]->setVariable({ 13,9 }, WORD_L, PUSH, LEFT);
		_ob[9]->setVariable({ 14,9 }, WORD_E, PUSH, LEFT);
		_ob[10]->setVariable({ 15,9 }, WORD_A, PUSH, LEFT);
		_ob[11]->setVariable({ 16,9 }, WORD_R, PUSH, LEFT);

		_ob[12]->setVariable({ 11,12 }, BABA, ASTOP, LEFT);

		_ob[13]->setVariable({ 6,15 }, KEKE, ASTOP, LEFT);
		_ob[14]->setVariable({ 7,15 }, ROCK, ASTOP, LEFT);
		_ob[15]->setVariable({ 6,16 }, WORD_KEKE, PUSH, LEFT);
		_ob[16]->setVariable({ 7,16 }, WORD_ROCK, PUSH, LEFT);
		_ob[17]->setVariable({ 16,16 }, WORD_IS, PUSH, LEFT);
		_ob[18]->setVariable({ 16,15 }, WORD_IS, PUSH, LEFT);
		_ob[19]->setVariable({ 17,16 }, WORD_PUSH, PUSH, LEFT);
		_ob[20]->setVariable({ 17,15 }, WORD_STOP, PUSH, LEFT);


		break;
	}
}

//������Ʈ Ű �Է� 01 23
void stageManager::ATypeControl(moveType act)
{
	_sleepCount = 0;

	//a�� ���� ���
	for (int i = 0; i < _ob.size(); i++)
	{
		//��� �� ����
		_ob[i]->dSave();

		if (_ob[i]->getAtype() == YOU)
		{
			setAstate(new you());
			getAstate(act, i,_ob);
		}
		else if (_ob[i]->getAtype() == WIN)
		{
			setAstate(new win());
			getAstate(act, i, _ob);
		}
		else if (_ob[i]->getAtype() == PUSH)
		{
			setAstate(new push());
			getAstate(act, i, _ob);
		}
		else if (_ob[i]->getAtype() == STOP)
		{
			setAstate(new stop());
			getAstate(act, i, _ob);
		}
	}
	//��� �� �̵�
	for (int i = 0; i < _ob.size(); i++)
	{
		_ob[i]->move();
	}
	//��� �� ��ȣ�ۿ�
	_bmg->iTypeinit(_ob);
}

//���� ����
bool stageManager::getgameSet()
{
	return _fin;
}

//���� ���� ����
void stageManager::setgameSet()
{
	for (int i = 0; i < _ob.size(); i++)
	{
		//������Ʈ�� Ÿ���� you �̰� ��ȣ�ۿ� üũ�� ���� ���
		if (_ob[i]->getAtype() == YOU && _ob[i]->getInteraction())
		{
			_fin = true;
		}
	}
}

//�ڷΰ���
void stageManager::cBack()
{
	for (int i = 0; i < _ob.size(); i++)
	{
		_ob[i]->dLoad();
	}
}
