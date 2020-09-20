#include "delegate.h"

void Delegate::BroadCast()
{
	for (auto & b : mDelegate)
	{
		b();
	}
}

void Delegate::AddFunc(std::function<void()>func)
{
	mDelegate.push_back(func);
}

void Delegate::RemoveFunc(std::function<void()> func)
{
	std::list<std::function<void()>>::iterator iter;

	for (iter = mDelegate.begin(); iter != mDelegate.end();)
	{
		typedef void (fntype)(void);

		auto a = func.target<void(*)()>();
		auto b = (*iter).target<fntype*>();

		if (*a == *b)
		{
			mDelegate.erase(iter++);
		}
		else
		{
			++iter;
		}
	}

}
