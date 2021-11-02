#pragma once
#include "object.h"

#include <vector>
//#include "singletonBase.h"

//±âº»
class aType
{
private:
	
public:
	virtual void setAction(moveType key, int objnum, vector<object*>& ob);
};

//you
class you : public aType
{
private:
	int i;
	int range;
public:

	virtual void setAction(moveType key, int objnum, vector<object*>& ob);
};

//win
class win : public aType
{
private:
	int i;
	int range;
public:

	virtual void setAction(moveType key, int objnum, vector<object*>& ob);
};

//push
class push : public aType
{
private:
	int i;
	int range;
public:
	virtual void setAction(moveType key, int objnum, vector<object*>& ob);
};

//stop
class stop : public aType
{
private:

public:

	virtual void setAction(moveType key, int objnum, vector<object*>& ob);
};