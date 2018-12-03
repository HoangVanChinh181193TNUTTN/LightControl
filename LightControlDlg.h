
// LightControlDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "LightControlDuc.h"


// CLightControlDlg dialog
class CLightControlDlg : public CDialogEx
{
// Construction
public:
	CLightControlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIGHTCONTROL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	CLightControl LightPort;
	CEdit p_GateName;
	CButton m_BtnConnect;
	CEdit m_chanel1;
	CEdit m_Chanel2;
	CEdit m_Chanel3;
	CEdit m_Chanel4;
	afx_msg void OnBnClickedButton2();
	CButton m_BtnSetValue;
	CSliderCtrl m_SliderChanel1;
	CSliderCtrl m_SliderChanel2;
	CSliderCtrl m_SliderChanel3;
	CSliderCtrl m_SliderChanel4;
	afx_msg void OnBnClickedConnect();
	CEdit m_PortName;
	afx_msg void OnBnClickedSetvalue();
	afx_msg void OnNMCustomdrawChanel1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawChanel2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawChanel3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawChanel4(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_SliderChanel5;
	CSliderCtrl m_SliderChanel6;
	CSliderCtrl m_SliderChanel7;
	CSliderCtrl m_SliderChanel8;
	CEdit m_Chanel5;
	CEdit m_Chanel6;
	CEdit m_Chanel7;
	CEdit m_Chanel8;
	afx_msg void OnNMCustomdrawChanel5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawChanel6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawChanel7(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawChanel8(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonOffall();
};
