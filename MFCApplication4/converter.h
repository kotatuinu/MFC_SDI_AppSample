#pragma once
#include <thread>
class converter
{
public:
	converter();
	~converter();

	void execute(IBindStatusCallback *pCallback);
	void convertThread(IBindStatusCallback *pCallback);
};

