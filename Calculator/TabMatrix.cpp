// TabMatrix.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "TabMatrix.h"
#include "afxdialogex.h"


// TabMatrix dialog

IMPLEMENT_DYNAMIC(TabMatrix, CDialog)

BOOL TabMatrix::OnInitDialog()
{
	CDialog::OnInitDialog();

	MatrixACString.push_back(std::vector<CString*>());
	MatrixACString[MatrixACString.size() - 1].push_back(&A00);
	MatrixACString[MatrixACString.size() - 1].push_back(&A01);
	MatrixACString[MatrixACString.size() - 1].push_back(&A02);
	MatrixACString[MatrixACString.size() - 1].push_back(&A03);

	MatrixACString.push_back(std::vector<CString*>());
	MatrixACString[MatrixACString.size() - 1].push_back(&A10);
	MatrixACString[MatrixACString.size() - 1].push_back(&A11);
	MatrixACString[MatrixACString.size() - 1].push_back(&A12);
	MatrixACString[MatrixACString.size() - 1].push_back(&A13);

	MatrixACString.push_back(std::vector<CString*>());
	MatrixACString[MatrixACString.size() - 1].push_back(&A20);
	MatrixACString[MatrixACString.size() - 1].push_back(&A21);
	MatrixACString[MatrixACString.size() - 1].push_back(&A22);
	MatrixACString[MatrixACString.size() - 1].push_back(&A23);

	MatrixACString.push_back(std::vector<CString*>());
	MatrixACString[MatrixACString.size() - 1].push_back(&A30);
	MatrixACString[MatrixACString.size() - 1].push_back(&A31);
	MatrixACString[MatrixACString.size() - 1].push_back(&A32);
	MatrixACString[MatrixACString.size() - 1].push_back(&A33);

	MatrixBCString.push_back(std::vector<CString*>());
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B00);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B01);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B02);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B03);

	MatrixBCString.push_back(std::vector<CString*>());
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B10);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B11);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B12);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B13);

	MatrixBCString.push_back(std::vector<CString*>());
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B20);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B21);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B22);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B23);

	MatrixBCString.push_back(std::vector<CString*>());
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B30);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B31);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B32);
	MatrixBCString[MatrixBCString.size() - 1].push_back(&B33);

	MatrixCCString.push_back(std::vector<CString*>());
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C00);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C01);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C02);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C03);

	MatrixCCString.push_back(std::vector<CString*>());
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C10);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C11);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C12);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C13);

	MatrixCCString.push_back(std::vector<CString*>());
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C20);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C21);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C22);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C23);

	MatrixCCString.push_back(std::vector<CString*>());
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C30);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C31);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C32);
	MatrixCCString[MatrixCCString.size() - 1].push_back(&C33);

	MatrixSize = 4;

	return TRUE;  // return TRUE  unless you set the focus to a control
}
TabMatrix::TabMatrix(CWnd* pParent /*=NULL*/)
	: CDialog(TabMatrix::IDD, pParent)
	, A00(_T("1")), A01(_T("1")), A02(_T("1")), A03(_T("1"))
	, A10(_T("1")), A11(_T("1")), A12(_T("1")), A13(_T("1"))
	, A20(_T("1")), A21(_T("1")), A22(_T("1")), A23(_T("1"))
	, A30(_T("1")), A31(_T("1")), A32(_T("1")), A33(_T("1"))

	, B00(_T("1")), B01(_T("1")), B02(_T("1")), B03(_T("1"))
	, B10(_T("1")), B11(_T("1")), B12(_T("1")), B13(_T("1"))
	, B20(_T("1")), B21(_T("1")), B22(_T("1")), B23(_T("1"))
	, B30(_T("1")), B31(_T("1")), B32(_T("1")), B33(_T("1"))

	, C00(_T("")), C01(_T("")), C02(_T("")), C03(_T(""))
	, C10(_T("")), C11(_T("")), C12(_T("")), C13(_T(""))
	, C20(_T("")), C21(_T("")), C22(_T("")), C23(_T(""))
	, C30(_T("")), C31(_T("")), C32(_T("")), C33(_T(""))
	, MatrixSize(0)
{

}

TabMatrix::~TabMatrix()
{
}

