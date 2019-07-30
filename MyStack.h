// MyStack.h: interface for the MyStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSTACK_H__D03D6F7A_762C_4F7C_8C8D_315E27AC8B7C__INCLUDED_)
#define AFX_MYSTACK_H__D03D6F7A_762C_4F7C_8C8D_315E27AC8B7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct _state//����������ÿ�����ӵ���ʱ״̬�����б��ڸ�λ�õ������Ƿ��ܴ��
{
	int x;//�������еĺ�����
	int y;//�������е�������
	int fangxiang;//�Ӵ˸���������һ���ӵķ���--1�������ߣ�2:�����ߣ�3�������ߣ�4��������
	int color;//�����ӵ����ʣ�0��û�����ӣ�1�����ӣ�2������,3:�߽�
	int footprint;//�Ƿ�������̽��������ӣ�1���ǣ�0����
	int dead;//���ڴ˸��ӵ����ӿ�������
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
	int size;//��ջ��С
	MyStack();
	virtual ~MyStack();
	void init();
	void push(_state* s);
	_state* pop();
	bool isEmpty();
	void print();
};

#endif // !defined(AFX_MYSTACK_H__D03D6F7A_762C_4F7C_8C8D_315E27AC8B7C__INCLUDED_)
