#include "pch.h"
#include "MyRightTrian.h"

IMPLEMENT_SERIAL(MyRightTrian, My3Edges, 1)

MyRightTrian::MyRightTrian()
{
}

MyRightTrian::MyRightTrian(CPoint begin, CPoint end) : My3Edges(begin, end)
{
	this->UpdatePoints();
}

void MyRightTrian::SetEnd(const CPoint end)
{
	MyShape::SetEnd(end);
	this->UpdatePoints();
}

void MyRightTrian::UpdatePoints()
{
	int p3x = this->GetEnd().x;
	int p3y = this->GetEnd().y;
	CPoint points[3] = { this->GetBegin(), CPoint(this->GetEnd().x, this->GetBegin().y), CPoint(p3x, p3y) };
	this->SetPoints(points);
}