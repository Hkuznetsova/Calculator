#pragma once
#include "resource.h"	
#include <vector>
#include <random>
#include <ctime> 
#include <string>  
#include <iostream>  
#include "afxwin.h"
// TabCalc dialog

class TabCalc : public CDialog
{
	DECLARE_DYNAMIC(TabCalc)

public:
	TabCalc(CWnd* pParent = NULL);   // standard constructor
	virtual ~TabCalc();

// Dialog Data
	enum { IDD = IDD_TAB_CALC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
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

	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonEqually();
	afx_msg void OnBnClickedButtonDivision();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonMult();
	afx_msg void AddNumberToResultValue(char num);
	afx_msg std::string GetStringFromValue(double value);
	afx_msg double CalculateResult();
	afx_msg void Clear();
	afx_msg void CheckOperation(int operationNum);

private:
	std::vector<CMFCButton> buttonVect;
	CFont font;
	CString resultValueString;
	std::vector<CMFCButton*> buttons;
	int operationNumBuffer;
	double value1;
	double value2;
};
