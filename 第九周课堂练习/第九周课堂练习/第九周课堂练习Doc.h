
// �ھ��ܿ�����ϰDoc.h : C�ھ��ܿ�����ϰDoc ��Ľӿ�
//


#pragma once


class C�ھ��ܿ�����ϰDoc : public CDocument
{
protected: // �������л�����
	C�ھ��ܿ�����ϰDoc();
	DECLARE_DYNCREATE(C�ھ��ܿ�����ϰDoc)

// ����
public:

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
	virtual ~C�ھ��ܿ�����ϰDoc();
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
