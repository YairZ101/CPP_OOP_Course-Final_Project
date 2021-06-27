#pragma once
#include "MyPolygon.h"

class My3Edges : public MyPolygon
{
	DECLARE_SERIAL(My3Edges)
public:
	My3Edges();
	My3Edges(CPoint begin, CPoint end);
	//bool IsInShape(CPoint &point) const;
};