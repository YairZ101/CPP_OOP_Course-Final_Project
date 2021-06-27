#include "pch.h"
#include "My4Edges.h"

IMPLEMENT_SERIAL(My4Edges, MyPolygon, 1)

My4Edges::My4Edges()
{
}

My4Edges::My4Edges(CPoint begin, CPoint end) : MyPolygon(begin, end, 4)
{
}