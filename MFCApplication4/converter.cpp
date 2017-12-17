#include "stdafx.h"
#include "converter.h"


converter::converter()
{
}


converter::~converter()
{
}

void converter::execute(IBindStatusCallback *pCallback)
{
	std::thread t(&converter::convertThread, this, pCallback);
	t.detach();
}

void converter::convertThread(IBindStatusCallback *pCallback)
{
	pCallback->OnStartBinding(0, NULL);
	Sleep(500);
	pCallback->OnProgress(1, 3, 0, _T("test1"));
	Sleep(500);
	pCallback->OnProgress(2, 3, 0, _T("test2"));
	Sleep(500);
	pCallback->OnProgress(3, 3, 0, _T("test3"));
	Sleep(500);
	pCallback->OnStopBinding(S_OK, NULL);
	return;
}