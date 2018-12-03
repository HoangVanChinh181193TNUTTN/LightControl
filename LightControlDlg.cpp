
// LightControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LightControl.h"
#include "LightControlDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int vlChanel1, vlChanel2, vlChanel3, vlChanel4, vlChanel5, vlChanel6, vlChanel7, vlChanel8;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CLightControlDlg dialog



CLightControlDlg::CLightControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LIGHTCONTROL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLightControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, Btn_Connect, m_BtnConnect);
	DDX_Control(pDX, EDIT_Chanel1, m_chanel1);
	DDX_Control(pDX, EDIT_Chanel2, m_Chanel2);
	DDX_Control(pDX, EDIT_Chanel3, m_Chanel3);
	DDX_Control(pDX, EDIT_Chanel4, m_Chanel4);
	DDX_Control(pDX, Btn_SetValue, m_BtnSetValue);
	DDX_Control(pDX, SLIDER_Chanel1, m_SliderChanel1);
	DDX_Control(pDX, SLIDER_Chanel2, m_SliderChanel2);
	DDX_Control(pDX, SLIDER_Chanel3, m_SliderChanel3);
	DDX_Control(pDX, SLIDER_Chanel4, m_SliderChanel4);
	DDX_Control(pDX, EDIT_Port, m_PortName);
	DDX_Control(pDX, SLIDER_Chanel5, m_SliderChanel5);
	DDX_Control(pDX, SLIDER_Chanel6, m_SliderChanel6);
	DDX_Control(pDX, SLIDER_Chanel7, m_SliderChanel7);
	DDX_Control(pDX, SLIDER_Chanel8, m_SliderChanel8);
	DDX_Control(pDX, EDIT_Chanel5, m_Chanel5);
	DDX_Control(pDX, EDIT_Chanel6, m_Chanel6);
	DDX_Control(pDX, EDIT_Chanel7, m_Chanel7);
	DDX_Control(pDX, EDIT_Chanel8, m_Chanel8);
}

BEGIN_MESSAGE_MAP(CLightControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Btn_Connect, &CLightControlDlg::OnBnClickedConnect)
	ON_BN_CLICKED(Btn_SetValue, &CLightControlDlg::OnBnClickedSetvalue)
	ON_NOTIFY(NM_CUSTOMDRAW, SLIDER_Chanel1, &CLightControlDlg::OnNMCustomdrawChanel1)
	ON_NOTIFY(NM_CUSTOMDRAW, SLIDER_Chanel2, &CLightControlDlg::OnNMCustomdrawChanel2)
	ON_NOTIFY(NM_CUSTOMDRAW, SLIDER_Chanel3, &CLightControlDlg::OnNMCustomdrawChanel3)
	ON_NOTIFY(NM_CUSTOMDRAW, SLIDER_Chanel4, &CLightControlDlg::OnNMCustomdrawChanel4)
	ON_NOTIFY(NM_CUSTOMDRAW, SLIDER_Chanel5, &CLightControlDlg::OnNMCustomdrawChanel5)
	ON_NOTIFY(NM_CUSTOMDRAW, SLIDER_Chanel6, &CLightControlDlg::OnNMCustomdrawChanel6)
	ON_NOTIFY(NM_CUSTOMDRAW, SLIDER_Chanel7, &CLightControlDlg::OnNMCustomdrawChanel7)
	ON_NOTIFY(NM_CUSTOMDRAW, SLIDER_Chanel8, &CLightControlDlg::OnNMCustomdrawChanel8)
	ON_BN_CLICKED(IDC_BUTTON_OFFALL, &CLightControlDlg::OnBnClickedButtonOffall)
END_MESSAGE_MAP()


// CLightControlDlg message handlers

