// Managers.cpp: implementation of the Managers class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "programs.h"
#include "Managers.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Managers::Managers()
{
	Game_State=-1;
	int k,x,y;
	for(k=0;k<226;k++)
		nChessinfo[k].type=k%2;
	Gameinfo=100;//默认为 人-人 对战	并且判断禁手
	for(x=0;x<15;x++)
		for(y=0;y<15;y++)
		{
			map[x][y]=-1;//初始化棋盘
		}
}


Managers::~Managers()
{

}
////////////////////////////////////////////////////////////////////////
/*
* 函数名称：DoMSG(	CPiont pt   //传入坐标
					int action)	//行为
* 函数介绍：消息响应
* 输入参数：action含义 0为鼠标经过 1为按下左键  2为按下右件
* 输出参数：bool
* 返回值  ：true 表示响应成功 false为失败
*/

bool Managers::DoMsg(int x,int y, int action)
{
if(Game_State >2 || Game_State <1)
		return false;
	if(action==2)//右件响应为没有任何反应
		return false;
	if(action==1)//左件响应落子
	{
		//在游戏状态让Player1下棋或 人-人 对战时才能响应走棋
		if(	((Gameinfo%100)/10 == 0 || Game_State==1) && AddChess(x,y))//按左键走下棋子
		{
			LastCh.x=x;
			LastCh.y=y;
			LastCh.type=map[x][y]+100;
			return true;
		}
	}
	if(action==0)
	{
		if (x==LastCh.x && y==LastCh.y)
			return false;
		if(LastCh.type>=99)
		{
			map[LastCh.x][LastCh.y]=LastCh.type-100;
		}
		map[x][y]+=100;
		LastCh.x=x;
		LastCh.y=y;
		LastCh.type=map[x][y];
		return true;
	}
	return false;
}

////////////////////////////////////////////////////////////////////////
/*
* 函数名称：Updata()
* 函数介绍：游戏状态更新
* 输入参数：无
* 输出参数：bool
* 返回值  ：true 更新成功
*/
bool Managers::Updata()
{
	int k;//暂存更新后的游戏状态
	k=CheckState();//检查状态改变
	if(k==0)
	{
		Game_State = Game_State % 2 + 1;
		if(nKeyDown>=225)
		{
			Game_State=5;
			PAUSE=true;
		}
	}
	//Game_State为3表示游戏结束
	else if(k<0)//黑输了
	{
		Game_State=4;
		PAUSE=true;
	}
	else if(k>0)//黑赢了
	{
		Game_State=3;
		PAUSE=true;
	}
	return true;
}


bool Managers::CheckMap(int x,int y,int pow)
{
	if(map[x][y]==pow || map[x][y]==pow+100 || map[x][y]==pow-100)
		return true;
	return false;
}

////////////////////////////////////////////////////////////////////////
/*
* 函数名称：AddChess(int x,int y,int tpye)
* 函数介绍：增加新棋子到棋盘
* 输入参数：(x,y)一组坐标 type表明是黑棋还是白棋
* 输出参数：bool
* 返回值  ：true 表示响应成功 false为失败
*/
bool Managers::AddChess(int x, int y)
{
	if(CheckMap(x,y,-1))
	{
		map[x][y]=nChessinfo[nKeyDown].type+100;
		if(nKeyDown>0)
			map[nChessinfo[nKeyDown-1].x][nChessinfo[nKeyDown-1].y]-=100;
		nChessinfo[nKeyDown].x=x;
		nChessinfo[nKeyDown].y=y;
		nKeyDown++;
		Updata();
	}
	else
		return false;

	return true;
}
////////////////////////////////////////////////////////////////////////
/*
* 函数名称：AddChess(int x,int y,int tpye)
* 函数介绍：增加新棋子到棋盘
* 输入参数：(x,y)一组坐标 type表明是黑棋还是白棋
* 输出参数：bool
* 返回值  ：true 表示响应成功 false为失败
*/
Chess Managers::GetLastChe()
{
	return nChessinfo[nKeyDown-1];
};

