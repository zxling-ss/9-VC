
// MFCApplication3View.cpp : CMFCApplication3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3View

IMPLEMENT_DYNCREATE(CMFCApplication3View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication3View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication3View ����/����

CMFCApplication3View::CMFCApplication3View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication3View::~CMFCApplication3View()
{
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication3View ����

void CMFCApplication3View::OnDraw(CDC* pDC)
{
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	

	//����رճ����������ʱ�����ݱ�������ݽ������»�ͼ
	if (pDoc->a==1) 
	{
		/*pDC->Ellipse(pDoc->x1[0], pDoc->y1[0], pDoc->x2[0], pDoc->y1[0]);*/
		pDC->TextOutW(200, 200, pDoc->s);
		//int n = pDoc->DrawEllipse.x1.GetCount();		//��ȡ������Բ���������---����ķ���
		int n = pDoc->x1.GetCount();		//��ȡ������Բ���������---������ķ���
		for (int i = 0; i < n;i++){
			//�������е����ݽ����ػ�
			//pDC->Ellipse(pDoc->DrawEllipse.x1[i], pDoc->DrawEllipse.y1[i], pDoc->DrawEllipse.x2[i], pDoc->DrawEllipse.y2[i]);
			//���������е����ݽ����ػ�
			pDC->Ellipse(pDoc->x1[i], pDoc->y1[i], pDoc->x2[i], pDoc->y2[i]);

		}
		/*pDoc->a = 0;*/
	}
	
}

// CMFCApplication3View ���

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View ��Ϣ�������


void CMFCApplication3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CClientDC dc(this);		//����һ��CClientDC�Ķ���dc
	CMFCApplication3Doc* pDoc = GetDocument();

	CRect rc;				//����һ��������Բ�Ķ���rc
	int x1 = point.x-100;
	int y1 = point.y - 100;
	int x2 = point.x + 100;
	int y2 = point.y + 100;

	//������Բ�����굽������

	pDoc->x1.Add(x1);
	pDoc->y1.Add(y1);
	pDoc->x2.Add(x2);
	pDoc->y2.Add(y2);

	/*pDoc->x1 = point.x - 100;
	pDoc->y1 = point.y - 100;
	pDoc->x2 = point.x + 100;
	pDoc->x2 = point.y + 100;
*/
//������Բ�����굽������
	pDoc->DrawEllipse.x1.Add(x1);
	pDoc->DrawEllipse.x2.Add(x2);
	pDoc->DrawEllipse.y1.Add(y1);
	pDoc->DrawEllipse.y2.Add(y2);;

	dc.Ellipse(x1,y1,x2,y2);
	CView::OnLButtonDown(nFlags, point);
}
