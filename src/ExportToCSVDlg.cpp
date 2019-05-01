// ExportToCSVDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mboxview.h"
#include "ExportToCSVDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#undef THIS_FILE
#define THIS_FILE __FILE__
#define new DEBUG_NEW
#endif

// ExportToCSVDlg dialog

IMPLEMENT_DYNAMIC(ExportToCSVDlg, CDialogEx)

ExportToCSVDlg::ExportToCSVDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXPORT_TO_CSV, pParent)
{
	//{{AFX_DATA_INIT(ExportToCSVDlg)
	m_bFrom = TRUE;
	m_bTo = TRUE;
	m_bSubject = TRUE;
	m_bDate = TRUE;
	m_bCC = FALSE;
	m_bBCC = FALSE;
	m_bContent = FALSE;
	m_bGMTTime = 0;
	m_dateFormat = 0;
	m_bEncodingType = 1;  // UTF8
	m_nCodePageId = CP_UTF8;
	m_MessageLimitCharsString.Append("32500");
	//}}AFX_DATA_INIT
}

ExportToCSVDlg::~ExportToCSVDlg()
{
}

void ExportToCSVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ExportToCSVDlg)
	DDX_Check(pDX, IDC_EXPORT_FROM, m_bFrom);
	DDX_Check(pDX, IDC_EXPORT_TO, m_bTo);
	DDX_Check(pDX, IDC_EXPORT_SUBJECT, m_bSubject);
	DDX_Check(pDX, IDC_EXPORT_DATE, m_bDate);
	DDX_Check(pDX, IDC_EXPORT_CC, m_bCC);
	DDX_Check(pDX, IDC_EXPORT_BCC, m_bBCC);
	DDX_Check(pDX, IDC_EXPORT_MESSAGE, m_bContent);
	DDX_Text(pDX, IDC_EXPORT_MESSAGE_LIMIT, m_MessageLimitString);
	DDX_Text(pDX, IDC_EXPORT_MESSAGE_LIMIT_CHARS, m_MessageLimitCharsString);
	DDX_Radio(pDX, IDC_TIME_LOCAL, m_bGMTTime);
	DDX_Radio(pDX, IDC_DMY, m_dateFormat);
	DDX_Radio(pDX, IDC_ENCODING_NONE, m_bEncodingType);
	DDX_Text(pDX, IDC_ENCODING_CODE_PAGE_ID, m_nCodePageId);
	int deb = 1;
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ExportToCSVDlg, CDialogEx)
ON_BN_CLICKED(IDC_ENCODING_NONE, &ExportToCSVDlg::OnBnClickedEncodingNone)
ON_BN_CLICKED(IDC_ENCODING_UTF8, &ExportToCSVDlg::OnBnClickedEncodingUtf8)
ON_BN_CLICKED(IDC_ENCODING_CODE_PAGE, &ExportToCSVDlg::OnBnClickedEncodingCodePage)
END_MESSAGE_MAP()


// ExportToCSVDlg message handlers


BOOL ExportToCSVDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	GetDlgItem(IDC_ENCODING_CODE_PAGE_ID)->EnableWindow(FALSE);
	UpdateData(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void ExportToCSVDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData();

	if ((m_nCodePageId <= 0) || (m_nCodePageId > 65001))
	{
		AfxMessageBox("Code Page Id out of valid range 0-65001 !", MB_OK | MB_ICONHAND);
		return;
	}

	BOOL validString = TRUE;

	m_MessageLimitString.Trim();
	const char *p = m_MessageLimitString;
	const char *e = p + m_MessageLimitString.GetLength();
	if (!isEmptyLine(p, e))
	{
		if (isNumeric(m_MessageLimitString)) {
			int limit = _ttoi(m_MessageLimitString);
			if (limit < 0)
				validString = FALSE;
			else
				validString = TRUE;

		}
		else
			validString = FALSE;
	}

	if (validString == FALSE)
	{
		AfxMessageBox("Invalid line limit!", MB_OK | MB_ICONHAND);
		return;
	}

	validString = TRUE;

	m_MessageLimitCharsString.Trim();
	p = m_MessageLimitCharsString;
	e = p + m_MessageLimitCharsString.GetLength();
	if (!isEmptyLine(p, e))
	{
		if (isNumeric(m_MessageLimitCharsString)) {
			int limit = _ttoi(m_MessageLimitCharsString);
			if (limit < 0)
				validString = FALSE;
			else
				validString = TRUE;

		}
		else
			validString = FALSE;
	}

	if (validString == FALSE)
	{
		AfxMessageBox("Invalid character limit!", MB_OK | MB_ICONHAND);
		return;
	}

	CDialogEx::OnOK();
}


void ExportToCSVDlg::OnBnClickedEncodingNone()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_ENCODING_CODE_PAGE_ID)->EnableWindow(FALSE);
	int deb = 1;
}


void ExportToCSVDlg::OnBnClickedEncodingUtf8()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_ENCODING_CODE_PAGE_ID)->EnableWindow(FALSE);
	int deb = 1;
}


void ExportToCSVDlg::OnBnClickedEncodingCodePage()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_ENCODING_CODE_PAGE_ID)->EnableWindow(TRUE);
	int dreb = 1;
}
