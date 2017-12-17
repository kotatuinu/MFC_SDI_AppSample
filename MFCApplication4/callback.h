#pragma once
#include "urlmon.h"
#include <condition_variable>

class callback :
	public IBindStatusCallback
{
public:
	callback();
	~callback();

	typedef enum {
		STOP,
		START,
		END_NORMAL,
		END_ABNORMAL,
		END_CANCEL,
	} PROGRESS_STATUS;

	STDMETHODIMP QueryInterface(REFIID riid, void **ppvObject);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	STDMETHODIMP OnStartBinding(DWORD dwReserved, IBinding *pib);
	STDMETHODIMP GetPriority(LONG *pnPriority);
	STDMETHODIMP OnLowResource(DWORD reserved);
	STDMETHODIMP OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText);
	STDMETHODIMP OnStopBinding(HRESULT hresult, LPCWSTR szError);
	STDMETHODIMP GetBindInfo(DWORD *grfBINDF, BINDINFO *pbindinfo);
	STDMETHODIMP OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC *pformatetc, STGMEDIUM *pstgmed);
	STDMETHODIMP OnObjectAvailable(REFIID riid, IUnknown *punk);

	STDMETHODIMP SetConditionVariable(std::condition_variable *pCond);
	STDMETHODIMP GetStatus(callback::PROGRESS_STATUS &status, ULONG &maxCnt, ULONG &progressCnt);

private:
	LONG m_cRef;
	std::condition_variable *m_pCond;
	PROGRESS_STATUS m_status;
	ULONG m_maxCnt;
	ULONG m_progressCnt;
};

