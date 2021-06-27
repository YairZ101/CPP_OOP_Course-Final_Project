#pragma once
#include "My4Edges.h"

class MyRectangle : public My4Edges
{
	DECLARE_SERIAL(MyRectangle)
public:
	MyRectangle();
	MyRectangle(CPoint begin, CPoint end);
	virtual void SetEnd(const CPoint end);
	virtual void UpdatePoints();
};