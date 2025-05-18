#include <iostream>
#include <my_library.hpp>
#include <cstdlib>
using namespace std;

void CopyReverseArray(int arr1[100], int Copyarr[100], int length)
{
   // int x = length;
    for (int i = 0; i < length; i++)
    {
        Copyarr[i] = arr1[length-1-i];
       // x--;
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int arr[100],Copyarr[100], length = MyLib::ReadNumber("Please Enter Array Length");
    MyLib::ReadRandomArrayElements(arr, length);
    CopyReverseArray(arr, Copyarr, length);
    cout << "\nArray 1 Elements:\n";
    MyLib::PrintArrayElements(arr, length);
    cout << "Array Reverse Elements\n";
    MyLib::PrintArrayElements(Copyarr, length);
}

