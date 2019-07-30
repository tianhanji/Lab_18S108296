// WeiQ1_0.h : main header file for the WEIQ1_0 application
//

#if !defined(AFX_WEIQ1_0_H__58635585_57A1_4C76_A4BE_A2D8316123B2__INCLUDED_)
#define AFX_WEIQ1_0_H__58635585_57A1_4C76_A4BE_A2D8316123B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWeiQ1_0App:
// See WeiQ1_0.cpp for the implementation of this class
//

class CWeiQ1_0App : public CWinApp
{
public:
	CWeiQ1_0App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeiQ1_0App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWeiQ1_0App)
	 afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEIQ1_0_H__58635585_57A1_4C76_A4BE_A2D8316123B2__INCLUDED_)
