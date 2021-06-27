#pragma once
#include "My3Edges.h"

class MyRightTrian : public My3Edges
{
	DECLARE_SERIAL(MyRightTrian)
public:
	MyRightTrian();
	MyRightTrian(CPoint begin, CPoint end);
	virtual void SetEnd(const CPoint end);
	void UpdatePoints();
};