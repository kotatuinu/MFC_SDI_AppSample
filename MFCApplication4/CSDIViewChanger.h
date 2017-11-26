#pragma once
#include <vector>

class CSDIViewChanger
{
private:
	static CWnd* m_pMainWnd;       // main window (usually same AfxGetApp()->m_pMainWnd)
	std::vector<CView*> m_ViewList;
	static CSDIViewChanger* m_instance;

public:
	CSDIViewChanger();
	~CSDIViewChanger();
	static CSDIViewChanger* getInstance();

	static void setMainWnd(CWnd* pMainWnd);
	long addActiveView(CView* view);
	void removeActiveView(CView* view);

	long getListSize();

	CView* SwitchView(CView* pNewView);
	void SwitchView(ULONG no);
private:

};

