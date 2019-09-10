// TabCalc.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "TabCalc.h"
#include "afxdialogex.h"


// TabCalc dialog

IMPLEMENT_DYNAMIC(TabCalc, CDialog)

TabCalc::TabCalc(CWnd* pParent /*=NULL*/)
	: CDialog(TabCalc::IDD, pParent)
	, resultValueString(_T(""))
{

}

TabCalc::~TabCalc()
{
}
BOOL TabCalc::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Add buttons to vector
	buttons.push_back(&button0);
	buttons.push_back(&button1);
	buttons.push_back(&button2);
	buttons.push_back(&button3);
	buttons.push_back(&button4);
	buttons.push_back(&button5);
	buttons.push_back(&button6);
	buttons.push_back(&button7);
	buttons.push_back(&button8);
	buttons.push_back(&button9);
	buttons.push_back(&buttonDot);
	buttons.push_back(&buttonMult);
	buttons.push_back(&buttonMinus);
	buttons.push_back(&buttonPlus);
	buttons.push_back(&buttonDiv);
	buttons.push_back(&buttonEqual);
	buttons.push_back(&buttonC);
	value1 = 0;

	// create font
	font.CreateFont(32, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET,
	0, 0, 0, 0, _T("Microsoft Sans Serif"));
	srand(time(NULL));

	// init buttons with font and color
	for each (CMFCButton* item in buttons)
	{
		(*item).EnableWindowsTheming(FALSE);
		(*item).SetFaceColor(RGB(rand() % 255, rand() % 255, rand() % 255));
		(*item).SetFont(&font);
	}
	EditResult.SetFont(&font);
	Clear();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void TabCalc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BUTTON_DOT, buttonDot);
	DDX_Control(pDX, IDC_BUTTON_MULT, buttonMult);
	DDX_Control(pDX, IDC_BUTTON_MINUS, buttonMinus);
	DDX_Control(pDX, IDC_BUTTON_PLUS, buttonPlus);
	DDX_Control(pDX, IDC_BUTTON_DIVISION, buttonDiv);
	DDX_Control(pDX, IDC_BUTTON_EQUALLY, buttonEqual);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, buttonC);
	DDX_Control(pDX, IDC_BUTTON_0, button0);
	DDX_Control(pDX, IDC_BUTTON_1, button1);
	DDX_Control(pDX, IDC_BUTTON_2, button2);
	DDX_Control(pDX, IDC_BUTTON_3, button3);
	DDX_Control(pDX, IDC_BUTTON_4, button4);
	DDX_Control(pDX, IDC_BUTTON_5, button5);
	DDX_Control(pDX, IDC_BUTTON_6, button6);
	DDX_Control(pDX, IDC_BUTTON_7, button7);
	DDX_Control(pDX, IDC_BUTTON_8, button8);
	DDX_Control(pDX, IDC_BUTTON_9, button9);
	DDX_Text(pDX, IDC_EDIT_RESULT, resultValueString);
	DDX_Control(pDX, IDC_EDIT_RESULT, EditResult);
}


BEGIN_MESSAGE_MAP(TabCalc, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_0, &TabCalc::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &TabCalc::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &TabCalc::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &TabCalc::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &TabCalc::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &TabCalc::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &TabCalc::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &TabCalc::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &TabCalc::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &TabCalc::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &TabCalc::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULT, &TabCalc::OnBnClickedButtonMult)
	ON_BN_CLICKED(IDC_BUTTON_EQUALLY, &TabCalc::OnBnClickedButtonEqually)
	ON_BN_CLICKED(IDC_BUTTON_DIVISION, &TabCalc::OnBnClickedButtonDivision)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &TabCalc::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &TabCalc::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &TabCalc::OnBnClickedButtonDot)
END_MESSAGE_MAP()


// TabCalc message handlers

void TabCalc::OnBnClickedButtonDot()
{
	AddNumberToResultValue('.');
}


void TabCalc::OnBnClickedButton0()
{
	AddNumberToResultValue('0');
}

void TabCalc::OnBnClickedButton1()
{
	AddNumberToResultValue('1');
}


void TabCalc::OnBnClickedButton2()
{
	AddNumberToResultValue('2');
}


void TabCalc::OnBnClickedButton3()
{
	AddNumberToResultValue('3');
}

void TabCalc::OnBnClickedButton4()
{
	AddNumberToResultValue('4');
}


void TabCalc::OnBnClickedButton5()
{
	AddNumberToResultValue('5');
}


void TabCalc::OnBnClickedButton6()
{
	AddNumberToResultValue('6');
}

void TabCalc::OnBnClickedButton7()
{
	AddNumberToResultValue('7');
}


void TabCalc::OnBnClickedButton8()
{
	AddNumberToResultValue('8');
}


void TabCalc::OnBnClickedButton9()
{
	AddNumberToResultValue('9');
}

void TabCalc::AddNumberToResultValue(char num)
{
	resultValueString += num;
	UpdateData(FALSE);
}

void TabCalc::OnBnClickedButtonMinus()
{
	CheckOperation(1);
}

void TabCalc::OnBnClickedButtonMult()
{
	CheckOperation(2);
}


void TabCalc::OnBnClickedButtonEqually()
{
	CheckOperation(4);
}


void TabCalc::OnBnClickedButtonDivision()
{
	CheckOperation(3);
}


void TabCalc::OnBnClickedButtonPlus()
{
	CheckOperation(0);
}

void TabCalc::OnBnClickedButtonClear()
{
	Clear();
}

void TabCalc::Clear()
{
	value1 = 0;
	value2 = 0;
	operationNumBuffer = -1;
	resultValueString = "";
	UpdateData(FALSE);
}

void TabCalc::CheckOperation(int opNum)
{
	// if operation is first
	if (operationNumBuffer < 0)
	{
		value1 = _wtof(resultValueString);
		operationNumBuffer = opNum;
		resultValueString = "";
	}
	// if operation is =
	else if (opNum == 4)
	{
		value2 = _wtof(resultValueString);
		value1 = CalculateResult();

		resultValueString.Format(L"%g", value1);
		UpdateData(FALSE);

		operationNumBuffer = -1;
	}
	// if operation is + - / x
	else if (opNum >= 0)
	{
		value2 = _wtof(resultValueString);
		value1 = CalculateResult();

		operationNumBuffer = opNum;

		resultValueString.Format(L"%g", value1);
		UpdateData(FALSE);
		resultValueString = "";

	}
}
double TabCalc::CalculateResult()
{
	double result;
	switch (operationNumBuffer) 
	{
		case 0:
		{
				  return value1 + value2;
				  break;
		}
		case 1:
		{
				  return  value1 - value2;
				  break;
		}
		case 2:
		{
				  return value1 * value2;
				  break;
		}
		case 3:
		{
				  return value1 / value2;
				  break;
		}
		default:
		{
				   return value1;
				   break;
		}
	}
}