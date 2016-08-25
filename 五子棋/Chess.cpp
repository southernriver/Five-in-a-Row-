// Chess.cpp: implementation of the Chess class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "programs.h"
#include "Chess.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Chess::Chess()
{
	x=0;
	y=0;
	type=-1;
}

Chess::~Chess()
{

}
