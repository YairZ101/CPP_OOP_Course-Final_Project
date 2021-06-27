#pragma once
#include "MyPolygon.h"

class My4Edges : public MyPolygon
{
	DECLARE_SERIAL(My4Edges)
public:
	My4Edges();
	My4Edges(CPoint begin, CPoint end);
};