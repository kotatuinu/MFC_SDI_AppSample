#pragma once
#include <vector>

class CSDIViewChanger
{
private:
	CWnd* m_pMainWnd;       // main window (usually same AfxGetApp()->m_pMainWnd)
	CView* m_MainView;
	std::vector<CView*> m_ViewList;
	UINT m_viewID;

public:
	CSDIViewChanger();
	~CSDIViewChanger();

	void setMainWnd(CWnd* pMainWnd);
	long addView(CView* view);
	void removeView(CView* view);

	long getListSize();

	void SwitchMainView(const WCHAR* windowTitle = NULL);
	CView* SwitchView(CView* pNewView, const WCHAR* windowTitle = NULL);
	void SwitchView(ULONG no);
private:
	void copyViewParam(CView* pNewView);
};

