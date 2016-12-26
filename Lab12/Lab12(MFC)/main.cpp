#include <afxwin.h>
#include <time.h>
	class CMyMainWnd : public CFrameWnd {
		int _screenWidth,
			_screenHeight;
		bool isTrue = false;
	public:		
		CMyMainWnd() { // конструктор
			Create(NULL, L"Lab12");
			MoveWindow(GetSystemMetrics(SM_CYSCREEN)/2, GetSystemMetrics(SM_CYSCREEN)/2, 500, 500, true);
			this->_screenHeight = GetSystemMetrics(SM_CYSCREEN);
			this->_screenWidth = GetSystemMetrics(SM_CXSCREEN);
		}

		// методы
		afx_msg void OnLButtonDown(UINT, CPoint);
		afx_msg void OnRButtonDblClk(UINT, CPoint);
		afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
		DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)	// карта сообщений
	ON_WM_RBUTTONDBLCLK()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
class CMyApp : public CWinApp {
public:
	int countClick;
	void counter()
	{
		countClick++;
	}
	CMyApp() {}; // конструктор
	virtual BOOL InitInstance() {
		countClick = 0;
		m_pMainWnd = new CMyMainWnd();
		m_pMainWnd->ShowWindow(SW_SHOW);
		return TRUE;
	}
};

CMyApp theApp;

void CMyMainWnd::OnLButtonDown(UINT, CPoint)
{
	CClientDC cDC(this);
	do
	{
		theApp.counter();
		
		switch(theApp.countClick)
		{ 
		case 1:	{
				cDC.Ellipse(100, 100, 50, 50);
				break;
			}
		case 2:
			{
				cDC.Ellipse(100, 100, 150, 150);
				break;
			}
		case 3:
				cDC.SetDCPenColor(4);
				cDC.Ellipse(100, 100, 130, 130);
				break;
		case 4:
			{
				
				cDC.SetDCPenColor(5);
				cDC.Ellipse(100, 100, 180, 180);
				break;
			}
		case 5:
			{
				cDC.SetDCPenColor(6);
				cDC.Ellipse(100, 100, 200, 200);
				break;
			}
		case 6:
			{
				cDC.SetDCPenColor(7);
				cDC.Ellipse(100, 100, 300, 300);
				break;
			}
		case 7:
			{
				cDC.SetDCPenColor(8);
				cDC.Ellipse(100, 100, 250, 250);
				break;
			}
		}
		Sleep(500);
	} while (theApp.countClick != 8);
}
void CMyMainWnd::OnRButtonDblClk(UINT, CPoint) {
	isTrue = true;
	this->InvalidateRect(0); // перерисовать окно
}

void CMyMainWnd::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	this->InvalidateRect(0); // перерисовать окно
	CPaintDC pDC(this);
	CFont myFont;
	switch (nChar)
	{
		
		case 0x31: {	
						myFont.CreateFont(6, 8, 0, 1, 1, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, (CString)"Arial");
						pDC.SelectObject(&myFont);
						pDC.SetTextAlign(1);
						pDC.SetTextColor(RGB(255, 0, 0));
						pDC.TextOut(250, 250, L"TEXT BUTTON CLICK 1");
						break; 
					}

		case 0x32: {	
						myFont.CreateFont(8, 8, 0, 0, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, (CString)"Arial");
						pDC.SelectObject(&myFont); 
						pDC.SetTextAlign(2);
						pDC.SetTextColor(RGB(0, 255, 0));
						pDC.TextOut(250, 250, L"TEXT BUTTON CLICK 2");
						break; 
					}

		case 0x33: {	
						myFont.CreateFont(10, 10, 0, 1, 0, 1, 0, 1, RUSSIAN_CHARSET, 0, 0, 0, 0, (CString)"Arial");
						pDC.SelectObject(&myFont);
						pDC.SetTextAlign(8);
						pDC.SetTextColor(RGB(0, 0, 255));
						pDC.TextOut(250, 250, L"TEXT BUTTON CLICK 3");
						break; 
					}
		case 0x34: {	pDC.SetTextAlign(4);
						pDC.SetTextColor(RGB(255, 0, 0));
						pDC.TextOut(250, 250, L"TEXT BUTTON CLICK 4");
						break; 
					}

		case 0x35: {
			myFont.CreateFont(9, 9, 0, 0, 0, 0, 1, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, (CString)"Arial");
			pDC.SelectObject(&myFont);
			pDC.SetTextAlign(8);
						pDC.SetTextColor(RGB(20, 60, 200));
						pDC.TextOut(250, 250, L"TEXT BUTTON CLICK 5");
						break; 
					}

		case 0x36: {
						myFont.CreateFont(10, 11, 0, 0, 0, 1, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, (CString)"Arial");
						pDC.SelectObject(&myFont);
						pDC.SetTextAlign(6);
						pDC.SetTextColor(RGB(255, 20, 160));
						pDC.TextOut(250, 250, L"TEXT BUTTON CLICK 6");
						break; 
					}

		case 0x37: {	
						myFont.CreateFont(13, 6, 0, 0, 1, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, (CString)"Arial");
						pDC.SelectObject(&myFont);
						pDC.SetTextAlign(2);
						pDC.SetTextColor(RGB(50, 70, 80));
						pDC.TextOut(250, 250, L"TEXT BUTTON CLICK 7");
						break;
					}

		case 0x38: {	
						myFont.CreateFont(10, 10, 1, 0, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, (CString)"Arial");
						pDC.SelectObject(&myFont);
						pDC.SetTextAlign(4);
						pDC.SetTextColor(RGB(255, 255, 255));
						pDC.TextOut(250, 250, L"TEXT BUTTON CLICK 8");
						break; 
					}
		case 0x39: {	
						myFont.CreateFont(14, 15, 0, 1, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, (CString)"Arial");
						pDC.SelectObject(&myFont);
			
						pDC.SetTextAlign(1);
						pDC.SetTextColor(RGB(100, 100, 100));
						pDC.TextOut(250, 250, L"TEXT BUTTON CLICK 9");
						break; 
					}
	}
}