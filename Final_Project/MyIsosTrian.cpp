#include "pch.h"
#include "MyIsosTrian.h"

IMPLEMENT_SERIAL(MyIsosTrian, My3Edges, 1)

MyIsosTrian::MyIsosTrian()
{
}

MyIsosTrian::MyIsosTrian(CPoint begin, CPoint end) : My3Edges(begin, end)
{
	this->UpdatePoints();
}

void MyIsosTrian::SetEnd(const CPoint end)
{
	MyShape::SetEnd(end);
	this->UpdatePoints();
}

void MyIsosTrian::UpdatePoints()
{
	int p3x = this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) / 2;
	int p3y = this->GetEnd().y;
	CPoint points[3] = { this->GetBegin(), CPoint(this->GetEnd().x, this->GetBegin().y), CPoint(p3x, p3y) };
	this->SetPoints(points);
}