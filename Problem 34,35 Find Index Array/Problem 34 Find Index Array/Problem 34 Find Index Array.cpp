#include <iostream>
#include <cstdlib>
using namespace std;

int ReadNumber(string msg) {
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
void ReadRandomArray(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] =RandomNumber(1,100);
    }
}
void PrintArray(int arr[100], int length)
{
    cout << "\nArray Elements:\n";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int SearchNumberInArray(int arr[100], int length, int SearchNum)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == SearchNum)
        {
            return i;
        }
    }
    return -1;
}
void PrintArrayIndex(int arr[100],int length, int SearchNum)
{
    if (SearchNumberInArray(arr,length,SearchNum)!=0)
    {
        cout << "The Number Found At Position:" << SearchNumberInArray(arr, length, SearchNum) << endl;
        cout << "The Number Found At Order:" << SearchNumberInArray(arr, length, SearchNum) + 1 << endl;
    }
    else
        cout <<"Number is Not Found:-("<<endl;
}
bool CheckIndex(int arr[100], int length,int SearchNum)
{
    return SearchNumberInArray(arr, length, SearchNum) !=-1;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100],length=ReadNumber("Please Enter Number Of Elements");
    ReadRandomArray(arr,length);
    PrintArray(arr, length);
    int SearchNum = ReadNumber("Please Enter a Number to Search For:");
    cout << "--------------------------------\n";
    cout << "\nNumber you are looking for is:" << SearchNum << endl;
    // if(SearchNum==-1)
    if(CheckIndex(arr,length,SearchNum))
          cout << "Yes,Number is Found:-)" << endl;
    else
        cout << "No,Number is Not Found:-(" << endl;
   //  else 
      //   cout << "The Number Found At Position:" << SearchNumberInArray(arr, length, SearchNum) << endl;
   //  cout << "The Number Found At Order:" << SearchNumberInArray(arr, length, SearchNum) + 1 << endl;
}

