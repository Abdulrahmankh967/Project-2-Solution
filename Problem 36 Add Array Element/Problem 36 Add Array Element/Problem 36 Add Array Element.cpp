#include <iostream>
#include <my_library.hpp>

using namespace std;
int ReadNumber(string message)
{
	int Num;
	cout << message;
	cin >> Num;
	return Num;
}
void AddToArray(int Number,int arr[100], int &length)
{
	length++;
	arr[length - 1] = Number;
}
void InputUserNumberInArray(int arr[100], int &length)
{
	bool AddMore = true;
	do
	{
		AddToArray(ReadNumber("Please Enter Number?"),arr,length);
		cout << "Do You Want to add more Numbers?[0],NO:[1],Yes:";
	    cin >> AddMore;
	} while (AddMore);
}
void PrintArray(int arr[100], int &length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << endl;
}
int main()
{
	int arr[100], length = 0,Copyarr[100];
	InputUserNumberInArray(arr, length);
	cout << "---------------------------\n";
	cout << "\nArray Length:" << length << endl;
	cout << "Array Elements:";
	PrintArray(arr, length);
	
}

