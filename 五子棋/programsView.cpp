// programsView.cpp : implementation of the CProgramsView class
//

#include "stdafx.h"
#include "programs.h"

#include "Managers.h"
#include "programsDoc.h"
#include "programsView.h"
#include "Chess.h"
#include "Dig.h"
#include "Enter.h"
#include "player.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern Managers manager;
extern player	gameplayer[100];
/////////////////////////////////////////////////////////////////////////////
// CProgramsView

IMPLEMENT_DYNCREATE(CProgramsView, CView)

BEGIN_MESSAGE_MAP(CProgramsView, CView)
	//{{AFX_MSG_MAP(CProgramsView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgramsView construction/destruction

CProgramsView::CProgramsView()
{
	// TODO: add construction code here
	gameplayer[0].name="玩家1";
	gameplayer[1].name="玩家2";
	int t;
	for(t=0;t<100;t++)
		gameplayer[t].num=0;
	ReadScore();
}

CProgramsView::~CProgramsView()
{
	WriteScore();
}

BOOL CProgramsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	m_chessboard.LoadBitmap(chessboard);	//用CBitmap类中的LoadBitmap函数来加resource中的位图chessboard
	m_begin.LoadBitmap(begin);
	m_end.LoadBitmap(end);
	m_blackchess.LoadBitmap(blackchess);
	m_whitechess.LoadBitmap(whitechess);
	m_mask.LoadBitmap(mask);
	m_score.LoadBitmap(score);
	m_Chooseblackchess.LoadBitmap(chooseblackchess);
	m_Choosewhitechess.LoadBitmap(choosewhitechess);
	m_Choosespace.LoadBitmap(choosespace);
	st=TRUE;		//对st进行初始化，保证在OnDraw中只执行一次界面的初试化
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CProgramsView drawing

void CProgramsView::OnDraw(CDC* pDC)
{

	CProgramsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if(st==TRUE)
	{
			
		Chessboard.CreateCompatibleDC(pDC);
		Chessboard.SelectObject(m_chessboard);
		Begin.CreateCompatibleDC(pDC);
		Begin.SelectObject(m_begin);
		End.CreateCompatibleDC(pDC);
		End.SelectObject(m_end);
		Blackchess.CreateCompatibleDC(pDC);
		Blackchess.SelectObject(m_blackchess);
		Whitechess.CreateCompatibleDC(pDC);
		Whitechess.SelectObject(m_whitechess);
		Mask.CreateCompatibleDC(pDC);
		Mask.SelectObject(m_mask);
		Score.CreateCompatibleDC(pDC);
		Score.SelectObject(m_score);
		Chooseblackche.CreateCompatibleDC(pDC);
		Chooseblackche.SelectObject(m_Chooseblackchess);
		Choosewhiteche.CreateCompatibleDC(pDC);
		Choosewhiteche.SelectObject(m_Choosewhitechess);
		Choosespa.CreateCompatibleDC(pDC);
		Choosespa.SelectObject(m_Choosespace);
		st=FALSE;
	}
	//触发OnDraw进行全体重画
	PrintAll(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CProgramsView diagnostics

#ifdef _DEBUG
void CProgramsView::AssertValid() const
{
	CView::AssertValid();
}

void CProgramsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProgramsDoc* CProgramsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProgramsDoc)));
	return (CProgramsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProgramsView message handlers

void CProgramsView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	int	mx=(point.x-61)/30;
	int	my=(point.y-68)/30;


if(mx>=0 && mx<15 && my>=0 && my<15)
	{
	//走棋
		CDC	*pDC=GetDC();
		Chess t1=manager.GetLastChe();
		if(manager.DoMsg(mx,my,1))
		{
			Chess t2=manager.GetLastChe();
			pDC->BitBlt( 73+30*t1.x-15,86+30*t1.y-15,28,28,&Chessboard,73+30*t1.x-15,86+30*t1.y-15,MERGECOPY /*MERGEPAINT*/);
			PrintPart(t1.x,t1.y,t1.type,pDC);

			PrintPart(mx,my,t2.type,pDC);
			if(manager.Game_State>2)
				GamePlayer();
			PrintState(pDC);
		}

		ReleaseDC(pDC);
	}
	else if(mx>=17&&mx<=21&&my>=2&&my<=4)
	{
	//游戏开始
		int k=0;
		if(manager.Game_State==1 || manager.Game_State==2)
			k=MessageBox( "您的游戏没有结束，是否重新开始?","五子棋",MB_OKCANCEL);
		if(k!=IDCANCEL)
		{
			CEnter	enter;
			enter.editor1.Format("%s",gameplayer[0].name);
			enter.editor2.Format("%s",gameplayer[1].name);
			enter.DoModal();
					
			manager.GameStart();
			CDC *pDC=GetDC();
			PrintAll(pDC);
			pDC->DeleteDC();
		}
	}
	else if(mx>=17&&mx<=21&&my>=7&&my<=9)
	{	
		int k;
		if(manager.Game_State==1 || manager.Game_State==2)
			k=MessageBox( "您的游戏没有结束，是否结束游戏?","五子棋",MB_OKCANCEL);
		if(k==IDCANCEL)
			return;
		WriteScore();
		ReadScore();
		CDig	dig;
		for( int i = 0; i < 3; i ++ )
		{
			dig.m_strName[i] = buffer[i].name;
			dig.m_strNum[i].Format( "%d", buffer[i].num );
		}
		dig.DoModal();
		exit(0);

	}

	else if(mx>=15&&mx<=23&&my>=11&&my<=13)
	{
			ReadScore();
			CDig	dig;
			for( int i = 0; i < 3; i ++ )
	{
		dig.m_strName[i] = buffer[i].name;
		dig.m_strNum[i].Format( "%d", buffer[i].num );
	}
			dig.DoModal();
	}
 
	

	CView::OnLButtonDown(nFlags, point);
}

