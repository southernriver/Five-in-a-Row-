#if !defined(AFX_DIG_H__8C3A5EFC_9C04_474E_A191_FB00F2304C24__INCLUDED_)
#define AFX_DIG_H__8C3A5EFC_9C04_474E_A191_FB00F2304C24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDig dialog

class CDig : public CDialog
{
// Construction
public:
	CDig(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDig)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	CString m_strName[3];
	CString m_strNum[3];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(CDig)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnCancelMode();
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIG_H__8C3A5EFC_9C04_474E_A191_FB00F2304C24__INCLUDED_)
