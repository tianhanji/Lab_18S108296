// MyStack.h: interface for the MyStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSTACK_H__D03D6F7A_762C_4F7C_8C8D_315E27AC8B7C__INCLUDED_)
#define AFX_MYSTACK_H__D03D6F7A_762C_4F7C_8C8D_315E27AC8B7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct _state//保存棋盘中每个格子的临时状态，以判别处于该位置的棋子是否能存活
{
	int x;//在棋盘中的横坐标
	int y;//在棋盘中的纵坐标
	int fangxiang;//从此格子走向下一格子的方向--1：向右走，2:向左走，3：向上走，4：向下走
	int color;//此棋子的性质；0：没有棋子，1：黑子，2：白子,3:边界
	int footprint;//是否来过试探过这颗棋子；1：是，0：否
	int dead;//处于此格子的棋子可能死亡
};

struct _statenode
{
	_state s;
	_statenode* next;
};

class MyStack
{
public:
	_statenode* head;
	int size;//堆栈大小
	MyStack();
	virtual ~MyStack();
	void init();
	void push(_state* s);
	_state* pop();
	bool isEmpty();
	void print();
};

#endif // !defined(AFX_MYSTACK_H__D03D6F7A_762C_4F7C_8C8D_315E27AC8B7C__INCLUDED_)
