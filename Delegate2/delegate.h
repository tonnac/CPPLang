#include <iostream>
#include <list>
#include <functional>
#include <memory>

class Delegate
{
public:
	void BroadCast();

	void AddFunc(std::function<void()>func);
	void RemoveFunc(std::function<void()>func);

private:
	std::list<std::function<void()>> mDelegate;
};