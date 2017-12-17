#include "stdafx.h"
#include <map>
#include "controller.h"
#include "converter.h"
#include "callback.h"


const static std::map<callback::PROGRESS_STATUS, CProgressObserver::PROGRESS_STATUS> PROGRESS_STATUS_CONVERT = {
	{ callback::PROGRESS_STATUS::STOP, CProgressObserver::PROGRESS_STATUS::STOP },
	{ callback::PROGRESS_STATUS::START, CProgressObserver::PROGRESS_STATUS::START },
	{ callback::PROGRESS_STATUS::END_NORMAL, CProgressObserver::PROGRESS_STATUS::END_NORMAL },
	{ callback::PROGRESS_STATUS::END_ABNORMAL, CProgressObserver::PROGRESS_STATUS::END_ABNORMAL },
	{ callback::PROGRESS_STATUS::END_CANCEL, CProgressObserver::PROGRESS_STATUS::END_CANCEL },
};


controller::controller()
{
}


controller::~controller()
{
}

bool controller::execute()
{
	callback::PROGRESS_STATUS status = callback::PROGRESS_STATUS::STOP;
	converter obj;
	callback callbackObj;
	callbackObj.SetConditionVariable(&cond_);
	std::unique_lock<std::mutex> lk(mtx_);
	obj.execute(&callbackObj);
	do {
		cond_.wait(lk);
		ULONG maxCnt = 0;
		ULONG progressCnt = 0;
		callbackObj.GetStatus(status, maxCnt, progressCnt);
		for (decltype(m_observersList)::iterator ite = m_observersList.begin(); ite != m_observersList.end(); ite++)
		{
			(*ite)->notify(PROGRESS_STATUS_CONVERT.at(status), maxCnt, progressCnt);
		}
	} while (status == callback::PROGRESS_STATUS::START);

	return true;
}

void controller::addObserver(CProgressObserver *instanse)
{
	m_observersList.push_back(instanse);
}

void controller::clearObserver()
{
	m_observersList.clear();
}
