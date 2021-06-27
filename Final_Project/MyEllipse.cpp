#include "pch.h"
#include "MyEllipse.h"

IMPLEMENT_SERIAL(MyEllipse, MyShape, 1)

MyEllipse::MyEllipse()
{
}

MyEllipse::MyEllipse(CPoint begin, CPoint end) : MyShape(begin, end)
{
	this->UpdateCenter();
}

CPoint MyEllipse::GetCenter() const
{
	return this->center;
}

void MyEllipse::SetEnd(const CPoint end)
{
	MyShape::SetEnd(end);
	this->UpdateCenter();
}

void MyEllipse::UpdateCenter()
{
	this->center = CPoint(this->GetBegin().x + this->GetWidth() / 2, this->GetBegin().y + this->GetHeight() / 2);
}

void MyEllipse::Draw(CPaintDC& dc) const
{
	dc.Ellipse(this->GetBegin().x, this->GetBegin().y, this->GetEnd().x, this->GetEnd().y);
}

bool MyEllipse::IsInShape(CPoint& point) const
{
	return ((pow((point.x - this->GetCenter().x), 2) / pow(abs(this->GetWidth() / 2), 2)) + (pow((point.y - this->GetCenter().y), 2) / pow(abs(this->GetHeight() / 2), 2)) < 1);
}

int MyEllipse::GetUpperY() const
{
	return this->GetCenter().y - abs(this->GetHeight()) / 2;
}

int MyEllipse::GetLeftX() const
{
	return this->GetCenter().x - abs(this->GetWidth()) / 2;
}

void MyEllipse::Serialize(CArchive& ar)
{
	MyShape::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << center;
	}
	else // Loading, not storing
	{
		ar >> center;
	}
}