BOOL CLightControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_SliderChanel1.SetRange(0, 255);
	m_SliderChanel2.SetRange(0, 255);
	m_SliderChanel3.SetRange(0, 255);
	m_SliderChanel4.SetRange(0, 255);
	m_SliderChanel5.SetRange(0, 255);
	m_SliderChanel6.SetRange(0, 255);
	m_SliderChanel7.SetRange(0, 255);
	m_SliderChanel8.SetRange(0, 255);

	m_SliderChanel1.SetPos(1);
	m_SliderChanel2.SetPos(1);
	m_SliderChanel3.SetPos(1);
	m_SliderChanel4.SetPos(1);
	m_SliderChanel5.SetPos(1);
	m_SliderChanel6.SetPos(1);
	m_SliderChanel7.SetPos(1);
	m_SliderChanel8.SetPos(1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CLightControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLightControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLightControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int iPortMem;

void CLightControlDlg::OnBnClickedButton2()
{
	
	// TODO: Add your control notification handler code here
}


void CLightControlDlg::OnBnClickedConnect()
{
	CString	NameBtn;
	GetDlgItemText(Btn_Connect, NameBtn);
	if (NameBtn == _T("Connect"))
	{
		int iPort;
		iPort = GetDlgItemInt(EDIT_Port);
		if (iPort == NULL)
		{
			AfxMessageBox(_T("Please input the Com Port"), MB_ICONQUESTION);
		}
		if (LightPort.Connect(iPort, 9600))
		{
			iPortMem = iPort;
			AfxMessageBox(_T("Connect ComPort successfully"), MB_ICONINFORMATION);
			SetDlgItemText(Btn_Connect, _T("Disconnect"));
		}
		else
		{
			AfxMessageBox(_T("Connect error, Please check the light Port"), MB_ICONWARNING);
		}


	}
	if (NameBtn == _T("Disconnect"))
	{
		LightPort.Disconnect();
		SetDlgItemText(Btn_Connect, _T("Connect"));
	}
	// TODO: Add your control notification handler code here
}


void CLightControlDlg::OnBnClickedSetvalue()
{
	
	vlChanel1 = GetDlgItemInt(EDIT_Chanel1);
	vlChanel2 = GetDlgItemInt(EDIT_Chanel2);
	vlChanel3 = GetDlgItemInt(EDIT_Chanel3);
	vlChanel4 = GetDlgItemInt(EDIT_Chanel4);
	vlChanel5 = GetDlgItemInt(EDIT_Chanel5);
	vlChanel6 = GetDlgItemInt(EDIT_Chanel6);
	vlChanel7 = GetDlgItemInt(EDIT_Chanel7);
	vlChanel8 = GetDlgItemInt(EDIT_Chanel8);

	LightPort.ChangeLightValue8Ch(vlChanel1, vlChanel2, vlChanel3, vlChanel4, vlChanel5, vlChanel6, vlChanel7, vlChanel8);


	m_SliderChanel1.SetPos(vlChanel1);
	m_SliderChanel2.SetPos(vlChanel2);
	m_SliderChanel3.SetPos(vlChanel3);
	m_SliderChanel4.SetPos(vlChanel4);
	m_SliderChanel5.SetPos(vlChanel5);
	m_SliderChanel6.SetPos(vlChanel6);
	m_SliderChanel7.SetPos(vlChanel7);
	m_SliderChanel8.SetPos(vlChanel8);

	// TODO: Add your control notification handler code here
}

void CLightControlDlg::OnNMCustomdrawChanel1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	vlChanel1 = m_SliderChanel1.GetPos();
	LightPort.ChangeLightValue8Ch(vlChanel1, vlChanel2, vlChanel3, vlChanel4, vlChanel5, vlChanel6, vlChanel7, vlChanel8);
	SetDlgItemInt(EDIT_Chanel1, vlChanel1);
	*pResult = 0;
}


void CLightControlDlg::OnNMCustomdrawChanel2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	vlChanel2 = m_SliderChanel2.GetPos();

	LightPort.ChangeLightValue8Ch(vlChanel1, vlChanel2, vlChanel3, vlChanel4, vlChanel5, vlChanel6, vlChanel7, vlChanel8);
	SetDlgItemInt(EDIT_Chanel2, vlChanel2);
	*pResult = 0;
}


void CLightControlDlg::OnNMCustomdrawChanel3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here

	vlChanel3 = m_SliderChanel3.GetPos();
	LightPort.ChangeLightValue8Ch(vlChanel1, vlChanel2, vlChanel3, vlChanel4, vlChanel5, vlChanel6, vlChanel7, vlChanel8);
	SetDlgItemInt(EDIT_Chanel3, vlChanel3);
	*pResult = 0;
}


void CLightControlDlg::OnNMCustomdrawChanel4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	vlChanel4 = m_SliderChanel4.GetPos();
	LightPort.ChangeLightValue8Ch(vlChanel1, vlChanel2, vlChanel3, vlChanel4, vlChanel5, vlChanel6, vlChanel7, vlChanel8);
	SetDlgItemInt(EDIT_Chanel4, vlChanel4);
	*pResult = 0;
}




void CLightControlDlg::OnNMCustomdrawChanel5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	vlChanel5 = m_SliderChanel5.GetPos();
	LightPort.ChangeLightValue8Ch(vlChanel1, vlChanel2, vlChanel3, vlChanel4, vlChanel5, vlChanel6, vlChanel7, vlChanel8);
	SetDlgItemInt(EDIT_Chanel5, vlChanel5);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CLightControlDlg::OnNMCustomdrawChanel6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	vlChanel6 = m_SliderChanel6.GetPos();
	LightPort.ChangeLightValue8Ch(vlChanel1, vlChanel2, vlChanel3, vlChanel4, vlChanel5, vlChanel6, vlChanel7, vlChanel8);
	SetDlgItemInt(EDIT_Chanel6, vlChanel6);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CLightControlDlg::OnNMCustomdrawChanel7(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	vlChanel7 = m_SliderChanel7.GetPos();
	LightPort.ChangeLightValue8Ch(vlChanel1, vlChanel2, vlChanel3, vlChanel4, vlChanel5, vlChanel6, vlChanel7, vlChanel8);
	SetDlgItemInt(EDIT_Chanel7, vlChanel7);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CLightControlDlg::OnNMCustomdrawChanel8(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	vlChanel8 = m_SliderChanel8.GetPos();
	LightPort.ChangeLightValue8Ch(vlChanel1, vlChanel2, vlChanel3, vlChanel4, vlChanel5, vlChanel6, vlChanel7, vlChanel8);
	SetDlgItemInt(EDIT_Chanel8, vlChanel8);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}




void CLightControlDlg::OnBnClickedButtonOffall()
{
	SetDlgItemInt(EDIT_Chanel1, 0);
	SetDlgItemInt(EDIT_Chanel2, 0);
	SetDlgItemInt(EDIT_Chanel3, 0);
	SetDlgItemInt(EDIT_Chanel4, 0);
	SetDlgItemInt(EDIT_Chanel5, 0);
	SetDlgItemInt(EDIT_Chanel6, 0);
	SetDlgItemInt(EDIT_Chanel7, 0);
	SetDlgItemInt(EDIT_Chanel8, 0);
	OnBnClickedSetvalue();
	Sleep(1);
	// TODO: Add your control notification handler code here
}
