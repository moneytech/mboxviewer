// FindInMailDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mboxview.h"
#include "FindInMailDlg.h"
#include "afxdialogex.h"


// CFindInMailDlg dialog

IMPLEMENT_DYNAMIC(CFindInMailDlg, CDialogEx)

CFindInMailDlg::CFindInMailDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIND_IN_MAIL, pParent)
{

}

CFindInMailDlg::~CFindInMailDlg()
{
}

void CFindInMailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindDlg)
	DDX_Text(pDX, IDC_STRING, m_string);
	DDX_Check(pDX, IDC_WHOLE, m_bWholeWord);
	DDX_Check(pDX, IDC_CASE, m_bCaseSensitive);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindInMailDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CFindInMailDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CFindInMailDlg message handlers


void CFindInMailDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData();

	m_string.TrimRight();
	g_tu.MakeLower(m_string);
	if (m_string.IsEmpty()) {
		// If empty, clear the highlights
		; // AfxMessageBox("Cannot search for an empty string!", MB_OK | MB_ICONHAND);
		//return;
	}

	CDialogEx::OnOK();
}
