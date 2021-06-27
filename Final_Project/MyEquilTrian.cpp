#include "pch.h"
#include "MyEquilTrian.h"

IMPLEMENT_SERIAL(MyEquilTrian, My3Edges, 1)

MyEquilTrian::MyEquilTrian()
{
}

MyEquilTrian::MyEquilTrian(CPoint begin, CPoint end) : My3Edges(begin, end)
{
	this->UpdatePoints();
}

void MyEquilTrian::SetEnd(const CPoint end)
{
	MyShape::SetEnd(end);
	this->UpdatePoints();
}

void MyEquilTrian::UpdatePoints()
{
	if (abs(this->GetWidth()) > abs(this->GetHeight())) {
		int p2x = (2 * (this->GetBegin().y - this->GetEnd().y)) / sqrt(3) + this->GetBegin().x;
		int p3x = this->GetBegin().x + (p2x - this->GetBegin().x) / 2;
		if (this->GetWidth() > 0 && this->GetHeight() < 0 || this->GetWidth() < 0 && this->GetHeight() > 0) { // 1st Quarter && 3rd Quarter
			CPoint points[3] = { this->GetBegin(), CPoint(p2x, this->GetBegin().y), CPoint(p3x, this->GetEnd().y) };
			this->SetPoints(points);
		}
		if (this->GetWidth() < 0 && this->GetHeight() < 0 || this->GetWidth() > 0 && this->GetHeight() > 0) { // 2nd Quarter && 4th Quarter
			CPoint points[3] = { this->GetBegin(), CPoint(this->GetBegin().x - (p2x - this->GetBegin().x), this->GetBegin().y), CPoint(this->GetBegin().x - (p3x - this->GetBegin().x), this->GetEnd().y) };
			this->SetPoints(points);
		}
	}
	else {
		int p3x = this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) / 2;
		int p3y = sqrt(3) / 2 * (this->GetEnd().x - this->GetBegin().x);
		if (this->GetWidth() > 0 && this->GetHeight() < 0 || this->GetWidth() < 0 && this->GetHeight() > 0) { // 1st Quarter && 3rd Quarter
			CPoint points[3] = { this->GetBegin(), CPoint(this->GetEnd().x, this->GetBegin().y), CPoint(p3x, this->GetBegin().y - p3y) };
			this->SetPoints(points);
		}
		if (this->GetWidth() < 0 && this->GetHeight() < 0 || this->GetWidth() > 0 && this->GetHeight() > 0) { // 2nd Quarter && 4th Quarter
			CPoint points[3] = { this->GetBegin(), CPoint(this->GetEnd().x, this->GetBegin().y), CPoint(p3x, this->GetBegin().y + p3y) };
			this->SetPoints(points);
		}
	}
}