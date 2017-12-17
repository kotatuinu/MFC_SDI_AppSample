#include "stdafx.h"
#include "CProgressObserver.h"


CProgressObserver::CProgressObserver()
{
}


CProgressObserver::~CProgressObserver()
{
}

void CProgressObserver::notify(PROGRESS_STATUS status, ULONG maxCount, ULONG progressCnt)
{
	TRACE("CProgressObserver::notify status=%d, maxCnt=%d, progressCnt=%d\n", status, maxCount, progressCnt);
}
