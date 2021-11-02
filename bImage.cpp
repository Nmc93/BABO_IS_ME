#include "pch.h"
#include "bImage.h"

//이미지 초기화
HRESULT bImage::init()
{
	//맵
	IMAGEMANAGER->addImage("backGround","image/backG.bmp",WINSIZEX,WINSIZEY,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("backGround1","image/backG1.bmp",WINSIZEX,WINSIZEY,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("backGround2","image/backG2.bmp",WINSIZEX,WINSIZEY,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("backGround3","image/backG3.bmp",WINSIZEX,WINSIZEY,true,RGB(255,0,255));

	//바바
	//바바 left,right
	IMAGEMANAGER->addFrameImage("baba_lr0", "image/baba_lr0.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("baba_lr1", "image/baba_lr1.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("baba_lr2", "image/baba_lr2.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("baba_lr3", "image/baba_lr3.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("baba_lr4", "image/baba_lr4.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	//바바 up,down
	IMAGEMANAGER->addFrameImage("baba_ud0", "image/baba_ud0.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("baba_ud1", "image/baba_ud1.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("baba_ud2", "image/baba_ud2.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("baba_ud3", "image/baba_ud3.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("baba_ud4", "image/baba_ud4.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));

	//케케
	//케케 left,right
	IMAGEMANAGER->addFrameImage("keke_lr0", "image/keke_lr0.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("keke_lr1", "image/keke_lr1.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("keke_lr2", "image/keke_lr2.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("keke_lr3", "image/keke_lr3.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("keke_lr4", "image/keke_lr4.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	//케케 up,down
	IMAGEMANAGER->addFrameImage("keke_ud0", "image/keke_ud0.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("keke_ud1", "image/keke_ud1.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("keke_ud2", "image/keke_ud2.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("keke_ud3", "image/keke_ud3.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("keke_ud4", "image/keke_ud4.bmp", 75, 50, 3, 2, true, RGB(255, 0, 255));

	//오브젝트
	IMAGEMANAGER->addFrameImage("rock_0", "image/rock_0.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("flag_0", "image/flag_0.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));

	//word
	//object
	IMAGEMANAGER->addFrameImage("word_baba", "image/word_baba.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_keke", "image/word_keke.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_rock", "image/word_rock.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_flag", "image/word_flag.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	//verb
	IMAGEMANAGER->addFrameImage("word_is", "image/word_is.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	//attribute
	IMAGEMANAGER->addFrameImage("word_push", "image/word_push.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_win", "image/word_win.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_you", "image/word_you.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_stop", "image/word_stop.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	
	//============================================== 추가 해야함====================================
	//알파벳
	IMAGEMANAGER->addFrameImage("word_a", "alphabet/word_a.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_c", "alphabet/word_c.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_e", "alphabet/word_e.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_g", "alphabet/word_g.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_l", "alphabet/word_l.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_m", "alphabet/word_m.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("word_r", "alphabet/word_r.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));

	//단어없는 오브젝트

	IMAGEMANAGER->addFrameImage("cattail_0", "mapimage/cattail_0.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("leaf_0", "mapimage/leaf_0.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("pine_0", "mapimage/pine_0.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("pines", "mapimage/pines.bmp", 75, 25, 3, 1, true, RGB(255, 0, 255));

	//============================================== 추가 해야함====================================
	return S_OK;
}

void bImage::release()
{
}

void bImage::update()
{
}

void bImage::render()
{
}

//테스트용 이미지 변환
image* bImage::getImage(string word)
{
	return IMAGEMANAGER->findImage(word);
}

//이미지와 행동에 따른 이미지 변경
void bImage::imageChange(vector<object*>& ob)
{
	for (int i = 0; i < ob.size(); i++)
	{
		//======================= 캐릭터 =====================================
		//바바
		if (ob[i]->getItype() == BABA)
		{
			if (ob[i]->getMtype() == LEFT || ob[i]->getMtype() == RIGHT)
			{
				switch (ob[i]->getInum())
				{
				case 0:
					ob[i]->setImage(IMAGEMANAGER->findImage("baba_lr0"));
					break;
				case 1:
					ob[i]->setImage(IMAGEMANAGER->findImage("baba_lr1"));
					break;
				case 2:
					ob[i]->setImage(IMAGEMANAGER->findImage("baba_lr2"));
					break;
				case 3:
					ob[i]->setImage(IMAGEMANAGER->findImage("baba_lr3"));
					break;
				case 4:
					ob[i]->setImage(IMAGEMANAGER->findImage("baba_lr4"));
					break;
				}
			}
			else if (ob[i]->getMtype() == UP || ob[i]->getMtype() == DOWN)
			{
				switch (ob[i]->getInum())
				{
				case 0:
					ob[i]->setImage(IMAGEMANAGER->findImage("baba_ud0"));
					break;
				case 1:
					ob[i]->setImage(IMAGEMANAGER->findImage("baba_ud1"));
					break;
				case 2:
					ob[i]->setImage(IMAGEMANAGER->findImage("baba_ud2"));
					break;
				case 3:
					ob[i]->setImage(IMAGEMANAGER->findImage("baba_ud3"));
					break;
				case 4:
					ob[i]->setImage(IMAGEMANAGER->findImage("baba_ud4"));
					break;
				}
			}
		}
		//케케
		else if (ob[i]->getItype() == KEKE)
		{
			if (ob[i]->getMtype() == LEFT || ob[i]->getMtype() == RIGHT)
			{
				switch (ob[i]->getInum())
				{
				case 0:
					ob[i]->setImage(IMAGEMANAGER->findImage("keke_lr0"));
					break;
				case 1:
					ob[i]->setImage(IMAGEMANAGER->findImage("keke_lr1"));
					break;
				case 2:
					ob[i]->setImage(IMAGEMANAGER->findImage("keke_lr2"));
					break;
				case 3:
					ob[i]->setImage(IMAGEMANAGER->findImage("keke_lr3"));
					break;
				case 4:
					ob[i]->setImage(IMAGEMANAGER->findImage("keke_lr4"));
					break;
				}
			}
			else if (ob[i]->getMtype() == UP || ob[i]->getMtype() == DOWN)
			{
				switch (ob[i]->getInum())
				{
				case 0:
					ob[i]->setImage(IMAGEMANAGER->findImage("keke_ud0"));
					break;
				case 1:
					ob[i]->setImage(IMAGEMANAGER->findImage("keke_ud1"));
					break;
				case 2:
					ob[i]->setImage(IMAGEMANAGER->findImage("keke_ud2"));
					break;
				case 3:
					ob[i]->setImage(IMAGEMANAGER->findImage("keke_ud3"));
					break;
				case 4:
					ob[i]->setImage(IMAGEMANAGER->findImage("keke_ud4"));
					break;
				}
			}
		}
		//======================= 구조물 =====================================
		//====================== 단어 있음 ===================================
		else if (ob[i]->getItype() == ROCK)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("rock_0"));
		}
		else if (ob[i]->getItype() == FLAG)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("flag_0"));
		}
		//====================== 단어 없음 ===================================
		else if (ob[i]->getItype() == CATTAIL)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("cattail_0"));
		}
		else if (ob[i]->getItype() == LEAF)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("leaf_0"));
		}
		else if (ob[i]->getItype() == PINE)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("pine_0"));
		}
		else if (ob[i]->getItype() == PINES)
		{
		ob[i]->setImage(IMAGEMANAGER->findImage("pines"));
		}

		//======================== 단어 ====================================
		else if (ob[i]->getItype() == WORD_BABA)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("word_baba"));
		}
		else if (ob[i]->getItype() == WORD_KEKE)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("word_keke"));
		}
		else if (ob[i]->getItype() == WORD_ROCK)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("word_rock"));
		}
		else if (ob[i]->getItype() == WORD_IS)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("word_is"));
		}
		else if (ob[i]->getItype() == WORD_YOU)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("word_you"));
		}
		else if (ob[i]->getItype() == WORD_WIN)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("word_win"));
		}
		else if (ob[i]->getItype() == WORD_PUSH)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("word_push"));
		}
		else if (ob[i]->getItype() == WORD_STOP)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("word_stop"));
		}
		else if (ob[i]->getItype() == WORD_FLAG)
		{
			ob[i]->setImage(IMAGEMANAGER->findImage("word_flag"));
		}
		//======================== 단어 ====================================
		else if (ob[i]->getItype() == WORD_A)
		{
		ob[i]->setImage(IMAGEMANAGER->findImage("word_a"));
		}
		else if (ob[i]->getItype() == WORD_C)
		{
		ob[i]->setImage(IMAGEMANAGER->findImage("word_c"));
		}
		else if (ob[i]->getItype() == WORD_E)
		{
		ob[i]->setImage(IMAGEMANAGER->findImage("word_e"));
		}
		else if (ob[i]->getItype() == WORD_G)
		{
		ob[i]->setImage(IMAGEMANAGER->findImage("word_g"));
		}
		else if (ob[i]->getItype() == WORD_L)
		{
		ob[i]->setImage(IMAGEMANAGER->findImage("word_l"));
		}
		else if (ob[i]->getItype() == WORD_M)
		{
		ob[i]->setImage(IMAGEMANAGER->findImage("word_m"));
		}
		else if (ob[i]->getItype() == WORD_R)
		{
		ob[i]->setImage(IMAGEMANAGER->findImage("word_r"));
		}
	}
}

