#include <iostream>
#include <my_library.hpp>
using namespace std;

void ReadArrayElements(int arr[100],int &length)
{ 
	cout << "Please Enter Number Of Elements" << endl;
	cin >> length;
	cout << "\nEnter Array Elements:\n";
	for (int i = 0; i < length; i++)
	{
		cout << "Element[" << i+1 << "]:";
		cin >> arr[i];
	}
}
void PrintArrayElements(int arr[100],int length)
{
	
	for (int i = 0; i < length; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
}
int HowCheckRepeted(int arr[100],int length,int Check)
{
	int Count = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == Check)
			Count++;
	}
	return Count;
}
int main()
{
	int arr[100];
	int length=0;
	ReadArrayElements(arr,length);
	int Check = MyLib::ReadNumber("Please Enter Number You Want to Check:");
	cout << "\nOrginal Array:";
	PrintArrayElements(arr, length);
	cout << "Number " << Check << " is repeted ";
	cout << HowCheckRepeted(arr, length, Check) << " time(s)" << endl;
}

