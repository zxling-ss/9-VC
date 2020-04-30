// MyDlg0.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MyDlg0.h"
#include "afxdialogex.h"
#include"MFCApplication1Doc.h"

// MyDlg0 对话框

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, LBox);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg0::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &MyDlg0::OnLbnSelchangeList1)
//	ON_WM_MBUTTONDBLCLK()
//无法解析的外部符号 "public: void __thiscall MyDlg0::OnEnChangeEdit2(void)" (?OnEnChangeEdit2@MyDlg0@@QAEXXZ)
//	ON_EN_CHANGE(IDC_EDIT2, &MyDlg0::OnEnChangeEdit2)
//无法解析的外部符号 "public: void __thiscall MyDlg0::OnPop(void)" (?OnPop@MyDlg0@@QAEXXZ)
//	ON_COMMAND(ID_Pop, &MyDlg0::OnPop)

END_MESSAGE_MAP()


// MyDlg0 消息处理程序


void MyDlg0::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void MyDlg0::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	b = s;
	UpdateData(false);
}


BOOL MyDlg0::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		s = cfd.GetPathName();
	}
	LBox.AddString(s);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

