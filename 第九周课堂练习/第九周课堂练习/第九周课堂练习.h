
// �ھ��ܿ�����ϰ.h : �ھ��ܿ�����ϰ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ھ��ܿ�����ϰApp:
// �йش����ʵ�֣������ �ھ��ܿ�����ϰ.cpp
//

class C�ھ��ܿ�����ϰApp : public CWinAppEx
{
public:
	C�ھ��ܿ�����ϰApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ھ��ܿ�����ϰApp theApp;
