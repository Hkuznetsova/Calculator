#pragma once
#include "resource.h"	
#include "afxwin.h"

#include <vector>

// TabMatrix dialog

class TabMatrix : public CDialog
{
	DECLARE_DYNAMIC(TabMatrix)

public:
	TabMatrix(CWnd* pParent = NULL);   // standard constructor
	virtual ~TabMatrix();

// Dialog Data
	enum { IDD = IDD_TAB_MATRIX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCrtMatr();

	CString 
		A00, A01, A02, A03, 
		A10, A11, A12, A13, 
		A20, A21, A22, A23, 
		A30, A31, A32, A33;
	CString
		B00, B01, B02, B03,
		B10, B11, B12, B13,
		B20, B21, B22, B23,
		B30, B31, B32, B33;
	CString
		C00, C01, C02, C03,
		C10, C11, C12, C13,
		C20, C21, C22, C23,
		C30, C31, C32, C33;

	std::vector<std::vector<CString*>> MatrixACString;
	std::vector<std::vector<CString*>> MatrixBCString;
	std::vector<std::vector<CString*>> MatrixCCString;

	std::vector<std::vector<double>> MatrixA;
	std::vector<std::vector<double>> MatrixB;
	std::vector<std::vector<double>> MatrixC;
private:
	void FillMatrixVector(std::vector<std::vector<double>>& matrix, std::vector<std::vector<CString*>>& MatrixCString);
	int MatrixSize;
public:
	void CalculateMatrixMult();
	void OutputResultMatrixMult();
};
