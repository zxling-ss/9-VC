
// �ھ��ܿ�����ϰView.h : C�ھ��ܿ�����ϰView ��Ľӿ�
//

#pragma once


class C�ھ��ܿ�����ϰView : public CView
{
protected: // �������л�����
	C�ھ��ܿ�����ϰView();
	DECLARE_DYNCREATE(C�ھ��ܿ�����ϰView)

// ����
public:
	C�ھ��ܿ�����ϰDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C�ھ��ܿ�����ϰView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
};

#ifndef _DEBUG  // �ھ��ܿ�����ϰView.cpp �еĵ��԰汾
inline C�ھ��ܿ�����ϰDoc* C�ھ��ܿ�����ϰView::GetDocument() const
   { return reinterpret_cast<C�ھ��ܿ�����ϰDoc*>(m_pDocument); }
#endif

