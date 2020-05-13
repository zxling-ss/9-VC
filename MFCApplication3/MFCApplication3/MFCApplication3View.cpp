
// MFCApplication3View.cpp : CMFCApplication3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFCApplication3View 构造/析构

CMFCApplication3View::CMFCApplication3View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication3View::~CMFCApplication3View()
{
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication3View 绘制

void CMFCApplication3View::OnDraw(CDC* pDC)
{
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	

	//如果关闭程序加载数据时，依据保存的数据进行重新绘图
	if (pDoc->a==1) 
	{
		/*pDC->Ellipse(pDoc->x1[0], pDoc->y1[0], pDoc->x2[0], pDoc->y1[0]);*/
		pDC->TextOutW(200, 200, pDoc->s);
		//int n = pDoc->DrawEllipse.x1.GetCount();		//获取保存椭圆坐标的数量---用类的方法
		int n = pDoc->x1.GetCount();		//获取保存椭圆坐标的数量---用数组的方法
		for (int i = 0; i < n;i++){
			//调用类中的数据进行重绘
			//pDC->Ellipse(pDoc->DrawEllipse.x1[i], pDoc->DrawEllipse.y1[i], pDoc->DrawEllipse.x2[i], pDoc->DrawEllipse.y2[i]);
			//调用数组中的数据进行重绘
			pDC->Ellipse(pDoc->x1[i], pDoc->y1[i], pDoc->x2[i], pDoc->y2[i]);

		}
		/*pDoc->a = 0;*/
	}
	
}

// CMFCApplication3View 诊断

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View 消息处理程序


void CMFCApplication3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CClientDC dc(this);		//定义一个CClientDC的对象dc
	CMFCApplication3Doc* pDoc = GetDocument();

	CRect rc;				//定义一个描述椭圆的对象rc
	int x1 = point.x-100;
	int y1 = point.y - 100;
	int x2 = point.x + 100;
	int y2 = point.y + 100;

	//保存椭圆的坐标到数组中

	pDoc->x1.Add(x1);
	pDoc->y1.Add(y1);
	pDoc->x2.Add(x2);
	pDoc->y2.Add(y2);

	/*pDoc->x1 = point.x - 100;
	pDoc->y1 = point.y - 100;
	pDoc->x2 = point.x + 100;
	pDoc->x2 = point.y + 100;
*/
//保存椭圆的坐标到数组中
	pDoc->DrawEllipse.x1.Add(x1);
	pDoc->DrawEllipse.x2.Add(x2);
	pDoc->DrawEllipse.y1.Add(y1);
	pDoc->DrawEllipse.y2.Add(y2);;

	dc.Ellipse(x1,y1,x2,y2);
	CView::OnLButtonDown(nFlags, point);
}
