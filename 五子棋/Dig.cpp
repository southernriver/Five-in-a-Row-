// Dig.cpp : implementation file
//

#include "stdafx.h"
#include "programs.h"
#include "Dig.h"
#include "programsView.h"
#include "programsDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDig dialog


CDig::CDig(CWnd* pParent /*=NULL*/)
	: CDialog(CDig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDig)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	
}


void CDig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDig)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Text( pDX, IDC_STATIC_PALYER1, m_strName[0] );
	DDX_Text( pDX, IDC_STATIC_PALYER2, m_strName[1] );
	DDX_Text( pDX, IDC_STATIC_PALYER3, m_strName[2] );
	DDX_Text( pDX, IDC_STATIC_NUM1, m_strNum[0] );
	DDX_Text( pDX, IDC_STATIC_NUM2, m_strNum[1] );
	DDX_Text( pDX, IDC_STATIC_NUM3, m_strNum[2] );
}


BEGIN_MESSAGE_MAP(CDig, CDialog)
	//{{AFX_MSG_MAP(CDig)
	ON_WM_CREATE()
	ON_WM_CANCELMODE()
	ON_WM_CAPTURECHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDig message handlers

int CDig::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
//	CProgramsView	programs;
//	programs.ReadScore();
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CDig::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CDig::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	
	CDialog::OnCaptureChanged(pWnd);
}