void bImage::iTypeinit(vector<object*>& ob)
{
	//상태 초기화
	for (int i = 0; i < ob.size(); i++)
	{
		if (ob[i]->getItype() == BABA ||
			ob[i]->getItype() == KEKE ||
			ob[i]->getItype() == ROCK ||
			ob[i]->getItype() == FLAG)
		{
			ob[i]->setAtype(ASTOP);
		}
	}
}

//이미지에 따른 상호작용
void bImage::iTypeLr(vector<object*>& ob)
{
	//0 : left ,1 : right
	int ObjNum[2] = { 0,0 };
	bool clear[2] = {false, false};
	
	//is의 좌우 검사
	for (int i = 0; i < ob.size(); i++)
	{
		//i가 is가 아니라면 거름
		if (ob[i]->getItype() != WORD_IS) continue;

		//좌우검사
		for (int j = 0; j < ob.size(); j++)
		{
			//i와 j가 같다면 거름
			if (i == j) continue;

			//i의 left에 j가 있는가?(좌검사)
			if (ob[i]->getPoint().y == ob[j]->getPoint().y &&
				ob[i]->getPoint().x == ob[j]->getPoint().x + 1)
			{
				//j가 오브젝트의 word라면
				if (ob[j]->getItype() == WORD_BABA ||
					ob[j]->getItype() == WORD_KEKE ||
					ob[j]->getItype() == WORD_ROCK ||
					ob[j]->getItype() == WORD_FLAG)
				{
					ObjNum[0] = j;
					clear[0] = true;
				}
			}
			//i의 right에 j가 있는가?(우검사)
			if (ob[i]->getPoint().y == ob[j]->getPoint().y &&
				ob[i]->getPoint().x == ob[j]->getPoint().x - 1)
			{
				//j가 반응가능한 오브젝트라면
				if (ob[j]->getItype() == WORD_YOU ||
					ob[j]->getItype() == WORD_WIN ||
					ob[j]->getItype() == WORD_PUSH||
					ob[j]->getItype() == WORD_STOP||
					ob[j]->getItype() == WORD_BABA||
					ob[j]->getItype() == WORD_KEKE||
					ob[j]->getItype() == WORD_ROCK||
					ob[j]->getItype() == WORD_FLAG)
				{
					ObjNum[1] = j;
					clear[1] = true;
				}
			}

		}

		//is의 좌우에 모두 있다면
		if (clear[0] && clear[1])
		{
			for (int i = 0; i < ob.size(); i++)
			{
				//===================== Itype 변화 ===========================
				//right가 baba일때
				if (ob[ObjNum[1]]->getItype() == WORD_BABA)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setItype(BABA);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setItype(BABA);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setItype(BABA);
					}
				}
				//right가 keke일때
				else if (ob[ObjNum[1]]->getItype() == WORD_KEKE)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setItype(KEKE);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setItype(KEKE);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setItype(KEKE);
					}
				}
				//right가 rock일때
				else if (ob[ObjNum[1]]->getItype() == WORD_ROCK)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setItype(ROCK);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setItype(ROCK);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setItype(ROCK);
					}
				}
				//right가 flag일때
				else if (ob[ObjNum[1]]->getItype() == WORD_FLAG)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setItype(FLAG);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setItype(FLAG);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setItype(FLAG);
					}
				}
				//===================== Atype 변화 ============================
				//right가 you일때
				else if (ob[ObjNum[1]]->getItype() == WORD_YOU)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setAtype(YOU);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setAtype(YOU);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setAtype(YOU);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setAtype(YOU);
					}
				}
				//right가 win일때
				else if (ob[ObjNum[1]]->getItype() == WORD_WIN)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setAtype(WIN);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setAtype(WIN);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setAtype(WIN);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setAtype(WIN);
					}
				}
				//right가 push일때
				else if (ob[ObjNum[1]]->getItype() == WORD_PUSH)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setAtype(PUSH);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setAtype(PUSH);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setAtype(PUSH);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setAtype(PUSH);
					}
				}
				//right가 stop일때
				else if (ob[ObjNum[1]]->getItype() == WORD_STOP && ob[i]->getAtype() != PUSH)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setAtype(STOP);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setAtype(STOP);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setAtype(STOP);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setAtype(STOP);
					}
				}
			}
		}
		ObjNum[0] = ObjNum[1] = 0;
		clear[0] = clear[1] = false;
	}
}

