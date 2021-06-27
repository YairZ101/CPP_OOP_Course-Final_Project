#include "pch.h"
#include "My3Edges.h"

IMPLEMENT_SERIAL(My3Edges, MyPolygon, 1)

My3Edges::My3Edges()
{
}

My3Edges::My3Edges(CPoint begin, CPoint end) : MyPolygon(begin, end, 3)
{
}

//LONG sign(CPoint &p1, CPoint &p2, CPoint &p3) {
//    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
//}
//
//bool My3Edges::IsInShape(CPoint &point) const
//{
//    bool has_neg, has_pos;
//    LONG d1 = sign(point, this->GetPoints()[0], this->GetPoints()[1]);
//    LONG d2 = sign(point, this->GetPoints()[1], this->GetPoints()[2]);
//    LONG d3 = sign(point, this->GetPoints()[2], this->GetPoints()[0]);
//    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
//    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
//    return !(has_neg && has_pos);
//}