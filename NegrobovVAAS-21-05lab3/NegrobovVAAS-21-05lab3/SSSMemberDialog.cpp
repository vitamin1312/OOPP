// SSSMemberDialog.cpp : implementation file
//

#include "pch.h"
#include "NegrobovVAAS-21-05lab3.h"
#include "afxdialogex.h"
#include "SSSMemberDialog.h"


// SSSMemberDialog dialog

IMPLEMENT_DYNAMIC(SSSMemberDialog, CDialogEx)

SSSMemberDialog::SSSMemberDialog(CNegrobovVAAS2105lab3Doc* m_pDoc, BOOL add_new, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, is_president(FALSE)
{
	this->m_pDoc = m_pDoc;
	this->add_new = add_new;
}

SSSMemberDialog::~SSSMemberDialog()
{
}

void SSSMemberDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_ISPRES, is_president);
	DDX_Control(pDX, IDC_MEMNAME, mem_name);
	DDX_Control(pDX, IDC_MEMGROUP, mem_group);
	DDX_Control(pDX, IDC_MEMRATE, mem_rate);
	DDX_Control(pDX, IDC_MEMEXP, mem_exp);
}


void SSSMemberDialog::add_member() {
	std::shared_ptr<NegrobovSSSMember> pmem = std::make_shared<NegrobovSSSMember>();

}


void SSSMemberDialog::add_president() {

}


BEGIN_MESSAGE_MAP(SSSMemberDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &SSSMemberDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// SSSMemberDialog message handlers


void SSSMemberDialog::OnBnClickedOk()
{
	if (is_president)
		add_president();
	else
		add_member();
	CDialogEx::OnOK();
}
