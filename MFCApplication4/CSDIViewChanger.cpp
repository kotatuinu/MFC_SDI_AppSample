#include "stdafx.h"
#include "CSDIViewChanger.h"

CSDIViewChanger* CSDIViewChanger::m_instance = NULL;
CWnd* CSDIViewChanger::m_pMainWnd = NULL;

CSDIViewChanger::CSDIViewChanger()
{
}

CSDIViewChanger::~CSDIViewChanger()
{
	for (std::vector<CView*>::iterator ite = m_ViewList.begin(); ite != m_ViewList.end(); ite++)
	{
		delete *ite;
	}
}

CSDIViewChanger* CSDIViewChanger::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new CSDIViewChanger();
	}
	return m_instance;
}

void CSDIViewChanger::setMainWnd(CWnd* pMainWnd)
{
	m_pMainWnd = pMainWnd;
}

long CSDIViewChanger::addActiveView(CView* view)
{
	m_ViewList.push_back(view);
	return m_ViewList.size();
}
void removeActiveView(CView* view);

void CSDIViewChanger::removeActiveView(CView* view)
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
/*
void CSDIViewChanger::x()
{
	CView* pActiveView = ((CFrameWnd*)m_pMainWnd)->GetActiveView();
	m_pView2 = pActiveView;
	m_pView3 = new CFormViewTest3();

	CDocument* pCurrentDoc = ((CFrameWnd*)m_pMainWnd)->GetActiveDocument();
	CCreateContext newContext;
	newContext.m_pNewViewClass = NULL;
	newContext.m_pNewDocTemplate = NULL;
	newContext.m_pLastView = NULL;
	newContext.m_pCurrentFrame = NULL;
	newContext.m_pCurrentDoc = pCurrentDoc;

	UINT viewID = AFX_IDW_PANE_FIRST + 1;
	CRect rect(0, 0, 0, 0); // gets resized later
	m_pView3->Create(NULL, _T("View3"), WS_CHILD, rect, m_pMainWnd, viewID, &newContext);

	m_pView3->ModifyStyleEx(0, WS_EX_CLIENTEDGE);
	m_pView3->OnInitialUpdate();

}
*/
CView* CSDIViewChanger::SwitchView(CView* pNewView)
{
	CView* pActiveView = ((CFrameWnd*)m_pMainWnd)->GetActiveView();

	UINT temp = ::GetWindowLong(pActiveView->m_hWnd, GWL_ID);
	::SetWindowLong(pActiveView->m_hWnd, GWL_ID, ::GetWindowLong(pNewView->m_hWnd, GWL_ID));
	::SetWindowLong(pNewView->m_hWnd, GWL_ID, temp);

	pActiveView->ShowWindow(SW_HIDE);
	pNewView->ShowWindow(SW_SHOW);
	((CFrameWnd*)m_pMainWnd)->SetActiveView(pNewView);
	((CFrameWnd*)m_pMainWnd)->RecalcLayout();
	pNewView->Invalidate();
	return pActiveView;
}

void CSDIViewChanger::SwitchView(ULONG no)
{

	if (getListSize() > no)
	{
		// ERROR
		return;
	}
	SwitchView(m_ViewList.at(no));
}
