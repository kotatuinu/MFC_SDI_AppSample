#pragma once
#include <vector>

class CViewFrameController
{
private:
	std::vector<CSingleDocTemplate*> m_pDocTemplateList;
	static CViewFrameController* m_instance;

public:
	static CViewFrameController* getInstance();
	~CViewFrameController();

	long addFrame(CSingleDocTemplate* pDocTemplate);
	void remeoveFrame(CSingleDocTemplate* pDocTemplate);

	long getListSIze();

	void changeFrame(long no, CDocument *pDoc);
private:
	CViewFrameController();

};

