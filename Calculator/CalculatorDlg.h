
// CalculatorDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "TabCtrl.h"

// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
	// Construction
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// standard constructor
	TabCtrl tabCntr;
	// Dialog Data
	enum { IDD = IDD_CALCULATOR_DIALOG };

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
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);

};
