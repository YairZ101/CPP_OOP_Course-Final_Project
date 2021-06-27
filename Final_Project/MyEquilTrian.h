#pragma once
#include "My3Edges.h"

class MyEquilTrian : public My3Edges
{
	DECLARE_SERIAL(MyEquilTrian)
public:
	MyEquilTrian();
	MyEquilTrian(CPoint begin, CPoint end);
	virtual void SetEnd(const CPoint end);
	void UpdatePoints();
};