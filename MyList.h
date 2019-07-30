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
	int p_x;	//x坐标，1-19间的整数
	int p_y;	//y坐标，1-19间的整数
	int color;	//所放棋子颜色，1为黑，2为白
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
	//根据函数format定义的格式遍历链表，step记录结点遍历到了第几个结点
	void printList(void(*format)(void* e,void* steptag),int step);
	void del();//删除链表最后一个元素
	void clearList();
	bool searchele(int x, int y);

};

#endif // !defined(AFX_MYLIST_H__F0A0868E_B92A_46C5_AE26_53BE75B301FF__INCLUDED_)
