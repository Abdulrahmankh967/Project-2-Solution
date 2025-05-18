#include <iostream>
using namespace std;

void FillArray(int arr[100],int &length)
{
    length = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}
void AddToArray(int Number, int arr[100], int& length)
{
    length++;
    arr[length - 1] = Number;
}
int SearchNumberInArray(int Number,int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == Number)
        {
            return i;
        }
    }
    return -1;
}
bool IsNumberInArray(int Number,int arr[100],int length)
{
    return SearchNumberInArray(Number,arr,length) !=-1;
}
void CopyDistinctElementToArray(int arr[100], int arr2[100], int length, int &length2)
{
    for (int i = 0; i < length; i++)
    {
        if (!IsNumberInArray(arr[i], arr2, length))
        {
            AddToArray(arr[i], arr2, length2);
        }
    }
}
void PrintArrayElements(int arr[100],int length)
{
    for (int i = 0; i <length; i++)
        cout << arr[i] << " ";

    cout << endl;
}
int main()
{
    int length=0,length2=0;
    int arr[100], arr2[100];
    FillArray(arr, length);
    cout << "Array 1 Elements:\n";
    PrintArrayElements(arr,length);
    CopyDistinctElementToArray(arr, arr2, length, length2);
    cout << "\nArray 2 Distinct Elements:\n";
    PrintArrayElements(arr2, length2);
}
