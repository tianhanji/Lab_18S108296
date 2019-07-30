// WeiQ1_0View.cpp : implementation of the CWeiQ1_0View class
//

#include "stdafx.h"
#include "WeiQ1_0.h"

#include "WeiQ1_0Doc.h"
#include "WeiQ1_0View.h"
#include "MainFrm.h"
#include "stdlib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0View

IMPLEMENT_DYNCREATE(CWeiQ1_0View, CView)

BEGIN_MESSAGE_MAP(CWeiQ1_0View, CView)
	//{{AFX_MSG_MAP(CWeiQ1_0View)
	ON_WM_LBUTTONDOWN()
	//ON_COMMAND(ID_BACK, OnBack)
	//ON_COMMAND(ID_RECOVERY, OnRecovery)
	//ON_COMMAND(ID_HEAD, OnHead)
	//ON_COMMAND(ID_TAIL, OnTail)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	//ON_UPDATE_COMMAND_UI(ID_BACK, OnUpdateBack)
	//ON_UPDATE_COMMAND_UI(ID_RECOVERY, OnUpdateRecovery)
	//ON_UPDATE_COMMAND_UI(ID_HEAD, OnUpdateHead)
	//ON_UPDATE_COMMAND_UI(ID_TAIL, OnUpdateTail)
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0View construction/destruction

CWeiQ1_0View::CWeiQ1_0View()
{
	// TODO: add construction code here

}

CWeiQ1_0View::~CWeiQ1_0View()
{
}

BOOL CWeiQ1_0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0View drawing


//#define CATCH_CONFIG_MAIN
//
//#include <E:\Catch2-master\include\catch.hpp>
//TEST_CASE("Test with number big than 0", "[tag1]")
//{
//	REQUIRE(Factorial(2) == 2);
//	// REQUIRE((Factorial(3) == 6) && (Factorial(4) == 24)); cannot compile
//	CHECK(Factorial(0) == 1);
//	REQUIRE((Factorial(3) == 6 && Factorial(4) == 24));
//}



