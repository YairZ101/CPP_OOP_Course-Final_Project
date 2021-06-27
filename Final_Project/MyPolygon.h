#pragma once
#include "MyShape.h"

class MyPolygon : public MyShape
{
	DECLARE_SERIAL(MyPolygon)
public:
	MyPolygon();
	~MyPolygon();
	MyPolygon(CPoint begin, CPoint end, int numEdges);
	int GetNumEdges() const;
	void SetNumEdge(const int numEdges);
	CPoint* GetPoints() const;
	void SetPoints(const CPoint *points);
	virtual void Draw(CPaintDC &dc) const;
	bool IsInShape(CPoint &point) const;
	virtual int GetUpperY() const;
	virtual int GetLeftX() const;
	virtual void Serialize(CArchive& ar);
private:
	int numEdges;
	CPoint *points;
};