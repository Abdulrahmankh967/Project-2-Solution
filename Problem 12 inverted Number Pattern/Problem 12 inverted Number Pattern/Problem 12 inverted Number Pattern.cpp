#include <iostream>
#include <my_library.hpp>
using namespace std;

void InvertedNumberPattern(int Num)
{
    for (int i= Num; i>=1; i--)
    {
        for (char j = 1; j <=i; j++)
        {
            cout <<char(i+64);
        }
        Num--;
        cout << endl;
    }
}
void NormalNumberPattern(int Num)
{
    for (int i = 1; i <= Num; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            cout <<char(i+64);
        }
        cout << endl;
      
    }



}
int main()
{
InvertedNumberPattern(MyLib::ReadNumber("Please Enter Number"));
}

