
// Final_ProjectDlg.h : header file
//

#pragma once
#include <stack>
#include "MyShape.h"
#include "MyEllipse.h"
#include "MyCircle.h"
#include "MyPolygon.h"
#include "My3Edges.h"
#include "MyEquilTrian.h"
#include "MyIsosTrian.h"
#include "MyRightTrian.h"
#include "MyRectangle.h"
#include "MySquare.h"
#include "MyHIT.h"
using namespace std;

// CFinalProjectDlg dialog
class CFinalProjectDlg : public CDialogEx
{
// Construction
public:
	CFinalProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINAL_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
private:
	int shape = 0;
	bool isPressed = false;
	CTypedPtrArray<CObArray, MyShape*> shapes;
	stack<MyShape*> shapesUndo;
	stack<MyShape*> shapesRedo;
	void AddShape(CPoint &point);
	bool IsInBox(CPoint &point);
	bool delButton = false;
	int shapeIndex = 0;
	bool moveButton = false;
	bool moveAction = false;
	MyShape *selectedShape = NULL;
	CPoint pointPressed = NULL;
	void UpdateStack();

protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedEllipse();
	afx_msg void OnBnClickedCircle();
	afx_msg void OnBnClickedHit();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedUndo();
	afx_msg void OnBnClickedRedo();
	afx_msg void OnBnClickedMove();
	afx_msg void OnBnClickedEquiltrian();
	afx_msg void OnBnClickedIsostrian();
	afx_msg void OnBnClickedRighttrian();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedRectangle();
	afx_msg void OnBnClickedSquare();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
};
