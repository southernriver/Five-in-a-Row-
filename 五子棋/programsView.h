// programsView.h : interface of the CProgramsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROGRAMSVIEW_H__F12D2EE9_C66F_4124_A985_5F4449C8B200__INCLUDED_)
#define AFX_PROGRAMSVIEW_H__F12D2EE9_C66F_4124_A985_5F4449C8B200__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "player.h"


class CProgramsView : public CView
{
protected: // create from serialization only
	CProgramsView();
	DECLARE_DYNCREATE(CProgramsView)

// Attributes
public:
		CProgramsDoc * GetDocument();
// Operations
public:
	BOOL	st;		//用于控制Ondraw中只执行一次界面的初试化
	//CDC叫设备描述类，MFC将DC(设备描述表)和GDI（图形设备接口)封装在一起建立了CDC 
	//在这里添加对象，用来将图形同设备连接动一起
	CDC		Chessboard;	
	CDC		Begin;
	CDC		End;
	CDC		Blackchess;
	CDC		Whitechess;
	CDC		Mask;
	CDC		Score;
	CDC     Chooseblackche;
	CDC     Choosewhiteche;
	CDC     Choosespa;
	//定义CBitmap的对象，用来进行位图的相关处理
	CBitmap	m_chessboard;	
	CBitmap	m_begin;
	CBitmap	m_end;
	CBitmap	m_blackchess;
	CBitmap	m_whitechess;
	CBitmap	m_mask;
	CBitmap	m_score;
	CBitmap	m_Chooseblackchess;
	CBitmap m_Choosewhitechess;
	CBitmap m_Choosespace;
//	int		win_num[100];

	player	buffer[3];
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgramsView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
private:
	CString num;
	CFile mFile; 
	void WriteScore();
	void GamePlayer();
	void ReadScore();
	void PrintPart(int x,int y,int type,CDC *pdc);
	void PrintState(CDC *pdc);
	void PrintAll(CDC *pdc);
public:
	virtual ~CProgramsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProgramsView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in programsView.cpp
inline CProgramsDoc* CProgramsView::GetDocument()
   { return (CProgramsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRAMSVIEW_H__F12D2EE9_C66F_4124_A985_5F4449C8B200__INCLUDED_)
