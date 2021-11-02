#include "pch.h"
#include "aType.h"


void aType::setAction(moveType key, int objnum, vector<object*>& ob)
{
}

//오브젝트 move
void you::setAction(moveType key, int objnum, vector<object*>& ob)
{
	
	//====================================================================
	//							YOU의	리동처리
	//====================================================================
	
	//이동
	if (key == LEFT)
	{
		ob[objnum]->setActive(true);
		ob[objnum]->setMtype(LEFT);
	}
	else if (key == RIGHT)
	{
		ob[objnum]->setActive(true);
		ob[objnum]->setMtype(RIGHT);
	}
	else if (key == UP)
	{
		ob[objnum]->setActive(true);
		ob[objnum]->setMtype(UP);
	}
	else if (key == DOWN)
	{
		ob[objnum]->setActive(true);
		ob[objnum]->setMtype(DOWN);
	}

	//====================================================================
	//							YOU의	STOP처리
	//====================================================================

	range = 1;
	i = 0;
	while (true)
	{
		//마지막 비교대상까지 대상이 아니라면 종료
		if (i >= ob.size()) break;

		// 비교대상이 같다면 대상 변경
		if (objnum == i)
		{
			i++;
			continue;
		}

		//같은 y에 x 검색 범위 내에 들어와 있을 경우
		//LEFT
		if (key == LEFT)
		{
			if (ob[objnum]->getPoint().x == 0)
			{
				ob[objnum]->setMtype(LEFT);
				ob[objnum]->setActive(false);
				break;
			}
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x + range)
			{
				//범위 안에 들어와 있는 i의 좌표가 끝일경우
				if (ob[i]->getPoint().x == 0)
				{
					ob[objnum]->setMtype(LEFT);
					ob[objnum]->setActive(false);
					break;
				}
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 stop일 경우
				else if (ob[i]->getAtype() == STOP)
				{
					ob[objnum]->setMtype(LEFT);
					ob[objnum]->setActive(false);
					break;
				}
			}
		}
		//RIGHT
		else if (key == RIGHT)
		{
			if (ob[objnum]->getPoint().x == WINSIZEX / PSIZE - 1)
			{
				ob[objnum]->setMtype(RIGHT);
				ob[objnum]->setActive(false);
				break;
			}
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x - range)
			{
				//범위 안에 들어와 있는 i의 좌표가 끝일경우
				if (ob[i]->getPoint().x == WINSIZEX / PSIZE - 1)
				{
					ob[objnum]->setMtype(RIGHT);
					ob[objnum]->setActive(false);
					break;
				}
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 stop일 경우
				else if (ob[i]->getAtype() == STOP )
				{
					ob[objnum]->setMtype(RIGHT);
					ob[objnum]->setActive(false);
					break;
				}
			}
		}
		//UP
		else if (key == UP)
		{
			if (ob[objnum]->getPoint().y == 0)
			{
				ob[objnum]->setMtype(UP);
				ob[objnum]->setActive(false);
				break;
			}
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y + range)
			{
				//범위 안에 들어와 있는 i의 좌표가 끝일경우
				if (ob[i]->getPoint().y == 0)
				{
					ob[objnum]->setMtype(UP);
					ob[objnum]->setActive(false);
					break;
				}
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 stop일 경우
				else if (ob[i]->getAtype() == STOP)
				{
					ob[objnum]->setMtype(UP);
					ob[objnum]->setActive(false);
					break;
				}
			}
		}
		//DOWN
		else if (key == DOWN)
		{
			if (ob[objnum]->getPoint().y == WINSIZEY / PSIZE - 1)
			{
				ob[objnum]->setMtype(DOWN);
				ob[objnum]->setActive(false);
				break;
			}
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y - range)
			{
				//범위 안에 들어와 있는 i의 좌표가 끝일경우
				if (ob[i]->getPoint().y == WINSIZEY / PSIZE - 1)
				{
					ob[objnum]->setMtype(DOWN);
					ob[objnum]->setActive(false);
					break;
				}
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 stop일 경우
				else if (ob[i]->getAtype() == STOP)
				{
					ob[objnum]->setMtype(DOWN);
					ob[objnum]->setActive(false);
					break;
				}
			}
		}
		//비교했으나 범위에 없을 경우
		i++;
	}
	//====================================================================
	//							YOU의	이미지처리
	//====================================================================
	
	//LTRB 이미지 변환, 
	if (ob[objnum]->getItype() == BABA
		|| ob[objnum]->getItype() == KEKE)
	{
		if (ob[objnum]->getMtype() == LEFT || ob[objnum]->getMtype() == UP)
		{
			ob[objnum]->setVariable(ob[objnum]->getFrame().x, 1);
		}
		else if (ob[objnum]->getMtype() == RIGHT || ob[objnum]->getMtype() == DOWN)
		{
			ob[objnum]->setVariable(ob[objnum]->getFrame().x, 0);
		}
		//이미지 변환
		if (ob[objnum]->getInum() != 4)
		{
			ob[objnum]->setInum(ob[objnum]->getInum() + 1);
		}
		else if (ob[objnum]->getInum() == 4)
		{
			ob[objnum]->setInum(1);
		}
	}
	else
	{
		ob[objnum]->setVariable(ob[objnum]->getFrame().x, 0);
	}
}

