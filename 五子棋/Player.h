// Player.h: interface for the Player class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYER_H__1BDDE0E0_F4C6_496C_A413_74125AC25A5F__INCLUDED_)
#define AFX_PLAYER_H__1BDDE0E0_F4C6_496C_A413_74125AC25A5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class player
{
public:
	player(){};
	virtual ~player(){};
	CString	name;
	int		num;
};

#endif // !defined(AFX_PLAYER_H__1BDDE0E0_F4C6_496C_A413_74125AC25A5F__INCLUDED_)
