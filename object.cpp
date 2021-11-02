#include "pch.h"
#include "object.h"

HRESULT object::init()
{
	_img = IMAGEMANAGER->findImage("baba_lr0");

	_pt = {12,12};
	_rc = RectMake(_pt.x * PSIZE, _pt.y * PSIZE, PSIZE, PSIZE);
	_imgPt = { _rc.left, _rc.top };

	_frame.x = _frame.y = 0;
	_speed = 15;
	_sleep = 0;

	_iType = BABA;
	_aType = ASTOP;
	_mType = RIGHT;
	_count = _iNum = 0;
	_active = false;
	_interaction = false;

	return S_OK;
}

HRESULT object::init(POINT xy)
{
	_img = IMAGEMANAGER->findImage("baba_lr0");
	
	_pt = xy;
	_rc = RectMake(_pt.x * PSIZE,_pt.y * PSIZE,PSIZE,PSIZE);
	_imgPt = { _rc.left, _rc.top };

	_frame.x = _frame.y = 0;
	_speed = 15;
	_sleep = 0;

	_iType = BABA;
	_aType = ASTOP;
	_mType = RIGHT;
	_count = 0;
	_active = false;

	return S_OK;
}

void object::release()
{
}

void object::update()
{
	_rc = RectMake(_pt.x * PSIZE, _pt.y * PSIZE, PSIZE, PSIZE);
	
	//이미지 이동
	if (_imgPt.x != _rc.left)
	{
		if (_imgPt.x < _rc.left) _imgPt.x += 5;
		else if (_imgPt.x > _rc.left) _imgPt.x -= 5;
	}
	else if (_imgPt.y != _rc.top)
	{
		if (_imgPt.y < _rc.top) _imgPt.y += 5;
		else if (_imgPt.y > _rc.top) _imgPt.y -= 5;
	}

}

void object::render()
{
	draw();
}

void object::draw()
{
	_count++;
	
	if (_count%10 == 0)
	{
		if (_frame.y == 0)
		{
			_frame.x++;
			if (_frame.x > _img->getMaxFrameX()) _frame.x = 0;
		}
		else if (_frame.y == 1)
		{
			_frame.x--;
			if (_frame.x < 0) _frame.x = _img->getMaxFrameX();
		}
		_count = 0;
	}

	_img->frameRender(getMemDC(), _imgPt.x, _imgPt.y, _frame.x, _frame.y);
}

//오브젝트 이동
void object::move()
{
	if (_aType == YOU && _active ||
		_aType == PUSH&& _active)
	{
		if (_mType == LEFT)
		{
			_pt.x -= 1;
		}
		else if (_mType == RIGHT)
		{
			_pt.x += 1;
		}
		else if (_mType == UP)
		{
			_pt.y -= 1;
		}
		else if (_mType == DOWN)
		{
			_pt.y += 1;
		}
		_active = false;
	}

}

void object::setVariable(POINT pt, ImageType itype, actType atype, moveType mtype)
{
	_pt = pt;
	_iType= itype;
	_aType= atype;
	_mType= mtype;
}

void object::setVariable(int x, int y)
{
	_frame.x = x;
	_frame.y = y;
}

void object::dSave()
{
	// 데이터 저장
	sD.img = _img;
	sD.rc = _rc;
	sD.pt = _pt;
	sD.speed = _speed;
	sD.frame = _frame;
	sD.iNum = _iNum;
	sD.iType = _iType;
	sD.aType = _aType;
	sD.mType = _mType;
	sD.count =_count;
	sD.sleep = _sleep;
	sD.active = _active;			
	sD.interaction = _interaction;

	//리스트 삽입
	dataList.push_back(sD);
}

void object::dLoad()
{
	if (dataList.size() != 0)
	{
		// 데이터 불러오기
		_img = dataList.back().img;
		_rc = dataList.back().rc;
		_pt = dataList.back().pt;
		_speed = dataList.back().speed;
		_frame = dataList.back().frame;
		_iNum = dataList.back().iNum;
		_iType = dataList.back().iType;
		_aType = dataList.back().aType;
		_mType = dataList.back().mType;
		_count = dataList.back().count;
		_sleep = dataList.back().sleep;
		_active = dataList.back().active;
		_interaction = dataList.back().interaction;

		dataList.pop_back();
	}
}
