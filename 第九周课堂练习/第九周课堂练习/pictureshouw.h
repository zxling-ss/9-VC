#pragma once


// pictureshouw �Ի���

class pictureshouw : public CDialogEx
{
	DECLARE_DYNAMIC(pictureshouw)

public:
	pictureshouw(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pictureshouw();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
