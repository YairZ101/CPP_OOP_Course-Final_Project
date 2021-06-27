#include "pch.h"
#include "MyCircle.h"

IMPLEMENT_SERIAL(MyCircle, MyEllipse, 1)

MyCircle::MyCircle()
{
}

MyCircle::MyCircle(CPoint begin, CPoint end) : MyEllipse(begin, end)
{
	this->diameter = min(abs(this->GetWidth()), abs(this->GetHeight()));
	this->radius = this->diameter / 2;
	this->UpdateCenter();
}

CPoint MyCircle::GetCenter() const
{
	return this->center;
}

int MyCircle::GetRadius() const
{
	return this->radius;
}

void MyCircle::SetEnd(const CPoint end)
{
	MyShape::SetEnd(end);
	this->diameter = min(abs(this->GetWidth()), abs(this->GetHeight()));
	this->radius = this->diameter / 2;
	this->UpdateCenter();
	
}

void MyCircle::UpdateCenter()
{
	if (this->GetWidth() > 0 && this->GetHeight() < 0) // 1st Quarter
		this->center = CPoint(this->GetBegin().x + this->radius, this->GetBegin().y - this->radius);
	if (this->GetWidth() < 0 && this->GetHeight() < 0) // 2nd Quarter
		this->center = CPoint(this->GetBegin().x - this->radius, this->GetBegin().y - this->radius);
	if (this->GetWidth() < 0 && this->GetHeight() > 0) // 3rd Quarter
		this->center = CPoint(this->GetBegin().x - this->radius, this->GetBegin().y + this->radius);
	if (this->GetWidth() > 0 && this->GetHeight() > 0) // 4th Quarter
		this->center = CPoint(this->GetBegin().x + this->radius, this->GetBegin().y + this->radius);
}

void MyCircle::Draw(CPaintDC &dc) const
{
	CPoint new_end = CPoint(this->GetBegin().x, this->GetBegin().y);
	if (this->GetWidth() > 0 && this->GetHeight() < 0) // 1st Quarter
		new_end = CPoint(this->GetBegin().x + this->diameter, this->GetBegin().y - this->diameter);
	if (this->GetWidth() < 0 && this->GetHeight() < 0) // 2nd Quarter
		new_end = CPoint(this->GetBegin().x - this->diameter, this->GetBegin().y - this->diameter);
	if (this->GetWidth() < 0 && this->GetHeight() > 0) // 3rd Quarter
		new_end = CPoint(this->GetBegin().x - this->diameter, this->GetBegin().y + this->diameter);
	if (this->GetWidth() > 0 && this->GetHeight() > 0) // 4th Quarter
		new_end = CPoint(this->GetBegin().x + this->diameter, this->GetBegin().y + this->diameter);
	dc.Ellipse(this->GetBegin().x, this->GetBegin().y, new_end.x, new_end.y);
}

bool MyCircle::IsInShape(CPoint &point) const
{
	return (pow(point.x - this->GetCenter().x, 2) + pow(point.y - this->GetCenter().y, 2) < pow(this->radius, 2));
}

int MyCircle::GetUpperY() const
{
	return this->GetCenter().y - this->GetRadius();
}

int MyCircle::GetLeftX() const
{
	return this->GetCenter().x - this->GetRadius();
}

void MyCircle::Serialize(CArchive &ar)
{
	MyShape::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << diameter << radius << center;
	}
	else // Loading, not storing
	{
		ar >> diameter >> radius >> center;
	}
}