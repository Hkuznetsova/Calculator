// TabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "TabCtrl.h"
#include "TabCalc.h"
#include "TabMatrix.h"

// TabCtrl

IMPLEMENT_DYNAMIC(TabCtrl, CTabCtrl)

TabCtrl::TabCtrl()
{
	tabPages[0] = new TabCalc;
	tabPages[1] = new TabMatrix;
	numOfPages = 2;
}

TabCtrl::~TabCtrl()
{
	for (int i = 0; i < numOfPages; i++)
	{
		delete(tabPages[i]);
	}
}


BEGIN_MESSAGE_MAP(TabCtrl, CTabCtrl)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// TabCtrl message handlers




void TabCtrl::Init()
{
	tabCurrent = 0;

	tabPages[0]->Create(IDD_TAB_CALC, this);
	tabPages[1]->Create(IDD_TAB_MATRIX, this);

	tabPages[0]->ShowWindow(SW_SHOW);
	tabPages[1]->ShowWindow(SW_HIDE);

	//put information inside the tab
	SetRectangle();
}


void TabCtrl::SetRectangle()
{
	CRect tabRect, itemRect;
	int nx, ny, nxc, nyc;

	GetClientRect(&tabRect);
	GetItemRect(0, &itemRect);

	nx = itemRect.left;
	ny = itemRect.bottom + 1;
	nxc = tabRect.right - itemRect.left - 1;
	nyc = tabRect.bottom - ny - 1;
	tabPages[0]->SetWindowPos(&wndTop, nx, ny, nxc, nyc, SWP_SHOWWINDOW);

	for (int i = 1; i < numOfPages; i++)
	{
		tabPages[i]->SetWindowPos(&wndTop, nx, ny, nxc, nyc, SWP_HIDEWINDOW);
	}
}




void TabCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTabCtrl::OnLButtonDown(nFlags, point);

	if (tabCurrent != GetCurFocus())
	{
		tabPages[tabCurrent]->ShowWindow(SW_HIDE);
		tabCurrent = GetCurFocus();
		tabPages[tabCurrent]->ShowWindow(SW_SHOW);
		tabPages[tabCurrent]->GetFocus();
	}
}
