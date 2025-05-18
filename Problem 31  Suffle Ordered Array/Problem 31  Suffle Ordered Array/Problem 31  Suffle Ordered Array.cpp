#include <iostream>
#include <cstdlib>
using namespace std;
int ReadNumber(const string msg) {
	int Num;
	cout << msg << std::endl;
	cin >> Num;
	return Num;
}
void ReadArray(int arr[100],int length)
{
	
	for (int i = 0; i < length; i++)
	{
		arr[i] =i + 1;
	}
}
void Swap(int& A, int& B)
{
	int temp;
	temp = A;
	A = B;
	B = temp;
}
int RandomNumber(int from, int to)
{
	int RandNum;
	RandNum = rand() % (to - from + 1) + from;
	return RandNum;
}
void ArrayBeforeSuffle(int arr[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void ArrayAfterSuffle(int arr[100], int length)
{	
	for (int i =0; i<length; i++)
	{
		Swap(arr[RandomNumber(1,length)-1],arr[RandomNumber(1,length)-1]);
	}
}
void Print(int arr[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], length = ReadNumber("Please Enter Array Elements");
	ReadArray(arr, length);
	cout << "Array Elements Before Shuffle:\n";
	ArrayBeforeSuffle(arr, length);
	ArrayAfterSuffle(arr, length);
	cout << "Array Elements After Shuffle:\n";
	Print(arr, length);
}
