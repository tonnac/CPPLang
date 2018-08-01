#include <iostream>
#include <ctime>

void InsertionSort(int arr[], int len)
{
	int j;
	int i;
	int element;
	for (i = 1; i < len; i++)
	{
		element = arr[i];
		{
			j = i - 1;
			while (j >= 0 && arr[j] < element)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = element;
		}
	}
}

void randominput(int arr[], int len)
{
	for (int i = 0; i < len;i++)
	{
		arr[i] = rand() % 300;
	}
}

void Print(int arr[], int len)
{
	for (int i = 0; i < len;i++)
	{
		std::cout << arr[i] << " ";
	}
}

int main()
{
	srand(time(NULL));
	int arr[20];
	randominput(arr, 20);
	Print(arr, 20);
	std::cout << std::endl;
	InsertionSort(arr, 20);
	Print(arr, 20);
}
