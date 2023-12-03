// SSSDialog.cpp : implementation file
//

#include "pch.h"
#include "NegrobovVAAS-21-05lab3.h"
#include "afxdialogex.h"
#include "SSSDialog.h"
#include "SSSMemberDialog.h"


// SSSDialog dialog

IMPLEMENT_DYNAMIC(SSSDialog, CDialogEx)

SSSDialog::SSSDialog(CNegrobovVAAS2105lab3Doc* m_pDoc, CWnd* pParent/* = nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	this->m_pDoc = m_pDoc;
}

SSSDialog::~SSSDialog()
{
}

void SSSDialog::EnableWindows() {
	mem_name.EnableWindow(FALSE);
	mem_group.EnableWindow(FALSE);
	mem_rate.EnableWindow(FALSE);
	mem_exp.EnableWindow(FALSE);
}

void SSSDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MEMLIST, CLBMembers);
	DDX_Control(pDX, IDC_MEMNAME, mem_name);
	DDX_Control(pDX, IDC_MEMGROUP, mem_group);
	DDX_Control(pDX, IDC_MEMRATE, mem_rate);
	DDX_Control(pDX, IDC_MEMEXP, mem_exp);
	DDX_Control(pDX, IDC_EXPTXT, exp_txt);
}


BEGIN_MESSAGE_MAP(SSSDialog, CDialogEx)
	ON_LBN_SELCHANGE(IDC_MEMLIST, &SSSDialog::OnLbnSelchangeMemlist)
	ON_BN_CLICKED(IDC_DELETEMEM, &SSSDialog::OnBnClickedDeletemem)
	ON_BN_CLICKED(IDC_ADDMEM, &SSSDialog::OnBnClickedAddmem)
	ON_BN_CLICKED(IDC_CHANGEMEM, &SSSDialog::OnBnClickedChangemem)
END_MESSAGE_MAP()

BOOL SSSDialog::OnInitDialog() {
	CDialogEx::OnInitDialog();
	
	if (!m_pDoc->sss.members.empty()) {
		m_pDoc->sss.to_CLBMembers(CLBMembers);
		OnLbnSelchangeMemlist();
	}
	EnableWindows();
	//OnBnClickedShowTitlesCheck();
	return TRUE;
}


// SSSDialog message handlers

void SSSDialog::show_data(int index) {

	NegrobovSSSMember* mem = m_pDoc->sss.members[index].get();

	mem_name.SetWindowText(mem->get_name());
	mem_group.SetWindowText(mem->get_group());
	mem_rate.SetWindowText(to_cstring(mem->get_rate()));

	if (dynamic_cast<NegrobovSSSPresident*>(mem))
	{
		mem_exp.SetWindowText(
			to_cstring(dynamic_cast<NegrobovSSSPresident*>(mem)->get_experience())
		);
	}
	else
	{
		mem_exp.SetWindowText(_T(""));
	}

	EnableWindows();

}


void SSSDialog::OnLbnSelchangeMemlist()
{
	current_index = CLBMembers.GetCurSel();
	if (current_index < 0)
		return;

	show_data(current_index);
}


void SSSDialog::OnBnClickedDeletemem() {
	if (current_index != -1) {
		m_pDoc->sss.delete_member(current_index);
		if (CLBMembers.GetCount() != 0)
		{
			while (CLBMembers.DeleteString(0));
			m_pDoc->sss.to_CLBMembers(CLBMembers);
			int last = m_pDoc->sss.get_size() - 1;
			if (current_index > last)
				current_index = last;
			if (CLBMembers.GetCount() != 0)
			{
				CLBMembers.SetCurSel(current_index);
				OnLbnSelchangeMemlist();
			}
			else
			{
				mem_name.SetWindowText(_T(""));
				mem_group.SetWindowText(_T(""));
				mem_rate.SetWindowText(_T(""));
				mem_exp.SetWindowText(_T(""));
				EnableWindows();
			}
		}
		m_pDoc->SetModifiedFlag();
	}
}


void SSSDialog::OnBnClickedAddmem() {
	SSSMemberDialog dlg(m_pDoc, this, TRUE);
	dlg.DoModal();
	m_pDoc->UpdateAllViews(NULL);
	m_pDoc->SetModifiedFlag();
}


void SSSDialog::OnBnClickedChangemem()
{
	if (current_index != -1) {
		SSSMemberDialog dlg(m_pDoc, this, FALSE);
		dlg.DoModal();
		m_pDoc->UpdateAllViews(NULL);
		m_pDoc->SetModifiedFlag();
	}
}
