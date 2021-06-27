#pragma once
#include "My3Edges.h"

class MyIsosTrian : public My3Edges
{
	DECLARE_SERIAL(MyIsosTrian)
public:
	MyIsosTrian();
	MyIsosTrian(CPoint begin, CPoint end);
	virtual void SetEnd(const CPoint end);
	void UpdatePoints();
};