
// gLimMfcExamDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "gLimMfcExam.h"
#include "gLimMfcExamDlg.h"
#include "afxdialogex.h"

#include <iostream>
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")	//디버깅용 콘솔

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
using namespace std;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CgLimMfcExamDlg 대화 상자



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


// CgLimMfcExamDlg 메시지 처리기

BOOL CgLimMfcExamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CgLimMfcExamDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CgLimMfcExamDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define IMAGE_BPP 24
void CgLimMfcExamDlg::OnBnClickedBtnAction()
{
	int nWidth = IMAGE_WIDTH;
	int nHeight = IMAGE_HEIGHT;
	int nBpp = IMAGE_BPP;

	if (m_image == NULL) {
		m_image.Create(nWidth, -nHeight, IMAGE_BPP);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0, nWidth*nHeight * 3); // 검은색 채우기

	CPoint ptData = CPoint(rand() % IMAGE_WIDTH, rand() % IMAGE_HEIGHT); // 랜덤 좌표생성
	CRect rect(ptData.x - m_nCircleSize, ptData.y - m_nCircleSize, ptData.x + m_nCircleSize, ptData.y + m_nCircleSize);// 생성된 좌표 기준 사용자 입력 사이즈 Rect 계산
	cout << "랜덤좌표:\t" << ptData.x << "\t" << ptData.y << endl;

	int nCount = 0;
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (j * nPitch / 3 + i < IMAGE_WIDTH*IMAGE_HEIGHT && j * nPitch / 3 + i > 0) { // 메모리 범위 벗어나는것 방지
				fm[j * nPitch + i] = 0x81;
				nCount++;
			}
		}
	}

	CClientDC dc(this);
	GetCenterData();

	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}

	UpdateData(TRUE);

	DrawData(&dc, ptData);

	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}

	UpdateData(false);
}

void CgLimMfcExamDlg::GetCenterData()
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

	cout << "무게중심:\t" << dCenterX << "\t" << dCenterY << endl;
	memset(fm, 0, nWidth*nHeight * 3);

}

void CgLimMfcExamDlg::DrawData(CDC* pDC, CPoint ptData)
{
	//CRect rect(ptData, ptData);

	int nLeft = ptData.x - m_nCircleSize < 0 ? 0 : ptData.x - m_nCircleSize;
	int nRight = ptData.x + m_nCircleSize > IMAGE_WIDTH ? IMAGE_WIDTH - 1 : ptData.x + m_nCircleSize;
	int nTop = ptData.y - m_nCircleSize < 0 ? 0 : ptData.y - m_nCircleSize;
	int nBottom = ptData.y + m_nCircleSize > IMAGE_HEIGHT ? IMAGE_HEIGHT - 1 : ptData.y + m_nCircleSize;

	CRect rect(nLeft, nTop, nRight, nBottom);// 생성된 좌표 기준 사용자 입력 사이즈 Rect 계산

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	// 가로선
	for (int i = rect.left; i < rect.right; i++) {
		m_image.SetPixel(i, ptData.y, COLOR_YELLOW);
	}

	// 세로선
	for (int i = rect.top; i < rect.bottom; i++) {
		m_image.SetPixel(ptData.x, i, COLOR_YELLOW);
	}

	//두 좌표의 거리차이를 이용한 원 그리기
	CPoint ptNowIndex;
	for (int j = rect.top; j <= rect.bottom; j++) {
		for (int i = rect.left; i <= rect.right; i++) {
			ptNowIndex = CPoint(i, j);
			if (GetDistance(ptNowIndex, ptData) > m_nCircleSize - 1 && GetDistance(ptNowIndex, ptData) < m_nCircleSize + 1) {
				m_image.SetPixel(i, j, COLOR_YELLOW);
			}
		}
	}
}

#include <cmath>
double CgLimMfcExamDlg::GetDistance(CPoint ptData1, CPoint ptData2) {

	double distance;

	distance = sqrt(pow(ptData1.x - ptData2.x, 2) + pow(ptData1.y - ptData2.y, 2));
	return distance;
}

/* Ellipse, Line 을 이용한 마커 표시
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

	pDC->Ellipse(ptData.x - m_nCircleSize, ptData.y - m_nCircleSize, ptData.x + m_nCircleSize, ptData.y + m_nCircleSize);	// 원 그리기
	pDC->MoveTo(ptData.x - m_nCircleSize, ptData.y);
	pDC->LineTo(ptData.x + m_nCircleSize, ptData.y);	// 가로선
	pDC->MoveTo(ptData.x , ptData.y - m_nCircleSize);
	pDC->LineTo(ptData.x , ptData.y + m_nCircleSize);	// 세로선

	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}
*/
