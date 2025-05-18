#include <iostream>
#include <cstdlib>
using namespace std;

int ReadNumber(string msg) {
    int Num;
    cout << msg <<endl;
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
        arr[i] =RandomNumber(1, 100);
}
void AddToArray(int Number, int arr[100], int& length)
{
    length++;
    arr[length - 1] = Number;
}
void AddToCopyArray(int arr[100],int Copyarr[100],int length,int &length2)
{
    for (int i = 0; i < length; i++)
        AddToArray(arr[i],Copyarr,length2);
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
    int arr[100], length =ReadNumber("Please Enter Length Of Array?"),Copyarr[100],length2=0;
    ReadRandomArrayElements(arr, length);
    AddToCopyArray(arr, Copyarr, length, length2);
    cout << "\nArray 1 Elements:\n";
    PrintArrayElements(arr, length);
   cout << "\nArray 2 Elements:\n";
    PrintArrayElements(Copyarr, length);
}

