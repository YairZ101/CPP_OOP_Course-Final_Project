#pragma once
#include "MyShape.h"

class MyHIT : public MyShape
{
	DECLARE_SERIAL(MyHIT)
public:
	MyHIT();
	MyHIT(CPoint begin, CPoint end);
	virtual void Draw(CPaintDC& dc) const;
	virtual bool IsInShape(CPoint& point) const;
	virtual int GetUpperY() const;
	virtual int GetLeftX() const;
};