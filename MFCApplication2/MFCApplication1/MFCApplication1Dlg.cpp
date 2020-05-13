
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg �Ի���



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, Edit1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
	DDX_Text(pDX, IDC_EDIT1, Edit1);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCApplication1Dlg::OnLbnSelchangeList1)
	
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ�������
// (1) �ڶԻ����ʼ��ʱ��C++��ʽ�����ļ�"ѧ������. txt"������ʾ����ѧ���������б���У�
BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	//CFileDialog cfd(true);
	//int r = cfd.DoModal();
	//CString filename = cfd.GetPathName("ѧ������.txt");
	s = "";
	Editnumber = 0;

	ifstream ifs("ѧ������.txt");
	string s;
	CClientDC dc(this);
	
	while (ifs >> s)
	{
		//dc.TextOutW(x, y, CString(s.c_str()));
		Lbox.AddString(CString(s.c_str()));
	}


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//(2) ����������ѡ���б���ڵ�ĳ����Ŀʱ����ѡ�е���Ŀ�漴��ʾ�ڱ༭�ؼ��У�
void CMFCApplication1Dlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int n = Lbox.GetCurSel();
	Editnumber = n;
	Lbox.GetText(n, s);
	//Edit1.SetWindowText(s);
	//m_edit.UpdateData(TRUE);
	m_edit.SetWindowTextW(s);
}




void CMFCApplication1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//int n = Lbox.GetCurSel();
	//Lbox.GetText(n, s);
	//Edit1.SetWindowText(s);
	//m_edit.UpdateData(TRUE);
	//m_edit.SetWindowTextW(s);
	
	CDialogEx::OnLButtonDown(nFlags, point);
}

//�޸İ�ť�ĵ������---���Ա༭�ؼ��е�ѧ�������޸ĺ󣬵����ť��ʹ�޸ĵĽ����ӳ���б��
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�Ȼ�ñ༭���е�����
	CString str;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	//���༭���е����ݲ��뵽�б��
	Lbox.InsertString(Editnumber,str);    // �ѻ���str�е��ַ������뵽�б��B�����һ��
	//Lbox.AddString(CString("123"));
	//Lbox.InsertString(Editnumber, _T("123"));    // �ѻ���str�е��ַ������뵽�б��B�����һ��

	//ɾ���б���е�ԭʼ��Ϣ
	Lbox.DeleteString(Editnumber+1);             // ɾ���б��A�ĵ�һ���ַ��� 
}

//�˳�����ʱ�������޸ĺ��ѧ���������ļ�"ѧ������. txt"�������ļ��Ĵ���ɷŵ��Ի���������������С�
void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//���б���е�����д�뵽txt�ļ���
	ofstream os;     //����һ���ļ����������
	os.open("books.txt");//���������ļ�����

	CString str;
	
	str = "";
	//��ȡ�б���е�����
	int n = Lbox.GetCount();			//��ȡ����¼��
	for (int i = 0; i < n; i++) {
		Lbox.GetText(i, str);     //�˴���ȡ����strΪCString���ͣ���Ҫͨ��CT2Aת��string
		
		os <<CT2A(str);   //����������ݷ���txt�ļ���
		os << "\n";
	}


	
	
	os.close();
	
	CDialogEx::OnOK();
}
