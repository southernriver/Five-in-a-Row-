#if !defined(AFX_ENTER_H__C520A21A_E61D_4CD3_A326_F63C4D36EE46__INCLUDED_)
#define AFX_ENTER_H__C520A21A_E61D_4CD3_A326_F63C4D36EE46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Enter.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnter dialog

class CEnter : public CDialog
{
// Construction
public:
	CEnter(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEnter)
	enum { IDD = IDD_ENTER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	CString	editor1;
	CString	editor2;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnter)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTER_H__C520A21A_E61D_4CD3_A326_F63C4D36EE46__INCLUDED_)
