#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

bool Sorted(int* Array, int Size) {
	int i = 0;
	for (i = 0; i < (Size - 1); i++) {
		if (Array[i] <= Array[i + 1]) {
			return true;
		}
	}
	return false;
}

bool Sorted(char* Array, int Size) {
	int i = 0;
	for (i = 0; i < (Size - 1); i++) {
		if (Array[i] <= Array[i + 1]) {
			return true;
		}
	}
	return false;
}

int BinarySearch(int* Array, int FindElement, int Size) {
	int begin = 0, medium = Size/2, end = Size - 1;
	while (Array[medium] != FindElement) {
		medium = begin + end; //find size
		if (FindElement > Array[medium]) { //start with the medium element
			begin = medium + 1;
		}
		else if (FindElement < Array[medium]) {
			end = medium - 1;
		}
		else {
			return medium;
		}
		if (end < begin) { //if the "end" has reached the beginning.
			throw out_of_range("Impossible to find"); 
		}
	} 
	return medium;
}

void QuickSort(int* Array, int Size) { 
	int begin = 0, medium = Array[Size / 2], end = Size - 1;
	int a = 0;
	while (begin <= end) {
		while (Array[begin] < medium) {
			begin++;
		}
		while (Array[end] > medium) {
			end--;
		}
		if (begin <= end) {
			a = Array[begin];
			Array[begin] = Array[end];
			Array[end] = a;
			begin++;
			end--;
		} 
	} 
	if (begin <= Size - 1) {
		QuickSort(&Array[begin], Size - begin);
	}
	if (end > 0) {
		QuickSort(Array, end + 1);
	}
} 

void InsertionSort(int* Array, int Size) { 
	int begin = 0, end = 0, FindElement = 0;
	for (begin = 1; begin < Size; begin++) {
		FindElement = Array[begin];
		end = begin - 1;
		while ((end >= 0)&&(Array[end] > FindElement)) {
			Array[end + 1] = Array[end];
			end = end - 1;
		} 
		Array[end + 1] = FindElement;
	} 
}

void BogoSort(int* Array, int Size) { 
	srand(time(NULL)); 
	int a = 0; 
	while (!Sorted(Array, Size)) {
		for (int begin = 0; begin < Size; begin++) {
			a = Array[begin];
			Array[begin] = Array[rand() % Size];
			Array[rand() % Size] = a;
		}
	}
}

void CountingSort(char* Array, int Size) {
	int index1 = 0, index2 = 0, max = 0;
	for (index1 = 0; index1 < Size; index1++) {
		if (max < int(Array[index1])) {
			max = int(Array[index1]);
		}
	}
	int* count = new int[max + 1];
	for (index1 = 0; index1 < max + 1; index1++) {
		count[index1] = 0;
	}
	for (index1 = 0; index1 < Size; index1++) {
		count[int(Array[index1])]++;
	}
	while (index1 < max + 1) {
		while (count[index1] != 0) {
			Array[index2] = char(index1);
			count[index1]--;
			index2++;
		}
		index1++;
	}
}

int main()
{
	int* array;
	int Size = 10;
	clock_t time = 0;
	double Array_time[10];
	double max_time = 0;
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 10; j++)
		{
			array = new int[Size];
			for (int i = 0; i < Size; i++)
			{
				array[i] = rand();
			}
			time = clock();
			QuickSort(array, Size - 1);
			time = clock() - time;
			Array_time[j] = (double)time / CLOCKS_PER_SEC;
			cout << Array_time[j] << endl;
			max_time += Array_time[j];
			delete[] array;
		}
		cout << "Average time: " << max_time / 10 << endl;
		Size = Size * 10;
		max_time = 0;
	}
	Size = 10;
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 10; j++)
		{
			array = new int[Size];
			for (int i = 0; i < Size; i++)
			{
				array[i] = rand();
			}
			time = clock();
			InsertionSort(array, Size);
			time = clock() - time;
			Array_time[j] = (double)time / CLOCKS_PER_SEC;
			cout << Array_time[j] << endl;
			max_time += Array_time[j];
			delete[] array;
		}
		cout << "Average time: " << max_time / 10 << endl; Size = Size * 10; max_time = 0;
	} return 0;
}