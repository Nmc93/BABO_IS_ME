#include "pch.h"
#include "aType.h"


void aType::setAction(moveType key, int objnum, vector<object*>& ob)
{
}

//������Ʈ move
void you::setAction(moveType key, int objnum, vector<object*>& ob)
{
	
	//====================================================================
	//							YOU��	����ó��
	//====================================================================
	
	//�̵�
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
	//							YOU��	STOPó��
	//====================================================================

	range = 1;
	i = 0;
	while (true)
	{
		//������ �񱳴����� ����� �ƴ϶�� ����
		if (i >= ob.size()) break;

		// �񱳴���� ���ٸ� ��� ����
		if (objnum == i)
		{
			i++;
			continue;
		}

		//���� y�� x �˻� ���� ���� ���� ���� ���
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
				//���� �ȿ� ���� �ִ� i�� ��ǥ�� ���ϰ��
				if (ob[i]->getPoint().x == 0)
				{
					ob[objnum]->setMtype(LEFT);
					ob[objnum]->setActive(false);
					break;
				}
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� stop�� ���
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
				//���� �ȿ� ���� �ִ� i�� ��ǥ�� ���ϰ��
				if (ob[i]->getPoint().x == WINSIZEX / PSIZE - 1)
				{
					ob[objnum]->setMtype(RIGHT);
					ob[objnum]->setActive(false);
					break;
				}
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� stop�� ���
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
				//���� �ȿ� ���� �ִ� i�� ��ǥ�� ���ϰ��
				if (ob[i]->getPoint().y == 0)
				{
					ob[objnum]->setMtype(UP);
					ob[objnum]->setActive(false);
					break;
				}
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� stop�� ���
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
				//���� �ȿ� ���� �ִ� i�� ��ǥ�� ���ϰ��
				if (ob[i]->getPoint().y == WINSIZEY / PSIZE - 1)
				{
					ob[objnum]->setMtype(DOWN);
					ob[objnum]->setActive(false);
					break;
				}
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� stop�� ���
				else if (ob[i]->getAtype() == STOP)
				{
					ob[objnum]->setMtype(DOWN);
					ob[objnum]->setActive(false);
					break;
				}
			}
		}
		//�������� ������ ���� ���
		i++;
	}
	//====================================================================
	//							YOU��	�̹���ó��
	//====================================================================
	
	//LTRB �̹��� ��ȯ, 
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
		//�̹��� ��ȯ
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
	//							WIN��	YOUó��
	//====================================================================

	i = 0; // �񱳴�� ������Ʈ �ѹ�
	range = 1;// �񱳹���

	while (true)
	{
		//������ �񱳴����� ����� �ƴ϶�� ����
		if (i >= ob.size()) break;

		// �񱳴���� ���ٸ� ��� ����
		if (objnum == i || ob[i]->getAtype() != YOU)
		{
			i++;
			continue;
		}

		if (key == LEFT)
		{
			//���� y�� x �˻� ���� ���� ���� ���� ���
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x - range)
			{
				ob[i]->setInteraction(true);
			}
		}
		else if (key == RIGHT)
		{
			//���� y�� x �˻� ���� ���� ���� ���� ���
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x + range)
			{
				ob[i]->setInteraction(true);
			}
		}
		else if (key == UP)
		{
			//���� y�� x �˻� ���� ���� ���� ���� ���
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y - range)
			{
				ob[i]->setInteraction(true);
			}
		}
		else if (key == DOWN)
		{
			//���� y�� x �˻� ���� ���� ���� ���� ���
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y + range)
			{
				ob[i]->setInteraction(true);
			}
		}

		//�������� ������ ���� ���
		i++;
	}
}

