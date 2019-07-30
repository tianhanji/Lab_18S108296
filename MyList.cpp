// MyList.cpp: implementation of the MyList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WeiQ1_0.h"
#include "MyList.h"

#include <iostream>
using namespace std;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MyList::MyList()
{
	head=0;
	tail=0;
	now=0;
	size=0;
}

MyList::~MyList()
{

}

bool MyList::isEmpty()
{
	if(size==0)
		return true;
	return false;
}
void MyList::add(_node* newNode)
{
	while(tail!=now)
	{
		del();
	}
	if(isEmpty())
	{
		head = newNode;
	}
	else
	{
		newNode->pre = tail;
		tail->next = newNode;
	}
	tail = newNode;
	now=tail;
	size++;
}

void MyList::add(int x, int y,int color)
{
	_node* newNode=new _node;
	newNode->data.p_x = x;
	newNode->data.p_y = y;
	newNode->data.color=color;
	newNode->next = 0;
	newNode->pre =0;
	add(newNode);
}

void MyList::del()
{
	if(isEmpty())
	{
		TRACE("没有元素可以删除!\n");
		exit(1);
	}
	else if(size==1)
	{
		tail=0;
		head=0;
		size=0;
		now=0;
	}
	else if(now==tail)
	{
		tail->pre->next=0;
		tail=tail->pre;
		now=tail;
		size--;
	}
	else
	{
		tail->pre->next=0;
		tail=tail->pre;
		size--;
	}
	
}

bool MyList::searchele(int x, int y)
{
	/*_node* temp=head;
	for(int i=0;i<size;i++)
	{
		if((temp->data.p_x == x)&&(temp->data.p_y == y))
		{
			return true;
		}
		temp=temp->next;
	}*/
	return false;
}

void MyList::printList()
{

}

void MyList::printList(void(*format)(void* e,void* steptag),int step)
{

}

void MyList::clearList()
{
	while(size)
	{
		del();
	}
}


void MyList::init()
{
	head=0;
	tail=0;
	now=0;
	size=0;
}
