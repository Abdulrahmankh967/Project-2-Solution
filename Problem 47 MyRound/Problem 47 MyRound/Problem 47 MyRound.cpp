#include <iostream>
#include <cmath>
using namespace std;
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
int DrMohRound(float Num)
{
    int IntPart=(int)Num;
    float FractionPart = GetFractionPart(Num);
    if (abs(FractionPart) >= 0.5)
    {
        if (Num > 0)
            return ++IntPart;
        else
            return --IntPart;
    }
    else
        return IntPart;
}
float MyRound(float Num)
{
    if (Num > 0)
    {
        if (Num - (int)Num >= 0.5)
            return (int)Num + 1;
        else
            return (int)Num;
    }
    else
    {
        if ((int)Num-Num >= 0.5)
            return (int)Num-1;
        else
            return (int)Num;
    }
}


int main()
{
    float Num = ReadNumber("Please Enter Number");
    cout << "My Round=" << DrMohRound(Num)<<endl;
    cout << "C++ Round=" << round(Num)<<endl;
}