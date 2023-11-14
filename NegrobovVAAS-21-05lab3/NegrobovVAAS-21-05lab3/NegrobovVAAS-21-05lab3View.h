
// NegrobovVAAS-21-05lab3View.h : interface of the CNegrobovVAAS2105lab3View class
//

#pragma once


class CNegrobovVAAS2105lab3View : public CScrollView
{
protected: // create from serialization only
	CNegrobovVAAS2105lab3View() noexcept;
	DECLARE_DYNCREATE(CNegrobovVAAS2105lab3View)

// Attributes
public:
	CNegrobovVAAS2105lab3Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CNegrobovVAAS2105lab3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NegrobovVAAS-21-05lab3View.cpp
inline CNegrobovVAAS2105lab3Doc* CNegrobovVAAS2105lab3View::GetDocument() const
   { return reinterpret_cast<CNegrobovVAAS2105lab3Doc*>(m_pDocument); }
#endif

