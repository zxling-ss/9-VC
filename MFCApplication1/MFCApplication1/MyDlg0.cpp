// MyDlg0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MyDlg0.h"
#include "afxdialogex.h"
#include"MFCApplication1Doc.h"

// MyDlg0 �Ի���

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
//�޷��������ⲿ���� "public: void __thiscall MyDlg0::OnEnChangeEdit2(void)" (?OnEnChangeEdit2@MyDlg0@@QAEXXZ)
//	ON_EN_CHANGE(IDC_EDIT2, &MyDlg0::OnEnChangeEdit2)
//�޷��������ⲿ���� "public: void __thiscall MyDlg0::OnPop(void)" (?OnPop@MyDlg0@@QAEXXZ)
//	ON_COMMAND(ID_Pop, &MyDlg0::OnPop)

END_MESSAGE_MAP()


// MyDlg0 ��Ϣ�������


void MyDlg0::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void MyDlg0::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	b = s;
	UpdateData(false);
}


BOOL MyDlg0::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		s = cfd.GetPathName();
	}
	LBox.AddString(s);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

