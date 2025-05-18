#include <iostream>
#include <my_library.hpp>
#include <cstdlib>
using namespace std;
int RandomNumber(int from, int to)
{
    int RandNum;
    RandNum = rand() % (to - from + 1) + from;
    return RandNum;
}
void ReadRandomArrayElements(int arr[100], int& length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] =RandomNumber(1, 100);
    }
    
}
void SumArr1and2(int arr1[100], int arr2[100], int arr3[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr3[i] = arr1[i]+arr2[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr1[100],arr2[100],arr3[100], length=MyLib::ReadNumber("How Many Elements?\n");
    ReadRandomArrayElements(arr1, length);
    ReadRandomArrayElements(arr2, length);
    SumArr1and2(arr1, arr2, arr3, length);
    cout << "Array 1 Elements:\n";
    MyLib::PrintArrayElements(arr1, length);
    cout << "Array 2 Elements:\n";
    MyLib::PrintArrayElements(arr2, length);
    cout << "\nSum Of Array 1 and Array 2 is:\n";
    MyLib::PrintArrayElements(arr3, length);

}

