#pragma once
#include "afxdialogex.h"
#include "NegrobovVAAS-21-05lab3Doc.h"


// SSSMemberDialog dialog

class SSSMemberDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SSSMemberDialog)
	CNegrobovVAAS2105lab3Doc* m_pDoc;

public:
	SSSMemberDialog(CNegrobovVAAS2105lab3Doc* m_pDoc, BOOL add_new, CWnd* pParent = nullptr);   // standard constructor
	virtual ~SSSMemberDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL is_president;
	BOOL add_new;
	CEdit mem_name;
	CEdit mem_group;
	CEdit mem_rate;
	CEdit mem_exp;
	afx_msg void OnBnClickedOk();
	void add_member();
	void add_president();
};
