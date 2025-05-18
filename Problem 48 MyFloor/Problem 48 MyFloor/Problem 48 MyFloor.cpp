#include <iostream>
#include <cmath>
using namespace std;
int MyFloor(float Num)
{
    if (Num > 0)
        return (int)Num;
    else
        return (int)Num - 1;
}

float ReadNumber(string msg) {
    float Num;
    cout << msg << std::endl;
    cin >> Num;
    return Num;
}
float GetFractionPart(float Num)
{
    return Num - (int)Num;
}

int MyCeil(float Num)
{
    if (abs(GetFractionPart(Num)) > 0)
    {
        if (Num > 0)
            return (int)Num + 1;
        else
            return (int)Num;
    }
}
int main()
{
    float Num = ReadNumber("Please Enter Number?");
  //  cout << "C++ Floor=" <<floor(Num)<<endl;
  //  cout << "My Floor=" << MyFloor(Num) << endl;

    cout << "My Ceil=" << MyCeil(Num)<<endl;
    cout << "C++ Ceil=" << ceil(Num) << endl;
}

