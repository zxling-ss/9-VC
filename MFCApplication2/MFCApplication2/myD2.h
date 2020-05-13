#pragma once


// myD2 对话框

class myD2 : public CDialogEx
{
	DECLARE_DYNAMIC(myD2)

public:
	myD2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~myD2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
