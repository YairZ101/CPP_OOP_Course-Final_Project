#include "pch.h"
#include "MySquare.h"

IMPLEMENT_SERIAL(MySquare, MyRectangle, 1)

MySquare::MySquare()
{
}

MySquare::MySquare(CPoint begin, CPoint end) : MyRectangle(begin, end)
{
	this->UpdatePoints();
}

void MySquare::SetEnd(const CPoint end)
{
	MyShape::SetEnd(end);
	this->UpdatePoints();
}

void MySquare::UpdatePoints()
{
	if (abs(this->GetHeight()) > abs(this->GetWidth())) {
		if (this->GetWidth() > 0 && this->GetHeight() < 0 || this->GetWidth() < 0 && this->GetHeight() > 0) { // 1st Quarter && 3rd Quarter
			CPoint points[4] = {
							this->GetBegin(),
							CPoint(this->GetEnd().x, this->GetBegin().y),
							CPoint(this->GetEnd().x, this->GetBegin().y - this->GetWidth()),
							CPoint(this->GetBegin().x, this->GetBegin().y - this->GetWidth())
			};
			this->SetPoints(points);
		}
		if (this->GetWidth() < 0 && this->GetHeight() < 0 || this->GetWidth() > 0 && this->GetHeight() > 0) { // 2nd Quarter && 4th Quarter
			CPoint points[4] = {
							this->GetBegin(),
							CPoint(this->GetEnd().x, this->GetBegin().y),
							CPoint(this->GetEnd().x, this->GetBegin().y + this->GetWidth()),
							CPoint(this->GetBegin().x, this->GetBegin().y + this->GetWidth())
			};
			this->SetPoints(points);
		}
	}
	else {
		if (this->GetWidth() > 0 && this->GetHeight() < 0 || this->GetWidth() < 0 && this->GetHeight() > 0) { // 1st Quarter && 3rd Quarter
			CPoint points[4] = {
							this->GetBegin(),
							CPoint(this->GetBegin().x - this->GetHeight(), this->GetBegin().y),
							CPoint(this->GetBegin().x - this->GetHeight(), this->GetEnd().y),
							CPoint(this->GetBegin().x, this->GetEnd().y)
			};
			this->SetPoints(points);
		}
		if (this->GetWidth() < 0 && this->GetHeight() < 0 || this->GetWidth() > 0 && this->GetHeight() > 0) { // 2nd Quarter && 4th Quarter
			CPoint points[4] = {
							this->GetBegin(),
							CPoint(this->GetBegin().x + this->GetHeight(), this->GetBegin().y),
							CPoint(this->GetBegin().x + this->GetHeight(), this->GetEnd().y),
							CPoint(this->GetBegin().x, this->GetEnd().y)
			};
			this->SetPoints(points);
		}
	}
}