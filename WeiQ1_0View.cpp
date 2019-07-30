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

	_node* temp=new _node;//���ڱ�������
	CPoint top_left=pDoc->m_topleft;
	int space=pDoc->m_space;
	int radius=pDoc->m_radius;
	COLORREF bkcolor=pDoc->m_bkcolor;
	// TODO: add draw code for native data here
	DrawChessboard(pDC,top_left,bkcolor,space,radius);
	//�������ϵ�����
	temp=pDoc->m_historylist.head;
	int i,j;//ѭ��������
	CString str;//���ڽ�ÿһ������߷���ӡ����
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
				pDC->SelectStockObject(WHITE_BRUSH);//����
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
//�������̣�top_left�����Ͻ�,bkcolor��������ɫ,space�����Ӵ�С,radius�������������Ĵ�С
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
			stry.Format("0%d",i+1);//��ֱ��ʽ
		else
			stry.Format("%d",i+1);
		pDC->TextOut( top_left.x+space*i-3 , top_left.y-30 , strx[i] );//ˮƽABCD���
		pDC->TextOut( top_left.x-space/2-20 , top_left.y+space*i-7 ,stry);//��ֱ0102���
	}
	COLORREF color=pDC->GetBkColor();//���汳����ɫ

	pDC->FillSolidRect( top_left.x-space/2 , top_left.y-space/2 , space*19 , space*19 , bkcolor );
	
	pDC->SetBkColor(color);//�ָ�������ɫ

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

	CPoint top_left=pDoc->m_topleft;//���Ͻǵĵ�
	int space=pDoc->m_space;
	int x,y;//���ڱ��������������λ��
	int i=0,j=0;//��������
	int color;//����˲����Ǻڷ����ǰ׷�
	bool lefteat,righteat,upeat,downeat;
	int qiju[21][21];//
	int jinshou[21][21];//����������ֱ�־�����
	//�����㲻����Ч�ķ�Χ�ڣ�����
	if( point.x < top_left.x - space/2 ||
		point.x > top_left.x + 18*space + space/2 ||
		point.y < top_left.y - space/2 ||
		point.y > top_left.y + 18*space + space/2 )
	{
		TRACE("��Ч�����ӡ�\n");				
		return ;    
	}
	//��������ӵ��λ��,�������Ͻǵĵ��λ��Ϊ(1,1)
	x=(point.x+space/2-top_left.x)/space+1;
	y=(point.y+space/2-top_left.y)/space+1;
	if(pDoc->m_qiju[x][y]==4)//Ϊ��ٽ��ֻ��߻ᱻ�Է��Ե�
	{
		//::AfxMessageBox("��������!");
	}
	else
	{
		//�����б���Ϊ4��Ԫ�ػָ�Ϊ0
		for(int i=1;i<20;i++)
		{
			for(int j=1;j<20;j++)
			{
				jinshou[i][j]=pDoc->m_qiju[i][j];//�Ѵ��н��ֱ�־����ֱ�������
				if(pDoc->m_qiju[i][j]==4)
				{
					pDoc->m_qiju[i][j]=0;
				}
			}
		}

		//��������ȷ���˲�����ִ�ٽ��ֵ�������������ж�
		if(pDoc->m_qiju[x][y]==0)//��λ��û�б�����ռ��
		{
			if(pDoc->m_historylist.isEmpty()||pDoc->m_historylist.now==0
				||pDoc->m_historylist.now->data.color==2)//��û�����壬������һ���ǰ׷��µ�
			{
				color=1;
			}
			else
			{
				color=2;
			}
			//�����жϴ˴��ܲ��ܷ����ӣ�
			pDoc->m_qiju[x][y]=color;//�ȷŽ�ȥ��һ��	
			//�ܷ�Ե����ڵ���������,���ܳԣ��ͳԵ�������ֱ������pDoc->m_qiju
			righteat=((x+1!=20)&&(pDoc->m_qiju[x+1][y]!=color)
						&&(!MyOutFunction::isLive(pDoc->m_qiju,x+1,y,pDoc->m_qiju[x+1][y])));
			lefteat=((x-1!=0)&&(pDoc->m_qiju[x-1][y]!=color)
						&&(!MyOutFunction::isLive(pDoc->m_qiju,x-1,y,pDoc->m_qiju[x-1][y])));
			upeat=((y+1!=20)&&(pDoc->m_qiju[x][y+1]!=color)
						&&(!MyOutFunction::isLive(pDoc->m_qiju,x,y+1,pDoc->m_qiju[x][y+1])));
			downeat=((y-1!=0)&&(pDoc->m_qiju[x][y-1]!=color)
						&&(!MyOutFunction::isLive(pDoc->m_qiju,x,y-1,pDoc->m_qiju[x][y-1])));
			if((!righteat)&&(!lefteat)&&(!upeat)&&(!downeat))//���ܳԱ��˵�����
			{
				pDoc->m_qiju[x][y]=0;//�ѷŽ�ȥ��ȡ����
				////////////////////////����pDoc->m_qiju,��ֹ���ж��ܷ������ǽ�pDoc->m_qiju�޸���
				for(i=0;i<21;i++)
					for(j=0;j<21;j++)
						qiju[i][j]=pDoc->m_qiju[i][j];
				//////////////////////////
				if(MyOutFunction::isLive(qiju,x,y,color))//�Լ��᲻�ᱻ��
				{
					while(pDoc->m_historylist.now!=pDoc->m_historylist.tail)//nowָ���tailָ�벻һ�£�������now��Ĳ��ֽص�
					{
						pDoc->m_historylist.del();
					}
					pDoc->m_historylist.add(x,y,color);//������һ����
					pDoc->m_nowlist.add(x,y,color);//������һ���塣�ȵ������㷨����֮���������������ݾͲ�һ����
					pDoc->m_qiju[x][y]=color;
					pDoc->m_modified=true;//������ֱ��޸ı�־
				}
				else//û�гɹ�����
				{
					for(i=0;i<20;i++)
					{
						for(j=0;j<20;j++)
						{
							pDoc->m_qiju[i][j]=jinshou[i][j];//�ָ����ֱ�־
						}
					}
					//AfxMessageBox("��������" );
				}
			}
			else
			{
				while(pDoc->m_historylist.now!=pDoc->m_historylist.tail)//nowָ���tailָ�벻һ�£�������now��Ĳ��ֽص�
				{
					pDoc->m_historylist.del();
				}
				pDoc->m_historylist.add(x,y,color);//������һ����
				pDoc->m_nowlist.add(x,y,color);//������һ���塣�ȵ������㷨����֮���������������ݾͲ�һ����
				pDoc->m_qiju[x][y]=color;
				pDoc->m_modified=true;//������ֱ��޸ı�־
			}
			
		}
		else
		{
			TRACE("��Ч�����ӡ�\n");
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
		AfxMessageBox("���ܺ���");
	}
	else
	{
		pDoc->m_historylist.now=pDoc->m_historylist.now->pre;//����һ��
		MyOutFunction::moni(pDoc->m_qiju,pDoc->m_historylist);
		pDoc->m_modified=true;//������ֱ��޸ı�־
		
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
		AfxMessageBox("���ָܻ�");
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
		pDoc->m_modified=true;//������ֱ��޸ı�־
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
		AfxMessageBox("���ܺ���");
		return;
	}
	pDoc->m_historylist.now=0;
	MyOutFunction::moni(pDoc->m_qiju,pDoc->m_historylist);
	pDoc->m_modified=true;//������ֱ��޸ı�־

	Invalidate();
}

void CWeiQ1_0View::OnTail() 
{
	// TODO: Add your command handler code here

	CWeiQ1_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->m_historylist.now==pDoc->m_historylist.tail)
	{
		AfxMessageBox("���ָܻ�");
		return ;
	}
	pDoc->m_historylist.now=pDoc->m_historylist.tail;
	MyOutFunction::moni(pDoc->m_qiju,pDoc->m_historylist);
	pDoc->m_modified=true;//������ֱ��޸ı�־

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
	pDoc->m_openedFilename="";//���ļ�����Ϊ��
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
