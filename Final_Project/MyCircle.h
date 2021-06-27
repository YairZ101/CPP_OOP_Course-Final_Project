#pragma once
#include "MyEllipse.h"

class MyCircle : public MyEllipse
{
	DECLARE_SERIAL(MyCircle)
public:
	MyCircle();
	MyCircle(CPoint begin, CPoint end);
	CPoint GetCenter() const;
	int GetRadius() const;
	virtual void SetEnd(const CPoint end);
	virtual void UpdateCenter();
	virtual void Draw(CPaintDC &dc) const;
	virtual bool IsInShape(CPoint &point) const;
	virtual int GetUpperY() const;
	virtual int GetLeftX() const;
	virtual void Serialize(CArchive &ar);
private:
	int diameter, radius;
	CPoint center;
};