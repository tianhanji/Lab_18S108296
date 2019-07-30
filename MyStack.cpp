// MyStack.cpp: implementation of the MyStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WeiQ1_0.h"
#include "MyStack.h"
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
MyStack::MyStack()
{
	head=0;
	size=0;
}

MyStack::~MyStack()
{

}

void MyStack::init()
{
	head=0;
	size=0;
}

bool MyStack::isEmpty()
{
	return size==0;
}

void MyStack::push(_state *s)
{
	_statenode* temp=new _statenode;
	temp->next=0;
	temp->s=*s;
	if(isEmpty())
	{
		head = temp;
		size++;
	}
	else
	{
		temp->next = head;
		head = temp;
		size++;
	}
}

_state* MyStack::pop()
{
	if(isEmpty())
	{
		cerr<<"isEmpty!"<<endl;
		return 0;
	}
	else
	{
		_statenode* temp=head;
		_state* ret=new _state;
		head=head->next;
		temp->next=0;
		size--;
		ret=&temp->s;
		return ret;
	}
}

void MyStack::print()
{
	_statenode* temp = head;
	while(temp!=0)
	{
		cout<<temp->s.x<<"\t"<<temp->s.y<<endl;
		temp=temp->next;
	}
}