void CWeiQ1_0View::OnDraw(CDC* pDC)
{
	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	_node* temp=new _node;//用于遍历链表
	CPoint top_left=pDoc->m_topleft;
	int space=pDoc->m_space;
	int radius=pDoc->m_radius;
	COLORREF bkcolor=pDoc->m_bkcolor;
	// TODO: add draw code for native data here
	DrawChessboard(pDC,top_left,bkcolor,space,radius);
	//画棋盘上的棋子
	temp=pDoc->m_historylist.head;
	int i,j;//循环变量。
	CString str;//用于将每一步棋的走法打印出来
	int stepnum=0;
	for(i=1;i<20;i++)
	{
		for(j=1;j<20;j++)
		{
			if(pDoc->m_qiju[i][j] ==1)
			{
				pDC->SelectStockObject(BLACK_BRUSH);
				pDC->Ellipse(top_left.x + (i-1) * space - space/2,
						 top_left.y + (j-1) * space - space/2,
						 top_left.x + (i-1) * space + space/2,
						 top_left.y + (j-1) * space + space/2 );
			}
			else if(pDoc->m_qiju[i][j]==2)
			{
				pDC->SelectStockObject(WHITE_BRUSH);//白子
				pDC->Ellipse(top_left.x + (i-1) * space - space/2,
						 top_left.y + (j-1) * space - space/2,
						 top_left.x + (i-1) * space + space/2,
						 top_left.y + (j-1) * space + space/2 );
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0View printing

BOOL CWeiQ1_0View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWeiQ1_0View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWeiQ1_0View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0View diagnostics

#ifdef _DEBUG
void CWeiQ1_0View::AssertValid() const
{
	CView::AssertValid();
}

void CWeiQ1_0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeiQ1_0Doc* CWeiQ1_0View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeiQ1_0Doc)));
	return (CWeiQ1_0Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0View message handlers
//绘制棋盘，top_left：左上角,bkcolor：背景颜色,space：格子大小,radius：棋盘中特殊点的大小
void CWeiQ1_0View::DrawChessboard(CDC* pDC,CPoint top_left, COLORREF bkcolor, int space, int radius)
{
	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int i,j;
	CString strx,stry;
	strx.Format("ABCDEFGHIJKLMNOPQRS");
	for( i=0 ; i<19 ; i++ )
	{
		if(i+1<=9)
			stry.Format("0%d",i+1);//垂直格式
		else
			stry.Format("%d",i+1);
		pDC->TextOut( top_left.x+space*i-3 , top_left.y-30 , strx[i] );//水平ABCD输出
		pDC->TextOut( top_left.x-space/2-20 , top_left.y+space*i-7 ,stry);//竖直0102输出
	}
	COLORREF color=pDC->GetBkColor();//保存背景颜色

	pDC->FillSolidRect( top_left.x-space/2 , top_left.y-space/2 , space*19 , space*19 , bkcolor );
	
	pDC->SetBkColor(color);//恢复背景颜色

	for( i=0 ; i<19 ; i++ )
	{
		pDC->MoveTo( top_left.x , top_left.y + i*space );
	    pDC->LineTo( top_left.x + 18*space , top_left.y + i*space );

		pDC->MoveTo( top_left.x , top_left.y + i*space );
	    pDC->LineTo( top_left.x + 18*space , top_left.y + i*space );  
	}
    for( i=0 ; i<19 ; i++ )
	{
		pDC->MoveTo(top_left.x+space*i,top_left.y);
		pDC->LineTo( top_left.x + space*i , top_left.y + space*18 );
	}
	pDC->SelectStockObject(BLACK_BRUSH);
	for( i=0 ; i<3 ; i++ )
		for(j=0;j<3;j++)
			pDC->Ellipse(top_left.x + space*3 + space*6*i - radius ,
						 top_left.y + space*3 + space*6*j - radius ,
						 top_left.x + space*3 + space*6*i + radius ,
						 top_left.y + space*3 + space*6*j + radius );
}
	

void CWeiQ1_0View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CPoint top_left=pDoc->m_topleft;//左上角的点
	int space=pDoc->m_space;
	int x,y;//用于保存鼠标左键点击的位置
	int i=0,j=0;//迭代变量
	int color;//保存此步棋是黑方还是白方
	bool lefteat,righteat,upeat,downeat;
	int qiju[21][21];//
	int jinshou[21][21];//保存包含禁手标志的棋局
	//如果落点不在有效的范围内，返回
	if( point.x < top_left.x - space/2 ||
		point.x > top_left.x + 18*space + space/2 ||
		point.y < top_left.y - space/2 ||
		point.y > top_left.y + 18*space + space/2 )
	{
		TRACE("无效的落子。\n");				
		return ;    
	}
	//计算出落子点的位置,棋盘左上角的点的位置为(1,1)
	x=(point.x+space/2-top_left.x)/space+1;
	y=(point.y+space/2-top_left.y)/space+1;
	if(pDoc->m_qiju[x][y]==4)//为打劫禁手或者会被对方吃掉
	{
		//::AfxMessageBox("不能落子!");
	}
	else
	{
		//将所有被记为4的元素恢复为0
		for(int i=1;i<20;i++)
		{
			for(int j=1;j<20;j++)
			{
				jinshou[i][j]=pDoc->m_qiju[i][j];//把带有禁手标志的棋局保存下来
				if(pDoc->m_qiju[i][j]==4)
				{
					pDoc->m_qiju[i][j]=0;
				}
			}
		}

		//下面是在确定了不会出现打劫禁手的情况下做出的判断
		if(pDoc->m_qiju[x][y]==0)//该位置没有被棋子占据
		{
			if(pDoc->m_historylist.isEmpty()||pDoc->m_historylist.now==0
				||pDoc->m_historylist.now->data.color==2)//还没有下棋，或者上一着是白方下的
			{
				color=1;
			}
			else
			{
				color=2;
			}
			//下面判断此处能不能放棋子；
			pDoc->m_qiju[x][y]=color;//先放进去试一试	
			//能否吃掉右邻的他方棋子,若能吃，就吃掉，所以直接用了pDoc->m_qiju
			righteat=((x+1!=20)&&(pDoc->m_qiju[x+1][y]!=color)
						&&(!MyOutFunction::isLive(pDoc->m_qiju,x+1,y,pDoc->m_qiju[x+1][y])));
			lefteat=((x-1!=0)&&(pDoc->m_qiju[x-1][y]!=color)
						&&(!MyOutFunction::isLive(pDoc->m_qiju,x-1,y,pDoc->m_qiju[x-1][y])));
			upeat=((y+1!=20)&&(pDoc->m_qiju[x][y+1]!=color)
						&&(!MyOutFunction::isLive(pDoc->m_qiju,x,y+1,pDoc->m_qiju[x][y+1])));
			downeat=((y-1!=0)&&(pDoc->m_qiju[x][y-1]!=color)
						&&(!MyOutFunction::isLive(pDoc->m_qiju,x,y-1,pDoc->m_qiju[x][y-1])));
			if((!righteat)&&(!lefteat)&&(!upeat)&&(!downeat))//不能吃别人的棋子
			{
				pDoc->m_qiju[x][y]=0;//把放进去的取出来
				////////////////////////拷贝pDoc->m_qiju,防止在判断能否落子是将pDoc->m_qiju修改了
				for(i=0;i<21;i++)
					for(j=0;j<21;j++)
						qiju[i][j]=pDoc->m_qiju[i][j];
				//////////////////////////
				if(MyOutFunction::isLive(qiju,x,y,color))//自己会不会被吃
				{
					while(pDoc->m_historylist.now!=pDoc->m_historylist.tail)//now指针和tail指针不一致，将链表now后的部分截掉
					{
						pDoc->m_historylist.del();
					}
					pDoc->m_historylist.add(x,y,color);//保存这一步棋
					pDoc->m_nowlist.add(x,y,color);//保存这一步棋。等到吃子算法出来之后，这两个链表内容就不一样了
					pDoc->m_qiju[x][y]=color;
					pDoc->m_modified=true;//设置棋局被修改标志
				}
				else//没有成功下子
				{
					for(i=0;i<20;i++)
					{
						for(j=0;j<20;j++)
						{
							pDoc->m_qiju[i][j]=jinshou[i][j];//恢复禁手标志
						}
					}
					//AfxMessageBox("不能落子" );
				}
			}
			else
			{
				while(pDoc->m_historylist.now!=pDoc->m_historylist.tail)//now指针和tail指针不一致，将链表now后的部分截掉
				{
					pDoc->m_historylist.del();
				}
				pDoc->m_historylist.add(x,y,color);//保存这一步棋
				pDoc->m_nowlist.add(x,y,color);//保存这一步棋。等到吃子算法出来之后，这两个链表内容就不一样了
				pDoc->m_qiju[x][y]=color;
				pDoc->m_modified=true;//设置棋局被修改标志
			}
			
		}
		else
		{
			TRACE("无效的落子。\n");
			return;
		}
	}
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

void CWeiQ1_0View::OnBack() 
{
	// TODO: Add your command handler code here
	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->m_historylist.isEmpty()||pDoc->m_historylist.now==0)
	{
		AfxMessageBox("不能后退");
	}
	else
	{
		pDoc->m_historylist.now=pDoc->m_historylist.now->pre;//后退一步
		MyOutFunction::moni(pDoc->m_qiju,pDoc->m_historylist);
		pDoc->m_modified=true;//设置棋局被修改标志
		
	}
	Invalidate();
}

void CWeiQ1_0View::OnRecovery() 
{
	// TODO: Add your command handler code here
	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->m_historylist.now==pDoc->m_historylist.tail)
	{
		AfxMessageBox("不能恢复");
	}
	else
	{
		if(pDoc->m_historylist.now==0&&!pDoc->m_historylist.isEmpty())
		{
			pDoc->m_historylist.now=pDoc->m_historylist.head;
		}
		else
		{
			pDoc->m_historylist.now=pDoc->m_historylist.now->next;
		}
		MyOutFunction::moni(pDoc->m_qiju,pDoc->m_historylist);
		pDoc->m_modified=true;//设置棋局被修改标志
	}
	Invalidate();

}

