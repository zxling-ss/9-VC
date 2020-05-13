
// MFCApplication3Doc.cpp : CMFCApplication3Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication3Doc

IMPLEMENT_DYNCREATE(CMFCApplication3Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication3Doc, CDocument)
END_MESSAGE_MAP()


// CMFCApplication3Doc 构造/析构

CMFCApplication3Doc::CMFCApplication3Doc()
{
	// TODO: 在此添加一次性构造代码
	a = 0;
	s = _T("ZXLLOVELSS");
	
	/*DrawEllipse.x1 = 0;
	DrawEllipse.x2 = 0;
	DrawEllipse.y1 = 0;
	DrawEllipse.y2 = 0;*/
}

CMFCApplication3Doc::~CMFCApplication3Doc()
{

}



BOOL CMFCApplication3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFCApplication3Doc 序列化
//建立基于文档视图结构的程序，在客户区中用鼠标左键以渐变方式画出多个椭圆，以序列化方式保存这些椭圆到文件中；重新运行程序，点击"文件\打开"，打开所保存的椭圆信息文件，使所画的椭圆重新显示于客户区。
void CMFCApplication3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		ar << a << s;
		/*ar << x1 << y1 << x2 << y2;*/

	}
	else
	{
		// TODO: 在此添加加载代码
		ar >> a >> s;
		
		a = 1;
		
		//dc.Ellipse(x1[0], y1[0], x2[0], y2[0]);
		/*ar >> x1 >> y1 >> x2 >> x2 >> y2;*/

	}
	
	x1.Serialize(ar);
	y1.Serialize(ar);
	x2.Serialize(ar);
	y2.Serialize(ar);
	
	DrawEllipse.Serialize(ar);
	/*DrawEllipse.onDraw();*/
}


#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFCApplication3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMFCApplication3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFCApplication3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCApplication3Doc 诊断

#ifdef _DEBUG
void CMFCApplication3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCApplication3Doc 命令
