#include <iostream>
#include <my_library.hpp>
#include <cstdlib>
using namespace std;
enum enPrimeNotPrime{Prime=1,NotPrime=2};
void ReadRandomArrayElements(int arr[100], int &length)
{
    cout << "Please Enter Number Of Elements" << endl;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        arr[i] = MyLib::RandomNumber(1, 100);
    }

}
void CopyArray(int arr[100],int CopyArr[100], int length)
{
    
    for (int i = 0; i < length; i++)
    {
        CopyArr[i] = arr[i];
    }
}
enPrimeNotPrime CheckNumber(int N)
{

    for (int i = 2; i <= N / 2; i++)
    {
        if (N % i == 0)
            return enPrimeNotPrime::NotPrime;


    }
    return enPrimeNotPrime::Prime;
}
void CopyPrimeELements(int arr[100], int CopyArr[100], int length,int &length2)
{
    int Counter=0;
    for (int i = 0; i < length; i++)
    {
        if (CheckNumber(arr[i]) == enPrimeNotPrime::Prime)
        {
            CopyArr[Counter] = arr[i];
            Counter++;
        }
    }
    length2 = --Counter;
}
int main()
{
    srand((unsigned)time(NULL));

    int arr[100], length;

    ReadRandomArrayElements(arr, length);

    int CopyArr[100];
    int length2=0;

    CopyArray(arr, CopyArr, length);

    cout << "\nArray Elements:\n";
    MyLib::PrintArrayElements(arr, length);

    cout << "\nCopy Array Elements:\n";
    MyLib::PrintArrayElements(CopyArr, length);
    
}

