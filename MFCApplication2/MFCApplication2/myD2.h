#pragma once


// myD2 �Ի���

class myD2 : public CDialogEx
{
	DECLARE_DYNAMIC(myD2)

public:
	myD2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~myD2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
