#pragma once

#include <iostream>
#include <functional>
#include <list>
#include <memory>


template<typename T, typename ... ARGS>
class Delegate
{
	using typeFunc = std::function<T(ARGS...)>;
	typedef T(fntype)(ARGS...);

public:
	void AddFunc(typeFunc func);
	void RemoveFunc(typeFunc func);

	void AddLambda([](ARGS...)->T);

	void BroadCast(ARGS...args);

private:
	std::list<typeFunc> mDelegate;
};

#define FUNC_DECLARE_DELEGATE(Name, ...) \
typedef Delegate<__VA_ARGS__> Name;

#define MULTICAST_DELEGATE(RetType, Name, Param1Type, Param1Name) \
FUNC_DECLARE_DELEGATE(Name, RetType, Param1Type)