
// gLimMfcExamDlg.h : ��� ����
//

#pragma once


// CgLimMfcExamDlg ��ȭ ����
class CgLimMfcExamDlg : public CDialogEx
{
// �����Դϴ�.
private:
	CImage m_image;
	void DrawData(CDC* pDC, CPoint ptData);
	void GetCenterData(CPoint ptData);
public:
	CgLimMfcExamDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GLIMMFCEXAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAction();
	int m_nCircleSize;
};
