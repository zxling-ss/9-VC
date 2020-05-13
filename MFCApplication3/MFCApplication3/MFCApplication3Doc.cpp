
// MFCApplication3Doc.cpp : CMFCApplication3Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CMFCApplication3Doc ����/����

CMFCApplication3Doc::CMFCApplication3Doc()
{
	// TODO: �ڴ����һ���Թ������
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

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMFCApplication3Doc ���л�
//���������ĵ���ͼ�ṹ�ĳ����ڿͻ��������������Խ��䷽ʽ���������Բ�������л���ʽ������Щ��Բ���ļ��У��������г��򣬵��"�ļ�\��"�������������Բ��Ϣ�ļ���ʹ��������Բ������ʾ�ڿͻ�����
void CMFCApplication3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar << a << s;
		/*ar << x1 << y1 << x2 << y2;*/

	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
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

// ����ͼ��֧��
void CMFCApplication3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CMFCApplication3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CMFCApplication3Doc ���

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


// CMFCApplication3Doc ����
