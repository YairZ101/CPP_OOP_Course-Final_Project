#include "pch.h"
#include "MyRectangle.h"

IMPLEMENT_SERIAL(MyRectangle, My4Edges, 1)

MyRectangle::MyRectangle()
{
}

MyRectangle::MyRectangle(CPoint begin, CPoint end) : My4Edges(begin, end)
{
	this->UpdatePoints();
}

void MyRectangle::SetEnd(const CPoint end)
{
	MyShape::SetEnd(end);
	this->UpdatePoints();
}

void MyRectangle::UpdatePoints()
{
	CPoint points[4] = { this->GetBegin(), CPoint(this->GetEnd().x, this->GetBegin().y), this->GetEnd(), CPoint(this->GetBegin().x, this->GetEnd().y) };
	this->SetPoints(points);
}