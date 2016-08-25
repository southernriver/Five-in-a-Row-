// Computer.h: interface for the Computer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPUTER_H__EB4C984D_4D62_4EF9_AFC2_B16EEC4D4360__INCLUDED_)
#define AFX_COMPUTER_H__EB4C984D_4D62_4EF9_AFC2_B16EEC4D4360__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Computer  
{
public:
	void Reset();
	void Run(int x,int y);
	Computer();
	virtual ~Computer();
private:
	int maps[15][15][9][2];
};

#endif // !defined(AFX_COMPUTER_H__EB4C984D_4D62_4EF9_AFC2_B16EEC4D4360__INCLUDED_)
