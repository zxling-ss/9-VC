// myD2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "myD2.h"
#include "afxdialogex.h"


// myD2 �Ի���

IMPLEMENT_DYNAMIC(myD2, CDialogEx)

myD2::myD2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

myD2::~myD2()
{
}

void myD2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(myD2, CDialogEx)
END_MESSAGE_MAP()


// myD2 ��Ϣ�������
