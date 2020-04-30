#pragma once
#include "afxwin.h"


// MyDlg0 对话框

class MyDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg0)

public:
	MyDlg0(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg0();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLbnSelchangeList1();
	CListBox LBox;
	CEdit a;
	CString b;
	CString s;
	virtual BOOL OnInitDialog();
//	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnPop();
};
