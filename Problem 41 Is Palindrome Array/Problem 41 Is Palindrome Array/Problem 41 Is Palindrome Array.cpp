#include <iostream>
using namespace std;

int ReadNumber(const std::string& msg) {
    int Num;
    cout << msg << std::endl;
    cin >> Num;
    return Num;
}
void FillArray(int arr[100], int& length)
{
    length = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 200;
    arr[5] = 10;
}
void ReadArrayElements(int arr[100], int& length)
{
    cout << "\nEnter Array Elements:\n";
    for (int i = 0; i < length; i++)
    {
        cout << "Element[" << i + 1 << "]:";
        cin >> arr[i];
    }
}
bool IsPalindromeArray(int arr[100], int &length)
{
   // int j = length;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] != arr[length-i-1])
        {
            return false;
        }
       
    }
    return true;
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
    int arr[100], length = 0; //length =ReadNumber("Please Enter Array Length");
   // ReadArrayElements(arr, length);
    FillArray(arr, length);
    cout << "Array Elements:\n";
    PrintArray(arr, length);
    if (IsPalindromeArray(arr, length))
        cout << "\nYes,It's Palindrome Array\n";
    else
        cout << "\nNo,It's Not Palindrome Array\n";
}

