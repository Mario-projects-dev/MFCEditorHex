
// MFCEditorHexView.cpp : implementation of the CMFCEditorHexView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCEditorHex.h"
#endif

#include "MFCEditorHexDoc.h"
#include "MFCEditorHexView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCEditorHexView

IMPLEMENT_DYNCREATE(CMFCEditorHexView, CView)

BEGIN_MESSAGE_MAP(CMFCEditorHexView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCEditorHexView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCEditorHexView construction/destruction

CMFCEditorHexView::CMFCEditorHexView() noexcept
{
	// TODO: add construction code here

}

CMFCEditorHexView::~CMFCEditorHexView()
{
}

BOOL CMFCEditorHexView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCEditorHexView drawing

void CMFCEditorHexView::OnDraw(CDC* /*pDC*/)
{
	CMFCEditorHexDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCEditorHexView printing


void CMFCEditorHexView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCEditorHexView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCEditorHexView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCEditorHexView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCEditorHexView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCEditorHexView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCEditorHexView diagnostics

#ifdef _DEBUG
void CMFCEditorHexView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCEditorHexView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCEditorHexDoc* CMFCEditorHexView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCEditorHexDoc)));
	return (CMFCEditorHexDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCEditorHexView message handlers