void CProgramsView::OnLButtonUp(UINT nFlags, CPoint point) 
{



	CView::OnLButtonUp(nFlags, point);
}

void CProgramsView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnRButtonDown(nFlags, point);
}

void CProgramsView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnRButtonUp(nFlags, point);
}

void CProgramsView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int	x=point.x;
	int	y=point.y;
	CDC *pDC=new CClientDC(this);
	CString st;
	st.Format("(%3d,%3d)",point.x,point.y);
//	pDC->TextOut(20,20,st);

	int	mx=(point.x-61)/30;
	int	my=(point.y-68)/30;

	st.Format("(%3d,%3d)",mx,my);
//	pDC->TextOut(600,20,st);
	st.ReleaseBuffer();
	if(mx>=0 && mx<15 && my>=0 && my<15 && !manager.PAUSE)
	{
		Chess &temp=manager.LastCh;
		if(temp.x!=mx || temp.y!=my)
		{
			pDC->BitBlt( 73+30*temp.x-15,86+30*temp.y-15,28,28,&Chessboard,73+30*temp.x-15,86+30*temp.y-15,MERGECOPY /*MERGEPAINT*/);
			if(temp.type>=100)
			{
				PrintPart(temp.x,temp.y,temp.type-100,pDC);
			}
			manager.DoMsg(mx,my,0);
			PrintPart(mx,my,temp.type,pDC);
		}
	}
	ReleaseDC(pDC);
	CView::OnMouseMove(nFlags, point);
}

void CProgramsView::PrintAll(CDC *pDC)
{	int	x;
	int	y;
	pDC->BitBlt(0,0,800,600,&Chessboard,0,0,SRCCOPY);
	pDC->BitBlt(590,145,119,64,&Begin,0,0,SRCCOPY);
	pDC->BitBlt(590,275,115,63,&End,0,0,SRCCOPY);
	pDC->BitBlt(520,380,260,112,&Score,0,0,SRCCOPY);
//	PrintState(pDC);
	for(x=0;x<=14;x++)
		for(y=0;y<=14;y++)
		{	
			if(manager.map[x][y]>=0)
				PrintPart(x,y,manager.map[x][y],pDC);
		}
}

void CProgramsView::PrintState(CDC *pDC)
{
	CString st;
	if(manager.Game_State==1)
		{	st.Format("黑棋走棋         ");
			PrintPart(8,-1,0,pDC);
		}
	else if(manager.Game_State==2)
		{	st.Format("白棋走棋          ");
			PrintPart(8,-1,1,pDC);
		}
	else if(manager.Game_State==3)
		{	st=gameplayer[manager.Game_State-3].name+"胜利        ";
			PrintPart(8,-1,0,pDC);
		}
	else if(manager.Game_State==4)
		{	st=gameplayer[manager.Game_State-3].name+"胜利        ";
			PrintPart(8,-1,1,pDC);
		}
	else
		st.Format("游戏没有开始");
	pDC->TextOut(280,10,st);

//打印当前玩家状态
	pDC->TextOut(130,25,"黑子:");
	pDC->TextOut(190,25,gameplayer[0].name);
	pDC->TextOut(440,25,"白子:");
	pDC->TextOut(480,25,gameplayer[1].name);
	st.ReleaseBuffer();
}