void win::setAction(moveType key, int objnum, vector<object*>& ob)
{
	//====================================================================
	//							WIN의	YOU처리
	//====================================================================

	i = 0; // 비교대상 오브젝트 넘버
	range = 1;// 비교범위

	while (true)
	{
		//마지막 비교대상까지 대상이 아니라면 종료
		if (i >= ob.size()) break;

		// 비교대상이 같다면 대상 변경
		if (objnum == i || ob[i]->getAtype() != YOU)
		{
			i++;
			continue;
		}

		if (key == LEFT)
		{
			//같은 y에 x 검색 범위 내에 들어와 있을 경우
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x - range)
			{
				ob[i]->setInteraction(true);
			}
		}
		else if (key == RIGHT)
		{
			//같은 y에 x 검색 범위 내에 들어와 있을 경우
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x + range)
			{
				ob[i]->setInteraction(true);
			}
		}
		else if (key == UP)
		{
			//같은 y에 x 검색 범위 내에 들어와 있을 경우
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y - range)
			{
				ob[i]->setInteraction(true);
			}
		}
		else if (key == DOWN)
		{
			//같은 y에 x 검색 범위 내에 들어와 있을 경우
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y + range)
			{
				ob[i]->setInteraction(true);
			}
		}

		//비교했으나 범위에 없을 경우
		i++;
	}
}

