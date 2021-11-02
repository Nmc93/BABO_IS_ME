#include "pch.h"
#include "effect.h"

HRESULT effect::init()
{

	_cNum = RND->getInt(3);

	clearB = false;

	_iCount = 0;

	//랜덤 생성
	switch (_cNum)
	{
	case 0:
		for (int i = 0; i < 9; i++)
		{
			_wE[i].rcP = { i * 2 , -3 };
			_wE[i].eRc = RectMake( _wE[i].rcP.x * PSIZE, _wE[i].rcP.y * PSIZE, PSIZE, PSIZE);
			_wE[i].imgP = { _wE[i].rcP.x * PSIZE, _wE[i].rcP.y * PSIZE };
			_wE[i].img = new image;
			_wE[i].imgNum = 0;
		}
		break;
	case 1:
		for (int i = 0; i < 9; i++)
		{
			_wE[i].rcP = { 27 , i * 2 };
			_wE[i].eRc = RectMake(_wE[i].rcP.x * PSIZE, _wE[i].rcP.y * PSIZE, PSIZE, PSIZE);
			_wE[i].imgP = { _wE[i].rcP.x * PSIZE, _wE[i].rcP.y * PSIZE };
			_wE[i].img = new image;
			_wE[i].imgNum = 0;
		}
		break;
	case 2:
		for (int i = 0; i < 9; i++)
		{
			_wE[i].rcP = { 12 , 27 };
			_wE[i].eRc = RectMake(_wE[i].rcP.x * PSIZE, _wE[i].rcP.y * PSIZE, PSIZE, PSIZE);
			_wE[i].imgP = { _wE[i].rcP.x * PSIZE, _wE[i].rcP.y * PSIZE };
			_wE[i].img = new image;
			_wE[i].imgNum = 0;
		}
		break;
	}

	_wE[0].img = IMAGEMANAGER->findImage("word_g");
	_wE[1].img = IMAGEMANAGER->findImage("word_a");
	_wE[2].img = IMAGEMANAGER->findImage("word_m");
	_wE[3].img = IMAGEMANAGER->findImage("word_e");
	_wE[4].img = IMAGEMANAGER->findImage("word_c");
	_wE[5].img = IMAGEMANAGER->findImage("word_l");
	_wE[6].img = IMAGEMANAGER->findImage("word_e");
	_wE[7].img = IMAGEMANAGER->findImage("word_a");
	_wE[8].img = IMAGEMANAGER->findImage("word_r");

	return S_OK;
}

void effect::release()
{
}

void effect::update()
{
	_iCount++;

	for (int i = 0; i < 9; i++)
	{
		//이미지 이동
		if (_wE[i].imgP.x != _wE[i].eRc.left )
		{
			if (_wE[i].imgP.x < _wE[i].eRc.left) _wE[i].imgP.x += 5;
			else if (_wE[i].imgP.x > _wE[i].eRc.left) _wE[i].imgP.x -= 5;
		}
		else if (_wE[i].imgP.y != _wE[i].eRc.top)
		{
			if (_wE[i].imgP.y < _wE[i].eRc.top) _wE[i].imgP.y += 5;
			else if (_wE[i].imgP.y > _wE[i].eRc.top) _wE[i].imgP.y -= 5;
		}

		//이미지 
		if (_iCount % 10 == 0)
		{
			//이미지 번호
			if (_wE[i].imgNum < 2) _wE[i].imgNum++;
			else _wE[i].imgNum = 0;
		}

		//렉트 이동
		_wE[i].eRc = RectMake(_wE[i].rcP.x * PSIZE, _wE[i].rcP.y * PSIZE, PSIZE, PSIZE);
	}

}

void effect::render()
{
	for (int i = 0; i < 9; i++)
	{
		_wE[i].img->frameRender(getMemDC(), _wE[i].imgP.x, _wE[i].imgP.y, _wE[i].imgNum, 0);
	}
}

void effect::clear(bool tr)
{
	clearB = tr;

	if (clearB)
	{
		_wE[0].rcP = {7,2};
		_wE[1].rcP = {8,2};
		_wE[2].rcP = {9,2};
		_wE[3].rcP = {10,2};
		_wE[4].rcP = {12,2};
		_wE[5].rcP = {13,2};
		_wE[6].rcP = {14,2};
		_wE[7].rcP = {15,2};
		_wE[8].rcP = {16,2};
	}
}
