#pragma once
#include "MyRectangle.h"

class MySquare : public MyRectangle
{
	DECLARE_SERIAL(MySquare)
public:
	MySquare();
	MySquare(CPoint begin, CPoint end);
	virtual void SetEnd(const CPoint end);
	virtual void UpdatePoints();
};