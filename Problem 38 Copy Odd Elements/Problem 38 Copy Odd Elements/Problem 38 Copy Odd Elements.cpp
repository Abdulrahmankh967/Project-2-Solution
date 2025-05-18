#include <iostream>
#include <cstdlib>
using namespace std;
enum enPrimeNotPrime{Prime=1,NotPrime=2};
enPrimeNotPrime CheckNumber(int Num)
{
    for (int i = 2; i <= Num / 2; i++)
    {
        if (Num % i == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

int ReadNumber(string msg) {
    int Num;
    cout << msg << endl;
    cin >> Num;
    return Num;
}
int RandomNumber(int from, int to)
{
    int RandNum;
    RandNum = rand() % (to - from + 1) + from;
    return RandNum;
}
void ReadRandomArrayElements(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
        arr[i] = RandomNumber(1, 100);
}
void AddToArray(int Number, int arr[100], int& length)
{
    length++;
    arr[length - 1] = Number;
}
void CopyOddElements(int arr[100], int arr2[100], int length, int& length2)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 2 != 0)
            AddToArray(arr[i], arr2, length2);
    }
}
void CopyPrimeElements(int arr[100], int arr2[100], int length, int& length2)
{
    for (int i = 0; i < length; i++)
    {
        if (CheckNumber(arr[i]) == enPrimeNotPrime::Prime)
            AddToArray(arr[i], arr2, length2);
    }
}
void PrintArrayElements(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";

    cout << endl;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arr2[100], length, length2 = 0;
    length = ReadNumber("Please Enter Number Of Elements");
    ReadRandomArrayElements(arr, length);
    CopyPrimeElements(arr, arr2, length, length2);
    cout << "Array 1 Elements:\n";
    PrintArrayElements(arr, length);
    cout << "\nArray 2 Elements:\n";
    PrintArrayElements(arr2, length2);
}

