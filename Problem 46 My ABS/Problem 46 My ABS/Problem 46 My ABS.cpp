#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(string msg) {
    float Num;
    cout << msg << std::endl;
    cin >> Num;
    return Num;
}
float Myabs(float Num)
{
    if (Num > 0)
        return Num;
    else
        return -Num;
}
int main()
{
    float Num = ReadNumber("Please Enter Number");
    cout << "\nMy abs Result=" << Myabs(Num) << endl;
    cout << "C++ abs Result=" << abs(Num) << endl;
}