void CProgramsView::PrintPart(int x, int y, int type, CDC *pDC)
{
	if(type==0)
	{
		pDC->BitBlt(73+30*x-14,86+30*y-14,27,28,&Mask,0,0,MERGEPAINT);
		pDC->BitBlt(73+30*x-14,86+30*y-14,27,28,&Blackchess,0,0,SRCAND);
	}
		else if(type==1)
	{
		pDC->BitBlt(73+30*x-14,86+30*y-14,27,28,&Mask,0,0,MERGEPAINT);
		pDC->BitBlt(73+30*x-14,86+30*y-14,27,28,&Whitechess,0,0,SRCAND);
	}
	else if(type==100)
	{
		pDC->BitBlt(73+30*x-14,86+30*y-14,27,28,&Mask,0,0,MERGEPAINT);
		pDC->BitBlt(73+30*x-14,86+30*y-14,27,28,&Chooseblackche,0,0,SRCAND);
	}
	else if(type==101)
	{
		pDC->BitBlt(73+30*x-14,86+30*y-14,27,28,&Mask,0,0,MERGEPAINT);
		pDC->BitBlt(73+30*x-14,86+30*y-14,27,28,&Choosewhiteche,0,0,SRCAND);
	}
	else if(type==99)
	{
		pDC->BitBlt(73+30*x-14,86+30*y-14,27,28,&Choosespa,0,0,SRCAND);
	}

}



void CProgramsView::ReadScore()
{
	int k;
	//对文件进行读操作 
	CFile mFile1; 
	CString temp;
	if(mFile1.Open(".\\hero.txt",CFile::modeRead)==0) 
		{
			for(k=0;k<3;k++)
			{
				buffer[k].name="玩家";
				buffer[k].num=3-k;
			}
			WriteScore();
		}
	else
	{
		CArchive ar(&mFile1,CArchive::load); 
		for(k=0;k<3;k++)
		{
			ar>>temp;
			buffer[k].name=temp.Left(20);
			temp.Delete(0,20);
			buffer[k].num=atoi(temp.GetBuffer(temp.GetLength()));
		}
		ar.Close();
		mFile1.Close();
	}
}

void CProgramsView::GamePlayer()
{
	int i;
	int winer=manager.Game_State-3;
	int loser=(manager.Game_State-2)%2;
	for(i=2;i<100;i++)
	{
		if(gameplayer[i].name==gameplayer[winer].name)
		{
			gameplayer[i].num++;
			break;
		}
		else if(gameplayer[i].name=="")
		{
			gameplayer[i].name=gameplayer[winer].name;
			gameplayer[i].num++;
			break;
		}
	}
	for(i=2;i<100;i++)
	{
		if(gameplayer[i].name==gameplayer[loser].name)
		{
			gameplayer[i].num--;
			break;
		}
		else if(gameplayer[i].name=="")
		{
			gameplayer[i].name=gameplayer[loser].name;
			gameplayer[i].num--;
			break;
		}
	}

}



void CProgramsView::WriteScore()
{
	int i,t;
	for(i=2;gameplayer[i].name!="";i++)
	{
			if(gameplayer[i].num>buffer[1].num)
			{
				buffer[2]=buffer[1];
				if(gameplayer[i].num>buffer[0].num)
				{	buffer[1]=buffer[0];
					buffer[0].num=gameplayer[i].num;
					buffer[0].name=gameplayer[i].name;
				}
				else
				{	buffer[1].num=gameplayer[i].num;
					buffer[1].name=gameplayer[i].name;
				}
			}
			else if(gameplayer[i].num>buffer[2].num&&gameplayer[i].num<=buffer[1].num)
			{	buffer[2].num=gameplayer[i].num;
				buffer[2].name=gameplayer[i].name;
			}
	}
	mFile.Open(".\\hero.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	CArchive ar(&mFile,CArchive::store); 
	for(i=0;i<3;i++)
	{	if((t=buffer[i].name.GetLength())<=20)
		{
			for(;t<=20;t++)
				buffer[i].name=buffer[i].name+" ";
		}
		num.Format("%s%d",buffer[i].name,buffer[i].num);
		ar<<num;
	}
	ar.Close(); 
	mFile.Close(); 
}
