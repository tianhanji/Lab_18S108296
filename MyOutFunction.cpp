// MyOutFunction.cpp: implementation of the MyOutFunction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WeiQ1_0.h"
#include "MyOutFunction.h"
#include <fstream>
using namespace std;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MyOutFunction::MyOutFunction()
{

}

MyOutFunction::~MyOutFunction()
{

}

bool MyOutFunction::isLive(int go[][21], int x, int y, int color)
{
	if(color==0)return true;
	MyStack stack;
	stack.init();
	int now_x,now_y;//当前位置
	int i,j;
	int end=0;
	_state now_go[21][21]; //棋盘的具体布局状态
	_state* temp=new _state;//临时存储某些状态
	int deadnum=0;
	//初始化now_go
	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			now_go[i][j]=*creatState(i,j,go[i][j],0,0,0);
		}
	}
	now_go[x][y]=*creatState(x,y,color,1,1,0);
	now_x=x;
	now_y=y;
	stack.push(&now_go[x][y]);
	do
	{
		//stack.pop();
		if(isTong(now_go,now_x,now_y,end)==true)
		{
			if(end==1)return true;//找到出口，返回
			else//找到同类，将同类修改为合适的状态入栈代替自己
			{
				now_go[now_x][now_y].footprint=1;
				now_go[now_x][now_y].fangxiang=1;
				stack.push(&now_go[now_x][now_y]);
			}
		}
		else if(!stack.isEmpty())
		{
			now_go[now_x][now_y]=*stack.pop();
			now_go[now_x][now_y].fangxiang++;

			if(now_go[now_x][now_y].fangxiang<5)//还有方向没有去试探
			{
				stack.push(&now_go[now_x][now_y]);//重新压回栈中以便继续查找另一个方向
			}
			else
			{
				now_go[now_x][now_y].dead=1;//标记该点状态可能已死
				deadnum++;
				if(!stack.isEmpty())
				{
					temp=stack.pop();//从栈中取元素，以更新now_x,now_y;
					now_x=temp->x;
					now_y=temp->y;
					stack.push(&now_go[now_x][now_y]);
				}
			}
		}
				
	}while(!stack.isEmpty());
	
	for( i=1;i<20;i++)
	{
		for( j=1;j<20;j++)
		{
			if(now_go[i][j].dead==1)
			{
				if(deadnum==1)
				{
					go[i][j]=4;//标志此处棋子被吃，且有可能不能立即下子,为了检测打劫禁手
				}
				else
				{
					go[i][j]=0;
				}
			}
				
		}
	}
	return false;
}

bool MyOutFunction::isTong(_state go[][21], int &x, int &y, int &end)
{
	if(go[x][y].fangxiang==1)
	{
		if(go[x+1][y].footprint==1)
		{
			end=0;
			return false;
		}
		else if(go[x+1][y].color==0||go[x+1][y].color==4)
		{
			end=1;
			return true;
		}
		else if(go[x][y].color==go[x+1][y].color)
		{
			end=0;
			x=x+1;//找到同类，则将让同类去寻找能否走出，自己先等着
			return true;
		}
		else
		{
			end=0;
			return false;
		}
	}
	else if(go[x][y].fangxiang==2)
	{
		if(go[x-1][y].footprint==1)
		{
			end=0;
			return false;
		}
		else if(go[x-1][y].color==0||go[x-1][y].color==4)
		{
			end=1;
			return true;
		}
		else if(go[x][y].color==go[x-1][y].color)
		{
			x=x-1;
			end=0;
			return true;
		}
		else
		{
			end=0;
			return false;
		}
	}
	else if(go[x][y].fangxiang==3)
	{
		if(go[x][y+1].footprint==1)
		{
			end=0;
			return false;
		}
		else if(go[x][y+1].color==0||go[x][y+1].color==4)
		{
			end=1;
			return true;
		}
		else if(go[x][y].color==go[x][y+1].color)
		{
			y=y+1;
			end=0;
			return true;
		}
		else
		{
			end=0;
			return false;
		}
	}
	else if(go[x][y].fangxiang==4)
	{
		if(go[x][y-1].footprint==1)
		{
			end=0;
			return false;
		}
		else if(go[x][y-1].color==0||go[x][y-1].color==4)
		{
			end=1;
			return true;
		}
		else if(go[x][y].color==go[x][y-1].color)
		{
			y=y-1;
			end=0;
			return true;
		}
		else
		{
			end=0;
			return false;
		}
	}
	else 
	{
		end=0;
		return false;
	}
}

_state* MyOutFunction::creatState(int x, int y, int color, int fangxiang, int footprint, int dead)
{
	_state* ret=new _state;
	ret->x=x;
	ret->y=y;
	ret->color=color;
	ret->fangxiang=fangxiang;
	ret->footprint=footprint;
	ret->dead=dead;
	return ret;
}

bool MyOutFunction::moni(int qiju[][21], MyList list)
{
	//初始化棋局
	for(int i=1;i<20;i++)
	{
		for(int j=1;j<20;j++)
		{
			qiju[i][j]=0;
		}
	}
	for(int k=0;k<21;k++)
	{
		qiju[0][k]=3;
		qiju[20][k]=3;
		qiju[k][0]=3;
		qiju[k][20]=3;
	}
	_node* temp=list.head;
	bool lefteat,righteat,upeat,downeat;
	int x,y,color;
	while(list.now&&temp!=list.now->next)
	{
		//下面判断此处能不能放棋子；
		x=temp->data.p_x;
		y=temp->data.p_y;
		color=temp->data.color;
		qiju[x][y]=color;
		//能否吃掉右邻的他方棋子,若能吃，就吃掉，所以直接用了pDoc->m_qiju
		righteat=((x+1!=20)&&(qiju[x+1][y]!=color)
					&&(!MyOutFunction::isLive(qiju,x+1,y,qiju[x+1][y])));
		lefteat=((x-1!=0)&&(qiju[x-1][y]!=color)
					&&(!MyOutFunction::isLive(qiju,x-1,y,qiju[x-1][y])));
		upeat=((y+1!=20)&&(qiju[x][y+1]!=color)
					&&(!MyOutFunction::isLive(qiju,x,y+1,qiju[x][y+1])));
		downeat=((y-1!=0)&&(qiju[x][y-1]!=color)
					&&(!MyOutFunction::isLive(qiju,x,y-1,qiju[x][y-1])));
		temp=temp->next;
	}
	return true;
}

void MyOutFunction::initQiju(int qiju[][21])//初始化棋局，边界设为3,其余设为0
{
	for(int i=1;i<20;i++)
	{
		for(int j=1;j<20;j++)
		{
			qiju[i][j]=0;
		}
	}
	for(int k=0;k<21;k++)
	{
		qiju[0][k]=3;
		qiju[20][k]=3;
		qiju[k][0]=3;
		qiju[k][20]=3;
	}
}

bool MyOutFunction::readQipu(MyList &list, char *fileName)//从棋谱文件中读出文件
{
	return true;
}

char* MyOutFunction::_CStringToChars(CString string )
{
	int leng=string.GetLength();
	char* ret=new char[leng+1];
	for(int i=0;i<leng;i++)
	{
		ret[i]=string.GetAt(i);
	}
	ret[leng]='\0';
	return ret;
}



bool MyOutFunction::saveQipu(MyList list, char *fileName)
{
			return true;
}
