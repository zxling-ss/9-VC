// pictureshouw.cpp : 实现文件
//

#include "stdafx.h"
#include "第九周课堂练习.h"
#include "pictureshouw.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

// pictureshouw 对话框

IMPLEMENT_DYNAMIC(pictureshouw, CDialogEx)

pictureshouw::pictureshouw(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

pictureshouw::~pictureshouw()
{
}

void pictureshouw::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(pictureshouw, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &pictureshouw::OnBnClickedButton1)
END_MESSAGE_MAP()


// pictureshouw 消息处理程序


BOOL pictureshouw::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	ifstream ifp("1.txt");
	string s;
	CString picturePacth;
	ifp >> s;
	picturePacth = CString(s.c_str());
	CImage img;
	img.Load(picturePacth);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	/*pDC->TextOutW(100, 100, picturePacth);*/
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void pictureshouw::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	ifstream ifp("1.txt");
	string s;
	CString picturePacth;
	ifp >> s;
	picturePacth = CString(s.c_str());
	CImage img;
	img.Load(picturePacth);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	/*pDC->TextOutW(100, 100, picturePacth);*/
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
}
