#include <iostream>
#include <cstdlib>
using namespace std;

int ReadNumber (string msg) {
    int Num;
    cout << msg << std::endl;
    cin >> Num;
    return Num;
}
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
        arr[i] =RandomNumber(-100, 100);
    }

}
void PrintArrayElements(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int CountOdd(int arr[100], int length)
{
   int countOdd = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 2 != 0)
           countOdd++;
    }
    return countOdd;
}
int CountEven(int arr[100], int length)
{
    int countEven = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 2 == 0)
            countEven++;
    }
    return countEven;
}
int CountPositive(int arr[100], int length)
{
    int countPos = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > 0)
            countPos++;
    }
    return countPos;
}
int CountNegative(int arr[100], int length)
{
    int countNeg = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0)
            countNeg++;
    }
    return countNeg;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], length = ReadNumber("Please Enter Number Of Elements");
    ReadRandomArrayElements(arr, length);
    cout << "\nArray Elements:";
    PrintArrayElements(arr, length);
    cout << "\nOdd Numbers in Array is " << CountOdd(arr, length)<<endl;
    cout << "\nEven Numbers in Array is " << CountEven(arr, length) << endl;
    cout << "\nPositive Numbers in Array is " << CountPositive(arr, length) << endl;
    cout << "\nNegative Numbers in Array is " << CountNegative(arr, length) << endl;


}
