
// CalculatorDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include <vector>
#include <random>
#include <ctime> 
#include <string>  
#include <iostream>  

// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

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
	afx_msg void OnBnClickedButtonPlus();
	std::vector<CMFCButton> buttonVect;
private:
	CMFCButton buttonDot;
	CMFCButton buttonMult;
	CMFCButton buttonMinus;
	CMFCButton buttonPlus;
	CMFCButton buttonDiv;
	CMFCButton buttonEqual;
	CMFCButton buttonC;
	CMFCButton button0;
	CMFCButton button1;
	CMFCButton button2;
	CMFCButton button3;
	CMFCButton button4;
	CMFCButton button5;
	CMFCButton button6;
	CMFCButton button7;
	CMFCButton button8;
	CMFCButton button9;
	CEdit EditResult;

	CFont font;

	CString resultValueString;
	std::vector<CMFCButton*> buttons;
	int operationNumBuffer;
	int state;
	double value1;
	double value2;

public:
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonEqually();
	afx_msg void OnBnClickedButtonDivision();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonMult();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void AddNumberToResultValue(char num);
	afx_msg double GetValueFromString(std::string value);
	afx_msg std::string GetStringFromValue(double value);
	afx_msg double CalculateResult();
	afx_msg void ToClearState();
	afx_msg void CheckOperation(int operationNum);
};
