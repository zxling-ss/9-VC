
// MFCApplication3Doc.h : CMFCApplication3Doc 类的接口
//


#pragma once

//以类的方式保存椭圆坐标
class CDrawBase :public CObject		//继承自CObject
{
public:
	
	
public:
	//椭圆坐标
	CArray<int, int> x1;
	CArray<int, int> y1;
	CArray<int, int> x2;
	CArray<int, int> y2;
public:
	virtual void Serialize(CArchive& ar)			//重写了Serialize成员函数
	{
		if (ar.IsStoring()) {			//保存
		//	ar << x1 << y1 << x2 << y2;
		}
		else {		//加载
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
protected: // 仅从序列化创建
	CMFCApplication3Doc();
	DECLARE_DYNCREATE(CMFCApplication3Doc)

// 特性
public:
	int a;
	CString s;
	//数组方式保存椭圆坐标
	CArray<int,int> x1;
	CArray<int,int> y1;
	CArray<int,int> x2;
	CArray<int,int> y2;
	
	//在文档类中构建一个椭圆的类
	CDrawBase DrawEllipse;
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFCApplication3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
