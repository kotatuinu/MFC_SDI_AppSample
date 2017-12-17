#pragma once

class CProgressObserver
{
public:
	CProgressObserver();
	~CProgressObserver();

	typedef enum {
		STOP,
		START,
		END_NORMAL,
		END_ABNORMAL,
		END_CANCEL,
	} PROGRESS_STATUS;

	void notify(PROGRESS_STATUS status, ULONG maxCount, ULONG progressIndex);

};

