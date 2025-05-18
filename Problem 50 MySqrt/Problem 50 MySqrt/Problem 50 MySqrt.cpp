#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(string msg) {
    float Num;
    cout << msg << std::endl;
    cin >> Num;
    return Num;
}
int MySqrt(float Num)
{
    return pow(Num, 0.5);
}

int main()
{
    float Num = ReadNumber("Please Enter Number?");
    cout << "\nMy Sqrt=" << MySqrt(Num) << endl;
    cout << "C++ Sqrt=" << sqrt(Num);
}

