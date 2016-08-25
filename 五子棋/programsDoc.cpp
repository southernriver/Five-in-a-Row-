// programsDoc.cpp : implementation of the CProgramsDoc class
//

#include "stdafx.h"
#include "programs.h"

#include "programsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgramsDoc

IMPLEMENT_DYNCREATE(CProgramsDoc, CDocument)

BEGIN_MESSAGE_MAP(CProgramsDoc, CDocument)
	//{{AFX_MSG_MAP(CProgramsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgramsDoc construction/destruction

CProgramsDoc::CProgramsDoc()
{
	// TODO: add one-time construction code here

}

CProgramsDoc::~CProgramsDoc()
{
}

BOOL CProgramsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CProgramsDoc serialization

void CProgramsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CProgramsDoc diagnostics

#ifdef _DEBUG
void CProgramsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProgramsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProgramsDoc commands
