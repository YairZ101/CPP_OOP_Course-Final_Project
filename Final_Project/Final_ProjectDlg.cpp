
// Final_ProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Final_Project.h"
#include "Final_ProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFinalProjectDlg dialog



CFinalProjectDlg::CFinalProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINAL_PROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFinalProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFinalProjectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_Ellipse, &CFinalProjectDlg::OnBnClickedEllipse)
	ON_BN_CLICKED(IDC_Circle, &CFinalProjectDlg::OnBnClickedCircle)
	ON_BN_CLICKED(IDC_HIT, &CFinalProjectDlg::OnBnClickedHit)
	ON_BN_CLICKED(IDC_Clear, &CFinalProjectDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_Undo, &CFinalProjectDlg::OnBnClickedUndo)
	ON_BN_CLICKED(IDC_Redo, &CFinalProjectDlg::OnBnClickedRedo)
	ON_BN_CLICKED(IDC_Move, &CFinalProjectDlg::OnBnClickedMove)
	ON_BN_CLICKED(IDC_EquilTrian, &CFinalProjectDlg::OnBnClickedEquiltrian)
	ON_BN_CLICKED(IDC_IsosTrian, &CFinalProjectDlg::OnBnClickedIsostrian)
	ON_BN_CLICKED(IDC_RightTrian, &CFinalProjectDlg::OnBnClickedRighttrian)
	ON_BN_CLICKED(IDC_Delete, &CFinalProjectDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_Rectangle, &CFinalProjectDlg::OnBnClickedRectangle)
	ON_BN_CLICKED(IDC_Square, &CFinalProjectDlg::OnBnClickedSquare)
	ON_BN_CLICKED(IDC_Save, &CFinalProjectDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_Load, &CFinalProjectDlg::OnBnClickedLoad)
END_MESSAGE_MAP()


// CFinalProjectDlg message handlers

BOOL CFinalProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFinalProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		dc.Rectangle(100, 50, 5000, 2500);
		for (int i = 0; i < shapes.GetSize(); i++)
			shapes[i]->Draw(dc);
		CDialogEx::OnPaint();
	}
}


// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFinalProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool CFinalProjectDlg::IsInBox(CPoint &point)
{
	if (point.x >= 100 && point.x <= 5000 && point.y >= 50 && point.y <= 2500)
		return true;
	return false;
}


void CFinalProjectDlg::AddShape(CPoint &point)
{
	switch (shape) {
	case 1:
		shapes.Add(new MyEllipse(point, point));
		break;
	case 2:
		shapes.Add(new MyCircle(point, point));
		break;
	case 3:
		shapes.Add(new MyEquilTrian(point, point));
		break;
	case 4:
		shapes.Add(new MyIsosTrian(point, point));
		break;
	case 5:
		shapes.Add(new MyRightTrian(point, point));
		break;
	case 6:
		shapes.Add(new MyRectangle(point, point));
		break;
	case 7:
		shapes.Add(new MySquare(point, point));
		break;
	case 9:
		shapes.Add(new MyHIT(point, point));
		break;
	}
}


void CFinalProjectDlg::UpdateStack()
{
	MyShape* copyShape = NULL;
	if (dynamic_cast<MyCircle*>(selectedShape))
		copyShape = new MyCircle(selectedShape->GetBegin(), selectedShape->GetEnd());
	else if (dynamic_cast<MyEllipse*>(selectedShape))
		copyShape = new MyEllipse(selectedShape->GetBegin(), selectedShape->GetEnd());
	if (dynamic_cast<MyEquilTrian*>(selectedShape))
		copyShape = new MyEquilTrian(selectedShape->GetBegin(), selectedShape->GetEnd());
	if (dynamic_cast<MyIsosTrian*>(selectedShape))
		copyShape = new MyIsosTrian(selectedShape->GetBegin(), selectedShape->GetEnd());
	if (dynamic_cast<MyRightTrian*>(selectedShape))
		copyShape = new MyRightTrian(selectedShape->GetBegin(), selectedShape->GetEnd());
	if (dynamic_cast<MySquare*>(selectedShape))
		copyShape = new MySquare(selectedShape->GetBegin(), selectedShape->GetEnd());
	else if (dynamic_cast<MyRectangle*>(selectedShape))
		copyShape = new MyRectangle(selectedShape->GetBegin(), selectedShape->GetEnd());
	if (dynamic_cast<MyHIT*>(selectedShape))
		copyShape = new MyHIT(selectedShape->GetBegin(), selectedShape->GetEnd());
	copyShape->SetID(selectedShape->GetID());
	shapesUndo.push(copyShape);
}


void CFinalProjectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (moveButton || delButton) {
		for (int i = shapes.GetSize() - 1; i >= 0; i--) {
			if (shapes[i]->IsInShape(point)) {
				selectedShape = shapes[i];
				while (!shapesRedo.empty())
					shapesRedo.pop();
				pointPressed = point;
				if (moveButton) {
					moveAction = true;
					UpdateStack();
				}
				if (delButton)
					shapeIndex = i;
				break;
			}
		}
	}
	else if (IsInBox(point) && shape != 0) {
		AddShape(point);
		while (!shapesRedo.empty())
			shapesRedo.pop();
		isPressed = true;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CFinalProjectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (moveAction && IsInBox(point) && selectedShape->GetUpperY() > 50 && selectedShape->GetLeftX() > 100) {
		moveAction = false;
		selectedShape->Shift(point.x - this->pointPressed.x, point.y - this->pointPressed.y);
		Invalidate(FALSE);
		selectedShape = NULL;
		pointPressed = NULL;
	}
	else if (delButton && selectedShape != NULL && selectedShape->IsInShape(point) ) {
		UpdateStack();
		for (int i = shapeIndex; i < shapes.GetSize(); i++) {
			if (i + 1 == shapes.GetSize())
				shapes.SetAt(i, NULL);
			else
				shapes.SetAt(i, shapes[i + 1]);
		}
		delete shapes[shapes.GetSize() - 1];
		shapes.SetSize(shapes.GetSize() - 1);
		Invalidate(FALSE);
		selectedShape = NULL;
		pointPressed = NULL;
	}
	else if (isPressed && IsInBox(point)) {
		isPressed = false;
		shapes[shapes.GetSize() - 1]->SetEnd(point);
		selectedShape = shapes[shapes.GetSize() - 1];
		UpdateStack();
		selectedShape = NULL;
		Invalidate(FALSE);
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CFinalProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (moveAction && selectedShape->GetUpperY() > 50 && selectedShape->GetLeftX() > 100) {
		selectedShape->Shift(point.x - this->pointPressed.x, point.y - this->pointPressed.y);
		pointPressed = point;
		Invalidate(FALSE);
	}
	else if (moveAction && selectedShape->GetUpperY() <= 50) {
		selectedShape->Shift(0, 51 - selectedShape->GetUpperY());
		pointPressed = point;
		Invalidate();
	}
	else if (moveAction && selectedShape->GetLeftX() <= 100) {
		selectedShape->Shift(101 - selectedShape->GetLeftX(), 0);
		pointPressed = point;
		Invalidate();
	}
	else if (isPressed && IsInBox(point)) {
		shapes[shapes.GetSize() - 1]->SetEnd(point);
		Invalidate(FALSE);
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CFinalProjectDlg::OnBnClickedDelete()
{
	shape = 0;
	moveButton = false;
	delButton = true;
}

void CFinalProjectDlg::OnBnClickedMove()
{
	shape = 0;
	moveButton = true;
	delButton = false;
}

void CFinalProjectDlg::OnBnClickedEllipse()
{
	shape = 1;
	moveButton = false;
	delButton = false;
}

void CFinalProjectDlg::OnBnClickedCircle()
{
	shape = 2;
	moveButton = false;
	delButton = false;
}

void CFinalProjectDlg::OnBnClickedEquiltrian()
{
	shape = 3;
	moveButton = false;
	delButton = false;
}

void CFinalProjectDlg::OnBnClickedIsostrian()
{
	shape = 4;
	moveButton = false;
	delButton = false;
}

void CFinalProjectDlg::OnBnClickedRighttrian()
{
	shape = 5;
	moveButton = false;
	delButton = false;
}

void CFinalProjectDlg::OnBnClickedRectangle()
{
	shape = 6;
	moveButton = false;
	delButton = false;
}

void CFinalProjectDlg::OnBnClickedSquare()
{
	shape = 7;
	moveButton = false;
	delButton = false;
}

void CFinalProjectDlg::OnBnClickedHit()
{
	shape = 9;
	moveButton = false;
	delButton = false;
}


void CFinalProjectDlg::OnBnClickedClear()
{
	while (!shapes.IsEmpty()) {
		delete shapes[shapes.GetSize() - 1];
		shapes.RemoveAt(shapes.GetSize() - 1);
	}
	while (!shapesUndo.empty())
		shapesUndo.pop();
	while (!shapesRedo.empty())
		shapesRedo.pop();
	Invalidate(FALSE);
}


void CFinalProjectDlg::OnBnClickedUndo()
{
	if (!shapesUndo.empty()) {
		/*if (shapesUndo.top()->GetID() == shapes[shapes.GetSize() - 1]->GetID() && shapesUndo.top()->GetBegin() == shapes[shapes.GetSize() - 1]->GetBegin()) {
			shapesRedo.push(shapes[shapes.GetSize() - 1]);
			shapes.RemoveAt(shapes.GetSize() - 1);
			shapesUndo.pop();
			Invalidate(FALSE);
			return;
		}*/
		for (int i = 0; i < shapes.GetSize(); i++) {
			if (shapesUndo.top()->GetID() == shapes[i]->GetID()) {
				if (shapesUndo.top()->GetBegin() == shapes[i]->GetBegin()) {
					shapesRedo.push(shapes[shapes.GetSize() - 1]);
					shapes.RemoveAt(shapes.GetSize() - 1);
					shapesUndo.pop();
				}
				else {
					shapesRedo.push(shapes[i]);
					shapes.SetAt(i, shapesUndo.top());
					shapesUndo.pop();
				}
				Invalidate(FALSE);
				return;
			}
		}
		shapesRedo.push(shapesUndo.top());
		shapes.Add(shapesUndo.top());
		shapesUndo.pop();
		Invalidate(FALSE);
	}
}


void CFinalProjectDlg::OnBnClickedRedo()
{
	if (!shapesRedo.empty()) {
		for (int i = 0; i < shapes.GetSize(); i++) {
			if (shapesRedo.top()->GetID() == shapes[i]->GetID()) {
				shapes.SetAt(i, shapesRedo.top());
				shapesRedo.pop();
				Invalidate(FALSE);
				return;
			}
		}
		shapes.Add(shapesRedo.top());
		shapesRedo.pop();
		Invalidate(FALSE);
	}
}


void CFinalProjectDlg::OnBnClickedSave()
{
	CFileDialog dlg(FALSE, _T(".shps"), NULL, 0, _T("Shapes (*.shps)|*.shps|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		shapes.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CFinalProjectDlg::OnBnClickedLoad()
{
	CFileDialog dlg(TRUE, _T(".shps"), NULL, 0, _T("Shapes (*.shps)|*.shps|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		shapes.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}