// Chess.h: interface for the Chess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHESS_H__787E6DBE_87B7_42F2_A6BA_7FF8F160F5DB__INCLUDED_)
#define AFX_CHESS_H__787E6DBE_87B7_42F2_A6BA_7FF8F160F5DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Chess  //Æå×Ó°ë¾¶14 PX
{
public:
	Chess();
	virtual ~Chess();
	int x,y;
	int type;//1Îª°×Æå 0ÎªºÚÆå
};

#endif // !defined(AFX_CHESS_H__787E6DBE_87B7_42F2_A6BA_7FF8F160F5DB__INCLUDED_)
