// MyList.h: interface for the MyList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYLIST_H__F0A0868E_B92A_46C5_AE26_53BE75B301FF__INCLUDED_)
#define AFX_MYLIST_H__F0A0868E_B92A_46C5_AE26_53BE75B301FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


struct point
{
	int p_x;	//x���꣬1-19�������
	int p_y;	//y���꣬1-19�������
	int color;	//����������ɫ��1Ϊ�ڣ�2Ϊ��
};


struct _node
{
	point data;
	_node* next;
	_node* pre;
};



class MyList  
{
public:
	void init();
	MyList();
	virtual ~MyList();

	_node* head;
	_node* now;
	_node* tail;
	int size;

	void add(_node* newNode);
	void add(int x, int y,int color);
	bool isEmpty();
	void printList();
	//���ݺ���format����ĸ�ʽ��������step��¼���������˵ڼ������
	void printList(void(*format)(void* e,void* steptag),int step);
	void del();//ɾ���������һ��Ԫ��
	void clearList();
	bool searchele(int x, int y);

};

#endif // !defined(AFX_MYLIST_H__F0A0868E_B92A_46C5_AE26_53BE75B301FF__INCLUDED_)
