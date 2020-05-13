
// MFCApplication1Dlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication1Dlg 对话框



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


// CMFCApplication1Dlg 消息处理程序
// (1) 在对话框初始化时以C++方式读入文件"学生名单. txt"，并显示所有学生名单于列表框中；
BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	//CFileDialog cfd(true);
	//int r = cfd.DoModal();
	//CString filename = cfd.GetPathName("学生名单.txt");
	s = "";
	Editnumber = 0;

	ifstream ifs("学生名单.txt");
	string s;
	CClientDC dc(this);
	
	while (ifs >> s)
	{
		//dc.TextOutW(x, y, CString(s.c_str()));
		Lbox.AddString(CString(s.c_str()));
	}


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//(2) 当用鼠标左键选择列表框内的某个条目时，所选中的条目随即显示于编辑控件中；
void CMFCApplication1Dlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	int n = Lbox.GetCurSel();
	Editnumber = n;
	Lbox.GetText(n, s);
	//Edit1.SetWindowText(s);
	//m_edit.UpdateData(TRUE);
	m_edit.SetWindowTextW(s);
}




void CMFCApplication1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//int n = Lbox.GetCurSel();
	//Lbox.GetText(n, s);
	//Edit1.SetWindowText(s);
	//m_edit.UpdateData(TRUE);
	//m_edit.SetWindowTextW(s);
	
	CDialogEx::OnLButtonDown(nFlags, point);
}

//修改按钮的点击函数---当对编辑控件中的学生姓名修改后，点击按钮，使修改的结果反映到列表框；
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//先获得编辑框中的内容
	CString str;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	//将编辑框中的内容插入到列表框
	Lbox.InsertString(Editnumber,str);    // 把缓存str中的字符串插入到列表框B的最后一项
	//Lbox.AddString(CString("123"));
	//Lbox.InsertString(Editnumber, _T("123"));    // 把缓存str中的字符串插入到列表框B的最后一项

	//删除列表框中的原始信息
	Lbox.DeleteString(Editnumber+1);             // 删除列表框A的第一项字符串 
}

//退出程序时，保存修改后的学生名单到文件"学生名单. txt"。保存文件的代码可放到对话框类的析构函数中。
void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//将列表框中的内容写入到txt文件中
	ofstream os;     //创建一个文件输出流对象
	os.open("books.txt");//将对象与文件关联

	CString str;
	
	str = "";
	//获取列表框中的内容
	int n = Lbox.GetCount();			//获取到记录数
	for (int i = 0; i < n; i++) {
		Lbox.GetText(i, str);     //此处获取到的str为CString类型，需要通过CT2A转换string
		
		os <<CT2A(str);   //将输入的内容放入txt文件中
		os << "\n";
	}


	
	
	os.close();
	
	CDialogEx::OnOK();
}
