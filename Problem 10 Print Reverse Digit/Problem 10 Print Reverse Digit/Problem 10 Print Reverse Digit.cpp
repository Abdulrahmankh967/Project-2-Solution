#include <iostream>
using namespace std;

int ReadNumber(string message)
{
	int Num;
	cout << message << endl;
	cin >> Num;
	return Num;
}

int ReverseDigits(int Num)
{
	int x = 0;
	int Num2 = 0;

	while (Num > 0)
	{
		x = Num % 10;
		Num = Num / 10;
		Num2 = Num2 * 10 + x;
		//or
		//cout<<x; without Num2 var
	}
	return Num2;
}
void PrintDigitsReverse(int Num)
{
	int x = 0;
	int Num2 = ReverseDigits(Num);
	while (Num2 > 0)
	{
		x = Num2 % 10;
		Num2 = Num2 / 10;
		cout << x << endl;
	}

}
int main()
{
	
	PrintDigitsReverse(ReadNumber("Please Enter Number"));

}

