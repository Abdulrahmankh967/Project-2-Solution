#include <iostream>
#include <my_library.hpp>
#include <cstdlib>
using namespace std;

void ReadArrayElements(int arr[100], int& length)
{
	cout << "Please Enter Number Of Elements" << endl;
	cin >> length;
	int max = 0;
	for (int i = 0; i < length; i++)
	{
		arr[i] = MyLib::RandomNumber(1, 100);
	}

}
int MaxNumberInArray(int arr[100],int length)
{
	int max=0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
int MinNumberInArray(int arr[100], int length)
{
	int min=arr[0];
	for (int i = 1; i < length; i++)
	{
		if (arr[i]< min)
			min = arr[i];
	}
	return min;

}
int SumOfRandomArray(int arr[100], int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}
	return sum;
}
float AverageOfRandomArray(int arr[100], int length)
{
	return (float)SumOfRandomArray(arr, length) / length;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	int length = 0;
   ReadArrayElements(arr, length);
   cout << "\nArray Elements:\n";
   MyLib::PrintArrayElements(arr,length);
   cout << "\nMax Random Number=" <<MaxNumberInArray(arr,length)<< endl;
   cout << "\nMinumum Random Number=" << MinNumberInArray(arr, length) << endl;
   cout << "\nSum Of Random Array=" << SumOfRandomArray(arr, length) << endl;
   cout << "\nAverage Of Random Array=" << AverageOfRandomArray(arr, length) << endl;
}

