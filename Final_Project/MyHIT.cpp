#include "pch.h"
#include "MyHIT.h"

IMPLEMENT_SERIAL(MyHIT, MyShape, 1)

MyHIT::MyHIT()
{
}

MyHIT::MyHIT(CPoint begin, CPoint end) : MyShape(begin, end)
{
}

void MyHIT::Draw(CPaintDC& dc) const
{
	if (this->GetWidth() > 0 && this->GetHeight() > 0) {
		CPoint h[12] = {
				CPoint(this->GetBegin().x, this->GetBegin().y),
				CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.07, this->GetBegin().y),
				CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.07, this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.07),
				CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14, this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.07),
				CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14, this->GetBegin().y - (this->GetEnd().x - this->GetBegin().x) * 0.14),
				CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20, this->GetBegin().y - (this->GetEnd().x - this->GetBegin().x) * 0.14),
				CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20, this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.28),
				CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14, this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.28),
				CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14, this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.14),
				CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.07, this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.14),
				CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.07, this->GetBegin().y + 0.4 * (this->GetEnd().x - this->GetBegin().x)),
				CPoint(this->GetBegin().x, this->GetBegin().y + 0.4 * (this->GetEnd().x - this->GetBegin().x)),
		};
		CPoint h2[4] = {
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14, this->GetBegin().y + 0.35 * (this->GetEnd().x - this->GetBegin().x)),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20, this->GetBegin().y + 0.35 * (this->GetEnd().x - this->GetBegin().x)),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20, this->GetBegin().y + 0.4 * (this->GetEnd().x - this->GetBegin().x)),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14, this->GetBegin().y + 0.4 * (this->GetEnd().x - this->GetBegin().x))
		};

		CPoint i[4] = {
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14 * 2, this->GetBegin().y),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.21 * 1.65, this->GetBegin().y),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.21 * 1.65, this->GetBegin().y + 0.4 * (this->GetEnd().x - this->GetBegin().x)),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14 * 2, this->GetBegin().y + 0.4 * (this->GetEnd().x - this->GetBegin().x)),
		};
		CPoint i2[4] = {
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14 * 2,  this->GetBegin().y - (this->GetEnd().x - this->GetBegin().x) * 0.14),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.21 * 1.65,  this->GetBegin().y - (this->GetEnd().x - this->GetBegin().x) * 0.14),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.21 * 1.65,  this->GetBegin().y - (this->GetEnd().x - this->GetBegin().x) * 0.07),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14 * 2,  this->GetBegin().y - (this->GetEnd().x - this->GetBegin().x) * 0.07)
		};

		CPoint t[8] = {
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14 * 3 * 0.9, this->GetBegin().y),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20 * 3.13 * 0.9, this->GetBegin().y),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20 * 3.13 * 0.9,this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.05),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20 * 2.8 * 0.9,this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.05),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20 * 2.8 * 0.9, this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.28),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14 * 3.5 * 0.9, this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.28),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14 * 3.5 * 0.9,this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.05),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14 * 3 * 0.9,this->GetBegin().y + (this->GetEnd().x - this->GetBegin().x) * 0.05),
		};
		CPoint t2[4] = {
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14 * 3.5 * 0.9, this->GetBegin().y + 0.35 * (this->GetEnd().x - this->GetBegin().x)),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20 * 2.8 * 0.9, this->GetBegin().y + 0.35 * (this->GetEnd().x - this->GetBegin().x)),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20 * 2.8 * 0.9, this->GetBegin().y + 0.4 * (this->GetEnd().x - this->GetBegin().x)),
			CPoint(this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.14 * 3.5 * 0.9, this->GetBegin().y + 0.4 * (this->GetEnd().x - this->GetBegin().x))
		};

		dc.Polygon(h, 12);
		dc.Polygon(h2, 4);
		dc.Polygon(i, 4);
		dc.Polygon(i2, 4);
		dc.Polygon(t, 8);
		dc.Polygon(t2, 4);
	}
}

bool MyHIT::IsInShape(CPoint& point) const
{
	if (point.x >= this->GetBegin().x && point.x <= (this->GetBegin().x + (this->GetEnd().x - this->GetBegin().x) * 0.20 * 3.13 * 0.9) &&
		point.y >= this->GetBegin().y - (this->GetEnd().x - this->GetBegin().x) * 0.14 && point.y <= this->GetBegin().y + 0.4 * (this->GetEnd().x - this->GetBegin().x)) {
		return true;
	}
	return false;
}

int MyHIT::GetUpperY() const
{
	return this->GetBegin().y - (this->GetEnd().x - this->GetBegin().x) * 0.14;
}

int MyHIT::GetLeftX() const
{
	return this->GetBegin().x;
}