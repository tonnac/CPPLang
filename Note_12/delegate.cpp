#include "delegate.h"

template<typename T, typename ... ARGS>
void Delegate<T, ARGS...>::AddFunc(typeFunc func)
{
	T(*A)(ARGS...) = *(func.target<fntype*>());
	
	for (auto & a : mDelegate)
	{
		T(*B)(ARGS...) = *(a.target<fntype*>());

		if (A == B)
		{
			return;
		}
	}
	mDelegate.push_back(func);
}

template<typename T, typename ... ARGS>
void Delegate<T, ARGS...>::RemoveFunc(typeFunc func)
{
	T(*A)(ARGS...) = *(func.target<fntype*>());

	for (auto iter = mDelegate.begin(); iter != mDelegate.end();)
	{
		T(*B)(ARGS...) = *iter->target<fntype*>();

		if (A == B)
		{
			mDelegate.erase(iter++);
		}
		else
		{
			++iter;
		}
	}

}

template<typename T, typename ...ARGS>
void Delegate<T, ...ARGS>::AddLambda([](ARGS...)-> T)
{

}

template<typename T, typename ... ARGS>
void Delegate<T, ARGS...>::BroadCast(ARGS...args)
{
	if (!mDelegate.empty())
	{
		for (auto& a : mDelegate)
		{
			a(args...);
		}
	}
}