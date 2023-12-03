// SSSMemberDialog.cpp : implementation file
//

#include "pch.h"
#include "NegrobovVAAS-21-05lab3.h"
#include "afxdialogex.h"
#include "SSSMemberDialog.h"
#include "SSSDialog.h"


// SSSMemberDialog dialog

IMPLEMENT_DYNAMIC(SSSMemberDialog, CDialogEx)

SSSMemberDialog::SSSMemberDialog(CNegrobovVAAS2105lab3Doc* m_pDoc, SSSDialog* m_pDiag, BOOL add_new, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, is_president(FALSE)
{
	this->m_pDoc = m_pDoc;
	this->m_pDiag = m_pDiag;
	this->add_new = add_new;
}

SSSMemberDialog::~SSSMemberDialog()
{
}

BOOL SSSMemberDialog::OnInitDialog() {
	CDialogEx::OnInitDialog();

	if (add_new) {
		mem_exp.EnableWindow(FALSE);
	}

	else {

		NegrobovSSSMember* mem = m_pDoc->sss.members[m_pDiag->current_index].get();

		mem_name.SetWindowText(mem->get_name());
		mem_group.SetWindowText(mem->get_group());
		mem_rate.SetWindowText(to_cstring(mem->get_rate()));

		if (dynamic_cast<NegrobovSSSPresident*>(mem)) {
			mem_exp.SetWindowText(
				to_cstring(dynamic_cast<NegrobovSSSPresident*>(mem)->get_experience())
			);
			CB_is_president.SetCheck(TRUE);
			CB_is_president.EnableWindow(FALSE);
		}

		else {
			CB_is_president.SetCheck(FALSE);
			CB_is_president.EnableWindow(FALSE);
			mem_exp.EnableWindow(FALSE);
		}
	}
	return TRUE;
}

void SSSMemberDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_ISPRES, is_president);
	DDX_Control(pDX, IDC_MEMNAME, mem_name);
	DDX_Control(pDX, IDC_MEMGROUP, mem_group);
	DDX_Control(pDX, IDC_MEMRATE, mem_rate);
	DDX_Control(pDX, IDC_MEMEXP, mem_exp);
	DDX_Control(pDX, IDC_ISPRES, CB_is_president);
}


void SSSMemberDialog::add_member() {
	std::shared_ptr<NegrobovSSSMember> pmem = std::make_shared<NegrobovSSSMember>();

	CString name, group, rate;
	GetDlgItemText(IDC_MEMNAME, name);
	pmem->set_name(name);

	GetDlgItemText(IDC_MEMGROUP, group);
	pmem->set_group(group);

	GetDlgItemText(IDC_MEMRATE, rate);
	pmem->set_rate(_ttoi(rate));

	m_pDoc->sss.members.push_back(pmem);

}


void SSSMemberDialog::add_president() {
	std::shared_ptr<NegrobovSSSPresident> pmem = std::make_shared<NegrobovSSSPresident>();

	CString name, group, rate, exp;
	GetDlgItemText(IDC_MEMNAME, name);
	pmem->set_name(name);

	GetDlgItemText(IDC_MEMGROUP, group);
	pmem->set_group(group);

	GetDlgItemText(IDC_MEMRATE, rate);
	pmem->set_rate(_ttoi(rate));

	GetDlgItemText(IDC_MEMEXP, exp);
	pmem->set_experience(_ttoi(exp));

	m_pDoc->sss.members.push_back(pmem);

}

void SSSMemberDialog::change_member(NegrobovSSSMember* mem, BOOL is_p) {

	CString name, group, rate;
	GetDlgItemText(IDC_MEMNAME, name);
	mem->set_name(name);

	GetDlgItemText(IDC_MEMGROUP, group);
	mem->set_group(group);

	GetDlgItemText(IDC_MEMRATE, rate);
	mem->set_rate(_ttoi(rate));

	if (is_p) {
		CString exp;
		GetDlgItemText(IDC_MEMEXP, exp);
		dynamic_cast<NegrobovSSSPresident*>(mem)->set_experience(_ttoi(exp));
	}
}


BEGIN_MESSAGE_MAP(SSSMemberDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &SSSMemberDialog::OnBnClickedOk)
	ON_NOTIFY(BCN_HOTITEMCHANGE, IDC_ISPRES, &SSSMemberDialog::OnBnHotItemChangeIspres)
END_MESSAGE_MAP()


// SSSMemberDialog message handlers


void SSSMemberDialog::OnBnClickedOk()
{
	int idx;
	CDialogEx::OnOK();

	if (add_new) {
		if (is_president)
			add_president();
		else
			add_member();
		idx = m_pDoc->sss.get_size() - 1;
	}
	else {
		idx = m_pDiag->CLBMembers.GetCurSel();
		NegrobovSSSMember* mem = m_pDoc->sss.members[idx].get();
		change_member(mem, CB_is_president.GetCheck());
	}
	if (m_pDiag->CLBMembers.GetCount())
		while (m_pDiag->CLBMembers.DeleteString(0));
	m_pDoc->sss.to_CLBMembers(m_pDiag->CLBMembers);
	m_pDiag->CLBMembers.SetCurSel(idx);
	m_pDiag->OnLbnSelchangeMemlist();
}

void SSSMemberDialog::OnBnHotItemChangeIspres(NMHDR* pNMHDR, LRESULT* pResult)
{
	// This feature requires Internet Explorer 6 or greater.
	// The symbol _WIN32_IE must be >= 0x0600.
	LPNMBCHOTITEM pHotItem = reinterpret_cast<LPNMBCHOTITEM>(pNMHDR);
	mem_exp.EnableWindow(CB_is_president.GetCheck());
	*pResult = 0;
}
