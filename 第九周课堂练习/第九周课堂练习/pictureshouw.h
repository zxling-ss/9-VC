#pragma once


// pictureshouw 对话框

class pictureshouw : public CDialogEx
{
	DECLARE_DYNAMIC(pictureshouw)

public:
	pictureshouw(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pictureshouw();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
