
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox Lbox;
	CString s;		//�༭���ȡ�����ı�����
	int Editnumber;	//�༭���ȡ���б���еĵ�ǰ��ѡ��¼��	
	afx_msg void OnLbnSelchangeList1();
	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CString Edit1;
	CEdit m_edit;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