//오브젝트 push
void push::setAction(moveType key, int objnum, vector<object*>& ob)
{
	//====================================================================
	//							PUSH의	YOU처리
	//====================================================================

	i = 0; // 비교대상 오브젝트 넘버
	range = 1;// 비교범위
	if (key == LEFT)
	{
		while (true)
		{
			//마지막 비교대상까지 대상이 아니라면 종료
			if (i >= ob.size()) break;
			// 비교대상이 같다면 대상 변경
			if (objnum == i)
			{
				i++;
				continue;
			}

			//같은 y에 x 검색 범위 내에 들어와 있을 경우
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x - range)
			{
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 you일 경우
				else if (ob[i]->getAtype() == YOU)
				{
					ob[objnum]->setMtype(LEFT);
					ob[objnum]->setActive(true);
					break;
				}
			}

			//비교했으나 범위에 없을 경우
			i++;
		}
	}

	if (key == RIGHT)
	{
		while (true)
		{
			//마지막 비교대상까지 대상이 아니라면 종료
			if (i >= ob.size()) break;
			// 비교대상이 같다면 대상 변경
			if (objnum == i)
			{
				i++;
				continue;
			}

			//같은 y에 x 검색 범위 내에 들어와 있을 경우
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x + range)
			{
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 you일 경우
				else if (ob[i]->getAtype() == YOU)
				{
					ob[objnum]->setMtype(RIGHT);
					ob[objnum]->setActive(true);
					break;
				}
			}

			//비교했으나 범위에 없을 경우
			i++;
		}
	}
	else if (key == UP)
	{
		while (true)
		{
			//마지막 비교대상까지 대상이 아니라면 종료
			if (i >= ob.size()) break;
			// 비교대상이 같다면 대상 변경
			if (objnum == i)
			{
				i++;
				continue;
			}

			//같은 y에 x 검색 범위 내에 들어와 있을 경우
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y - range)
			{
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 you일 경우
				else if (ob[i]->getAtype() == YOU)
				{
					ob[objnum]->setMtype(UP);
					ob[objnum]->setActive(true);
					break;
				}
			}

			//비교했으나 범위에 없을 경우
			i++;
		}
	}
	else if (key == DOWN)
	{
		while (true)
		{
			//마지막 비교대상까지 대상이 아니라면 종료
			if (i >= ob.size()) break;
			// 비교대상이 같다면 대상 변경
			if (objnum == i)
			{
				i++;
				continue;
			}

			//같은 y에 x 검색 범위 내에 들어와 있을 경우
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y + range)
			{
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 you일 경우
				else if (ob[i]->getAtype() == YOU)
				{
					ob[objnum]->setMtype(DOWN);
					ob[objnum]->setActive(true);
					break;
				}
			}

			//비교했으나 범위에 없을 경우
			i++;
		}
	}
	//====================================================================
	//							PUSH의	STOP처리
	//====================================================================
	
	//STOP 확인

	i = 0; // 비교대상 오브젝트 넘버
	range = 1;// 비교범위

	while (true)
	{
		//마지막 비교대상까지 대상이 아니라면 종료
		if (i >= ob.size()) break;
		// 비교대상이 같다면 대상 변경
		if (objnum == i)
		{
			i++;
			continue;
		}

		//같은 y에 x 검색 범위 내에 들어와 있을 경우
		//LEFT
		if (key == LEFT)
		{
			if (ob[objnum]->getPoint().x == 0)
			{
				ob[objnum]->setMtype(LEFT);
				ob[objnum]->setActive(false);
				break;
			}
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x + range)
			{
				//범위 안에 들어와 있는 i의 좌표가 끝일경우
				if (ob[i]->getPoint().x == 0)
				{
					ob[objnum]->setMtype(LEFT);
					ob[objnum]->setActive(false);
					break;
				}
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 stop일 경우
				else if (ob[i]->getAtype() == STOP)
				{
					ob[objnum]->setMtype(LEFT);
					ob[objnum]->setActive(false);
					break;
				}
			}
		}
		//RIGHT
		else if (key == RIGHT)
		{
			if (ob[objnum]->getPoint().x == WINSIZEX / PSIZE - 1)
			{
				ob[objnum]->setMtype(RIGHT);
				ob[objnum]->setActive(false);
				break;
			}
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x - range)
			{
				//범위 안에 들어와 있는 i의 좌표가 끝일경우
				if (ob[i]->getPoint().x == WINSIZEX / PSIZE - 1)
				{
					ob[objnum]->setMtype(RIGHT);
					ob[objnum]->setActive(false);
					break;
				}
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 stop일 경우
				if (ob[i]->getAtype() == STOP )
				{
					ob[objnum]->setMtype(RIGHT);
					ob[objnum]->setActive(false);
					break;
				}
			}
		}
		//UP
		else if (key == UP)
		{
			//마지막 땅을 밟았을 경우
			if (ob[objnum]->getPoint().y == 0)
			{
				ob[objnum]->setMtype(UP);
				ob[objnum]->setActive(false);
				break;
			}
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y + range)
			{
				//범위 안에 들어와 있는 i의 좌표가 끝일경우
				if (ob[i]->getPoint().y == 0)
				{
					ob[objnum]->setMtype(UP);
					ob[objnum]->setActive(false);
					break;
				}
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 stop일 경우
				else if (ob[i]->getAtype() == STOP)
				{
					ob[objnum]->setMtype(UP);
					ob[objnum]->setActive(false);
					break;
				}
			}
		}
		//DOWN
		else if (key == DOWN)
		{
			//마지막 땅을 밟았을 경우
			if (ob[objnum]->getPoint().y == WINSIZEY / PSIZE - 1)
			{
				ob[objnum]->setMtype(DOWN);
				ob[objnum]->setActive(false);
				break;
			}
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y - range)
			{
				//범위 안에 들어와 있는 i의 좌표가 끝일경우
				if (ob[objnum]->getPoint().y == WINSIZEY / PSIZE - 1)
				{
					ob[objnum]->setMtype(DOWN);
					ob[objnum]->setActive(false);
					break;
				}
				//범위 안에 들어와 있는 i의 태그가 push일 경우
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//범위 안에 들어와있는 i의 태그가 stop일 경우
				else if (ob[i]->getAtype() == STOP)
				{
					ob[objnum]->setMtype(DOWN);
					ob[objnum]->setActive(false);
					break;
				}
			}
		}
		//비교했으나 범위에 없을 경우
		i++;
	}
}

void stop::setAction(moveType key, int objnum, vector<object*>& ob)
{
	//stop이 멈추는게 아니다.
	//stop을 본 다른 놈들이 멈추는거지
}