void TabMatrix::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT11, A00); DDX_Text(pDX, IDC_EDIT12, A01); DDX_Text(pDX, IDC_EDIT13, A02); DDX_Text(pDX, IDC_EDIT14, A03);
	DDX_Text(pDX, IDC_EDIT15, A10); DDX_Text(pDX, IDC_EDIT16, A11); DDX_Text(pDX, IDC_EDIT17, A12); DDX_Text(pDX, IDC_EDIT18, A13);
	DDX_Text(pDX, IDC_EDIT19, A20); DDX_Text(pDX, IDC_EDIT20, A21); DDX_Text(pDX, IDC_EDIT21, A22); DDX_Text(pDX, IDC_EDIT22, A23);
	DDX_Text(pDX, IDC_EDIT23, A30); DDX_Text(pDX, IDC_EDIT24, A31); DDX_Text(pDX, IDC_EDIT25, A32); DDX_Text(pDX, IDC_EDIT26, A33);

	DDX_Text(pDX, IDC_EDIT27, B00); DDX_Text(pDX, IDC_EDIT28, B01); DDX_Text(pDX, IDC_EDIT29, B02); DDX_Text(pDX, IDC_EDIT30, B03);
	DDX_Text(pDX, IDC_EDIT31, B10); DDX_Text(pDX, IDC_EDIT32, B11); DDX_Text(pDX, IDC_EDIT33, B12); DDX_Text(pDX, IDC_EDIT34, B13);
	DDX_Text(pDX, IDC_EDIT35, B20); DDX_Text(pDX, IDC_EDIT36, B21); DDX_Text(pDX, IDC_EDIT37, B22); DDX_Text(pDX, IDC_EDIT38, B23);
	DDX_Text(pDX, IDC_EDIT39, B30); DDX_Text(pDX, IDC_EDIT40, B31); DDX_Text(pDX, IDC_EDIT41, B32); DDX_Text(pDX, IDC_EDIT42, B33);

	DDX_Text(pDX, IDC_EDIT43, C00); DDX_Text(pDX, IDC_EDIT44, C01); DDX_Text(pDX, IDC_EDIT45, C02); DDX_Text(pDX, IDC_EDIT46, C03);
	DDX_Text(pDX, IDC_EDIT47, C10); DDX_Text(pDX, IDC_EDIT48, C11); DDX_Text(pDX, IDC_EDIT49, C12); DDX_Text(pDX, IDC_EDIT50, C13);
	DDX_Text(pDX, IDC_EDIT51, C20); DDX_Text(pDX, IDC_EDIT52, C21); DDX_Text(pDX, IDC_EDIT53, C22); DDX_Text(pDX, IDC_EDIT54, C23);
	DDX_Text(pDX, IDC_EDIT55, C30); DDX_Text(pDX, IDC_EDIT56, C31); DDX_Text(pDX, IDC_EDIT57, C32); DDX_Text(pDX, IDC_EDIT58, C33);
}


BEGIN_MESSAGE_MAP(TabMatrix, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_CRT_MATR, &TabMatrix::OnBnClickedButtonCrtMatr)
END_MESSAGE_MAP()


// TabMatrix message handlers


void TabMatrix::OnBnClickedButtonCrtMatr()
{
	FillMatrixVector(MatrixA, MatrixACString);
	FillMatrixVector(MatrixB, MatrixBCString);
	CalculateMatrixMult();
	OutputResultMatrixMult();
}

void TabMatrix::FillMatrixVector(std::vector<std::vector<double>>& matrix, std::vector<std::vector<CString*>>& MatrixCString)
{
	matrix.clear();
	for (int i = 0; i < MatrixCString.size(); i++)
	{
		matrix.push_back(std::vector<double>());
		for (int j = 0; j < MatrixCString[i].size(); j++)
		{
			UpdateData(true);
			matrix[matrix.size() - 1].push_back(_wtof(*MatrixCString[i][j]));
		}
	}
}


void TabMatrix::CalculateMatrixMult()
{
	MatrixC.clear();
	for (int i = 0; i < MatrixSize; i++)
	{
		MatrixC.push_back(std::vector<double>());
		for (int j = 0; j < MatrixSize; j++)
		{
			MatrixC[MatrixC.size() - 1].push_back(0);
			for (int k = 0; k < MatrixSize; k++)
				MatrixC[i][j] += MatrixA[i][k] * MatrixB[k][j];
		}
	}
}


void TabMatrix::OutputResultMatrixMult()
{

	for (int i = 0; i < MatrixSize; i++)
	{
		for (int j = 0; j < MatrixSize; j++)
		{
			(*MatrixCCString[i][j]).Format(L"%g", MatrixC[i][j]);
			UpdateData(FALSE);
		}
	}
}
