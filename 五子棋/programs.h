// programs.h : main header file for the PROGRAMS application
//

#if !defined(AFX_PROGRAMS_H__2B1C45DF_FFD0_42A3_9264_F7133D66697A__INCLUDED_)
#define AFX_PROGRAMS_H__2B1C45DF_FFD0_42A3_9264_F7133D66697A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CProgramsApp:
// See programs.cpp for the implementation of this class
//

class CProgramsApp : public CWinApp
{
public:
	CProgramsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgramsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CProgramsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRAMS_H__2B1C45DF_FFD0_42A3_9264_F7133D66697A__INCLUDED_)
