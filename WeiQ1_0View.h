// WeiQ1_0View.h : interface of the CWeiQ1_0View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WEIQ1_0VIEW_H__2EC7F4D7_BD6F_453F_BBFB_C3569DA85C96__INCLUDED_)
#define AFX_WEIQ1_0VIEW_H__2EC7F4D7_BD6F_453F_BBFB_C3569DA85C96__INCLUDED_

#if _MSC_VER > 1000

#include "MyOutFunction.h"

#pragma once
#endif // _MSC_VER > 1000


class CWeiQ1_0View : public CView
{
protected: // create from serialization only
	CWeiQ1_0View();
	DECLARE_DYNCREATE(CWeiQ1_0View)

// Attributes
public:
	CWeiQ1_0Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeiQ1_0View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWeiQ1_0View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWeiQ1_0View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBack();
	afx_msg void OnRecovery();
	afx_msg void OnHead();
	afx_msg void OnTail();
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnAppExit();
	afx_msg void OnUpdateBack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRecovery(CCmdUI* pCmdUI);
	afx_msg void OnUpdateHead(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTail(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DrawChessboard(CDC* pDC,CPoint top_left,COLORREF bkcolor,int  space, int radius);//ªÊ÷∆∆Â≈Ã
};

#ifndef _DEBUG  // debug version in WeiQ1_0View.cpp
inline CWeiQ1_0Doc* CWeiQ1_0View::GetDocument()
   { return (CWeiQ1_0Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEIQ1_0VIEW_H__2EC7F4D7_BD6F_453F_BBFB_C3569DA85C96__INCLUDED_)
