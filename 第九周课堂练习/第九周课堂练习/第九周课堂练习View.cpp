
// 第九周课堂练习View.cpp : C第九周课堂练习View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第九周课堂练习.h"
#endif

#include "第九周课堂练习Doc.h"
#include "第九周课堂练习View.h"
#include "pictureshouw.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第九周课堂练习View

IMPLEMENT_DYNCREATE(C第九周课堂练习View, CView)

BEGIN_MESSAGE_MAP(C第九周课堂练习View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &C第九周课堂练习View::On32771)
	ON_COMMAND(ID_32772, &C第九周课堂练习View::On32772)
END_MESSAGE_MAP()

// C第九周课堂练习View 构造/析构

C第九周课堂练习View::C第九周课堂练习View()
{
	// TODO: 在此处添加构造代码

}

C第九周课堂练习View::~C第九周课堂练习View()
{
}

BOOL C第九周课堂练习View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第九周课堂练习View 绘制

void C第九周课堂练习View::OnDraw(CDC* /*pDC*/)
{
	C第九周课堂练习Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第九周课堂练习View 打印

BOOL C第九周课堂练习View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第九周课堂练习View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第九周课堂练习View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第九周课堂练习View 诊断

#ifdef _DEBUG
void C第九周课堂练习View::AssertValid() const
{
	CView::AssertValid();
}

void C第九周课堂练习View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第九周课堂练习Doc* C第九周课堂练习View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第九周课堂练习Doc)));
	return (C第九周课堂练习Doc*)m_pDocument;
}
#endif //_DEBUG


// C第九周课堂练习View 消息处理程序


void C第九周课堂练习View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog file(TRUE, NULL, NULL, NULL, NULL, NULL);

	if (IDOK == file.DoModal()) {
		CString filePath = file.GetPathName();
		string s = CT2A(filePath);


		ofstream ofs("1.txt");
		ofs << s << endl;
		ofs.close();

	}
}


void C第九周课堂练习View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	pictureshouw pic;
	int r=pic.DoModal();
	if (r == IDOK) {

	}
}
