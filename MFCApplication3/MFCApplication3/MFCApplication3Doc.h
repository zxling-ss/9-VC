
// MFCApplication3Doc.h : CMFCApplication3Doc ��Ľӿ�
//


#pragma once

//����ķ�ʽ������Բ����
class CDrawBase :public CObject		//�̳���CObject
{
public:
	
	
public:
	//��Բ����
	CArray<int, int> x1;
	CArray<int, int> y1;
	CArray<int, int> x2;
	CArray<int, int> y2;
public:
	virtual void Serialize(CArchive& ar)			//��д��Serialize��Ա����
	{
		if (ar.IsStoring()) {			//����
		//	ar << x1 << y1 << x2 << y2;
		}
		else {		//����
		//	ar >> x1 >> y1 >>  x2 >> y2;

		}
		x1.Serialize(ar);
		y1.Serialize(ar);
		x2.Serialize(ar);
		y2.Serialize(ar);
	}
};
class CMFCApplication3Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication3Doc();
	DECLARE_DYNCREATE(CMFCApplication3Doc)

// ����
public:
	int a;
	CString s;
	//���鷽ʽ������Բ����
	CArray<int,int> x1;
	CArray<int,int> y1;
	CArray<int,int> x2;
	CArray<int,int> y2;
	
	//���ĵ����й���һ����Բ����
	CDrawBase DrawEllipse;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCApplication3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
