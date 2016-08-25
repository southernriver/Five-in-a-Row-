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
	bool GameType(int t);//改变游戏的Playerinfo
	Chess GetLastChe();//返回最后一个下的棋子的信息
	Managers();
	virtual ~Managers();

	int CheckState();//检查是否有胜利或失败 为0什么也不发生 负数表示失败 正数表示胜利
	bool GameBack(int steps=2);//悔棋 steps是多少步,悔棋一步基本没意义
	void GameStart();//初始化开始
	bool AddChess(int x,int y);//在map上增加新棋子,若成功 返回true不成功返回false
	bool DoMsg(int x,int y,int action);//消息响应
	int map[15][15];	
	friend class Computer;//申请一个电脑AI的有元，方便制作AI。以后这个类就是AI类了
	int Game_State;	 
	bool PAUSE;
Chess LastCh; //上一次鼠标划过的棋子信息
	int nKeyDown;//已经走了多少步,走的步数为nKeyDown-1
private:
	bool Updata();//游戏更新
	bool CheckMap(int x,int y,int pow);//用来查看游戏地图map[x][y]是否和pow相等
	int Gameinfo; ; 
	Chess nChessinfo[226];
protected: //下面2个函数之所以要申请成protected，是为了让AI类能够很好的调用
	bool ForbidLoc(Chess k);//判断K棋子落地是否造成禁手
	int GetNum(Chess nCh,int i,int j,bool goon);//这个函数起辅助作用 用于检测nCh在(i,j)方向上的连子个数
};


#endif // !defined(AFX_MANAGERS_H__969F3774_5D9B_4381_914D_7F5A71275856__INCLUDED_)
