#include <conio.h>
#include <Windows.h>
#include<iostream>
using namespace std;
template<class T>
void sort_1(T *arr, int n)//прямым включение 
{
	for (int i = 1; i < n; i++)
	{
	 T temp = arr[i];
	 int index = i;
	 while ((index > 0) && (arr[index - 1]) > temp)
	 {
		 arr[index] = arr[index - 1];
		 index--;
	 }
	 arr[index] = temp;
	}
 }
void sort_2(int*arr, int size)//прямым выбором
{
	int min, temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
void sort_3(int*arr, int size)//пузырьком 
{
	for (int i = 0; i < (size - 1); i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j-1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}



void sort_4(int *arr, int size)//шейкерная 
{
	bool flag = true;
	int left = 0, right = size - 1;
	while ((left < right) && (flag == true))
	{
		flag = false;
		for (int i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = true;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				int temp = arr[i];
				arr[i] = arr[i-1];
				arr[i - 1] = temp;
				flag = true;
			}
		}
		left++;
	}
}
void sort_5(int*arr, int size)//шелла версия 1  
{
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = 0; i <(size-step); i++)
		{
			int j = i;
			while ((j >=0) && (arr[j] > arr[j + step]))
			{
				int temp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = temp;
				j--;
			}
		}
	}
}
void ShellSort(int size, int*arr)//шелла версия два 
{
	int j;
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = step; i < size; i++)
		{
			int temp = arr[i];
			for (j = i; j >= step; j -= step)
			{
				if (temp < arr[j - step])
				{
					arr[j] = arr[j - step];
				}
				else break;
			}
			arr[j] = temp;
		}
	}
}
void sort_fast(int*arr, int first, int last)
{
	int base = arr[(last + first) / 2];
	int left = first;
	int right = last;
	do {
		while (arr[right] > base) right--;
		while (arr[left] < base) left++;
		if (left <= right) {
			swap(arr[left], arr[right]);
			right--; left++;
		}
	} while (left <= right);
	if (left < last) sort_fast(arr, left, last);
	if (right > first) sort_fast(arr, first, right);
}
int main()
{
	int arr[10] = { 1,5,12,4,0,2,4,7,8,10 };
	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i];
		cout << "  ";
	
	}
	printf(" \n");
	cout << endl;
	sort_fast(arr,0,9);
	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i];		
		cout <<"  ";
	}
	cout << endl;
	getchar();
	return 0;
}