//위아래 검사
void bImage::iTypeUd(vector<object*>& ob)
{
	//0 : up ,1 : down
	int ObjNum[2] = { 0,0 };
	bool clear[2] = { false, false };

	//is의 위아래 검사
	for (int i = 0; i < ob.size(); i++)
	{
		//i가 is가 아니라면 거름
		if (ob[i]->getItype() != WORD_IS) continue;

		//위아래검사
		for (int j = 0; j < ob.size(); j++)
		{
			//i와 j가 같다면 거름
			if (i == j) continue;

			//i의 left에 j가 있는가?(위검사)
			if (ob[i]->getPoint().x == ob[j]->getPoint().x &&
				ob[i]->getPoint().y == ob[j]->getPoint().y + 1)
			{
				//j가 오브젝트의 word라면
				if (ob[j]->getItype() == WORD_BABA ||
					ob[j]->getItype() == WORD_KEKE ||
					ob[j]->getItype() == WORD_ROCK ||
					ob[j]->getItype() == WORD_FLAG)
				{
					ObjNum[0] = j;
					clear[0] = true;
				}
			}
			//i의 right에 j가 있는가?(아래검사)
			if (ob[i]->getPoint().x == ob[j]->getPoint().x &&
				ob[i]->getPoint().y == ob[j]->getPoint().y - 1)
			{
				//j가 속성 word라면
				if (ob[j]->getItype() == WORD_YOU ||
					ob[j]->getItype() == WORD_WIN ||
					ob[j]->getItype() == WORD_PUSH ||
					ob[j]->getItype() == WORD_STOP ||
					ob[j]->getItype() == WORD_BABA ||
					ob[j]->getItype() == WORD_KEKE ||
					ob[j]->getItype() == WORD_ROCK ||
					ob[j]->getItype() == WORD_FLAG)
				{
					ObjNum[1] = j;
					clear[1] = true;
				}
			}

		}

		//is의 위아래에 모두 있다면
		if (clear[0] && clear[1])
		{
			for (int i = 0; i < ob.size(); i++)
			{
				//===================== Itype 변화 ===========================
				//right가 baba일때
				if (ob[ObjNum[1]]->getItype() == WORD_BABA)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setItype(BABA);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setItype(BABA);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setItype(BABA);
					}
				}
				//right가 keke일때
				else if (ob[ObjNum[1]]->getItype() == WORD_KEKE)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setItype(KEKE);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setItype(KEKE);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setItype(KEKE);
					}
				}
				//right가 rock일때
				else if (ob[ObjNum[1]]->getItype() == WORD_ROCK)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setItype(ROCK);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setItype(ROCK);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setItype(ROCK);
					}
				}
				//right가 flag일때
				else if (ob[ObjNum[1]]->getItype() == WORD_FLAG)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setItype(FLAG);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setItype(FLAG);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setItype(FLAG);
					}
				}
				//===================== Atype 변화 ============================
				//down이 you일때
				if (ob[ObjNum[1]]->getItype() == WORD_YOU)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setAtype(YOU);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setAtype(YOU);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setAtype(YOU);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setAtype(YOU);
					}
				}
				//down이 win일때
				else if (ob[ObjNum[1]]->getItype() == WORD_WIN)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setAtype(WIN);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setAtype(WIN);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setAtype(WIN);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setAtype(WIN);
					}
				}
				//down이 push일때
				else if (ob[ObjNum[1]]->getItype() == WORD_PUSH)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setAtype(PUSH);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setAtype(PUSH);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setAtype(PUSH);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setAtype(PUSH);
					}
				}
				//down이 stop일때
				else if (ob[ObjNum[1]]->getItype() == WORD_STOP && ob[i]->getAtype() != PUSH)
				{
					if (ob[ObjNum[0]]->getItype() == WORD_BABA)
					{
						if (ob[i]->getItype() == BABA) ob[i]->setAtype(STOP);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_KEKE)
					{
						if (ob[i]->getItype() == KEKE) ob[i]->setAtype(STOP);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_ROCK)
					{
						if (ob[i]->getItype() == ROCK) ob[i]->setAtype(STOP);
					}
					else if (ob[ObjNum[0]]->getItype() == WORD_FLAG)
					{
						if (ob[i]->getItype() == FLAG) ob[i]->setAtype(STOP);
					}
				}
			}
		}
		ObjNum[0] = ObjNum[1] = 0;
		clear[0] = clear[1] = false;
	}
}
