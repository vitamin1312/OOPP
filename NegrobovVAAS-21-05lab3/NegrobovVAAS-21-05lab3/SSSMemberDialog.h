#pragma once
#include "afxdialogex.h"
#include "NegrobovVAAS-21-05lab3Doc.h"
#include "SSSDialog.h"


// SSSMemberDialog dialog

class SSSMemberDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SSSMemberDialog)


public:
	SSSMemberDialog(CNegrobovVAAS2105lab3Doc* m_pDoc, SSSDialog* m_pDiag, BOOL add_new, CWnd* pParent = nullptr);   // standard constructor
	virtual ~SSSMemberDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CNegrobovVAAS2105lab3Doc* m_pDoc;
	SSSDialog* m_pDiag;
	BOOL OnInitDialog();

	BOOL is_president;
	BOOL add_new;
	CEdit mem_name;
	CEdit mem_group;
	CEdit mem_rate;
	CEdit mem_exp;
	afx_msg void OnBnClickedOk();
	void add_member();
	void add_president();
	void change_member(NegrobovSSSMember* mem, BOOL is_p);
	afx_msg void OnBnHotItemChangeIspres(NMHDR* pNMHDR, LRESULT* pResult);
	CButton CB_is_president;
};
