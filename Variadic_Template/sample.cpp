#include <iostream>

template <typename ... ARGS> class Test {};
template <typename ... ARGS> void fooo(ARGS...args) { std::cout << "1" << std::endl; }

int f(int a) { return a + 1; }

template <typename ... Types>
void goo(Types ... Args)
{
	std::cout << "goo" << std::endl;
}

void hoo(int a, int b, int c)
{
	std::cout << "hoo" << a << b << c << std::endl;
}

template <typename ... ARGS>
void foo(ARGS...args)
{
	std::cout << sizeof...(ARGS) << std::endl;
	std::cout << sizeof...(args) << std::endl;


	goo(args...);
	hoo(args...);
	hoo(f(args)...);
}

int main()
{
//	foo(1, 2, 3, 4);
//	Test<int, double, float> e;

	foo(1, 2, 3);

	return 0;
}