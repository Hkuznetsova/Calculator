
// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CalculatorApp.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorDlg::IDD, pParent)
	, resultValueString(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
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

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CCalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_EQUALLY, &CCalculatorDlg::OnBnClickedButtonEqually)
	ON_BN_CLICKED(IDC_BUTTON_DIVISION, &CCalculatorDlg::OnBnClickedButtonDivision)
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_MULT, &CCalculatorDlg::OnBnClickedButtonMult)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
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


	font.CreateFont(32, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET,
		0, 0, 0, 0, _T("Microsoft Sans Serif"));
	srand(time(NULL));
	
	for each (CMFCButton* item in buttons)
	{
		(*item).EnableWindowsTheming(FALSE);
		(*item).SetFaceColor(RGB(rand() % 255, rand() % 255, rand() % 255));
		(*item).SetFont(&font);
	}
	EditResult.SetFont(&font);
	ToClearState();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


double GetValueFromString(std::string value)
{
	return std::stod(value);
}

void CCalculatorDlg::OnBnClickedButtonDot()
{
	AddNumberToResultValue('.');
}


void CCalculatorDlg::OnBnClickedButton0()
{
	AddNumberToResultValue('0');
}

void CCalculatorDlg::OnBnClickedButton1()
{
	AddNumberToResultValue('1');
}


void CCalculatorDlg::OnBnClickedButton2()
{
	AddNumberToResultValue('2');
}


void CCalculatorDlg::OnBnClickedButton3()
{
	AddNumberToResultValue('3');
}

void CCalculatorDlg::OnBnClickedButton4()
{
	AddNumberToResultValue('4');
}


void CCalculatorDlg::OnBnClickedButton5()
{
	AddNumberToResultValue('5');
}


void CCalculatorDlg::OnBnClickedButton6()
{
	AddNumberToResultValue('6');
}

void CCalculatorDlg::OnBnClickedButton7()
{
	AddNumberToResultValue('7');
}


void CCalculatorDlg::OnBnClickedButton8()
{
	AddNumberToResultValue('8');
}


void CCalculatorDlg::OnBnClickedButton9()
{
	AddNumberToResultValue('9');
}

void CCalculatorDlg::AddNumberToResultValue(char num)
{

	resultValueString += num;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedButtonMinus()
{
	CheckOperation(1);
}

void CCalculatorDlg::OnBnClickedButtonMult()
{
	CheckOperation(2);
}


void CCalculatorDlg::OnBnClickedButtonEqually()
{
	CheckOperation(4);
}


void CCalculatorDlg::OnBnClickedButtonDivision()
{
	CheckOperation(3);
}


void CCalculatorDlg::OnBnClickedButtonPlus()
{
	CheckOperation(0);
}

void CCalculatorDlg::OnBnClickedButtonClear()
{
	ToClearState();
}

void CCalculatorDlg::ToClearState()
{
	value1 = 0;
	value2 = 0;
	operationNumBuffer = -1;
	resultValueString = "";
	UpdateData(FALSE);
}

void CCalculatorDlg::CheckOperation(int opNum)
{
	if (operationNumBuffer < 0)
	{
		value1 = _wtof(resultValueString);
		operationNumBuffer = opNum;
		resultValueString = "";
	} else if (opNum == 4)
	{
		value2 = _wtof(resultValueString);
		value1 = CalculateResult();
		resultValueString.Format(L"%g", value1);
		UpdateData(FALSE);
		operationNumBuffer = -1;
	}
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
double CCalculatorDlg::CalculateResult()
{
	double result;
	switch (operationNumBuffer) {
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

