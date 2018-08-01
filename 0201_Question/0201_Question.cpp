#include "0201_Question.h"
#include <iostream>


void QUESTION_1::Plus(int & ref)
{
	++ref;
}
void QUESTION_1::Change(int & ref)
{
	ref *= -1;
}

QUESTION_3::QUESTION_3(int a, int b) : num1(a), num2(b), ptr1(&num1), ptr2(&num2)
{}

void QUESTION_3::Main()
{
	std::cout << "ptr1: " << *ptr1 << std::endl;
	std::cout << "ptr2: " << *ptr2 << std::endl;
	Swap();
	std::cout << "ptr1: " << *ptr1 << std::endl;
	std::cout << "ptr2: " << *ptr2 << std::endl;
}

void QUESTION_3::Swap()
{
	ptr1 = &num2;
	ptr2 = &num1;
}