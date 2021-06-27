#pragma once
#include "MyShape.h"

class MyEllipse : public MyShape
{
	DECLARE_SERIAL(MyEllipse)
public:
	MyEllipse();
	MyEllipse(CPoint begin, CPoint end);
	CPoint GetCenter() const;
	virtual void SetEnd(const CPoint end);
	virtual void UpdateCenter();
	virtual void Draw(CPaintDC& dc) const;
	virtual bool IsInShape(CPoint& point) const;
	virtual int GetUpperY() const;
	virtual int GetLeftX() const;
	virtual void Serialize(CArchive& ar);
private:
	CPoint center;
};