//������Ʈ push
void push::setAction(moveType key, int objnum, vector<object*>& ob)
{
	//====================================================================
	//							PUSH��	YOUó��
	//====================================================================

	i = 0; // �񱳴�� ������Ʈ �ѹ�
	range = 1;// �񱳹���
	if (key == LEFT)
	{
		while (true)
		{
			//������ �񱳴����� ����� �ƴ϶�� ����
			if (i >= ob.size()) break;
			// �񱳴���� ���ٸ� ��� ����
			if (objnum == i)
			{
				i++;
				continue;
			}

			//���� y�� x �˻� ���� ���� ���� ���� ���
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x - range)
			{
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� you�� ���
				else if (ob[i]->getAtype() == YOU)
				{
					ob[objnum]->setMtype(LEFT);
					ob[objnum]->setActive(true);
					break;
				}
			}

			//�������� ������ ���� ���
			i++;
		}
	}

	if (key == RIGHT)
	{
		while (true)
		{
			//������ �񱳴����� ����� �ƴ϶�� ����
			if (i >= ob.size()) break;
			// �񱳴���� ���ٸ� ��� ����
			if (objnum == i)
			{
				i++;
				continue;
			}

			//���� y�� x �˻� ���� ���� ���� ���� ���
			if (ob[objnum]->getPoint().y == ob[i]->getPoint().y &&
				ob[objnum]->getPoint().x == ob[i]->getPoint().x + range)
			{
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� you�� ���
				else if (ob[i]->getAtype() == YOU)
				{
					ob[objnum]->setMtype(RIGHT);
					ob[objnum]->setActive(true);
					break;
				}
			}

			//�������� ������ ���� ���
			i++;
		}
	}
	else if (key == UP)
	{
		while (true)
		{
			//������ �񱳴����� ����� �ƴ϶�� ����
			if (i >= ob.size()) break;
			// �񱳴���� ���ٸ� ��� ����
			if (objnum == i)
			{
				i++;
				continue;
			}

			//���� y�� x �˻� ���� ���� ���� ���� ���
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y - range)
			{
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� you�� ���
				else if (ob[i]->getAtype() == YOU)
				{
					ob[objnum]->setMtype(UP);
					ob[objnum]->setActive(true);
					break;
				}
			}

			//�������� ������ ���� ���
			i++;
		}
	}
	else if (key == DOWN)
	{
		while (true)
		{
			//������ �񱳴����� ����� �ƴ϶�� ����
			if (i >= ob.size()) break;
			// �񱳴���� ���ٸ� ��� ����
			if (objnum == i)
			{
				i++;
				continue;
			}

			//���� y�� x �˻� ���� ���� ���� ���� ���
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y + range)
			{
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� you�� ���
				else if (ob[i]->getAtype() == YOU)
				{
					ob[objnum]->setMtype(DOWN);
					ob[objnum]->setActive(true);
					break;
				}
			}

			//�������� ������ ���� ���
			i++;
		}
	}
	//====================================================================
	//							PUSH��	STOPó��
	//====================================================================
	
	//STOP Ȯ��

	i = 0; // �񱳴�� ������Ʈ �ѹ�
	range = 1;// �񱳹���

	while (true)
	{
		//������ �񱳴����� ����� �ƴ϶�� ����
		if (i >= ob.size()) break;
		// �񱳴���� ���ٸ� ��� ����
		if (objnum == i)
		{
			i++;
			continue;
		}

		//���� y�� x �˻� ���� ���� ���� ���� ���
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
				//���� �ȿ� ���� �ִ� i�� ��ǥ�� ���ϰ��
				if (ob[i]->getPoint().x == 0)
				{
					ob[objnum]->setMtype(LEFT);
					ob[objnum]->setActive(false);
					break;
				}
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� stop�� ���
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
				//���� �ȿ� ���� �ִ� i�� ��ǥ�� ���ϰ��
				if (ob[i]->getPoint().x == WINSIZEX / PSIZE - 1)
				{
					ob[objnum]->setMtype(RIGHT);
					ob[objnum]->setActive(false);
					break;
				}
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� stop�� ���
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
			//������ ���� ����� ���
			if (ob[objnum]->getPoint().y == 0)
			{
				ob[objnum]->setMtype(UP);
				ob[objnum]->setActive(false);
				break;
			}
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y + range)
			{
				//���� �ȿ� ���� �ִ� i�� ��ǥ�� ���ϰ��
				if (ob[i]->getPoint().y == 0)
				{
					ob[objnum]->setMtype(UP);
					ob[objnum]->setActive(false);
					break;
				}
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� stop�� ���
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
			//������ ���� ����� ���
			if (ob[objnum]->getPoint().y == WINSIZEY / PSIZE - 1)
			{
				ob[objnum]->setMtype(DOWN);
				ob[objnum]->setActive(false);
				break;
			}
			if (ob[objnum]->getPoint().x == ob[i]->getPoint().x &&
				ob[objnum]->getPoint().y == ob[i]->getPoint().y - range)
			{
				//���� �ȿ� ���� �ִ� i�� ��ǥ�� ���ϰ��
				if (ob[objnum]->getPoint().y == WINSIZEY / PSIZE - 1)
				{
					ob[objnum]->setMtype(DOWN);
					ob[objnum]->setActive(false);
					break;
				}
				//���� �ȿ� ���� �ִ� i�� �±װ� push�� ���
				if (ob[i]->getAtype() == PUSH)
				{
					range++;
					i = 0;
					continue;
				}
				//���� �ȿ� �����ִ� i�� �±װ� stop�� ���
				else if (ob[i]->getAtype() == STOP)
				{
					ob[objnum]->setMtype(DOWN);
					ob[objnum]->setActive(false);
					break;
				}
			}
		}
		//�������� ������ ���� ���
		i++;
	}
}

void stop::setAction(moveType key, int objnum, vector<object*>& ob)
{
	//stop�� ���ߴ°� �ƴϴ�.
	//stop�� �� �ٸ� ����� ���ߴ°���
}