////////////////////////////////////////////////////////////////////////
/*
* 函数名称：GameStart()
* 函数介绍：初始化游戏
* 输入参数：无
* 输出参数：无
* 返回值  ：无
*/
void Managers::GameStart()
{
	int x,y;
	for(x=0;x<15;x++)
		for(y=0;y<15;y++)
			map[x][y]=-1;
	nKeyDown=0;//设置下子为下了0颗子
	PAUSE=false;//游戏没有暂停
	if(Gameinfo%10 ==0 || Gameinfo%100 ==10)//如果本地用户是黑 则先走
		Game_State=1;
	else
		Game_State=2;
	LastCh.type=-1;

}

////////////////////////////////////////////////////////////////////////
/*
* 函数名称：GameBack(int steps)
* 函数介绍：悔棋
* 输入参数：悔棋的步数，默认为2
* 输出参数：bool
* 返回值  ：是否悔棋成功 对不满足的返回false 否则是true
*/
bool Managers::GameBack(int steps)
{
	if(nKeyDown<steps)
		return false;
	int k;
	nKeyDown-=steps;
	for(k=nKeyDown;k<nKeyDown+steps;k++)
		map[nChessinfo[k].x][nChessinfo[k].y ]=-1;
	if(steps%2 == 1)
	{
		Game_State = Game_State%2 +1;//下棋的人改变
	}
	return true;
}

////////////////////////////////////////////////////////////////////////
/*
* 函数名称：CheckState()
* 函数介绍：检查状态
* 输入参数：无
* 输出参数：int
* 返回值  ：0为游戏继续 负数白色赢，正数为黑色赢
*/

