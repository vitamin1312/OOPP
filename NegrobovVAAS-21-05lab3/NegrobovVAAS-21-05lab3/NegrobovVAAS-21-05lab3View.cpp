
// NegrobovVAAS-21-05lab3View.cpp : implementation of the CNegrobovVAAS2105lab3View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NegrobovVAAS-21-05lab3.h"
#endif

#include "NegrobovVAAS-21-05lab3Doc.h"
#include "NegrobovVAAS-21-05lab3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNegrobovVAAS2105lab3View

IMPLEMENT_DYNCREATE(CNegrobovVAAS2105lab3View, CScrollView)

BEGIN_MESSAGE_MAP(CNegrobovVAAS2105lab3View, CScrollView)
END_MESSAGE_MAP()

// CNegrobovVAAS2105lab3View construction/destruction

CNegrobovVAAS2105lab3View::CNegrobovVAAS2105lab3View() noexcept
{
	// TODO: add construction code here

}

CNegrobovVAAS2105lab3View::~CNegrobovVAAS2105lab3View()
{
}

BOOL CNegrobovVAAS2105lab3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CNegrobovVAAS2105lab3View drawing

void CNegrobovVAAS2105lab3View::OnDraw(CDC* pDC)
{
	CNegrobovVAAS2105lab3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen pen(PS_SOLID, 3, RGB(10, 7, 10));
	CPen* pOldPen = pDC->SelectObject(&pen);

	CSize total_size = pDoc->sss.draw_members(pDC);

	SetScrollSizes(MM_TEXT, total_size);

	pDC->SelectObject(pOldPen);
}

void CNegrobovVAAS2105lab3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CNegrobovVAAS2105lab3View diagnostics

#ifdef _DEBUG
void CNegrobovVAAS2105lab3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CNegrobovVAAS2105lab3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CNegrobovVAAS2105lab3Doc* CNegrobovVAAS2105lab3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNegrobovVAAS2105lab3Doc)));
	return (CNegrobovVAAS2105lab3Doc*)m_pDocument;
}
#endif //_DEBUG


// CNegrobovVAAS2105lab3View message handlers
