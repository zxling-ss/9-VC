// pictureshouw.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ھ��ܿ�����ϰ.h"
#include "pictureshouw.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

// pictureshouw �Ի���

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


// pictureshouw ��Ϣ�������


BOOL pictureshouw::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

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
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void pictureshouw::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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
