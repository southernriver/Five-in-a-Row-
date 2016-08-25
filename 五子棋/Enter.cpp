// Enter.cpp : implementation file
//

#include "stdafx.h"
#include "programs.h"
#include "Enter.h"
#include "player.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern	player	gameplayer[100];
/////////////////////////////////////////////////////////////////////////////
// CEnter dialog


CEnter::CEnter(CWnd* pParent /*=NULL*/)
	: CDialog(CEnter::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnter)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	
}


void CEnter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnter)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Text( pDX, IDC_EDIT1, editor1 );
	DDX_Text( pDX, IDC_EDIT2, editor2 );
}


BEGIN_MESSAGE_MAP(CEnter, CDialog)
	//{{AFX_MSG_MAP(CEnter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnter message handlers

void CEnter::OnOK() 
{
	// TODO: Add extra validation here
	char	ch1[20];
	char	ch2[20];
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch2,20);
	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1,20);
	gameplayer[0].name.Format("%s",ch1);
	gameplayer[1].name.Format("%s",ch2);
	CDialog::OnOK();
}
