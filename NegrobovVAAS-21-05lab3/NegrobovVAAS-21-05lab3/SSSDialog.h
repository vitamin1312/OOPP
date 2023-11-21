#pragma once
#include "afxdialogex.h"


class CMFCApplicationDoc;

// SSSDialog dialog

class SSSDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SSSDialog)
	CMFCApplicationDoc* m_pDoc;

public:
	SSSDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SSSDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
