#include "stdafx.h"
#include "CSDIViewChanger.h"

CSDIViewChanger::CSDIViewChanger()
{
	m_viewID = AFX_IDW_PANE_FIRST;
}

CSDIViewChanger::~CSDIViewChanger()
{
}

void CSDIViewChanger::setMainWnd(CWnd* pMainWnd)
{
	m_pMainWnd = pMainWnd;
}

long CSDIViewChanger::addView(CView* view)
{
	m_ViewList.push_back(view);
	return m_ViewList.size();
}
void removeActiveView(CView* view);

void CSDIViewChanger::removeView(CView* view)
{
	for (std::vector<CView*>::iterator ite = m_ViewList.begin(); ite != m_ViewList.end(); ite++)
	{
		if (view == *ite) {
			m_ViewList.erase(ite);
		}
	}
}

long CSDIViewChanger::getListSize()
{
	return m_ViewList.size();
}

//SDI“à‚ÌViewØ‚è‘Ö‚¦
// http://www.softist.com/programming/sdi-multi-view/sdi-multi-view.htm ‚©‚çƒRƒs[

void CSDIViewChanger::copyViewParam(CView* pNewView)
{
	CDocument* pCurrentDoc = ((CFrameWnd*)m_pMainWnd)->GetActiveDocument();
	CCreateContext newContext;
	newContext.m_pNewViewClass = NULL;
	newContext.m_pNewDocTemplate = NULL;
	newContext.m_pLastView = NULL;
	newContext.m_pCurrentFrame = NULL;
	newContext.m_pCurrentDoc = pCurrentDoc;

	m_viewID++;
	CRect rect(0, 0, 0, 0); // gets resized later
	pNewView->Create(NULL, _T(""), WS_CHILD, rect, m_pMainWnd, m_viewID, &newContext);

	pNewView->ModifyStyleEx(0, WS_EX_CLIENTEDGE);
	pNewView->OnInitialUpdate();
}

CView* CSDIViewChanger::SwitchView(CView* pNewView, const WCHAR* windowTitle)
{
	CView* pActiveView = ((CFrameWnd*)m_pMainWnd)->GetActiveView();
	if (pNewView == pActiveView)
	{
		return pActiveView;
	}
	copyViewParam(pNewView);

	UINT temp = ::GetWindowLong(pActiveView->m_hWnd, GWL_ID);
	::SetWindowLong(pActiveView->m_hWnd, GWL_ID, ::GetWindowLong(pNewView->m_hWnd, GWL_ID));
	::SetWindowLong(pNewView->m_hWnd, GWL_ID, temp);

	pActiveView->ShowWindow(SW_HIDE);
	pNewView->ShowWindow(SW_SHOW);
	((CFrameWnd*)m_pMainWnd)->SetActiveView(pNewView);
	((CFrameWnd*)m_pMainWnd)->RecalcLayout();
	pNewView->Invalidate();

	if (windowTitle != NULL)
	{
		m_pMainWnd->SetWindowText(windowTitle);
	}
	return pNewView;
}

void CSDIViewChanger::SwitchMainView(const WCHAR* windowTitle)
{
	SwitchView(m_MainView, windowTitle);
}

void CSDIViewChanger::SwitchView(ULONG no)
{
	try {
		SwitchView(m_ViewList.at(no));
	}
	catch (std::out_of_range &e)
	{
		//error
	}
}
