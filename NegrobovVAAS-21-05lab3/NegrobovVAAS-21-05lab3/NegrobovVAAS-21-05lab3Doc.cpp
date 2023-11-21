
// NegrobovVAAS-21-05lab3Doc.cpp : implementation of the CNegrobovVAAS2105lab3Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NegrobovVAAS-21-05lab3.h"
#endif

#include "NegrobovVAAS-21-05lab3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CNegrobovVAAS2105lab3Doc

IMPLEMENT_DYNCREATE(CNegrobovVAAS2105lab3Doc, CDocument)

BEGIN_MESSAGE_MAP(CNegrobovVAAS2105lab3Doc, CDocument)
	ON_COMMAND(ID_EDIT_SSSDIALOG, &CNegrobovVAAS2105lab3Doc::OnEditSssdialog)
END_MESSAGE_MAP()


// CNegrobovVAAS2105lab3Doc construction/destruction

CNegrobovVAAS2105lab3Doc::CNegrobovVAAS2105lab3Doc() noexcept
{
	// TODO: add one-time construction code here

}

CNegrobovVAAS2105lab3Doc::~CNegrobovVAAS2105lab3Doc()
{
}

BOOL CNegrobovVAAS2105lab3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	sss.clear();
	return TRUE;
}




// CNegrobovVAAS2105lab3Doc serialization

void CNegrobovVAAS2105lab3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		sss.to_file(ar);
	}
	else
	{
		sss.from_file(ar);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CNegrobovVAAS2105lab3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CNegrobovVAAS2105lab3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CNegrobovVAAS2105lab3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CNegrobovVAAS2105lab3Doc diagnostics

#ifdef _DEBUG
void CNegrobovVAAS2105lab3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNegrobovVAAS2105lab3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CNegrobovVAAS2105lab3Doc commands


void CNegrobovVAAS2105lab3Doc::OnEditSssdialog()
{
	// TODO: Add your command handler code here
}
