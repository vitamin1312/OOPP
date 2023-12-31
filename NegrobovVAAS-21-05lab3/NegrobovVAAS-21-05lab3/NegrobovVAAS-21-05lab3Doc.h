
// NegrobovVAAS-21-05lab3Doc.h : interface of the CNegrobovVAAS2105lab3Doc class
//

#include "NegrobovSSS.h"

#pragma once


class CNegrobovVAAS2105lab3Doc : public CDocument
{
protected: // create from serialization only
	CNegrobovVAAS2105lab3Doc() noexcept;
	DECLARE_DYNCREATE(CNegrobovVAAS2105lab3Doc)

// Attributes
public:
	NegrobovSSS sss;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CNegrobovVAAS2105lab3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEditSssdialog();
	afx_msg void OnBnClickedAddmem();
};