void CWeiQ1_0View::OnHead() 
{
	// TODO: Add your command handler code here

	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->m_historylist.isEmpty()||pDoc->m_historylist.now==0)
	{
		AfxMessageBox("不能后退");
		return;
	}
	pDoc->m_historylist.now=0;
	MyOutFunction::moni(pDoc->m_qiju,pDoc->m_historylist);
	pDoc->m_modified=true;//设置棋局被修改标志

	Invalidate();
}

void CWeiQ1_0View::OnTail() 
{
	// TODO: Add your command handler code here

	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->m_historylist.now==pDoc->m_historylist.tail)
	{
		AfxMessageBox("不能恢复");
		return ;
	}
	pDoc->m_historylist.now=pDoc->m_historylist.tail;
	MyOutFunction::moni(pDoc->m_qiju,pDoc->m_historylist);
	pDoc->m_modified=true;//设置棋局被修改标志

	Invalidate();

}


void CWeiQ1_0View::OnFileNew() 
{
	// TODO: Add your command handler code here
	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_historylist.clearList();
	MyOutFunction::initQiju(pDoc->m_qiju);
	pDoc->m_modified=false;
	pDoc->m_openedFilename="";//将文件名设为空
	Invalidate();
}

void CWeiQ1_0View::OnFileOpen() 
{
	
}

void CWeiQ1_0View::OnFileSave() 
{
	
}

void CWeiQ1_0View::OnFileSaveAs() 
{
	
}

void CWeiQ1_0View::OnAppExit() 
{
	exit(1);
	Invalidate();
}

void CWeiQ1_0View::OnUpdateBack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	bool able=true;
	if(pDoc->m_historylist.now!=0)
	{
		able=true;
	}
	else
	{
		able=false;
	}
	pCmdUI->Enable(able);
}

void CWeiQ1_0View::OnUpdateRecovery(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	bool able=true;
	if(pDoc->m_historylist.now!=pDoc->m_historylist.tail)
	{
		able=true;
	}
	else
	{
		able=false;
	}
	pCmdUI->Enable(able);
}

void CWeiQ1_0View::OnUpdateHead(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	bool able=true;
	if(pDoc->m_historylist.now!=0)
	{
		able=true;
	}
	else
	{
		able=false;
	}
	pCmdUI->Enable(able);
}

void CWeiQ1_0View::OnUpdateTail(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	bool able=true;
	if(pDoc->m_historylist.now!=pDoc->m_historylist.tail)
	{
		able=true;
	}
	else
	{
		able=false;
	}
	pCmdUI->Enable(able);
}
