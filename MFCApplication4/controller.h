#pragma once
#include "urlmon.h"
#include "CProgressObserver.h"
#include <vector>
#include <mutex>
#include <condition_variable>

class controller
{
private:
	std::vector<CProgressObserver*> m_observersList;
	std::mutex mtx_;
	std::condition_variable cond_;

public:
	controller();
	~controller();

	void addObserver(CProgressObserver *instanse);
	void clearObserver();

	bool execute();
};

