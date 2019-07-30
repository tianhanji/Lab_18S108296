// WeiQ1_0Doc.cpp : implementation of the CWeiQ1_0Doc class
//

#include "stdafx.h"
#include "WeiQ1_0.h"

#include "WeiQ1_0Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0Doc

IMPLEMENT_DYNCREATE(CWeiQ1_0Doc, CDocument)

BEGIN_MESSAGE_MAP(CWeiQ1_0Doc, CDocument)
	//{{AFX_MSG_MAP(CWeiQ1_0Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0Doc construction/destruction

CWeiQ1_0Doc::CWeiQ1_0Doc()
{
	// TODO: add one-time construction code here
	m_topleft=CPoint(50,30);
	m_bkcolor=RGB(255,193,37);//ÆåÅÌ±³¾°É«
	m_space=30;
	m_radius=6;
	m_historylist.init();
	m_nowlist.init();
	m_openedFilename="";
	m_modified=false;
	for(int i=1;i<20;i++)
	{
		for(int j=1;j<20;j++)
		{
			m_qiju[i][j]=0;
		}
	}
	for(int k=0;k<21;k++)
	{
		m_qiju[0][k]=3;
		m_qiju[20][k]=3;
		m_qiju[k][0]=3;
		m_qiju[k][20]=3;
	}
}

CWeiQ1_0Doc::~CWeiQ1_0Doc()
{
}

BOOL CWeiQ1_0Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0Doc serialization

void CWeiQ1_0Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0Doc diagnostics

#ifdef _DEBUG
void CWeiQ1_0Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWeiQ1_0Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0Doc commands
