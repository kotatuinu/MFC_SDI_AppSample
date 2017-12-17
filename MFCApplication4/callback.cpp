#include "stdafx.h"
#include "callback.h"


callback::callback()
	:m_cRef(1),
	m_pCond(NULL),
	m_status(PROGRESS_STATUS::STOP),
	m_maxCnt(0),
	m_progressCnt(0)
{
	m_cRef = 1;
}


callback::~callback()
{
}

STDMETHODIMP callback::QueryInterface(REFIID riid, void **ppvObject)
{
	*ppvObject = NULL;

	if (IsEqualIID(riid, IID_IUnknown) || IsEqualIID(riid, IID_IBindStatusCallback)) {
		*ppvObject = static_cast<IBindStatusCallback *>(this);
	}
	else {
		return E_NOINTERFACE;
	}

	AddRef();

	return S_OK;
}


STDMETHODIMP_(ULONG) callback::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}

STDMETHODIMP_(ULONG) callback::Release()
{
	if (InterlockedDecrement(&m_cRef) == 0) {
		delete this;
		return 0;
	}

	return m_cRef;
}

STDMETHODIMP callback::OnStartBinding(DWORD dwReserved, IBinding *pib)
{
	m_status = callback::PROGRESS_STATUS::START;
	m_pCond->notify_one();
	return S_OK;
}

STDMETHODIMP callback::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
{
	m_maxCnt = ulProgressMax;
	m_progressCnt = ulProgress;
	m_status = callback::PROGRESS_STATUS::START;
	m_pCond->notify_one();
	/*
	switch (ulStatusCode) {
	case BINDSTATUS_FINDINGRESOURCE:
		break;
	case BINDSTATUS_CONNECTING:
		break;
	case BINDSTATUS_SENDINGREQUEST:
		break;
	case BINDSTATUS_MIMETYPEAVAILABLE:
		break;
	case BINDSTATUS_BEGINDOWNLOADDATA:
		break;
	case BINDSTATUS_DOWNLOADINGDATA:
		break;
	case BINDSTATUS_ENDDOWNLOADDATA:
		break;
	case BINDSTATUS_COOKIE_SENT:
		break;
	case BINDSTATUS_CACHEFILENAMEAVAILABLE:
		break;
	default:
		break;
	}
*/
	return S_OK;
}

STDMETHODIMP callback::OnStopBinding(HRESULT hresult, LPCWSTR szError)
{
	TCHAR szBuf[256];

	if (SUCCEEDED(hresult)) {
		m_pCond->notify_one();
		m_status = callback::PROGRESS_STATUS::END_NORMAL;
		lstrcpy(szBuf, TEXT("OnStopBinding"));
	}
	else {
		m_status = callback::PROGRESS_STATUS::END_ABNORMAL;
		wsprintf(szBuf, TEXT("OnStopBinding (error %x)"), hresult);
	}
	return S_OK;
}

STDMETHODIMP callback::GetPriority(LONG *pnPriority)
{
	return E_NOTIMPL;
}

STDMETHODIMP callback::OnLowResource(DWORD reserved)
{
	return E_NOTIMPL;
}

STDMETHODIMP callback::GetBindInfo(DWORD *grfBINDF, BINDINFO *pbindinfo)
{
	//*grfBINDF = BINDF_ASYNCHRONOUS | BINDF_ASYNCSTORAGE | BINDF_PULLDATA | BINDF_GETNEWESTVERSION | BINDF_NOWRITECACHE;
	//return S_OK;
	return E_NOTIMPL;
}

STDMETHODIMP callback::OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC *pformatetc, STGMEDIUM *pstgmed)
{
	return E_NOTIMPL;
}

STDMETHODIMP callback::OnObjectAvailable(REFIID riid, IUnknown *punk)
{
	return E_NOTIMPL;
}

STDMETHODIMP callback::SetConditionVariable(std::condition_variable *pCond)
{
	m_pCond = pCond;
	return S_OK;
}

STDMETHODIMP callback::GetStatus(callback::PROGRESS_STATUS &status, ULONG &maxCnt, ULONG &progressCnt)
{

	status = m_status;
	maxCnt = m_maxCnt;
	progressCnt = m_progressCnt;
	return S_OK;
}
