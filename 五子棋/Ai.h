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
	void checkgo(int x,int y,bool color,int nu,int inx,int iny);//Ԥ�⺯��
	bool bejs(int nx, int ny);	/*++�˴���ӽ��ֿ���++*/
	//��Ϊ�Ҳ���Ϥ������Ĺ�������û�����ý���	
	bool bj2(int x1,int y1,int x2,int y2,bool style);					
	char ntoc(char num,bool type,bool style);
	CPoint getmax(bool color);
	CPoint getbg(bool style);
	int getAitype();
	int AItype;//0��Ԥ��6�� 1��Ԥ��10�� 2��Ԥ��16��
	int Aitype2;
	int Model;//0��->�� 1��->�� 2����
public:
	Ai();
	CPoint AiGo(bool color);
	virtual ~Ai();
	unsigned char user[15][15][4];//�������
	unsigned char pc[15][15][4];//�������




};

#endif // !defined(AFX_Ai_H__C9C7DFA9_4481_4AC7_AA05_AEFC6179BC4D__INCLUDED_)
