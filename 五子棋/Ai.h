// Ai.h: interface for the Ai class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Ai_H__C9C7DFA9_4481_4AC7_AA05_AEFC6179BC4D__INCLUDED_)
#define AFX_Ai_H__C9C7DFA9_4481_4AC7_AA05_AEFC6179BC4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Ai  
{
private:
	void fillin(bool color,bool player,bool type);
	void setqx(int nx ,int ny,bool style,bool player,int st,bool type);	
	void setall();
	void clear(bool style);
	void checkgo(int x,int y,bool color,int nu,int inx,int iny);//预测函数
	bool bejs(int nx, int ny);	/*++此处添加禁手控制++*/
	//因为我不熟悉五子棋的规则，所以没有设置禁手	
	bool bj2(int x1,int y1,int x2,int y2,bool style);					
	char ntoc(char num,bool type,bool style);
	CPoint getmax(bool color);
	CPoint getbg(bool style);
	int getAitype();
	int AItype;//0低预测6步 1中预测10步 2高预测16步
	int Aitype2;
	int Model;//0人->机 1机->人 2对翌
public:
	Ai();
	CPoint AiGo(bool color);
	virtual ~Ai();
	unsigned char user[15][15][4];//储存棋局
	unsigned char pc[15][15][4];//储存棋局




};

#endif // !defined(AFX_Ai_H__C9C7DFA9_4481_4AC7_AA05_AEFC6179BC4D__INCLUDED_)
