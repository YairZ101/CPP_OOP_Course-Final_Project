#include "pch.h"
#include "MyShape.h"

IMPLEMENT_SERIAL(MyShape, CObject, 1)

int MyShape::globalID = 1;

MyShape::MyShape()
{
}

MyShape::MyShape(CPoint begin, CPoint end) : begin(begin), end(end), width(end.x - begin.x), height(end.y - begin.y)
{
}

CPoint MyShape::GetBegin() const
{
	return this->begin;
}

CPoint MyShape::GetEnd() const
{
	return this->end;
}

int  MyShape::GetWidth() const
{
	return this->width;
}

int MyShape::GetHeight() const
{
	return this->height;
}

int MyShape::GetID() const
{
	return this->id;
}

void MyShape::SetBegin(const CPoint begin)
{
	this->begin = begin;
	this->width = this->end.x - this->begin.x;
	this->height = this->end.y - this->begin.y;
}

void MyShape::SetEnd(const CPoint end)
{
	this->end = end;
	this->width = this->end.x - this->begin.x;
	this->height = this->end.y - this->begin.y;
}

void MyShape::SetID(int id)
{
	this->id = id;
}

void MyShape::Draw(CPaintDC &dc) const
{
}

void MyShape::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << begin << end << height << width << id << globalID;
	}
	else // Loading, not storing
	{
		ar >> begin >> end >> height >> width >> id >> globalID;
	}
}

void MyShape::Shift(int x, int y)
{
	this->SetBegin(this->GetBegin() + CPoint(x, y));
	this->SetEnd(this->GetEnd() + CPoint(x, y));
}

bool MyShape::IsInShape(CPoint& point) const
{
	return false;
}

int MyShape::GetUpperY() const
{
	return 0;
}

int MyShape::GetLeftX() const
{
	return 0;
}