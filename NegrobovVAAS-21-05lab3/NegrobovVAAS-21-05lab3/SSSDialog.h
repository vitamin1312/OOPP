#pragma once
#include "afxdialogex.h"
#include "NegrobovVAAS-21-05lab3Doc.h"


class CNegrobovVAAS2105lab3Doc;

// SSSDialog dialog

class SSSDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SSSDialog)
	CNegrobovVAAS2105lab3Doc* m_pDoc;

public:
	SSSDialog(CNegrobovVAAS2105lab3Doc* m_pDoc, CWnd* pParent = nullptr);   // standard constructor
	virtual ~SSSDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox CLBMembers;

	virtual BOOL OnInitDialog();

	CEdit mem_name;
	CEdit mem_group;
	CEdit mem_rate;
	CEdit mem_exp;
	int current_index = -1;
	afx_msg void OnLbnSelchangeMemlist();
	void show_data(int index);
	afx_msg void OnBnClickedDeletemem();
	void EnableWindows();
	afx_msg void OnBnClickedAddmem();
	afx_msg void OnBnClickedChangemem();
	CStatic exp_txt;
};
