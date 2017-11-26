#include "stdafx.h"
#include "CViewFrameController.h"
#include <iterator>

CViewFrameController* CViewFrameController::m_instance = NULL;

CViewFrameController::CViewFrameController()
{
}


CViewFrameController::~CViewFrameController()
{
	for (std::vector<CSingleDocTemplate*>::iterator ite = m_pDocTemplateList.begin(); ite != m_pDocTemplateList.end(); ite++)
	{
		delete *ite;
	}
}

CViewFrameController* CViewFrameController::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new CViewFrameController();
	}
	return m_instance;
}

long CViewFrameController::addFrame(CSingleDocTemplate* pDocTemplate)
{
	m_pDocTemplateList.push_back(pDocTemplate);
	return m_pDocTemplateList.size();
}

void CViewFrameController::remeoveFrame(CSingleDocTemplate* pDocTemplate)
{
	for (std::vector<CSingleDocTemplate*>::iterator ite = m_pDocTemplateList.begin(); ite != m_pDocTemplateList.end(); ite++)
	{
		if (pDocTemplate == *ite) {
			m_pDocTemplateList.erase(ite);
		}
	}
}

long CViewFrameController::getListSIze()
{
	return m_pDocTemplateList.size();
}

void CViewFrameController::changeFrame(long no, CDocument *pDoc)
{
	if (m_pDocTemplateList.size() > (ULONG)no)
	{
		CSingleDocTemplate *instance = m_pDocTemplateList[no];
		instance->InitialUpdateFrame(instance->CreateNewFrame(pDoc, 0), 0);
	}
}