int Managers::CheckState()
{
	int n;//分别记录连子个数
	Chess k;//记录棋子的变量
	int i,j;//5个循环变量
	bool check;
	check=false;
	k=GetLastChe();//得到最后一颗下的棋子
	if(k.type==1)//白子情况 检测4个方向 
	{
		for(i=-1;i<=0;i++)
			for(j=-1;j<=1;j++)
				if((i!=0 || j!=0) && (i!=0 || j!=1))
				{
					n=GetNum(k,i,j,false)+GetNum(k,-i,-j,false)+1;//此方向上的连子个数
					if(n>=5)
						return -1;//白色胜利 返回-1
				}
	}
	else	//黑子的情况
	{
		for(i=-1;i<=0;i++)
			for(j=-1;j<=1;j++)
				if((i!=0 || j!=0) && (i!=0 || j!=1))
				{
					n=GetNum(k,i,j,false)+GetNum(k,-i,-j,false)+1;//此方向上的连子个数
					if(n==5)
						return 1;//黑色胜利 返回1
				}
		if(Gameinfo/100 == 0)
			return 0;
		if(ForbidLoc(k))//禁手和 5连同时形成判胜利，所以先判断是否5连
			return -1;
	}
	return 0;//什么改变也没有 返回0
}
////////////////////////////////////////////////////////////////////////
/*
* 函数名称：GetNum(Chess nCh,int i, int j,bool goon)
* 函数介绍：求连子个数
* 输入参数：nCh 要求的棋子 i j为一组方向 goon是一个开关表示是否计算断开连接点
* 输出参数：int
* 返回值  ：连子数
*/
int Managers::GetNum(Chess nCh,int i, int j,bool goon)
{
	int t,x,y;
	x=nCh.x+i;
	y=nCh.y+j;
	t=0;//t记录连子个数
	if (nCh.type>=99)
		nCh.type-=100;
	while(x>=0 && y>=0 && x<15 && y < 15 && CheckMap(x,y,nCh.type))
	{
		x+=i;
		y+=j;
		t++;
	}
	if(goon && CheckMap(x,y,-1) && x>=0 && y>=0 && x<15 && y < 15 && CheckMap(x+i,y+j,nCh.type))//计算断开的接点问题
	{
		Chess nc;
		nc.type=nCh.type;
		nc.x=x;
		nc.y=y;
		x=GetNum(nc,i,j,false);
		if (x!=0)
			t+=x+100;//加上100用于区别是否有间断，这个在追踪是否有阻拦时用到
	}
	return t;
}
////////////////////////////////////////////////////////////////////////
/*
* 函数名称：ForbidLoc(Chess k)
* 函数介绍：判断棋子k是否形成禁手
* 输入参数：k 需要判断的棋子
* 输出参数：bool
* 返回值  ：形成返回true,否则返回false
*/
bool Managers::ForbidLoc(Chess k)
{	int i,j,l,m;//循环变量
	int n1,n2,n3,n4,n;
	int t1,t2,t3,t4;//记录
	//由于黑子先走 不能走双3 双4 以及4、3、3 所以判断相对复杂
	for(i=-1;i<=0;i++)
		for(j=-1;j<=1;j++)
			if((i!=0 || j!=0) && (j!=1 || i!=0))
			{
				n1=GetNum(k,i,j,true);
				n2=GetNum(k,-i,-j,false);

				t1=GetNum(k,i,j,false);
				t2=GetNum(k,-i,-j,false);
				//判断实连子数,确定是否形成长连禁手
				if(t1+t2+1>5)
					return true;
				t1=GetNum(k,i,j,false);
				t2=GetNum(k,-i,-j,true);
			reCheck://重新判断 由于两边取舍的不同
				n=n1%100+n2%100+1;//求总连子数
				if(n%100==4)//判断是否构成双4
				{
					if(!CheckMap(k.x+i*(n1%100+1+n1/100),k.y+j*(n1+1),-1) &&  
 !CheckMap(k.x-i*(n2%100+1+n2/100),k.y-j*(n2%100+1+n2/100),-1))
						goto checkk;//如果4个棋子两边都被堵死则决不可能是双4 
					//但由于由于有4、3、3禁手的存在 所有如果没构成双4的 也要判断是否同时构成双3
					for(m=-1;m<=0;m++)
						for(l=-1;l<=1;l++)
							if((m!=i || l!=j) && (l!=1 || m!=0) && (m!=0 || l!=0))
							{
								n3=GetNum(k,m,l,true);
								n4=GetNum(k,-m,-l,false);
								t3=GetNum(k,m,l,false);
								t4=GetNum(k,-m,-l,true);
							reCheck44:
								if(n3%100+n4%100+1 == 4 && 
(CheckMap(k.x+m*(n3%100+1+n3/100),k.y+l*(n3%100+1+n3/100),-1) ||
 CheckMap(k.x-m*(n4%100+1+n4/100),k.y-l*(n4%100+1+n4/100),-1)))
									return true;//到此 双4成立
								if(n3!=t3 || n4!=t4)
								{
									n3=t3;
									n4=t4;
									goto reCheck44;
								}
								
							}
				}
				else if(n%100==3)//判断是否构成双3
				{
					if(!CheckMap(k.x+i*(n1%100+1+n1/100),k.y+j*(n1%100+1+n1/100),-1)||
 !CheckMap(k.x-i*(n2%100+1+n2/100),k.y-j*(n2%100+1+n2/100),-1))
						goto checkk;//如果3个棋子任意一边被堵死则决不可能是双3
					for(m=-1;m<=0;m++)
						for(l=-1;l<=1;l++)
							if((m!=i || l!=j) && (l!=1 || m!=0) && (m!=0 || l!=0))
							{
								n3=GetNum(k,m,l,true);
								n4=GetNum(k,-m,-l,false);
								t3=GetNum(k,m,l,false);
								t4=GetNum(k,-m,-l,true);
							reCheck33:
								if(n3%100+n4%100+1 == 3 &&
CheckMap(k.x+m*(n3%100+1+n3/100),k.y+l*(n3%100+1),-1) &&
 CheckMap(k.x-m*(n4%100+1+n4/100),k.y-l*(n4%100+1+n4/100),-1))
									return true;//到此 双3成立
								if(n3!=t3 || n4!=t4)
								{
									n3=t3;
									n4=t4;
									goto reCheck33;
								}						
							}
				}
			checkk:
				if(t1!=n1 || t2!=n2)//如果两边取舍不同造成结果不一致 则用新值重新判断
				{
					n1=t1;
					n2=t2;
					goto reCheck;
				}
			}
	return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
* 函数名称：GameType(int t)
* 函数介绍：改变游戏设置
* 输入参数：t 就是playerinfo
* 输出参数：bool
* 返回值  ：true表示成功 false表示失败
*/

bool Managers::GameType(int t)
{
	if(t%10>1)
		return false;
	if(t%100>11)
		return false;
	if(t>111)
		return false;
	int Playerinfo=t;
	return true;
}

