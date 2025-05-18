#include <iostream>
#include <cstdlib>
using namespace std;
enum enRandom { SpecialChar = 1, SmallLetter = 2, CapitalLetter = 3, Digit = 4 };
int ReadNumber(const string& msg) {
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
char GetRandomChar(enRandom CharType)
{
    switch (CharType)
    {
    case enRandom::SpecialChar:
        return RandomNumber(33, 47);
    case enRandom::SmallLetter:
        return RandomNumber(97, 122);
    case enRandom::CapitalLetter:
        return RandomNumber(65, 90);
    case enRandom::Digit:
        return RandomNumber(48, 57);
    }
}
string GeneratrWord(enRandom CharType,short length)
{
    string word = "";
    for (int i = 0; i < length; i++)
    {
        word += GetRandomChar(CharType);
    }
    return word;
}
string GenerateKey()
{
    string Key = "";
    Key += GeneratrWord(enRandom::CapitalLetter, 4)+"-";
    Key += GeneratrWord(enRandom::CapitalLetter, 4)+"-";
    Key += GeneratrWord(enRandom::CapitalLetter, 4)+"-";
    Key += GeneratrWord(enRandom::CapitalLetter, 4);
    return Key;
}
void FillArrayWithtKeys(string arr[100],int NumOfKeys)
{
    for (int i =0; i < NumOfKeys; i++)
    {
        arr[i] = GenerateKey();
       
    }
}
void PrintStringArray(string arr[100], short length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "Array[" << i + 1 << "]:" << arr[i] << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    string arr[100];
    int Keys =ReadNumber("Please Enter Number Of Keys");
    FillArrayWithtKeys(arr, Keys);
    PrintStringArray(arr, Keys);
}

