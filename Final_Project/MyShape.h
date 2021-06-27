#pragma once

class MyShape : public CObject
{
	DECLARE_SERIAL(MyShape)
public:
	MyShape();
	MyShape(CPoint begin, CPoint end);
	CPoint GetBegin() const;
	CPoint GetEnd() const;
	int GetWidth() const;
	int GetHeight() const;
	int GetID() const;
	void SetBegin(const CPoint begin);
	virtual void SetEnd(const CPoint end);
	void SetID(int id);
	virtual void Draw(CPaintDC &dc) const;
	virtual void Serialize(CArchive &ar);
	virtual void Shift(int x, int y);
	virtual bool IsInShape(CPoint &point) const;
	virtual int GetUpperY() const;
	virtual int GetLeftX() const;
private:
	CPoint begin, end;
	int width, height, id = globalID++;
	static int globalID;
};