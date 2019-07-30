// WeiQ1_0Doc.h : interface of the CWeiQ1_0Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WEIQ1_0DOC_H__D198FDB1_B425_4D41_8E01_CDAB1167A9EA__INCLUDED_)
#define AFX_WEIQ1_0DOC_H__D198FDB1_B425_4D41_8E01_CDAB1167A9EA__INCLUDED_

#include "MyList.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWeiQ1_0Doc : public CDocument
{
protected: // create from serialization only
	CWeiQ1_0Doc();
	DECLARE_DYNCREATE(CWeiQ1_0Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeiQ1_0Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool m_modified;
	char* m_openedFilename;
	MyList m_nowlist;//����������ʣ�µ����ӵ���Ϣ
	int m_qiju[21][21];//��������Ҫ��ʾ����Ϣ����Ҫ�������жϳ���
	MyList m_historylist;//���������߹���ÿһ��
	int m_radius;
	int m_space;
	COLORREF m_bkcolor;
	CPoint m_topleft;
	virtual ~CWeiQ1_0Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWeiQ1_0Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEIQ1_0DOC_H__D198FDB1_B425_4D41_8E01_CDAB1167A9EA__INCLUDED_)
