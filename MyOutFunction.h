// MyOutFunction.h: interface for the MyOutFunction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYOUTFUNCTION_H__D5B922EC_4A2A_4CE7_9FF7_A1CF9EC45959__INCLUDED_)
#define AFX_MYOUTFUNCTION_H__D5B922EC_4A2A_4CE7_9FF7_A1CF9EC45959__INCLUDED_

#if _MSC_VER > 1000

#include "MyStack.h"
#include "MyList.h"
#include "MyOutFunction.h"

#pragma once
#include <string>
using namespace std;
#endif // _MSC_VER > 1000

class MyOutFunction  
{
public:
	static bool saveQipu(MyList list,char* fileName);
	static char* _CStringToChars(CString string );
	static bool readQipu(MyList& list, char* fileName);
	static void initQiju(int qiju[21][21]);
	static bool moni(int qiju[21][21], MyList list);
	static _state* creatState(int x,int y,int color,int fangxiang,int footprint, int dead);//创建一颗棋子
	static bool isTong(_state go[21][21],int& x,int& y,int& end);//判断处于该格子的棋子按某个方向能否走出该格子
	//判断go[x][y]能否存活，若不能存活，则将和go[x][y]一起不能存活的子消掉
	static bool isLive(int go[21][21],int x, int y, int color);
	MyOutFunction();
	virtual ~MyOutFunction();

};

#endif // !defined(AFX_MYOUTFUNCTION_H__D5B922EC_4A2A_4CE7_9FF7_A1CF9EC45959__INCLUDED_)
