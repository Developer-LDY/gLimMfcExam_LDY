
// gLimMfcExam.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CgLimMfcExamApp:
// �� Ŭ������ ������ ���ؼ��� gLimMfcExam.cpp�� �����Ͻʽÿ�.
//

class CgLimMfcExamApp : public CWinApp
{
public:
	CgLimMfcExamApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CgLimMfcExamApp theApp;