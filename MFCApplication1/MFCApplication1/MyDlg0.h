#pragma once
#include "afxwin.h"


// MyDlg0 �Ի���

class MyDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg0)

public:
	MyDlg0(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg0();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
