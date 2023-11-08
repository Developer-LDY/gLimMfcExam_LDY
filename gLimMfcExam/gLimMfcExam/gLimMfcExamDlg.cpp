
// gLimMfcExamDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "gLimMfcExam.h"
#include "gLimMfcExamDlg.h"
#include "afxdialogex.h"

#include <iostream>
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")	//������ �ܼ�

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.
using namespace std;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgLimMfcExamDlg ��ȭ ����



CgLimMfcExamDlg::CgLimMfcExamDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GLIMMFCEXAM_DIALOG, pParent)
	, m_nCircleSize(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgLimMfcExamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CIRCLE_SIZE, m_nCircleSize);
}

BEGIN_MESSAGE_MAP(CgLimMfcExamDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ACTION, &CgLimMfcExamDlg::OnBnClickedBtnAction)
END_MESSAGE_MAP()


// CgLimMfcExamDlg �޽��� ó����

BOOL CgLimMfcExamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CgLimMfcExamDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CgLimMfcExamDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CgLimMfcExamDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define IMAGE_BPP 8
void CgLimMfcExamDlg::OnBnClickedBtnAction()
{
	int nWidth = IMAGE_WIDTH;
	int nHeight = IMAGE_HEIGHT;
	int nBpp = IMAGE_BPP;

	if (m_image == NULL) {
		m_image.Create(nWidth, -nHeight, nBpp);
	}
	
	if (nBpp == IMAGE_BPP) {
		static RGBQUAD rgb[256];

		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}

		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	
	memset(fm, 0, nWidth*nHeight); // ������ ä���

	CPoint ptData = CPoint(rand() % IMAGE_WIDTH, rand() % IMAGE_HEIGHT); // ���� ��ǥ����
	CRect rect(ptData.x - m_nCircleSize, ptData.y - m_nCircleSize, ptData.x + m_nCircleSize, ptData.y + m_nCircleSize);// ������ ��ǥ ���� ����� �Է� ������ Rect ���

	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (j * nPitch + i < IMAGE_WIDTH*IMAGE_HEIGHT && j * nPitch + i > 0) {
				fm[j * nPitch + i] = 0x81;
			}
		}
	}
	
	CClientDC dc(this);

	GetCenterData(ptData);

	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}

	UpdateData(TRUE);
	DrawData(&dc, ptData);
	UpdateData(false);
}

void CgLimMfcExamDlg::GetCenterData(CPoint ptData)
{
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();

	int nTh = 0x80;
	CRect rect(0, 0, nWidth, nHeight);
	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;

	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j * nPitch + i] > nTh) {
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
	}

	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	cout << "�����߽�:\t" << dCenterX << "\t" << dCenterY << endl;
	memset(fm, 0, nWidth*nHeight);

}

void CgLimMfcExamDlg::DrawData(CDC* pDC, CPoint ptData)
{
	CRect rect(ptData,ptData);
	CPen pen;
	pen.CreatePen(PS_SOLID, 3, COLOR_YELLOW);
	CPen* oldPen = pDC->SelectObject(&pen);
	CBrush brush,* oldBrush;
	
	brush.CreateStockObject(NULL_BRUSH);
	oldBrush = pDC->SelectObject(&brush);

	rect.InflateRect(1, 1);

	pDC->Ellipse(ptData.x - m_nCircleSize, ptData.y - m_nCircleSize, ptData.x + m_nCircleSize, ptData.y + m_nCircleSize);	// �� �׸���
	pDC->MoveTo(ptData.x - m_nCircleSize, ptData.y);
	pDC->LineTo(ptData.x + m_nCircleSize, ptData.y);	// ���μ�
	pDC->MoveTo(ptData.x , ptData.y - m_nCircleSize);
	pDC->LineTo(ptData.x , ptData.y + m_nCircleSize);	// ���μ�

	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}

