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
	Gameinfo=100;//Ĭ��Ϊ ��-�� ��ս	�����жϽ���
	for(x=0;x<15;x++)
		for(y=0;y<15;y++)
		{
			map[x][y]=-1;//��ʼ������
		}
}


Managers::~Managers()
{

}
////////////////////////////////////////////////////////////////////////
/*
* �������ƣ�DoMSG(	CPiont pt   //��������
					int action)	//��Ϊ
* �������ܣ���Ϣ��Ӧ
* ���������action���� 0Ϊ��꾭�� 1Ϊ�������  2Ϊ�����Ҽ�
* ���������bool
* ����ֵ  ��true ��ʾ��Ӧ�ɹ� falseΪʧ��
*/

bool Managers::DoMsg(int x,int y, int action)
{
if(Game_State >2 || Game_State <1)
		return false;
	if(action==2)//�Ҽ���ӦΪû���κη�Ӧ
		return false;
	if(action==1)//�����Ӧ����
	{
		//����Ϸ״̬��Player1����� ��-�� ��սʱ������Ӧ����
		if(	((Gameinfo%100)/10 == 0 || Game_State==1) && AddChess(x,y))//�������������
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
* �������ƣ�Updata()
* �������ܣ���Ϸ״̬����
* �����������
* ���������bool
* ����ֵ  ��true ���³ɹ�
*/
bool Managers::Updata()
{
	int k;//�ݴ���º����Ϸ״̬
	k=CheckState();//���״̬�ı�
	if(k==0)
	{
		Game_State = Game_State % 2 + 1;
		if(nKeyDown>=225)
		{
			Game_State=5;
			PAUSE=true;
		}
	}
	//Game_StateΪ3��ʾ��Ϸ����
	else if(k<0)//������
	{
		Game_State=4;
		PAUSE=true;
	}
	else if(k>0)//��Ӯ��
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
* �������ƣ�AddChess(int x,int y,int tpye)
* �������ܣ����������ӵ�����
* ���������(x,y)һ������ type�����Ǻ��廹�ǰ���
* ���������bool
* ����ֵ  ��true ��ʾ��Ӧ�ɹ� falseΪʧ��
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
* �������ƣ�AddChess(int x,int y,int tpye)
* �������ܣ����������ӵ�����
* ���������(x,y)һ������ type�����Ǻ��廹�ǰ���
* ���������bool
* ����ֵ  ��true ��ʾ��Ӧ�ɹ� falseΪʧ��
*/
Chess Managers::GetLastChe()
{
	return nChessinfo[nKeyDown-1];
};

////////////////////////////////////////////////////////////////////////
/*
* �������ƣ�GameStart()
* �������ܣ���ʼ����Ϸ
* �����������
* �����������
* ����ֵ  ����
*/
void Managers::GameStart()
{
	int x,y;
	for(x=0;x<15;x++)
		for(y=0;y<15;y++)
			map[x][y]=-1;
	nKeyDown=0;//��������Ϊ����0����
	PAUSE=false;//��Ϸû����ͣ
	if(Gameinfo%10 ==0 || Gameinfo%100 ==10)//��������û��Ǻ� ������
		Game_State=1;
	else
		Game_State=2;
	LastCh.type=-1;

}

////////////////////////////////////////////////////////////////////////
/*
* �������ƣ�GameBack(int steps)
* �������ܣ�����
* �������������Ĳ�����Ĭ��Ϊ2
* ���������bool
* ����ֵ  ���Ƿ����ɹ� �Բ�����ķ���false ������true
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
		Game_State = Game_State%2 +1;//������˸ı�
	}
	return true;
}

////////////////////////////////////////////////////////////////////////
/*
* �������ƣ�CheckState()
* �������ܣ����״̬
* �����������
* ���������int
* ����ֵ  ��0Ϊ��Ϸ���� ������ɫӮ������Ϊ��ɫӮ
*/

int Managers::CheckState()
{
	int n;//�ֱ��¼���Ӹ���
	Chess k;//��¼���ӵı���
	int i,j;//5��ѭ������
	bool check;
	check=false;
	k=GetLastChe();//�õ����һ���µ�����
	if(k.type==1)//������� ���4������ 
	{
		for(i=-1;i<=0;i++)
			for(j=-1;j<=1;j++)
				if((i!=0 || j!=0) && (i!=0 || j!=1))
				{
					n=GetNum(k,i,j,false)+GetNum(k,-i,-j,false)+1;//�˷����ϵ����Ӹ���
					if(n>=5)
						return -1;//��ɫʤ�� ����-1
				}
	}
	else	//���ӵ����
	{
		for(i=-1;i<=0;i++)
			for(j=-1;j<=1;j++)
				if((i!=0 || j!=0) && (i!=0 || j!=1))
				{
					n=GetNum(k,i,j,false)+GetNum(k,-i,-j,false)+1;//�˷����ϵ����Ӹ���
					if(n==5)
						return 1;//��ɫʤ�� ����1
				}
		if(Gameinfo/100 == 0)
			return 0;
		if(ForbidLoc(k))//���ֺ� 5��ͬʱ�γ���ʤ�����������ж��Ƿ�5��
			return -1;
	}
	return 0;//ʲô�ı�Ҳû�� ����0
}
////////////////////////////////////////////////////////////////////////
/*
* �������ƣ�GetNum(Chess nCh,int i, int j,bool goon)
* �������ܣ������Ӹ���
* ���������nCh Ҫ������� i jΪһ�鷽�� goon��һ�����ر�ʾ�Ƿ����Ͽ����ӵ�
* ���������int
* ����ֵ  ��������
*/
int Managers::GetNum(Chess nCh,int i, int j,bool goon)
{
	int t,x,y;
	x=nCh.x+i;
	y=nCh.y+j;
	t=0;//t��¼���Ӹ���
	if (nCh.type>=99)
		nCh.type-=100;
	while(x>=0 && y>=0 && x<15 && y < 15 && CheckMap(x,y,nCh.type))
	{
		x+=i;
		y+=j;
		t++;
	}
	if(goon && CheckMap(x,y,-1) && x>=0 && y>=0 && x<15 && y < 15 && CheckMap(x+i,y+j,nCh.type))//����Ͽ��Ľӵ�����
	{
		Chess nc;
		nc.type=nCh.type;
		nc.x=x;
		nc.y=y;
		x=GetNum(nc,i,j,false);
		if (x!=0)
			t+=x+100;//����100���������Ƿ��м�ϣ������׷���Ƿ�������ʱ�õ�
	}
	return t;
}
////////////////////////////////////////////////////////////////////////
/*
* �������ƣ�ForbidLoc(Chess k)
* �������ܣ��ж�����k�Ƿ��γɽ���
* ���������k ��Ҫ�жϵ�����
* ���������bool
* ����ֵ  ���γɷ���true,���򷵻�false
*/
bool Managers::ForbidLoc(Chess k)
{	int i,j,l,m;//ѭ������
	int n1,n2,n3,n4,n;
	int t1,t2,t3,t4;//��¼
	//���ں������� ������˫3 ˫4 �Լ�4��3��3 �����ж���Ը���
	for(i=-1;i<=0;i++)
		for(j=-1;j<=1;j++)
			if((i!=0 || j!=0) && (j!=1 || i!=0))
			{
				n1=GetNum(k,i,j,true);
				n2=GetNum(k,-i,-j,false);

				t1=GetNum(k,i,j,false);
				t2=GetNum(k,-i,-j,false);
				//�ж�ʵ������,ȷ���Ƿ��γɳ�������
				if(t1+t2+1>5)
					return true;
				t1=GetNum(k,i,j,false);
				t2=GetNum(k,-i,-j,true);
			reCheck://�����ж� ��������ȡ��Ĳ�ͬ
				n=n1%100+n2%100+1;//����������
				if(n%100==4)//�ж��Ƿ񹹳�˫4
				{
					if(!CheckMap(k.x+i*(n1%100+1+n1/100),k.y+j*(n1+1),-1) &&  
 !CheckMap(k.x-i*(n2%100+1+n2/100),k.y-j*(n2%100+1+n2/100),-1))
						goto checkk;//���4���������߶������������������˫4 
					//������������4��3��3���ֵĴ��� �������û����˫4�� ҲҪ�ж��Ƿ�ͬʱ����˫3
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
									return true;//���� ˫4����
								if(n3!=t3 || n4!=t4)
								{
									n3=t3;
									n4=t4;
									goto reCheck44;
								}
								
							}
				}
				else if(n%100==3)//�ж��Ƿ񹹳�˫3
				{
					if(!CheckMap(k.x+i*(n1%100+1+n1/100),k.y+j*(n1%100+1+n1/100),-1)||
 !CheckMap(k.x-i*(n2%100+1+n2/100),k.y-j*(n2%100+1+n2/100),-1))
						goto checkk;//���3����������һ�߱����������������˫3
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
									return true;//���� ˫3����
								if(n3!=t3 || n4!=t4)
								{
									n3=t3;
									n4=t4;
									goto reCheck33;
								}						
							}
				}
			checkk:
				if(t1!=n1 || t2!=n2)//�������ȡ�᲻ͬ��ɽ����һ�� ������ֵ�����ж�
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
* �������ƣ�GameType(int t)
* �������ܣ��ı���Ϸ����
* ���������t ����playerinfo
* ���������bool
* ����ֵ  ��true��ʾ�ɹ� false��ʾʧ��
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

