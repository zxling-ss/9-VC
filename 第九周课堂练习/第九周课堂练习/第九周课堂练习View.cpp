
// �ھ��ܿ�����ϰView.cpp : C�ھ��ܿ�����ϰView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ھ��ܿ�����ϰ.h"
#endif

#include "�ھ��ܿ�����ϰDoc.h"
#include "�ھ��ܿ�����ϰView.h"
#include "pictureshouw.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ھ��ܿ�����ϰView

IMPLEMENT_DYNCREATE(C�ھ��ܿ�����ϰView, CView)

BEGIN_MESSAGE_MAP(C�ھ��ܿ�����ϰView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &C�ھ��ܿ�����ϰView::On32771)
	ON_COMMAND(ID_32772, &C�ھ��ܿ�����ϰView::On32772)
END_MESSAGE_MAP()

// C�ھ��ܿ�����ϰView ����/����

C�ھ��ܿ�����ϰView::C�ھ��ܿ�����ϰView()
{
	// TODO: �ڴ˴���ӹ������

}

C�ھ��ܿ�����ϰView::~C�ھ��ܿ�����ϰView()
{
}

BOOL C�ھ��ܿ�����ϰView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ھ��ܿ�����ϰView ����

void C�ھ��ܿ�����ϰView::OnDraw(CDC* /*pDC*/)
{
	C�ھ��ܿ�����ϰDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ھ��ܿ�����ϰView ��ӡ

BOOL C�ھ��ܿ�����ϰView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ھ��ܿ�����ϰView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ھ��ܿ�����ϰView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ھ��ܿ�����ϰView ���

#ifdef _DEBUG
void C�ھ��ܿ�����ϰView::AssertValid() const
{
	CView::AssertValid();
}

void C�ھ��ܿ�����ϰView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ھ��ܿ�����ϰDoc* C�ھ��ܿ�����ϰView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ھ��ܿ�����ϰDoc)));
	return (C�ھ��ܿ�����ϰDoc*)m_pDocument;
}
#endif //_DEBUG


// C�ھ��ܿ�����ϰView ��Ϣ�������


void C�ھ��ܿ�����ϰView::On32771()
{
	// TODO: �ڴ���������������
	CFileDialog file(TRUE, NULL, NULL, NULL, NULL, NULL);

	if (IDOK == file.DoModal()) {
		CString filePath = file.GetPathName();
		string s = CT2A(filePath);


		ofstream ofs("1.txt");
		ofs << s << endl;
		ofs.close();

	}
}


void C�ھ��ܿ�����ϰView::On32772()
{
	// TODO: �ڴ���������������
	pictureshouw pic;
	int r=pic.DoModal();
	if (r == IDOK) {

	}
}
