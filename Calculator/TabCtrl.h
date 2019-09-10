#pragma once


// TabCtrl

class TabCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(TabCtrl)

public:
	TabCtrl();
	virtual ~TabCtrl();
	CDialog *tabPages[2];
	int tabCurrent;
	int numOfPages;
	void Init();

protected:
	DECLARE_MESSAGE_MAP()

	void SetRectangle();
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


