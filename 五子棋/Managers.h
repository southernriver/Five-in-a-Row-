// Managers.h: interface for the Managers class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGERS_H__969F3774_5D9B_4381_914D_7F5A71275856__INCLUDED_)
#define AFX_MANAGERS_H__969F3774_5D9B_4381_914D_7F5A71275856__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Chess.h"
class Managers  
{
public:
	bool GameType(int t);//�ı���Ϸ��Playerinfo
	Chess GetLastChe();//�������һ���µ����ӵ���Ϣ
	Managers();
	virtual ~Managers();

	int CheckState();//����Ƿ���ʤ����ʧ�� Ϊ0ʲôҲ������ ������ʾʧ�� ������ʾʤ��
	bool GameBack(int steps=2);//���� steps�Ƕ��ٲ�,����һ������û����
	void GameStart();//��ʼ����ʼ
	bool AddChess(int x,int y);//��map������������,���ɹ� ����true���ɹ�����false
	bool DoMsg(int x,int y,int action);//��Ϣ��Ӧ
	int map[15][15];	
	friend class Computer;//����һ������AI����Ԫ����������AI���Ժ���������AI����
	int Game_State;	 
	bool PAUSE;
Chess LastCh; //��һ����껮����������Ϣ
	int nKeyDown;//�Ѿ����˶��ٲ�,�ߵĲ���ΪnKeyDown-1
private:
	bool Updata();//��Ϸ����
	bool CheckMap(int x,int y,int pow);//�����鿴��Ϸ��ͼmap[x][y]�Ƿ��pow���
	int Gameinfo; ; 
	Chess nChessinfo[226];
protected: //����2������֮����Ҫ�����protected����Ϊ����AI���ܹ��ܺõĵ���
	bool ForbidLoc(Chess k);//�ж�K��������Ƿ���ɽ���
	int GetNum(Chess nCh,int i,int j,bool goon);//��������������� ���ڼ��nCh��(i,j)�����ϵ����Ӹ���
};


#endif // !defined(AFX_MANAGERS_H__969F3774_5D9B_4381_914D_7F5A71275856__INCLUDED_)
